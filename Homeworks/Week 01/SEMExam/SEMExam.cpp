#include <algorithm>
#include <iostream>

int main()
{
	unsigned n = 0;
	std::cin >> n;
	for (unsigned i = 0; i < n; i++)
	{
		int histogram[26]{};
		unsigned len = 0;
		unsigned min = 0;
		std::string str;
		std::cin >> len >> min >> str;
		for (unsigned j = 0; j < len; j++)
		{
			if (str[j] >= 'A' && str[j] <= 'Z')
				histogram[str[j] - 'A']++;
		}
		std::string res;
		for (unsigned k = 0; k < 26; k++)
		{
			if (histogram[k] >= min)
				res.push_back(k + 'A');
		}
		std::sort(res.begin(), res.end());
		std::cout << res << std::endl;
	}
}
