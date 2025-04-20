#include <iostream>
#include <vector>
using namespace std;
class Node{
public:
    Node* left;
    Node* right;
    int data;

    Node(int data){
        left = nullptr;
        right = nullptr;
        this->data = data;
    }
};
void inorder(Node* root, vector<int>& in){
    if(root == nullptr) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
void preorder(Node* root, vector<int>& pre){
    if(root == nullptr) return;
    pre.push_back(root->data);
    inorder(root->left, pre);
    inorder(root->right, pre);
}
void postorder(Node* root, vector<int>& post){
    if(root == nullptr) return;
    inorder(root->left, post);
    inorder(root->right, post);
    post.push_back(root->data);
}
void print(vector<int>& v){
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    
    cout << endl << endl;   
}
Node* insert(Node* root, int data){
    if(root == nullptr){
     return new Node(data);
    }
        if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}
int main(){
    
    Node* root = nullptr;
    vector<int>nums = {8, 10, 3, 1, 6, 14, 17};
    for(int i = 0; i < nums.size(); i++){
        root = insert(root, nums[i]);
    }

    vector<int>in1;
    vector<int>pre1;
    vector<int>post1;
    
    inorder(root, in1);
    cout << "Inorder Traversal ";
    print(in1);

    preorder(root, pre1);
    cout << "preorder Traversal ";
    print(pre1);

    postorder(root, post1);
    cout << "postorder Traversal ";
    print(post1);
    return 0;
}