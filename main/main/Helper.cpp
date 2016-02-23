#include "Helper.h"

bool Helper::in_vector(vector <string> haystack, string needle){
	for (size_t i = 0; i < haystack.size(); i++) if (haystack[i] == needle) return true;
	return false;
}