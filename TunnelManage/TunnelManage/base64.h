#include "stdafx.h"
#include <string>
#ifndef _BASE64_H
#define _BASE64_H
std::string base64_encode(unsigned char const*, unsigned int len);
std::string base64_decode(std::string const& s);
#endif
