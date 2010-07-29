/* ****************************************************************************

 * eID Middleware Project.
 * Copyright (C) 2008-2010 FedICT.
 *
 * This is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version
 * 3.0 as published by the Free Software Foundation.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this software; if not, see
 * http://www.gnu.org/licenses/.

**************************************************************************** */
#ifndef __MW_UTIL_H__
#define __MW_UTIL_H__

#include "config.h"
#include <string>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdarg.h>

#ifndef __APPLE__
#include "error.h"
#endif

#ifndef HAVE_ERRNO_T
typedef int errno_t;
#endif

std::wstring wstring_From_string(std::string const& in);
std::string string_From_wstring(std::wstring const& in);
void wstring_TrimR(std::wstring *in);

void vector_From_bytes(std::vector<unsigned char> *out, const unsigned char *in, size_t len);

void TokenizeS (const std::string& str, std::vector<std::string>& tokens, const std::string& delimiters, unsigned long maxToken=0);
void TokenizeW (const std::wstring& str, std::vector<std::wstring>& tokens, const std::wstring& delimiters, unsigned long maxToken=0);

void wstring_to_lower(std::wstring& str);
wchar_t clean_char(wchar_t in);
void wstring_clean(std::wstring& str);

using namespace std;

template <class T>
inline wstring towstring (const T& t)
{
	wstringstream ss;
	ss << t;
	return ss.str();
}

template <class T>
inline string tostring (const T& t)
{
	stringstream ss;
	ss << t;
	return ss.str();
}

// template for joining elements into textual lists (but we should use boost instead)
template <typename rT, typename cT>
inline rT join (const cT& list, const rT& sep)
{
	rT result;
	typename cT::const_iterator i=list.begin();
	if(i!=list.end())
		result.append(*i++);
	for(;i!=list.end();i++)
	{
		result.append(sep);
		result.append(*i);
	}
	return result;
}

#ifndef HAVE_VASPRINTF
int vasprintf(char **strp, const char *fmt, va_list ap);
#endif

int _wfopen_s(FILE** pFile, const wchar_t *filename, const wchar_t *mode);
int fwprintf_s(FILE *stream, const wchar_t *format, ...);
int strcpy_s(char *dest, size_t len, const char *src);
int wcscpy_s(wchar_t *dest, size_t len, const wchar_t *src);
int wcscpy_s(wchar_t *dest, const wchar_t *src);
int wcscat_s(wchar_t* dst, size_t elem, const wchar_t* src);

errno_t _localtime_s(struct tm* _tm, const time_t *time);
int 	_swprintf_s(wchar_t *buffer, size_t sizeOfBuffer, const wchar_t *format, ...);
int 	_vfwprintf_s(FILE *stream, const wchar_t *format, va_list argptr);
int 	_vfprintf_s(FILE *stream, const char* format, va_list argptr); 
int 	dupenv_s(char **buffer, size_t *numberOfElements, const char *varname);

#endif //__MW_UTIL_H__