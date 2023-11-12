#include <algorithm>
#include <iostream>
#include <vector>


int main()
{
    int n = 0, k = 0, count = 0;
    std::cin >> n >> k;
	std::vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int el = 0;
		std::cin >> el;
		arr.push_back(el);
	}
	std::sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
	{
		if (std::binary_search(arr.begin(), arr.end(), arr[i] + k))
			count++;
	}
    std::cout << count;
}
