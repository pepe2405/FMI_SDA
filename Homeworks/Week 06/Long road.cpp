#include <iostream>
#include <vector>

struct Node
{
	long long val = 0;
	Node* left = nullptr;
	Node* right = nullptr;
	Node() = default;
	Node(int val, Node* left, Node* right) : val(val), left(left), right(right){}
};

long long findMax(Node* root, long long& res)
{
	if (root == nullptr)
		return 0;

	long long l = findMax(root->left, res);
	long long r = findMax(root->right, res);

	long long maxim = std::max(std::max(l, r) + root->val, root->val);
	long long top = std::max(maxim, l + r + root->val);
	res = std::max(res, top);

	return maxim;
}

int main()
{
	long long n = 0;
	std::cin >> n;

	std::vector<Node> arr(n);

	for (int i = 0; i < n; i++)
	{
		long long val, left, right;
		std::cin >> val >> left >> right;

		arr[i].val = val;
		if (left == -1)
			arr[i].left = nullptr;
		else
			arr[i].left = &arr[left];
		if (right == -1)
			arr[i].right = nullptr;
		else
			arr[i].right = &arr[right];
	}

	long long res = LONG_MIN;

	findMax(&arr[0], res);

	std::cout << res;
}
