// https://www.hackerrank.com/contests/sda-test3-2022-2023-rdsafgtvh/challenges/--149/submissions/code/1370402250

#include <iostream>

struct Node
{
	long long value = 0;
	Node* left = nullptr;
	Node* right = nullptr;

	Node(long long value) : value(value), left(nullptr), right(nullptr){}
};

Node* connect(Node* root, long long n)
{
	if (root == nullptr)
		return new Node(n);
	if (n < root->value)
		root->left = connect(root->left, n);
	if (n > root->value)
		root->right = connect(root->right, n);
	return root;
}

bool hasThoChildren(Node* node)
{
	return (node->left != nullptr && node->right != nullptr);
}

void print(Node* root)
{
	if (root == NULL)
		return;
	if (hasThoChildren(root))
		std::cout << root->value << ' ';
	print(root->left);
	print(root->right);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	long long t, n;
	std::cin >> t;

	for (long long i = 0; i < t; i++)
	{
		std::cin >> n;

		long long number;
		std::cin >> number;
		Node* root = new Node(number);
		for (long long j = 1; j < n; j++)
		{
			std::cin >> number;
			connect(root, number);
		}
		print(root);
		std::cout << std::endl;
	}
}
