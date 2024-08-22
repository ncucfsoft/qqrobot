#include "stdafx.h"
#include "PictureEx.h"
#include <math.h>
#include <process.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
extern int switchrate;
extern BOOL ExitFlag;
extern BOOL bShowpwding;
extern BOOL bNoSpecialEffect;
extern int screen_xsize;
extern	int screen_ysize;
extern BOOL bLastGifOver;
int alreadyinitgraph;
//////////////////////////////////////////////////////////////////////
// Nested structures member functions
//////////////////////////////////////////////////////////////////////

inline int CPictureEx::TGIFControlExt::GetPackedValue(enum ControlExtValues Value)
{
	int nRet = (int)m_cPacked;
	switch (Value)
	{
	case GCX_PACKED_DISPOSAL:
		nRet = (nRet & 28) >> 2;
		break;

	case GCX_PACKED_USERINPUT:
		nRet = (nRet & 2) >> 1;
		break;

	case GCX_PACKED_TRANSPCOLOR:
		nRet &= 1;
		break;
	};

	return nRet;
}

inline int CPictureEx::TGIFLSDescriptor::GetPackedValue(enum LSDPackedValues Value)
{
	int nRet = (int)m_cPacked;

	switch (Value)
	{
	case LSD_PACKED_GLOBALCT:
		nRet = nRet >> 7;
		break;

	case LSD_PACKED_CRESOLUTION:
		nRet = ((nRet & 0x70) >> 4) + 1;
		break;

	case LSD_PACKED_SORT:
		nRet = (nRet & 8) >> 3;
		break;

	case LSD_PACKED_GLOBALCTSIZE:
		nRet &= 7;
		break;
	};

	return nRet;
}

inline int CPictureEx::TGIFImageDescriptor::GetPackedValue(enum IDPackedValues Value)
{
	int nRet = (int)m_cPacked;

	switch (Value)
	{
	case ID_PACKED_LOCALCT:
		nRet >>= 7;
		break;

	case ID_PACKED_INTERLACE:
		nRet = ((nRet & 0x40) >> 6);
		break;

	case ID_PACKED_SORT:
		nRet = (nRet & 0x20) >> 5;
		break;

	case ID_PACKED_LOCALCTSIZE:
		nRet &= 7;
		break;
	};

	return nRet;
}


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPictureEx::CPictureEx()
{
	// check structures size
	ASSERT(sizeof(TGIFImageDescriptor) == 10);
	ASSERT(sizeof(TGIFAppExtension)    == 14);
	ASSERT(sizeof(TGIFPlainTextExt)    == 15);
	ASSERT(sizeof(TGIFLSDescriptor)    ==  7);
	ASSERT(sizeof(TGIFControlExt)	   ==  8);
	ASSERT(sizeof(TGIFCommentExt)	   ==  2);
	ASSERT(sizeof(TGIFHeader)		   ==  6);
	m_image=NULL;
	m_pGIFLSDescriptor = NULL;
	m_pGIFHeader	   = NULL;
	m_pPicture		   = NULL;
	m_pRawData		   = NULL;
	m_hThread		   = NULL;
	m_hBitmap          = NULL;
	m_hMemDC		   = NULL;
	m_bIsInitialized   = FALSE;
	m_bExitThread	   = FALSE;
	m_bIsGIF		   = FALSE;
	m_clrBackground    = RGB(0,0,0); // white by default
	m_nGlobalCTSize    = 0;
	m_nCurrOffset	   = 0;
	m_nDataSize		   = 0;
	m_PictureSize.cx = m_PictureSize.cy = 0;
	m_iStartTime=0;
	m_bShouldStart=0;
	m_bStartingeffect=0;
	m_crossstop=false;
	m_hExitEvent = CreateEvent(NULL,TRUE,FALSE,NULL);
}

CPictureEx::~CPictureEx()
{
	UnLoad();
	CloseHandle(m_hExitEvent);
}

