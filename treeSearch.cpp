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
void preOrder(BinaryTreeNode* root) {

     if(root == nullptr) {
         return;
     }
    
     cout << root->data << " ";
     preOrder(root->left);
     preOrder(root->right);
}
void postOrder(BinaryTreeNode* root) {

     if(root == nullptr) {
         return;
     }
     
     postOrder(root->left);
     postOrder(root->right);
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

int main() {
    // Build demo tree:
    //         A
    //       /   \
    //      B     C
    //     / \   /
    //    D   E F

    BinaryTreeNode* root = new BinaryTreeNode("A");
    root->left = new BinaryTreeNode("B");
    root->right = new BinaryTreeNode("C");
    root->left->left = new BinaryTreeNode("D");
    root->left->right = new BinaryTreeNode("E");
    root->right->left = new BinaryTreeNode("F");

    cout << "In-order:   ";
    inorder(root);
    cout << "\n";

    cout << "Pre-order:  ";
    preOrder(root);
    cout << "\n";

    cout << "Post-order: ";
    postOrder(root);
    cout << "\n";
    cout << "Level-order: ";
    levelorder(root);
    cout << "\n";

    freeTree(root);

    return 0;
}
