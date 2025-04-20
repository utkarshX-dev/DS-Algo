#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    unordered_set<int>s;
    unordered_set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    cout<<"size of set : "<<s.size()<<endl;
    s.insert(0);
    s.insert(9);
    s.insert(9);
    s.insert(9);
    s.insert(9);
    cout<<"size of set : "<<s.size()<<endl;
    for(int ele : s){
        cout<<ele<<" ";
    }
    //s.find() = it searches element and if not found it returns the last element
    int target = 4;
    if(s.find(target)!=s.end()){
        cout<<"Element exits"<<endl;
    } 
    return 0;
}