BEGIN_MESSAGE_MAP(CPictureEx, CStatic)
	//{{AFX_MSG_MAP(CMyStatic)
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CPictureEx::Load(HGLOBAL hGlobal, DWORD dwSize)
{
	blankimage=false;

	IStream *pStream = NULL;
	UnLoad();
	if(dwSize==0)
		blankimage=true;
	
	if(blankimage==false)
	{
	if (!(m_pRawData = reinterpret_cast<unsigned char*> (GlobalLock(hGlobal))) )
	{
		TRACE(_T("Load: Error locking memory\n"));
		return FALSE;
	};

	m_nDataSize = dwSize;
	m_pGIFHeader = reinterpret_cast<TGIFHeader *> (m_pRawData);

	if ((memcmp(&m_pGIFHeader->m_cSignature,"GIF",3) != 0) &&
		((memcmp(&m_pGIFHeader->m_cVersion,"87a",3) != 0) ||
		 (memcmp(&m_pGIFHeader->m_cVersion,"89a",3) != 0)) )
	{
	
		// it's neither GIF87a nor GIF89a
	// do the default processing

		// clear GIF variables
		m_pRawData = NULL;
		GlobalUnlock(hGlobal);

		// don't delete memory on object's release
		if (CreateStreamOnHGlobal(hGlobal,FALSE,&pStream) != S_OK)
			return FALSE;

				if(blankimage==false)
		{
				m_image=new CImage;
				
		
		  HRESULT hr =m_image->Load(pStream);
		
    if (!SUCCEEDED(hr))
    {
   
pStream->Release();
delete m_image;
m_image=NULL;
			return FALSE;
   } 
	
	pStream->Release();
		}
		// store picture's size

		//long hmWidth;
		//long hmHeight;
		//hmWidth=m_image->GetWidth();
		//hmHeight=m_image->GetHeight();
		//
		//HDC hDC = ::GetDC(m_hWnd);
		////m_PictureSize.cx = MulDiv(hmWidth, GetDeviceCaps(hDC,LOGPIXELSX), 2540);
		////m_PictureSize.cy = MulDiv(hmHeight, GetDeviceCaps(hDC,LOGPIXELSY), 2540);
		//::ReleaseDC(m_hWnd,hDC);
	}
	else
	{
		// it's a GIF
		m_bIsGIF = TRUE;
		m_pGIFLSDescriptor = reinterpret_cast<TGIFLSDescriptor *>
			(m_pRawData + sizeof(TGIFHeader));
		if (m_pGIFLSDescriptor->GetPackedValue(LSD_PACKED_GLOBALCT) == 1)
		{
			// calculate the globat color table size
			m_nGlobalCTSize = static_cast<int>
				(3*pow(float(2),m_pGIFLSDescriptor->GetPackedValue(LSD_PACKED_GLOBALCTSIZE)+1));
			// get the background color if GCT is present
			unsigned char *pBkClr = m_pRawData + sizeof(TGIFHeader) + 
				sizeof(TGIFLSDescriptor) + 3*m_pGIFLSDescriptor->m_cBkIndex;
			m_clrBackground = RGB(pBkClr[0],pBkClr[1],pBkClr[2]);
		};

		// store the picture's size
		m_PictureSize.cx = m_pGIFLSDescriptor->m_wWidth;
		m_PictureSize.cy = m_pGIFLSDescriptor->m_wHeight;

		// determine frame count for this picture
		UINT nFrameCount=0;
		ResetDataPointer();
		while (SkipNextGraphicBlock())
			nFrameCount++;

#ifdef GIF_TRACING
		TRACE(
			_T(" -= GIF encountered\n"
			   "Logical Screen dimensions = %dx%d\n"
			   "Global color table = %d\n"
			   "Color depth = %d\n"
			   "Sort flag = %d\n"
			   "Size of Global Color Table = %d\n"
			   "Background color index = %d\n"
			   "Pixel aspect ratio = %d\n"
			   "Frame count = %d\n"
			   "Background color = %06Xh\n\n"
			  ),
			m_pGIFLSDescriptor->m_wWidth,
			m_pGIFLSDescriptor->m_wHeight,
			m_pGIFLSDescriptor->GetPackedValue(LSD_PACKED_GLOBALCT),
			m_pGIFLSDescriptor->GetPackedValue(LSD_PACKED_CRESOLUTION),
			m_pGIFLSDescriptor->GetPackedValue(LSD_PACKED_SORT),
			m_pGIFLSDescriptor->GetPackedValue(LSD_PACKED_GLOBALCTSIZE),
			m_pGIFLSDescriptor->m_cBkIndex,
			m_pGIFLSDescriptor->m_cPixelAspect,
			nFrameCount,
			m_clrBackground
			);
		EnumGIFBlocks();
#endif

		if (nFrameCount == 0) // it's an empty GIF!
		{
			m_pRawData = NULL;
			GlobalUnlock(hGlobal);
			return FALSE;
		};

		// now check the frame count
		// if there's only one frame, no need to animate this GIF
		// therefore, treat it like any other pic

		if (nFrameCount == 1)
		{
			// clear GIF variables
			m_pRawData = NULL;
			GlobalUnlock(hGlobal);

			// don't delete memory on object's release
			if (CreateStreamOnHGlobal(hGlobal,FALSE,&pStream) != S_OK)
				return FALSE;

			if (OleLoadPicture(pStream,dwSize,FALSE,IID_IPicture,
				(LPVOID *)&m_pPicture) != S_OK)
			{
				pStream->Release();
				return FALSE;
			};

			pStream->Release();
		}
		else
		{
		// if, on the contrary, there are several frames
		// then store separate frames in an array

			TFrame frame;
			UINT nBlockLen;
			HGLOBAL hFrameData;
			UINT nCurFrame = 0;

			ResetDataPointer();
			while (hFrameData = GetNextGraphicBlock(&nBlockLen,
				&frame.m_nDelay, &frame.m_frameSize,
				&frame.m_frameOffset, &frame.m_nDisposal) )
			{
				#ifdef GIF_TRACING
				//////////////////////////////////////////////
				// uncomment the following strings if you want 
				// to write separate frames on disk
				//
				//	CString szName;
				//	szName.Format(_T("%.4d.gif"),nCurFrame);
				//	WriteDataOnDisk(szName,hFrameData,nBlockLen);
				//	nCurFrame++;
				#endif // GIF_TRACING

				IStream *pStream = NULL;

				// delete memory on object's release
				if (CreateStreamOnHGlobal(hFrameData,TRUE,&pStream) != S_OK)
				{
					GlobalFree(hFrameData);
					continue;
				};

				if (OleLoadPicture(pStream,nBlockLen,FALSE,
					IID_IPicture,
					reinterpret_cast<LPVOID *>(&frame.m_pPicture)) != S_OK)
				{
					pStream->Release();
					continue;
				};
				pStream->Release();
			
				// everything went well, add this frame
				m_arrFrames.push_back(frame);
			};

			// clean after ourselves
			m_pRawData = NULL;
			GlobalUnlock(hGlobal);

			if (m_arrFrames.empty()) // couldn't load any frames
				return FALSE;
		};

	};
	}
	// if (!IsGIF...
	if(blankimage==false)
	{
	if(IsGIF())
	return PrepareDC(m_PictureSize.cx,m_PictureSize.cy);
	else
	return PrepareDC(m_image->GetWidth(),m_image->GetHeight());
	}
	else
	{
	return PrepareDC(screen_xsize,screen_ysize);
	}
}

void CPictureEx::UnLoad()
{
	bPngType=false;	
if(m_image)
{
m_szOld.cx=m_image->GetWidth();
	m_szOld.cy=m_image->GetHeight();
}
	if(m_hMemDC)
	{
	SaveDocImage();
	m_iStartTime = clock();
	m_bShouldStart=true;
	m_crossstop=false;
	}

	//m_mywpstyle=WPSTYLE_TILE;
	if(m_image)
		{
			delete m_image;
			m_image=NULL;
		}
	
	Stop();
	if(m_pPicture)
	{
		m_pPicture->Release();
		m_pPicture = NULL;
	};
	
	std::vector<TFrame>::iterator it;
	for (it=m_arrFrames.begin();it<m_arrFrames.end();it++)
		(*it).m_pPicture->Release();
	m_arrFrames.clear();

	if (m_hMemDC)
	{
	SaveDocImage();
	m_iStartTime = clock();
	m_bShouldStart=true;
	m_crossstop=false;
		SelectObject(m_hMemDC,m_hOldBitmap);
		::DeleteDC(m_hMemDC);
		::DeleteObject(m_hBitmap);
		m_hMemDC  = NULL;
		m_hBitmap = NULL;
	};

	m_pGIFLSDescriptor = NULL;
	m_pGIFHeader	   = NULL;
	m_pRawData		   = NULL;
	m_hThread		   = NULL;
	m_bIsInitialized   = FALSE;
	m_bExitThread	   = FALSE;
	m_bIsGIF		   = FALSE;
	m_clrBackground    = RGB(0,0,0); // white by default
	m_nGlobalCTSize	   = 0;
	m_nCurrOffset	   = 0;
	m_nDataSize		   = 0;
}

