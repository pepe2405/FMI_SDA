#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n = 0;
	std::cin >> n;
	std::stack<int> stack;
	std::vector<int> nums;
	std::vector<int> removeCount(n, 0);

	for (int i = 0; i < n; i++)
	{
		int k = 0;
		std::cin >> k;
		nums.push_back(k);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		while (!stack.empty() && nums[i] < nums[stack.top()])
		{
			removeCount[i] = std::max(removeCount[i] + 1, removeCount[stack.top()]);
			stack.pop();
		}
		stack.push(i);
	}

	std::cout << *std::max_element(removeCount.begin(), removeCount.end());
}
