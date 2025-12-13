#include <iostream>
#include <string>
using namespace std;

struct BSTNode {
    string city;
    float distance;
    BSTNode* left;
    BSTNode* right;
    BSTNode(const string& c, float d) : city(c), distance(d), left(nullptr), right(nullptr) {}
};

BSTNode* insert(BSTNode* root, const string& city, float distance) {
    if (!root) return new BSTNode(city, distance);
    if (distance < root->distance) root->left = insert(root->left, city, distance);
    else root->right = insert(root->right, city, distance);
    return root;
}

void inorder(BSTNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->city << " (" << root->distance << " km)" << "\n";
    inorder(root->right);
}

int main() {
    BSTNode* root = nullptr;
    root = insert(root, "Kundapura", 31.87);
    root = insert(root, "Mangalore", 52.47);
    root = insert(root, "Karkala", 34.1);
    root = insert(root, "Sagarika Nagar", 0);
    
    cout << "Cities sorted by distance:\n";
    inorder(root);
    return 0;
}