BOOL CPictureEx::Draw(int mywpstyle,int step)
{
	m_n_step=step;
	CRect steprect;
	if(step>=0)
	steprect.SetRect(screen_xsize/10.0*(step),0,screen_xsize/10.0*(step+1),screen_ysize);
	else
steprect.SetRect(0,0,screen_xsize,screen_ysize);
	


	if (!m_bIsInitialized)
	{
		TRACE(_T("Call of one the CPictureEx::Load() member functions before calling Draw()\n"));
		return FALSE;
	};
	m_mywpstyle=mywpstyle;
	if(blankimage)
	{
			//m_image->Draw(m_hMemDC, 0, 0, m_image->GetWidth(), m_image->GetHeight(), 0, 0, m_image->GetWidth(), m_image->GetHeight());
	SetBkColor(RGB(0,0,0));
		InvalidateRect(steprect,FALSE);
	}
	else if (IsAnimatedGIF())
	{
	// the picture needs some animation
	// we'll start the thread that will handle it for us
	
		unsigned int nDummy;
		m_hThread = (HANDLE) _beginthreadex(NULL,0,_ThreadAnimation,this,
			CREATE_SUSPENDED,&nDummy);
		if (!m_hThread)
		{
			TRACE(_T("Draw: Couldn't start a GIF animation thread\n"));
			return FALSE;
		} 
		else 
			ResumeThread(m_hThread);
	} 
	else
	{
		if(IsGIF())
		{
		if (m_pPicture)
		{
			long hmWidth;
			long hmHeight;
			m_pPicture->get_Width(&hmWidth);
			m_pPicture->get_Height(&hmHeight);
		
						{
				if (m_pPicture->Render(m_hMemDC, 0, 0, m_PictureSize.cx, m_PictureSize.cy, 
				0, hmHeight, hmWidth, -hmHeight, NULL) == S_OK)
			{
				InvalidateRect(steprect,FALSE);

				return TRUE;
			}
			
						}
		}
		}
		else
		{
			if(m_image)
			{
		m_image->Draw(m_hMemDC, 0, 0, m_image->GetWidth(), m_image->GetHeight(), 0, 0, m_image->GetWidth(), m_image->GetHeight());
		InvalidateRect(steprect,FALSE);
			}
		
		}
	};

	return FALSE;	
}

SIZE CPictureEx::GetSize() const
{
	return m_PictureSize;
}


BOOL CPictureEx::Load(LPCTSTR szFileName)
{
	ASSERT(szFileName);
	
	CFile file;
	HGLOBAL hGlobal;
	DWORD dwSize;

	if (!file.Open(szFileName,
				CFile::modeRead | 
				CFile::shareDenyWrite) )
	{
		TRACE(_T("Load (file): Error opening file %s\n"),szFileName);
		return FALSE;
	};

	dwSize = file.GetLength();
	hGlobal = GlobalAlloc(GMEM_MOVEABLE | GMEM_NODISCARD,dwSize);
	if (!hGlobal)
	{
		TRACE(_T("Load (file): Error allocating memory\n"));
		return FALSE;
	};
	
	char *pData = reinterpret_cast<char*>(GlobalLock(hGlobal));
	if (!pData)
	{
		TRACE(_T("Load (file): Error locking memory\n"));
		GlobalFree(hGlobal);
		return FALSE;
	};

	TRY
	{
		file.Read(pData,dwSize);
	}
	CATCH(CFileException, e);                                          
	{
		TRACE(_T("Load (file): An exception occured while reading the file %s\n"),
			szFileName);
		GlobalFree(hGlobal);
		//e->Delete();   // DO NOT CALL THIS, CAN CAUSE CRASH.  majun, 7.31
		file.Close();
		return FALSE;
	}
	END_CATCH
	GlobalUnlock(hGlobal);
	file.Close();

	if(StrStrI(szFileName,_T(".png")))
	{
	bPngType=true;


	}

	BOOL bRetValue = Load(hGlobal,dwSize);
	GlobalFree(hGlobal);
	return bRetValue;
}

BOOL CPictureEx::Load(LPCTSTR szResourceName, LPCTSTR szResourceType)
{
	ASSERT(szResourceName);
	ASSERT(szResourceType);

	HRSRC hPicture = FindResource(AfxGetResourceHandle(),szResourceName,szResourceType);
	HGLOBAL hResData;
	if (!hPicture || !(hResData = LoadResource(AfxGetResourceHandle(),hPicture)))
	{
		TRACE(_T("Load (resource): Error loading resource %s\n"),szResourceName);
		return FALSE;
	};
	DWORD dwSize = SizeofResource(AfxGetResourceHandle(),hPicture);

	// hResData is not the real HGLOBAL (we can't lock it)
	// let's make it real

	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE | GMEM_NODISCARD,dwSize);
	if (!hGlobal)
	{
		TRACE("Load (resource): Error allocating memory\n");
		FreeResource(hResData);
		return FALSE;
	};
	
	char *pDest = reinterpret_cast<char *> (GlobalLock(hGlobal));
	char *pSrc = reinterpret_cast<char *> (LockResource(hResData));
	if (!pSrc || !pDest)
	{
		TRACE(_T("Load (resource): Error locking memory\n"));
		GlobalFree(hGlobal);
		FreeResource(hResData);
		return FALSE;
	};
	CopyMemory(pDest,pSrc,dwSize);
	FreeResource(hResData);
	GlobalUnlock(hGlobal);

	BOOL bRetValue = Load(hGlobal,dwSize);
	GlobalFree(hGlobal);
	return bRetValue;
}

void CPictureEx::ResetDataPointer()
{
	// skip header and logical screen descriptor
	m_nCurrOffset = 
		sizeof(TGIFHeader)+sizeof(TGIFLSDescriptor)+m_nGlobalCTSize;
}

