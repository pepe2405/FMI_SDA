#include <iostream>
#include <vector>

struct Node
{
	long long id, x = 0;
	Node* left;
	Node* right;
	Node(long long id, Node* left, Node* right) : id(id), left(left), right(right){}
	Node() : Node(0, nullptr, nullptr){}
};

int main()
{
	long long n = 0;
	std::cin >> n;
	std::vector<Node> arr(n);
	std::vector<long long> neg(n);
	std::vector<long long> pos(n);

	for (long long i = 0; i < n; i++)
	{
		long long mid, left, right;
		std::cin >> mid >> left >> right;
		arr[i].id = mid;

		if (arr[i].x < 0)
		{
			neg[abs(arr[i].x)] += arr[i].id;
		}
		else
		{
			pos[arr[i].x] += arr[i].id;
		}

		if (left == -1)
		{
			arr[i].left = nullptr;
		}
		else
		{
			arr[i].left = &arr[left];
			arr[i].left->x = arr[i].x - 1;
			arr[i].left->id = left + 1;
			
		}
		if (right == -1)
		{
			arr[i].right = nullptr;
		}
		else
		{
			arr[i].right = &arr[right];
			arr[i].right->x = arr[i].x + 1;
			arr[i].right->id = right + 1;
		}
	}

	for (long long i = n - 1; i >= 0; i--)
	{
		if (neg[i] != 0)
		{
			std::cout << neg[i] << ' ';
		}
	}
	for (long long i = 0; i < n; i++)
	{
		if (pos[i] != 0)
		{
			std::cout << pos[i] << ' ';
		}
	}


}
