#include <algorithm>
#include <iostream>
#include <vector>

int convertToInt(char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0' + 1;
	if (ch >= 'a' && ch <= 'z')
		return ch - 'a' + 11;
	if (ch >= 'A' && ch <= 'Z')
		 return ch - 'A' + 37;
	return -1;
}

char convertToChar(int n)
{
	if (n >= 1 && n <= 10)
		return n - 1 + '0';
	if (n >= 11 && n <= 36)
		return n - 11 + 'a';
	if (n >= 37 && n <= 62)
		return n - 37 + 'A';
	return 0;
}

std::vector<int> countSort(std::vector<int>& input)
{
	const long long n = input.size();
	std::vector<int> copy(63, 0);
	std::vector<int> output(n);


	for (long long i = 0; i < n; i++)
		copy[input[i]]++;
	for (int i = 1; i < 63; i++)
		copy[i] += copy[i - 1];
	for (long long i = n - 1; i >= 0; i--)
	{
		output[copy[input[i]] - 1] = input[i];
		copy[input[i]]--;
	}
	return output;
}

int main()
{
	int n = 0;
	std::string str;
	std::cin >> n >> str;

	std::vector<int> arr(n);
	
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = convertToInt(str[i]);
	}

	arr = countSort(arr);

	for (size_t i = 0; i < n; i++)
	{
		str[i] = convertToChar(arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << str[i];
	}
}