BOOL CPictureEx::SkipNextGraphicBlock()
{
	if (!m_pRawData) return FALSE;

	// GIF header + LSDescriptor [+ GCT] [+ Control block] + Data

	enum GIFBlockTypes nBlock;

	nBlock = GetNextBlock();

	while ((nBlock != BLOCK_CONTROLEXT) &&
		   (nBlock != BLOCK_IMAGE) &&
		   (nBlock != BLOCK_PLAINTEXT) &&
		   (nBlock != BLOCK_UNKNOWN) &&
		   (nBlock != BLOCK_TRAILER) )
	{
		if (!SkipNextBlock()) return NULL;
		nBlock = GetNextBlock();
	};

	if ((nBlock == BLOCK_UNKNOWN) ||
		(nBlock == BLOCK_TRAILER))
		return FALSE;

	// it's either a control ext.block, an image or a plain text

	if (GetNextBlockLen() <= 0) return FALSE;

	if (nBlock == BLOCK_CONTROLEXT)
	{
		if (!SkipNextBlock()) return FALSE;
		nBlock = GetNextBlock();

		// skip everything until we meet an image block or a plain-text block
		while ((nBlock != BLOCK_IMAGE) &&
			   (nBlock != BLOCK_PLAINTEXT) &&
			   (nBlock != BLOCK_UNKNOWN) &&
			   (nBlock != BLOCK_TRAILER) )
		{
			if (!SkipNextBlock()) return NULL;
			nBlock = GetNextBlock();
		};

		if ((nBlock == BLOCK_UNKNOWN) ||
			(nBlock == BLOCK_TRAILER))
			return FALSE;
	};

	// skip the found data block (image or plain-text)
	if (!SkipNextBlock()) return FALSE;

	return TRUE;
}

UINT CPictureEx::GetSubBlocksLen(UINT nStartingOffset) const
{
	UINT nRet = 0;
	UINT nCurOffset = nStartingOffset;
	
	while (m_pRawData[nCurOffset] != 0)
	{
		nRet += m_pRawData[nCurOffset]+1;
		nCurOffset += m_pRawData[nCurOffset]+1;
	};

	return nRet+1;
}

enum CPictureEx::GIFBlockTypes CPictureEx::GetNextBlock() const
{
	switch(m_pRawData[m_nCurrOffset])
	{
	case 0x21:
	// extension block
		switch(m_pRawData[m_nCurrOffset+1])
		{
		case 0x01:
		// plain text extension
			return BLOCK_PLAINTEXT;
			break;

		case 0xF9:
		// graphic control extension
			return BLOCK_CONTROLEXT;
			break;

		case 0xFE:
		// comment extension
			return BLOCK_COMMEXT;
			break;

		case 0xFF:
		// application extension
			return BLOCK_APPEXT;
			break;
		};
		break;
	
	case 0x3B:
	// trailer
		return BLOCK_TRAILER;
		break;

	case 0x2C:
	// image data
		return BLOCK_IMAGE;
		break;
	};

	return BLOCK_UNKNOWN;
}

BOOL CPictureEx::SkipNextBlock()
{
	if (!m_pRawData) return FALSE;

	int nLen = GetNextBlockLen();
	if ((nLen <= 0) || ((m_nCurrOffset+nLen) > m_nDataSize))
		return FALSE;

	m_nCurrOffset += nLen;
	return TRUE;
}

int CPictureEx::GetNextBlockLen() const
{
	GIFBlockTypes nBlock = GetNextBlock();

	int nTmp;

	switch(nBlock)
	{
	case BLOCK_UNKNOWN:
		return -1;
		break;

	case BLOCK_TRAILER:
		return 1;
		break;

	case BLOCK_APPEXT:
		nTmp = GetSubBlocksLen(m_nCurrOffset+sizeof(TGIFAppExtension));
		if (nTmp > 0)
			return sizeof(TGIFAppExtension)+nTmp;
		break;

	case BLOCK_COMMEXT:
		nTmp = GetSubBlocksLen(m_nCurrOffset+sizeof(TGIFCommentExt));
		if (nTmp > 0)
			return sizeof(TGIFCommentExt)+nTmp;
		break;

	case BLOCK_CONTROLEXT:
		return sizeof(TGIFControlExt);
		break;

	case BLOCK_PLAINTEXT:
		nTmp = GetSubBlocksLen(m_nCurrOffset+sizeof(TGIFPlainTextExt));
		if (nTmp > 0)
			return sizeof(TGIFPlainTextExt)+nTmp;
		break;

	case BLOCK_IMAGE:
		TGIFImageDescriptor *pIDescr = 
			reinterpret_cast<TGIFImageDescriptor *> (&m_pRawData[m_nCurrOffset]);
		int nLCTSize = (int)
			(pIDescr->GetPackedValue(ID_PACKED_LOCALCT)*3*
			pow(float(2),pIDescr->GetPackedValue(ID_PACKED_LOCALCTSIZE)+1));

		int nTmp = GetSubBlocksLen(m_nCurrOffset+
			sizeof(TGIFImageDescriptor) + nLCTSize + 1);
		if (nTmp > 0)
			return sizeof(TGIFImageDescriptor) + nLCTSize + 1 + nTmp;
		break;
	};

	return 0;
}

UINT WINAPI CPictureEx::_ThreadAnimation(LPVOID pParam)
{
	ASSERT(pParam);
	CPictureEx *pPic = reinterpret_cast<CPictureEx *> (pParam);
	pPic->ThreadAnimation();

	// this thread has finished its work so we close the handle
	CloseHandle(pPic->m_hThread); 
	// and init the handle to zero (so that Stop() doesn't Wait on it)
	pPic->m_hThread = 0;
	return 0;
}

