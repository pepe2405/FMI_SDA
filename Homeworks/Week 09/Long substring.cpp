#include <iostream>

int main()
{
	std::string first, second;
	std::cin >> first >> second;

	size_t max = 0, curr = 0;

	for (size_t i = 0; i < first.size(); i++)
	{
		curr = 0;
		size_t row = i;

		for (size_t j = 0; j < second.size() && row < first.size(); j++, row++)
		{
			if (first[row] != second[j])
				curr = 0;
			else
			{
				curr++;
				max = std::max(max, curr);
			}
		}
	}

	std::cout << max;
}
