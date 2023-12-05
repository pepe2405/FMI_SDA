#include <iostream>

using namespace std;

long long sum = 0;

class Node {
public:
    int data;
    Node* leftNode;
    Node* rightNode;
    Node(int d) {
        data = d;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        }
        else {
            Node* cur;
            if (data <= root->data) {
                cur = insert(root->leftNode, data);
                root->leftNode = cur;
            }
            else {
                cur = insert(root->rightNode, data);
                root->rightNode = cur;
            }

            return root;
        }
    }

    void findSum(Node* root)
    {
        if (root->leftNode == nullptr && root->rightNode == nullptr && root->data % 2 == 1)
            sum += root->data;
        if (root->leftNode != nullptr)
            findSum(root->leftNode);
        if (root->rightNode != nullptr)
            findSum(root->rightNode);
    }

    void leaves(Node* root) {
        findSum(root);
        std::cout << sum;
    }


}; //End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.leaves(root);
    return 0;
}