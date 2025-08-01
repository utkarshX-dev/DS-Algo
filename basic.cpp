#include <iostream>
#include <queue>
using namespace std;
int main(){
    priority_queue<int>pq;
    pq.push(45);
    pq.push(46);
    pq.push(12);
    pq.push(10);
    cout << pq.top() << endl; //46
    pq.pop();
    cout << pq.top() << endl; //45
    pq.pop();
    cout << pq.top() << endl; //45
    pq.pop();
    cout << pq.top() << endl; //45
    pq.pop();
    pq.pop();
    pq.pop();
    pq.pop();
    cout << "Size of priority queue : "<<  pq.size() << endl;
    cout << "size of priority quueue : " << pq.top() << endl;
    cout << pq.top() << endl; //45
    return 0;
}