#include <iostream>
#include <string>

bool IsKPeriodic(std::string &str, size_t k)
{
	size_t strLen = str.length(); // get the length of the incoming string
	std::string subStr = str.substr(0, k); //get a first substring of length k

	// if the strLen is not a multiple of k or equal to 0
	if (strLen % k > 0 || strLen == 0)
		return false;

	// loop through all following substring of length k and compare it with the first substring
	for (size_t i = k; i < strLen; (i += k)) {
		if (subStr != str.substr(i, k))
			return false;
	}
	return true;
}

int main()
{
	std::string m_str = "abcabcabcabc";
	size_t K = 3;
	bool res = IsKPeriodic(m_str, K); // true
	std::cout << "The string '" + m_str + "' is " << (res ? "": "NOT ")<< "a multiple of " << K << std::endl;

	m_str = "abcabcabcabc";
	K = 5;
	res = IsKPeriodic(m_str, K); // false
	std::cout << "The string '" + m_str + "' is " << (res ? "" : "NOT ") << "a multiple of " << K << std::endl;

	m_str = "abcabcabcabc";
	K = 15;
	res = IsKPeriodic(m_str, K); // false
	std::cout << "The string '" + m_str + "' is " << (res ? "" : "NOT ") << "a multiple of " << K << std::endl;

	return 0;
}