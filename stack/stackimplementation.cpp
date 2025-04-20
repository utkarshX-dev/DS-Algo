#include <iostream>
using namespace std;
class stack{
    private :
    
    int *arr;
    int topindex;
    int size;
    
    public:
    
    stack(int size){
        this->size=size;
        arr=new int[size];
        topindex=-1;
    }
    void push(int value){
        if(topindex==size-1){
            cout<<"Stack overflow"<<endl;
        }
        else{
            topindex++;
            arr[topindex]=value;
        }
    }
    
    bool empty(){
        if(topindex>=0){
            return 0;
        }
        else{
            return 1;
        }
    }
    void top(){
        if(topindex==-1){
            cout<<"-1"<<endl ;
        }
        else{
            cout<<arr[topindex]<<endl;
        }
    }
    
    void pop(){
        if(topindex==-1){
            cout<<"Stack underflow"<<endl;
        }
        else{
            topindex--;
        }
    }

};
int main(){
    stack s1(5);
    s1.push(22);
    s1.push(43);
    s1.push(44);
    // s1.push(44);
    // s1.push(44);
    // s1.push(44);
    s1.top();
    s1.pop();
    s1.top();
    s1.pop();
    s1.top();
    s1.pop();
    s1.top();
    if(s1.empty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
    return 0;
}