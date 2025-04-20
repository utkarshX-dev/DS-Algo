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

void buildfromlevelorder(node* &root)
{
    queue<node *> q;
    int data;
    cout << "Enter data for root : ";
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        // left node operations :
        int leftdata;
        cout << "Enter data for left node of "<<temp->data<<endl;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left); 
        }
        int rightdata;
        cout << "Enter data for right node of "<<temp->data<<endl;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right); 
        }
    }
}
int main()
{
    node *root = nullptr;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    buildfromlevelorder(root);
    levelOrder(root);
    return 0;
}