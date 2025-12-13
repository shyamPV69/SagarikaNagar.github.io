#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    string name;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const string& n) : name(n), left(nullptr), right(nullptr) {}
};

void preorderTraversal(TreeNode* root) {
    if (!root) return;
    cout << root->name << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    TreeNode* root = new TreeNode("Sagarika Nagar");
    root->left = new TreeNode("Residential Zone");
    root->right = new TreeNode("Commercial City");
    root->left->left = new TreeNode("Forest Area");
    root->left->right = new TreeNode("Agricultural Zone");

    cout << "Map Regions (Preorder): ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