void CPictureEx::ThreadAnimation()
{
	int nTemp = 0;
	bLastGifOver=false;
	while (!m_bExitThread)
	{
		if (m_arrFrames[nTemp].m_pPicture)
		{
		///////////////////////////////////////////////////////
		// Before rendering a frame we should take care of what's 
		// behind that frame. TFrame::m_nDisposal will be our guide:
		//   0 - no disposal specified (do nothing)
		//   1 - do not dispose (again, do nothing)
		//   2 - restore to background color (m_clrBackground)
		//   3 - restore to previous

			//////// disposal method #3
			HDC hMemDC = NULL;
			HBITMAP hMemBM = NULL, hOldBM;

			if (m_arrFrames[nTemp].m_nDisposal == 3)
			{
				// prepare a memory DC and store the background in it
				hMemDC = CreateCompatibleDC(m_hMemDC);
				hMemBM = CreateCompatibleBitmap(m_hMemDC,
							m_arrFrames[nTemp].m_frameSize.cx,
							m_arrFrames[nTemp].m_frameSize.cy);
				
				if (hMemDC && hMemBM)
				{
					hOldBM = reinterpret_cast<HBITMAP> (SelectObject(hMemDC,hMemBM));
					BitBlt(hMemDC,0,0,
						m_arrFrames[nTemp].m_frameSize.cx,
						m_arrFrames[nTemp].m_frameSize.cy,
						m_hMemDC,
						m_arrFrames[nTemp].m_frameOffset.cx,
						m_arrFrames[nTemp].m_frameOffset.cy,
						SRCCOPY);
				};
			};
			///////////////////////

			long hmWidth;
			long hmHeight;
			m_arrFrames[nTemp].m_pPicture->get_Width(&hmWidth);
			m_arrFrames[nTemp].m_pPicture->get_Height(&hmHeight);

			if (m_arrFrames[nTemp].m_pPicture->Render(m_hMemDC, 
				m_arrFrames[nTemp].m_frameOffset.cx, 
				m_arrFrames[nTemp].m_frameOffset.cy, 
				m_arrFrames[nTemp].m_frameSize.cx, 
				m_arrFrames[nTemp].m_frameSize.cy, 
				0, hmHeight, hmWidth, -hmHeight, NULL) == S_OK)
			{
				Invalidate(FALSE);
			};
			
			if (m_bExitThread)
			{
				if (hMemDC)
				{
					// dispose local variables
					SelectObject(hMemDC,hOldBM);
					DeleteDC(hMemDC);
					DeleteObject(hMemBM);
				};
				break;
				bLastGifOver=true;
			};

			// if the delay time is too short (like in old GIFs), wait for 100ms
			if (m_arrFrames[nTemp].m_nDelay < 5) 
				WaitForSingleObject(m_hExitEvent, 100);
			else
				WaitForSingleObject(m_hExitEvent, 10*m_arrFrames[nTemp].m_nDelay);

			if (m_bExitThread)
			{
				if (hMemDC)
				{
					// dispose local variables
					SelectObject(hMemDC,hOldBM);
					DeleteDC(hMemDC);
					DeleteObject(hMemBM);
				};
					bLastGifOver=true;
				break;
			};

			// disposal method #2
			if (m_arrFrames[nTemp].m_nDisposal == 2)
			{
				HBRUSH hBrush = CreateSolidBrush(m_clrBackground);
				if (hBrush)
				{
					RECT rect = {
						m_arrFrames[nTemp].m_frameOffset.cx,
						m_arrFrames[nTemp].m_frameOffset.cy,
						m_arrFrames[nTemp].m_frameOffset.cx + m_arrFrames[nTemp].m_frameSize.cx,
						m_arrFrames[nTemp].m_frameOffset.cy + m_arrFrames[nTemp].m_frameSize.cy };
					FillRect(m_hMemDC,&rect,hBrush);
					DeleteObject(hBrush);
				};
			} 
			else
				if (hMemDC && (m_arrFrames[nTemp].m_nDisposal == 3) )
				{
					// put it back
					BitBlt(m_hMemDC,
						m_arrFrames[nTemp].m_frameOffset.cx,
						m_arrFrames[nTemp].m_frameOffset.cy,
						m_arrFrames[nTemp].m_frameSize.cx,
						m_arrFrames[nTemp].m_frameSize.cy,
						hMemDC,0,0, SRCCOPY);
					// dispose local variables
					SelectObject(hMemDC,hOldBM);
					DeleteDC(hMemDC);
					DeleteObject(hMemBM);
				};
		};
		nTemp++;
		if (nTemp == m_arrFrames.size())
		{
			nTemp = 0; 
		// init the screen for the first frame,
			HBRUSH hBrush = CreateSolidBrush(m_clrBackground);
			if (hBrush)
			{
				RECT rect = {0,0,m_PictureSize.cx,m_PictureSize.cy};
				FillRect(m_hMemDC,&rect,hBrush);
				DeleteObject(hBrush);
			};
				bLastGifOver=true;
		};
	};
}

void CPictureEx::Stop()
{
	m_bExitThread = TRUE;
	SetEvent(m_hExitEvent);
	if (m_hThread)
	{
		// we'll wait for 5 seconds then continue execution
		WaitForSingleObject(m_hThread,5000);
		CloseHandle(m_hThread);
		m_hThread = NULL;
	}

	// make it possible to Draw() again
	ResetEvent(m_hExitEvent);
	m_bExitThread = FALSE;
}

HGLOBAL CPictureEx::GetNextGraphicBlock(UINT *pBlockLen, 
	UINT *pDelay, SIZE *pBlockSize, SIZE *pBlockOffset, 
	UINT *pDisposal)
{
	if (!m_pRawData) return NULL;

	// GIF header + LSDescriptor [+ GCT] [+ Control block] + Data

	*pDisposal = 0;
	enum GIFBlockTypes nBlock;
	nBlock = GetNextBlock();

	while (
		(nBlock != BLOCK_CONTROLEXT) &&
		(nBlock != BLOCK_IMAGE) &&
		(nBlock != BLOCK_PLAINTEXT) &&
		(nBlock != BLOCK_UNKNOWN) &&
		(nBlock != BLOCK_TRAILER)
		)
	{
		if (!SkipNextBlock()) return NULL;
		nBlock = GetNextBlock();
	};

	if ((nBlock == BLOCK_UNKNOWN) ||
		(nBlock == BLOCK_TRAILER))
		return NULL;

	// it's either a control ext.block, an image or a plain text

	int nStart = m_nCurrOffset;
	int nBlockLen = GetNextBlockLen();

	if (nBlockLen <= 0) return NULL;

	if (nBlock == BLOCK_CONTROLEXT)
	{
		// get the following data
		TGIFControlExt *pControl = 
			reinterpret_cast<TGIFControlExt *> (&m_pRawData[m_nCurrOffset]);
		// store delay time
		*pDelay = pControl->m_wDelayTime;
		// store disposal method
		*pDisposal = pControl->GetPackedValue(GCX_PACKED_DISPOSAL);

		if (!SkipNextBlock()) return NULL;
		nBlock = GetNextBlock();
		
		// skip everything until we find data to display 
		// (image block or plain-text block)
		
		while (
			(nBlock != BLOCK_IMAGE) &&
			(nBlock != BLOCK_PLAINTEXT) &&
			(nBlock != BLOCK_UNKNOWN) &&
			(nBlock != BLOCK_TRAILER)
			)
		{
			if (!SkipNextBlock()) return NULL;
			nBlock = GetNextBlock();
			nBlockLen += GetNextBlockLen();
		};

		if ((nBlock == BLOCK_UNKNOWN) || (nBlock == BLOCK_TRAILER))
			return NULL;
		nBlockLen += GetNextBlockLen();
	}
	else
		*pDelay = -1; // to indicate that there was no delay value

	if (nBlock == BLOCK_IMAGE)
	{
		// store size and offsets
		TGIFImageDescriptor *pImage = 
			reinterpret_cast<TGIFImageDescriptor *> (&m_pRawData[m_nCurrOffset]);
		pBlockSize->cx = pImage->m_wWidth;
		pBlockSize->cy = pImage->m_wHeight;
		pBlockOffset->cx = pImage->m_wLeftPos;
		pBlockOffset->cy = pImage->m_wTopPos;
	};

	if (!SkipNextBlock()) return NULL;

	HGLOBAL hGlobal = GlobalAlloc(GMEM_FIXED,
		sizeof(TGIFHeader) +
		sizeof(TGIFLSDescriptor) +
		m_nGlobalCTSize +
		nBlockLen + 
		1);  // for the trailer

	if (!hGlobal) return NULL;

	int nOffset = 0; 

	// GMEM_FIXED means we get a pointer
	unsigned char *pGlobal = reinterpret_cast<unsigned char *> (hGlobal);

	CopyMemory(pGlobal,m_pRawData, 
		sizeof(TGIFHeader)+sizeof(TGIFLSDescriptor)+m_nGlobalCTSize);
	nOffset += sizeof(TGIFHeader)+sizeof(TGIFLSDescriptor)+m_nGlobalCTSize;

	CopyMemory(pGlobal + nOffset,&m_pRawData[nStart], nBlockLen);
	nOffset += nBlockLen;

	pGlobal[nOffset] = 0x3B; // trailer
	nOffset++;

	*pBlockLen = nOffset;

	return hGlobal;
}

