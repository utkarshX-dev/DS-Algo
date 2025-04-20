#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
    // set<int>s;
    // s.insert(4);
    // s.insert(3);
    // s.insert(3);
    // s.insert(3);
    // s.insert(1);
    // s.insert(0);
    // for(auto x : s){
    //     cout<<x<<" ";
    // }
    // cout<<endl <<s.size();

    // unordered map
    //  unordered_map<int,int>m;
    //  m[1] = 10;
    //  if (m.find(1) != m.end())
    //  {
    //      cout<<"Key present";
    //  }

    // cout<<m[1];

    // map<int,int>m;
    // m.insert(make_pair(1,30));
    // m[2] = 100;
    // m[2] = 105;
    // m.insert({0,40});
    // for(auto x : m){
    //     cout << x.first << " " << x.second <<endl;
    // }

    // string map
    map<string, int> m;
    m["Raghav"] = 11000;
    m["Utkarsh"] = 134;
    m["Uday"] = 12;
    for (auto x : m)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}