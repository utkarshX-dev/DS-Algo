#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
int size(node *head)
{
    int cnt = 0;
    node *temp = head;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
void print(node *head)
{
    node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertathead(node *&head, int data)
{
    if (head == nullptr)
    {
        head = new node(data);
        return;
    }
    node *new_node = new node(data);
    new_node->next = head;
    head = new_node;
}
void insertatend(node *head, int data)
{
    if (head == nullptr)
    {
        head = new node(data);
        return;
    }
    else
    {
        node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new node(data);
    }
}
void insertatanyposition(node *head, int data, int position, int size)
{
    if (position > size)
    {
        cout << "size of linkedlist is smaller than position";
        return;
    }
    if (position == 1)
    {
        insertathead(head, data);
    }
    else if (position == size)
    {
        insertatend(head, data);
    }
    else
    {
        node *temp = head;
        int iteration = position - 1;
        while (iteration)
        {
            temp = temp->next;
            iteration--;
        }
        node *new_node = new node(data);
        new_node->next = temp->next;
        temp->next = new_node;
    }
}
void deleteathead(node *&head)
{
    if (size(head) == 0)
    {
        cout << "Size of linkedlist is 0";
        return;
    }
    head = head->next;
}
void deleteatend(node *&head)
{
    if (size(head) == 0)
    {
        cout << "size of linkedlist is 0";
    }
    else if (head->next == nullptr)
    {
        head = nullptr;
    }
    else
    {
        node *temp = head;
        while (temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
    }
}

void deleteatrandom(node *head, int position, int size)
{
    if (position > size)
    {
        cout << "size of linkedlist is smaller than position";
        return;
    }
    if (position == 1)
    {
        deleteathead(head);
    }
    else if (position == size)
    {
        deleteatend(head);
    }
    else
    {
        node *temp = head;
        int iteration = position - 1;
        while (iteration)
        {
            temp = temp->next;
            iteration--;
        }
        temp->next = temp->next->next;
    }
}
bool findElement(node *head, int element)
{
    node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == element)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
// int main(){
//     node *head = nullptr;
//     head = new node(1);
//     head->next = new node(2);
//     head->next->next = new node(3);
//     head->next->next->next = new node(4);

//     // printing whole linkedlist
//     print(head);
//     cout << endl<<endl;

//     // insert at head
//     insertathead(head, 5);
//     print(head);
//     cout << endl<<endl;

//     // insert at random position
//     insertatanyposition(head, 6, 5, size(head));
//     print(head);
//     cout << endl<<endl;
//     insertatanyposition(head, 7, 6, size(head));
//     print(head);
//     cout << endl<<endl;
//     insertatanyposition(head, 0, 3, size(head));
//     print(head);
//     cout << endl<<endl;

//     // deletion at head;
//     deleteathead(head);
//     print(head);
//     cout << endl<<endl;

//     // deletion at end
//     deleteatend(head);
//     print(head);
//     cout << endl<<endl;

//     // finding an element which is not present in linkedlist
//     if (findElement(head, 5)){
//         cout << "5 is present in linkedlist";
//     }
//     else{
//         cout << "5 is not present in linkedlist";
//     }
//     cout << endl<< endl;

//     // findingelement which is present in linkedlist
//     if (findElement(head, 6)){
//         cout << "6 is present in linkedlist";
//     }
//     else{
//         cout << "6 is not present in linkedlist";
//     }
//     return 0;
// }
    int main() {
        node *head = nullptr;
        head = new node(10);
        head->next = new node(20);
        head->next->next = new node(30);
        head->next->next->next = new node(40);

        // printing whole linked list
        print(head);
        cout << endl << endl;

        // insert at head
        insertathead(head, 50);
        print(head);
        cout << endl << endl;

        // insert at random position
        insertatanyposition(head, 15, 3, size(head));
        print(head);
        cout << endl << endl;
        insertatanyposition(head, 25, 5, size(head));
        print(head);
        cout << endl << endl;
        insertatanyposition(head, 5, 1, size(head));
        print(head);
        cout << endl << endl;

        // deletion at head
        deleteathead(head);
        print(head);
        cout << endl << endl;

        // deletion at end
        deleteatend(head);
        print(head);
        cout << endl << endl;

        // finding an element which is not present in linked list
        if (findElement(head, 100)) {
            cout << "100 is present in linked list";
        } else {
            cout << "100 is not present in linked list";
        }
        cout << endl << endl;

        // finding an element which is present in linked list
        if (findElement(head, 15)) {
            cout << "15 is present in linked list";
        } else {
            cout << "15 is not present in linked list";
        }
        return 0;
    }