BOOL CPictureEx::IsGIF() const
{
	return m_bIsGIF;
}

BOOL CPictureEx::IsAnimatedGIF() const
{
	return (m_bIsGIF && (m_arrFrames.size() > 1));
}

int CPictureEx::GetFrameCount() const
{
	if (!IsAnimatedGIF())
		return 0;

	return m_arrFrames.size();
}

COLORREF CPictureEx::GetBkColor() const
{
	return m_clrBackground;
}

extern HDC Graph_SwitchWP_ReturnDC();
#define WPSTYLE_CENTER      0
#define WPSTYLE_TILE        1
#define WPSTYLE_STRETCH     2
void PaintDCBy(CDC& myDC,int xsize,int ysize,int dcx,int dcy,HDC m_hMemDC,int scx,int scy,int srcsizex,int srcsizey,int pmode,int bwpstyle)
{

	if(bwpstyle==WPSTYLE_STRETCH)//||(srcsizex+srcsizey)>(xsize+ysize))
	{
		::SetStretchBltMode(myDC.m_hDC,HALFTONE);
		::StretchBlt(myDC.m_hDC,dcx,dcy,xsize,ysize,m_hMemDC,scx,scy,srcsizex,srcsizey,pmode);
	}
	else if(bwpstyle==WPSTYLE_TILE)
	{
	CRect rect(0,0,xsize,ysize);
	int nStartLeft,nStartTop,nDispWidth,nDispHeight,nWidth,nHeight;
	nWidth=srcsizex;
	nHeight=srcsizey;
	nStartLeft = rect.left;
            nStartTop = rect.top;
            nDispWidth = 0;
            nDispHeight = 0;
            
            do 
            {
                nStartLeft = rect.left;
                nDispWidth = srcsizex;
                do
                {
                   ::BitBlt(myDC.m_hDC,nStartLeft,nStartTop,nWidth, nHeight,m_hMemDC, 0, 0, pmode);

                    nStartLeft += srcsizex;
                    if (rect.right - nStartLeft > srcsizex ){
                        nDispWidth = srcsizex;
                    }
                    else{
                        nDispWidth = rect.right - nStartLeft;
                    }
                } while(nStartLeft < rect.right);

                nStartTop += srcsizey;
                
                if (rect.bottom - nStartTop >srcsizey ){
                    nDispHeight = srcsizey;
                }
                else{
                    nDispHeight = rect.bottom - nStartTop;
                }

            } while(nStartTop < rect.bottom);
	}
	else if(bwpstyle==WPSTYLE_CENTER)
	{
		
	HBRUSH hBrush = CreateSolidBrush(RGB(0,0,0));
			if (hBrush)
			{
				RECT rect = {0,0,xsize,ysize};
				FillRect(myDC.m_hDC,&rect,hBrush);
					DeleteObject(hBrush);
			}

			int nStartLeft,nStartTop,nDispWidth,nDispHeight,nWidth,nHeight;
	nWidth=srcsizex;
	nHeight=srcsizey;
	nStartLeft=(xsize-srcsizex)/2;
	nStartTop=(ysize-srcsizey)/2;
	 ::BitBlt(myDC.m_hDC,nStartLeft,nStartTop,nWidth, nHeight,m_hMemDC, 0, 0, pmode);

	}
	
	//::SetBkMode(m_hDC,TRANSPARENT);
//::TextOut(m_hDC,100,100,_T("dakdd"),5);

}
extern void Graph_UpdateScreen(HDC des_hdc, int Transparent=255);
extern BOOL alreadyinitgraph;
extern BOOL bShowBubbles;
static int neffectcount=0;
static int numberi=0;
void CPictureEx::CrossShow(CPaintDC& dc)
{
	

int j=1;


//for(i=1;i<screen_ysize/2;i++)
{
	for(j=numberi;j>=1;j--)
	{
		
	dc.BitBlt(0,0+(j-1)*2,screen_xsize,1,&m_screenmemdc,0,(screen_ysize/2-numberi)*2+(j-1)*2,SRCCOPY);
dc.BitBlt(0,0+screen_ysize-(2*j-1),screen_xsize,1,&m_screenmemdc,0,(numberi-j)*2+1,SRCCOPY);


	}
	//Sleep(5);

}

if (numberi<screen_ysize/2)
	{			
	
			Invalidate(FALSE);				 //   do it again!
	numberi++;
	}
	else
	{
numberi=0;	
		OverOnceSpecialEffect(dc);
	}

	
}
void CPictureEx::CenterCrossShow(CPaintDC& dc)
{
	
//for(j=0;j<=screen_xsize/2;j++)
			{		
				dc.BitBlt(screen_xsize/2+numberi,0,1,screen_ysize,&m_screenmemdc,
					screen_xsize/2+numberi,0,SRCCOPY); 
				dc.BitBlt(screen_xsize/2-numberi,0,1,screen_ysize,&m_screenmemdc,
					screen_xsize/2-numberi,0, SRCCOPY); 
				
				Sleep(1);
			}


	if (numberi<=screen_xsize/2)
	{			
	
			Invalidate(FALSE);				 //   do it again!
	numberi++;
	}
	else
	{
numberi=0;	
		OverOnceSpecialEffect(dc);
	}

}
void CPictureEx::HorCrossShow(CPaintDC& dc)
{
	
		//for(int i=0;i<=screen_xsize/20;i++)
				for(int j=0;j<=20;j++)
				{
					dc.BitBlt(j*screen_xsize/20, 0, numberi, screen_ysize,&m_screenmemdc,j*screen_xsize/20,  0, SRCCOPY);
					//Sleep(1);
				}
	
	
	if (numberi<=screen_xsize/20)
	{			
	
			Invalidate(FALSE);				 //   do it again!
	numberi++;
	}
	else
	{
numberi=0;	
		OverOnceSpecialEffect(dc);
	}

}
void CPictureEx::OverOnceSpecialEffect(CPaintDC& dc)
{
		dc.BitBlt(0,0,screen_xsize,screen_ysize,&m_screenmemdc,0,0,SRCCOPY);
	m_bShouldStart=false;
	neffectcount++;
	m_bStartingeffect=false;
}
void CPictureEx::FadeOut(CPaintDC& dc)
{

CreateTempBitmap(&dc);
		ASSERT(m_dcBlend.m_hDC);
		// render current (NEW) image into temporary dc.
//	PaintDCBy(m_dcBlend,screen_xsize,screen_ysize,0,0,m_hMemDC,0,0,screen_xsize,screen_ysize,SRCCOPY,m_mywpstyle);
		m_dcBlend.BitBlt(0, 0, screen_xsize, screen_ysize, &m_screenmemdc, 0, 0, SRCCOPY);

		BLENDFUNCTION bf;
		memset(&bf,0,sizeof(bf));
		bf.BlendOp = AC_SRC_OVER;
		int BLEND_DURATION=min(switchrate*1000/2,3000);
		int alpha=255;
		

		{
		alpha= ((clock() - m_iStartTime) * 255) / BLEND_DURATION;
		alpha = max(255-alpha,0);			 // alpha = 1-alpha (backwards)
		
		bf.SourceConstantAlpha = alpha;
		TRACE(_T(" [alpha = %d]\n"), alpha);

		// blend old image on top of new, in temporary DC
		m_dcBlend.AlphaBlend(0,0,screen_xsize,screen_ysize,
			&m_dcOld,
			0,0,screen_xsize,screen_ysize,
			bf);

	dc.BitBlt(0, 0, screen_xsize, screen_ysize, &m_dcBlend, 0, 0, SRCCOPY);
	
		}
	if (alpha>0)
	{							 // not done yet?
			Invalidate(FALSE);				 //   do it again!
		}
	else
	{
			DeleteDocImage();			// delete old doc image
	m_iStartTime = 0;	
		OverOnceSpecialEffect(dc);
	}

	
}

