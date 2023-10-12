#include <iostream>

int main() 
{
	std::string str;
	unsigned n = 0;
	char ch;
	std::cin >> str >> n >> ch;
	const unsigned len = str.length();
	if (len > 100 || n > 1000000000)
		return -1;
	unsigned count = 0;
	for (unsigned i = 0; i < len; i++)
	{
		if (str[i] == ch)
			count++;
	}
	count *= (n / len);
	for (unsigned i = 0; i < (n % len); i++)
	{
		if (str[i] == ch)
			count++;
	}
	std::cout << count;
}