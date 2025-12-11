#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    int height;
    Node(int k): key(k), left(nullptr), right(nullptr), height(1) {}
};

int height(Node* n) { return n ? n->height : 0; }
int balance(Node* n) { return n ? height(n->left) - height(n->right) : 0; }

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int bal = balance(node);

    if (bal > 1 && key < node->left->key) return rightRotate(node);
    if (bal < -1 && key > node->right->key) return leftRotate(node);
    if (bal > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (bal < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    vector<int> vals = {10, 20, 30, 40, 50, 25};
    Node* root = nullptr;
    for (int v : vals) root = insert(root, v);
    cout << "Inorder traversal (sorted): ";
    inorder(root);
    cout << "\n";
    return 0;
}