void CPictureEx::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	BOOL normalpicflag=false;
	
	int srcsizex,srcsizey;

	if(IsGIF())
	{
	srcsizex=m_PictureSize.cx;
	srcsizey=m_PictureSize.cy;
	}
	else if(m_image)
	{
		normalpicflag=true;
	srcsizex=m_image->GetWidth();
	srcsizey=m_image->GetHeight();
	}
else if(blankimage)
	{
	srcsizex=screen_xsize;
	srcsizey=screen_ysize;
	}
	if(alreadyinitgraph&&bShowBubbles)
	{
	HDC temphdc=NULL;
	CDC   tempdc; 
tempdc.Attach(temphdc); 

PaintDCBy(tempdc,screen_xsize,screen_ysize,0,0,m_hMemDC,0,0,srcsizex,srcsizey,SRCCOPY,m_mywpstyle);

tempdc.Detach();
}
else if(!normalpicflag)
	PaintDCBy(dc,screen_xsize,screen_ysize,0,0,m_hMemDC,0,0,srcsizex,srcsizey,SRCCOPY,m_mywpstyle);
else
{

		if(m_bShouldStart==0||bShowpwding||bNoSpecialEffect)
	{
		if(bShowpwding)
		{
		numberi=0;
		m_bStartingeffect=false;
		}
	PaintDCBy(dc,screen_xsize,screen_ysize,0,0,m_hMemDC,0,0,srcsizex,srcsizey,SRCCOPY,m_mywpstyle);

	}
	else
	{
		int randnum=4;
		
			if(m_bStartingeffect==false)
		{
			randnum=3+rand()%5;
		CreateScreenBitmap(&dc);
			PaintDCBy(m_screenmemdc,screen_xsize,screen_ysize,0,0,m_hMemDC,0,0,srcsizex,srcsizey,SRCCOPY,m_mywpstyle);
		m_bStartingeffect=true;
		}
		
		
		//CrossShow(dc);

		if(neffectcount==0||neffectcount%randnum==3)
		FadeOut(dc);
		else
		{
			int tempint=neffectcount%4;
			if(tempint==1)
				CenterCrossShow(dc);
			else if(tempint==2)
HorCrossShow(dc);
			else
CrossShow(dc);
	}
		
	}

}

}
BOOL CPictureEx::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//return true;
	return CStatic::OnEraseBkgnd(pDC);
}

void CPictureEx::CreateTempBitmap(CDC* pDC)
{
	static int onceflag=0;
	if(onceflag==0)
	{
	TRACE(_T("CPictureView::CreateTempBitmap\n"));
	DeleteTempBitmap();
	m_dcBlend.CreateCompatibleDC(pDC);
	m_bmBlend.CreateCompatibleBitmap(pDC, screen_xsize, screen_ysize);
	m_dcBlend.SelectObject(&m_bmBlend);
	onceflag=1;
	}
}
void CPictureEx::CreateScreenBitmap(CDC* pDC)
{
	static int onceflag=0;
	if(onceflag==0)
	{
	TRACE(_T("CPictureView::CreatescreenBitmap\n"));
	DeleteScreenBitmap();
	m_screenmemdc.CreateCompatibleDC(pDC);
	m_screenbitmap.CreateCompatibleBitmap(pDC, screen_xsize, screen_ysize);
	m_screenmemdc.SelectObject(&m_screenbitmap);
	onceflag=1;
	}
}
void CPictureEx::DeleteScreenBitmap()
{
	TRACE(_T("CPictureView::DeleteScreenBitmap\n"));
	if (m_screenmemdc.m_hDC) {
		TRACE(_T(" [deleting]\n"));
		m_screenmemdc.SelectObject((HBITMAP)NULL);
		m_screenmemdc.DeleteDC();
		m_screenbitmap.DeleteObject();
	}
}
void CPictureEx::DeleteTempBitmap()
{
	TRACE(_T("CPictureView::DeleteTempBitmap\n"));
	if (m_dcBlend.m_hDC) {
		TRACE(_T(" [deleting]\n"));
		m_dcBlend.SelectObject((HBITMAP)NULL);
		m_dcBlend.DeleteDC();
		m_bmBlend.DeleteObject();
	}
}
void CPictureEx::SlidePaintDCBy(CDC& myDC,int xsize,int ysize,int dcx,int dcy,HDC m_hMemDC,int scx,int scy,int srcsizex,int srcsizey,int pmode,int bwpstyle)
{
	
	PaintDCBy(myDC,screen_xsize,screen_ysize,0,0,m_hMemDC,0,0,srcsizex,srcsizey,SRCCOPY,m_mywpstyle);


		

}
void CPictureEx::DeleteDocImage()
{
		if (m_dcOld.m_hDC!=NULL)
		{
		m_dcOld.SelectObject((CBitmap*)NULL); // de-select bitmap from DC
		m_bmOld.DeleteObject();					  // delete bitmap
		m_dcOld.DeleteDC();						  // delete DC
	}
}
void CPictureEx::SaveDocImage()
{
	

	DeleteDocImage();							 // delete old doc image

	
	if(!ExitFlag&&GetSafeHwnd())
	{
	CClientDC dc(this);						 // my client DC
	m_dcOld.CreateCompatibleDC(&dc);		 // create memory DC
	m_bmOld.CreateCompatibleBitmap(&dc, screen_xsize, screen_ysize); // create bitmap
	m_dcOld.SelectObject(&m_bmOld);							// select it into DC
	//::BitBlt(m_dcOld.m_hDC,0, 0, screen_xsize, screen_ysize, m_hMemDC, 0, 0, SRCCOPY);									// draw picture on bitmap
														// and save size
	PaintDCBy(m_dcOld,screen_xsize,screen_ysize,0,0,m_hMemDC,0,0,m_szOld.cx,m_szOld.cy,SRCCOPY,m_mywpstyle);
	}
}

