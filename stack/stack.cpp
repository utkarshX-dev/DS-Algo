#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int>s;
    stack<int>s2;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s2.push(11);
    s2.push(12);
    s2.push(13);
    s2.push(14);
    cout<<s.top()<<endl;
    cout<<s2.top()<<endl;
    s.swap(s2);
    cout<<s.top()<<endl;
    cout<<s2.top()<<endl;
    // cout<<s.size()<<endl;
    // s.pop();
    // s.pop();
    // s.pop();
    // cout<<s.top()<<endl;
    // cout<<s.size()<<endl;
    // s.pop();
    // if(s.empty()){
    //     cout<<"stack is empty"<<endl;
    // }
    // else
    // {
    //     cout<<"stack is not empty"<<endl;
    // }
    
    return 0;
}