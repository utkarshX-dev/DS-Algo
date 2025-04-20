#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    queue<int> q;
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.size() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.size() << endl;

    queue<int> q2;
    q2.push(5);
    q2.push(6);
    q2.push(7);
    cout << "After swapping " << endl;
    // swapping
    swap(q, q2);
    // now q2 becomes q and q1 becomes q2
    cout << q.front() << endl;
    cout << q2.front() << endl;

    q2.pop();
    // q2.pop();
    // if(q2.empty()){
    //     cout<<"q2 is empty"<<endl;
    // }
    // else{
    //     cout<<"q2 is not empty"<<endl;
    // }
    cout << q2.front() << endl;
    cout << q2.back() << endl;
    return 0;
}
