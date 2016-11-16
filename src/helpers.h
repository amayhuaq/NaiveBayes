#include <sstream>
#include <string>

namespace helpers {

std::string to_string(int num) {
	std::ostringstream ostr; //output string stream
	ostr << num; //use the string stream just like cout,
	return ostr.str();
}

}
