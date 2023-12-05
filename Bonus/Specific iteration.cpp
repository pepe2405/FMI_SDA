#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
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
    int height = 0;  
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printSFB() {
        deque<Node*> arr;
        arr.push_back(root);
        while (!arr.empty())
        {
            int size = arr.size();
            if (height % 2 == 0)
            {
                for (int i = 0; i < size; i++)
                {
                    std::cout << arr.front()->value << ' ';

                    if (arr.front()->left)
                        arr.push_back(arr.front()->left);
                    if (arr.front()->right)
                        arr.push_back(arr.front()->right);
                    arr.pop_front();
                }
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    std::cout << arr.back()->value << ' ';

                    if (arr.back()->right)
                        arr.push_front(arr.back()->right);
                    if (arr.back()->left)
                        arr.push_front(arr.back()->left);
                    arr.pop_back();
                }
            }
            height++;

        }
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

    tree.printSFB();
    return 0;
}