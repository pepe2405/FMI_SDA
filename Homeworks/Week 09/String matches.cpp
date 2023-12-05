#include <iostream>

int main()
{
	std::string first, second;
	std::cin >> first >> second;

	unsigned count = 0, i = 0, j = 0;

	while(i < second.size())
	{
		if (first[j] != second[i])
			i++;

		else
		{
			while (first[j] == second[i] && j < first.size())
			{
				i++;
				j++;
			}

			if (j == first.size())
				count++;
		}

		j = 0;
	}

	std::cout << count;
}
