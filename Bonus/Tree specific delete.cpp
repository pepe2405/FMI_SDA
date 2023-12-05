#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void deletePenultimateAndPrint() {
        getAllValues(root);
    }

    void getAllValues(Node* node)
    {
        if (node == nullptr)
            return;
        getAllValues(node->left);
        if (!isParent(node))
        {
	        std::cout << node->value << ' ';
        }
        getAllValues(node->right);
    }

    bool isParent(Node* node)
    {
	    if (node == nullptr)
	    {
            return false;
	    }
        if (node->left == nullptr && node->right == nullptr)
        {
            return false;
        }
	    if (node->left == nullptr)
	    {
            return !(node->right->right != nullptr || node->right->left != nullptr);
	    }
        if (node->right == nullptr)
        {
            return !(node->left->right != nullptr || node->left->left != nullptr);
        }

        return !(node->right->right != nullptr || node->right->left != nullptr || node->left->right != nullptr || node->left->left != nullptr);
    }

private:
    //you can write helper functions if needed
    Node* root;

    Node* insert(Node* curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        }
        else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        }
        else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        }
        else {
            //if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for (int i = 0; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
    tree.deletePenultimateAndPrint();
    return 0;
}