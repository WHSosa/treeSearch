#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct BinaryTreeNode {
    string data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(const string& value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(BinaryTreeNode* root) {
    if (root == nullptr){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preOrderTraversal(BinaryTreeNode* root) {

     if(root == nullptr) {
         return;
     }
    
     cout << root->data << " ";
     preOrderTraversal(root->left);
     preOrderTraversal(root->right);
}
void postOrderTraversal(BinaryTreeNode* root) {

     if(root == nullptr) {
         return;
     }
     
     postOrderTraversal(root->left);
     postOrderTraversal(root->right);
     cout << root->data << " ";
}
void levelorder(BinaryTreeNode* root) {
    if (root == nullptr) {
        return;
    }
    queue<BinaryTreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) { q.push(current->left);}
        if (current->right) { q.push(current->right);}
    }
}

void freeTree(BinaryTreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

