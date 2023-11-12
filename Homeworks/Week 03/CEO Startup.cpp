#include <iostream>
#include <vector>

bool check(std::vector<int>& arr, long long m, long long curr)
{
	long long i = -1, n = arr.size(), count = 1;
	long long sum = 0;
	while (++i < n && count <= m)
	{
		if (sum + arr[i] <= curr)
			sum += arr[i];
		else
		{
			sum = arr[i];
			count++;
		}
			
	}
	return count <= m;
}

int main()
{
	long long n = 0, m = 0;
	std::cin >> n >> m;
	std::vector<int> arr;
	for (int i = 0; i < n; i++)
	{
		int k = 0;
		std::cin >> k;
		arr.push_back(k);
	}

	long long left = 0, right = 0, result = 0, mid = 0;
	for (long long el : arr)
	{
		right += el;
		left = std::max(left, el);
	}
	result = right;

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (check(arr, m, mid))
		{
			result = std::min(result, mid);
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	if (m == 0 || arr.empty())
    {
		result = 0;
    }
    std::cout << result;
}
