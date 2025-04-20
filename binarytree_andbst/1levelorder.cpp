#include <iostream>
#include <queue>
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
void levelOrder(node *root)
{
    if (root == nullptr)
        return;
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == nullptr)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << temp->data << " ";
            // Push the left child to the queue if it exists
            if (temp->left)
            {
                q.push(temp->left);
            }

            // Push the right child to the queue if it exists
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node *root = nullptr;
    // creation of tree
    root = buildtree(root);
    levelOrder(root);
    return 0;
}