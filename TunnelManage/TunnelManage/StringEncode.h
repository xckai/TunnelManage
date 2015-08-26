
#ifndef _STRINGENCODE
#define  _STRINGENCODE
#include <iostream>
#include <string>
using namespace std;
class StringEncode{
public:
	static string  base64_encode(const string &s);
	static string  base64_decode(std::string const& s);

};

#endif // !_STRINGENCODE

