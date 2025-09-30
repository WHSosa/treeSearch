#include <iostream>
#include <string>
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
