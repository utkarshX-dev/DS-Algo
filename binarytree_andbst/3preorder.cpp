#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
node *buildtree(node *root)
{
    int data;
    cout << "Enter data for node : " << endl;
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }
    root = new node(data);
    cout << "Enter data for left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}
void preorder(node *root)
{
    // nlr
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    node *root = nullptr;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildtree(root);
    preorder(root);
    return 0;
}