BOOL CPictureEx::PrepareDC(int nWidth, int nHeight)
{
	//::SetFocus(GetSafeHwnd());
	::SetWindowPos(GetSafeHwnd(),HWND_TOPMOST,0,0,nWidth,nHeight,SWP_NOMOVE|SWP_NOZORDER);
	m_szOld.cx=nWidth;
	m_szOld.cy=nHeight;
	HDC hWinDC = ::GetDC(m_hWnd);
	if (!hWinDC) return FALSE;
	
	m_hMemDC = CreateCompatibleDC(hWinDC);
	if (!m_hMemDC) 
	{
		::ReleaseDC(m_hWnd,hWinDC);
		return FALSE;
	};

	m_hBitmap  = CreateCompatibleBitmap(hWinDC,nWidth,nHeight);
	if (!m_hBitmap) 
	{
		::ReleaseDC(m_hWnd,hWinDC);
		::DeleteDC(m_hMemDC);
		return FALSE;
	};

	m_hOldBitmap = reinterpret_cast<HBITMAP> 
						(SelectObject(m_hMemDC,m_hBitmap));
	
	// fill the background
	m_clrBackground =GetSysColor(COLOR_3DFACE);
	RECT rect = {0,0,nWidth,nHeight};
	FillRect(m_hMemDC,&rect,(HBRUSH)(COLOR_WINDOW));

	m_bIsInitialized = TRUE;
	return TRUE;
}

void CPictureEx::OnDestroy() 
{
	Stop();	
	CStatic::OnDestroy();
}

void CPictureEx::SetBkColor(COLORREF clr)
{
	if (!m_bIsInitialized) return;

	m_clrBackground = clr;

	HBRUSH hBrush = CreateSolidBrush(clr);
	if (hBrush)
	{
		int ccx=m_PictureSize.cx;
		int ccy=m_PictureSize.cy;
		if(blankimage)
		{
			ccx=screen_xsize;
		ccy=screen_ysize;
		}
		RECT rect = {0,0,ccx,ccy};
		FillRect(m_hMemDC,&rect,hBrush);
		DeleteObject(hBrush);
	};
}

#ifdef GIF_TRACING
void CPictureEx::WriteDataOnDisk(CString szFileName, HGLOBAL hData, DWORD dwSize)
{
	CFile file;

	if (!file.Open(szFileName,
			CFile::modeCreate |
			CFile::modeWrite |
			CFile::shareDenyNone))
	{
		TRACE(_T("WriteData: Error creating file %s\n"),szFileName);
		return;
	};

	char *pData = reinterpret_cast<char *> (GlobalLock(hData));
	if (!pData)
	{
		TRACE(_T("WriteData: Error locking memory\n"));
		return;
	};

	TRY
	{
		file.Write(pData,dwSize);
	}
	CATCH(CFileException, e);                                          
	{
		TRACE(_T("WriteData: An exception occured while writing to the file %s\n"),
			szFileName);
		//e->Delete();   // DO NOT CALL THIS, CAN CAUSE CRASH.  majun, 7.31
		GlobalUnlock(hData);
		file.Close();
		return;
	}
	END_CATCH
	
	GlobalUnlock(hData);
	file.Close();
}

void CPictureEx::EnumGIFBlocks()
{
	enum GIFBlockTypes nBlock;

	ResetDataPointer();
	while(m_nCurrOffset < m_nDataSize)
	{
		nBlock = GetNextBlock();
		switch(nBlock)
		{
		case BLOCK_UNKNOWN:
			TRACE(_T("- Unknown block\n"));
			return;
			break;

		case BLOCK_TRAILER:
			TRACE(_T("- Trailer block\n"));
			break;

		case BLOCK_APPEXT:
			TRACE(_T("- Application extension block\n"));
			break;

		case BLOCK_COMMEXT:
			TRACE(_T("- Comment extension block\n"));
			break;

		case BLOCK_CONTROLEXT:
			{
			TGIFControlExt *pControl = 
				reinterpret_cast<TGIFControlExt *> (&m_pRawData[m_nCurrOffset]);
			TRACE(_T("- Graphic control extension block (delay %d, disposal %d)\n"),
					pControl->m_wDelayTime, pControl->GetPackedValue(GCX_PACKED_DISPOSAL));
			};
			break;

		case BLOCK_PLAINTEXT:
			TRACE(_T("- Plain text extension block\n"));
			break;

		case BLOCK_IMAGE:
			TGIFImageDescriptor *pIDescr = 
				reinterpret_cast<TGIFImageDescriptor *> (&m_pRawData[m_nCurrOffset]);
			TRACE(_T("- Image data block (%dx%d  %d,%d)\n"),
					pIDescr->m_wWidth,
					pIDescr->m_wHeight,
					pIDescr->m_wLeftPos,
					pIDescr->m_wTopPos);
			break;
		};

		SkipNextBlock();	
	};

	TRACE(_T("\n"));
}
#endif // GIF_TRACING
