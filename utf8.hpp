/*
	Copyright (C) 2004-2005 Cory Nelson

	This software is provided 'as-is', without any express or implied
	warranty.  In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose,
	including commercial applications, and to alter it and redistribute it
	freely, subject to the following restrictions:

	1. The origin of this software must not be misrepresented; you must not
		claim that you wrote the original software. If you use this software
		in a product, an acknowledgment in the product documentation would be
		appreciated but is not required.
	2. Altered source versions must be plainly marked as such, and must not be
		misrepresented as being the original software.
	3. This notice may not be removed or altered from any source distribution.
*/

// namespaces added by Arvid Norberg

#ifndef __UTF8_H__
#define __UTF8_H__

#include <string>
#include <iterator>
#include <stdexcept>
#include <cwchar>

namespace libtorrent {
namespace detail {

template<typename InputIterator>
wchar_t decode_utf8_mb(InputIterator &iter, InputIterator last)
{
	if (iter == last) throw std::runtime_error("incomplete UTF-8 sequence");
	if (((*iter) & 0xc0) != 0x80) throw std::runtime_error("invalid UTF-8 sequence");

	return (wchar_t)((*iter++) & 0x3f);
}

template<typename InputIterator>
wchar_t decode_utf8(InputIterator &iter, InputIterator last)
{
	wchar_t ret;

	if (((*iter) & 0x80) == 0) // one byte
	{
		ret = *iter++;
	}
	else if (((*iter) & 0xe0) == 0xc0) // two bytes
	{
		wchar_t byte1 = (*iter++) & 0x1f;
		wchar_t byte2 = decode_utf8_mb(iter, last);
		ret = (byte1 << 6) | byte2;
	}
	else if (((*iter) & 0xf0) == 0xe0) // three bytes
	{
		wchar_t byte1 = (*iter++) & 0x0f;
		wchar_t byte2 = decode_utf8_mb(iter, last);
		wchar_t byte3 = decode_utf8_mb(iter, last);
		ret = (byte1 << 12) | (byte2 << 6) | byte3;
	}
	// TODO: support surrogate pairs
	else
	{
		throw std::runtime_error("UTF-8 not convertable to UTF-16");
	}
	return ret;
}

template<typename InputIterator, typename OutputIterator>
OutputIterator utf8_wchar(InputIterator first, InputIterator last, OutputIterator dest)
{
	char buf[32];
	int i=0;
	try
	{
	for(; first!=last; ++dest)
	{

		*dest = decode_utf8(first, last);
	}
	
	return dest;
	}
	catch(...)
	{
	return dest;
	}
}

template<typename InputIterator, typename OutputIterator>
void encode_wchar(InputIterator iter, OutputIterator &dest)
{
	if(*iter <= 0x007F)
	{
		*dest=(char)*iter;
		++dest;
	}
	else if(*iter <= 0x07FF)
	{
		*dest = (char)(
			0xC0 |
			((*iter & 0x07C0) >> 6)
		);
		++dest;

		*dest = (char)(
			0x80 |
			(*iter & 0x003F)
		);
		++dest;
	}
	else if(*iter <= 0xFFFF)
	{
		*dest = (char)(
			0xE0 |
			((*iter & 0xF000) >> 12)
		);
		++dest;

		*dest = (char)(
			0x80 |
			((*iter & 0x0FC0) >> 6)
		);
		++dest;

		*dest = (char)(
			0x80 |
			(*iter & 0x003F)
		);
		++dest;
	}
}

template<typename InputIterator, typename OutputIterator>
OutputIterator wchar_utf8(InputIterator first, InputIterator last, OutputIterator dest)
{
	for(; first!=last; ++first)
		encode_wchar(first, dest);
	return dest;
}

}

inline void utf8_wchar(const std::string &utf8, std::wstring &wide)
{
	wide.clear();
	detail::utf8_wchar(utf8.begin(), utf8.end(), std::back_inserter(wide));
}



inline void wchar_mbchar(const std::wstring &wcharbuf, std::string &mbcharbuf)
{

	mbcharbuf.clear();

  
  setlocale(LC_CTYPE, "");  //

  		
  
  int dd=wcstombs(NULL, wcharbuf.c_str(), wcharbuf.size());
  
 
  if(dd<0)
  {
  return;
  }
  char *mbcs = new char[dd+1];
  dd=wcstombs(mbcs, wcharbuf.c_str(), dd);
  mbcs[dd]=0;
  mbcharbuf=mbcs;


  delete[] mbcs;
  

}
inline void mbchar_wchar(const std::string &mbcharbuf,std::wstring &wcharbuf )
{

	wcharbuf.clear();
	std::wstring wide;
	
	
  setlocale(LC_CTYPE, "");  //
  
  int dd=mbstowcs(NULL, mbcharbuf.c_str(), mbcharbuf.size());
  if(dd<0)
  {
  return;
  }
	wchar_t *wbcs = new wchar_t[dd+1];
  
  dd=mbstowcs(wbcs, mbcharbuf.c_str(), dd);
  wbcs[dd]=0;
  wcharbuf=wbcs;

  delete[] wbcs;
  

}
inline std::wstring utf8_wchar(const std::string &str)
{
	std::wstring ret;
	utf8_wchar(str, ret);
	return ret;
}

inline void wchar_utf8(const std::wstring &wide, std::string &utf8)
{
	utf8.clear();
	detail::wchar_utf8(wide.begin(), wide.end(), std::back_inserter(utf8));
}

inline void utf8_mbchar(const std::string &utf8, std::string &mbchar)
{

	mbchar.clear();
	std::wstring wide;
	utf8_wchar(utf8, wide);
		wchar_mbchar(wide,mbchar);
  

}


inline void mbchar_utf8(const std::string &mbchar, std::string &utf8)
{

	utf8.clear();
	std::wstring wide;
mbchar_wchar(mbchar,wide);
wchar_utf8(wide,utf8);
}
inline std::string wchar_utf8(const std::wstring &str)
{
	std::string ret;
	wchar_utf8(str, ret);
	return ret;
}

}

#endif
