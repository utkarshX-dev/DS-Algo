#include <iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(21);
    pq.push(13);
    pq.push(0);
    pq.push(17);
    pq.push(11);
    while (!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    return 0;
}