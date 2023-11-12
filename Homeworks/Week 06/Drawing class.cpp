#include <iostream>
#include <vector>

struct Node
{
	Node* left = nullptr;
	Node* right = nullptr;
	long long parCount = 0;
	long long leftSTCount = 0;
	long long rightSTCount = 0;
};

long long getAllCount(Node* root)
{
	long long count = 0;

	if (root->left)
	{
		count++;
		count += getAllCount(root->left);
	}
	if (root->right)
	{
		count++;
		count += getAllCount(root->right);
	}
	return count;
}

long long getLeftCount(Node* root)
{
	long long count = 0;
	if (root->left)
	{
		count++;
		count += getAllCount(root->left);
	}
	return count;
}

long long getRightCount(Node* root)
{
	long long count = 0;
	if (root->right)
	{
		count++;
		count += getAllCount(root->right);
	}
	return count;
}

void getMax(Node* root, long long& max)
{
	long long curr = 0;
	if (root->parCount)
	{
		if (!curr)
			curr = 1;
		curr *= root->parCount;
	}
	if (root->leftSTCount)
	{
		if (!curr)
			curr = 1;
		curr *= root->leftSTCount;
	}
	if (root->rightSTCount)
	{
		if (!curr)
			curr = 1;
		curr *= root->rightSTCount;
	}

	max = std::max(curr, max);
	if (root->left)
		getMax(root->left, max);
	if (root->right)
		getMax(root->right, max);
}

int main()
{
	long long n = 0;
	std::cin >> n;
	std::vector<Node> arr(n);

	for (int i = 0; i < n; i++)
	{
		long long left, right;
		std::cin >> left >> right;

		if (left == -1)
			arr[i].left = nullptr;
		else
			arr[i].left = &arr[left];
		if (right == -1)
			arr[i].right = nullptr;
		else
			arr[i].right = &arr[right];
	}

	for (auto &node : arr)
	{
		node.leftSTCount = getLeftCount(&node);
		node.rightSTCount = getRightCount(&node);

		if (node.left)
			node.left->parCount = node.parCount + node.rightSTCount + 1;
		if (node.right)
			node.right->parCount = node.parCount + node.leftSTCount + 1;
	}

	long long max = 0;
	getMax(&arr[0], max);
	std::cout << max;
}
