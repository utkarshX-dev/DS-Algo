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
        left = nullptr;
        right = nullptr;
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

node *InsertInbst(node *&root, int d)
{
    if (root == nullptr)
    {
        root = new node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = InsertInbst(root->right, d);
    }
    else
    {
        root->left = InsertInbst(root->left, d);
    }
    return root;
}
void inorder(node *root){
    //lnr
    //base case
    if(root == nullptr) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right); 
}

void takeinput(node *&root) // Pass root by reference
{
    int data;
    cout << "Enter data (-1 to stop): ";
    cin >> data;
    while (data != -1)
    {
        root = InsertInbst(root, data);
        cin >> data;
    }
}

int main()
{
    node *root = nullptr;
    cout << "Enter data to create BST "<<endl;
    takeinput(root);
    cout << "Printing nodes: " << endl;
    levelOrder(root);
    cout<<"Inorder : ";
    inorder(root);
    return 0;
}
