#include <iostream>
#include <stack>
#include<queue>
using namespace std;
int main(){
    deque<int>d;
    d.push_back(11);
    d.push_back(12);
    d.push_back(13);
    d.push_back(14);
    d.pop_front();
    d.pop_back();
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    //  d.pop_back();
    // d.pop_back();
    if(d.empty()){
        cout<<"doubly ended queue is empty"<<endl;
    }
    else
    {
        cout<<"It is not empty "<<endl;
    }
    return 0;
}