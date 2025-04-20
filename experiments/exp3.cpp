// implementing stack using arrays
#include <iostream>
using namespace std;
class stack{
public:
    int size;
    int *arr;
    int topIndex;
    //constructor
    stack(int size){
        this->size = size;
        topIndex = -1;
        arr = new int[size];
    }

    void push(int ele){
        if (isFull()){
            cout << "Stack Overflow" << endl;
        }
        else{
            topIndex++;
            arr[topIndex] = ele;
        }
    }

    int pop(){
        if (isEmpty()){
            cout << "Stack Underflow";
            return -1;
        }
        else{
            int ele = arr[topIndex];
            topIndex--;
            return ele;
        }
    }

    bool isEmpty(){
        if (topIndex == -1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull(){
        if (topIndex == size - 1){
            return true;
        }
        else{
            return false;
        }
    }

    void display(){
        if (isFull()){
            cout << "Stack is full" << endl;
        }
        else if (isEmpty()){
            cout << "Stack is empty" << endl;
        }
        else{
            cout << "Stack is neither full or empty" << endl;
            cout << "Top element : " << arr[topIndex] << endl;
        }
    }

    int top(){
        if (isEmpty()){
            return -1;
        }
        else{
            return arr[topIndex];
        }
    }
};
// Ques)Task : check whether a string is palindrome or not using stack ?
bool palindrome(string s){
    int n = s.length();
    stack st(n);
    for (int i = 0; i < n; i++){
        st.push(s[i]);
    }
    int i = 0;
    while (i < n){
        char ch = st.top();
        if (ch == s[i]){
            i++;
            st.pop();
        }
        else{
            return false;
        }
    }
    return true;
}
int main() {
    stack st(3); // Creating a stack of size 3

    // Testing stack functions
    st.push(5);
    st.push(15);
    
    cout << "Top element before popping: " << st.top() << endl;
    cout << endl;

    cout << "Popped element: " << st.pop() << endl;
    cout << endl;

    if (st.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }
    cout << endl;

    st.pop(); // remove top element(5)

    if (st.isEmpty()) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack is not empty" << endl;
    }
    cout << endl;

    cout << "Trying to pop from an empty stack:" << endl;
    st.pop();  // Should print "Stack Underflow"
    cout << endl;

    // Testing palindrome function
    string s2 = "hello";
    cout << "Checking if \"" << s2 << "\" is a palindrome:" << endl;

    if (palindrome(s2)){
        cout << s2 << " is a palindrome" << endl;
    } else {
        cout << s2 << " is not a palindrome" << endl;
    }
    cout << endl;
    return 0;
}
