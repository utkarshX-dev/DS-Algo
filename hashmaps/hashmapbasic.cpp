#include <iostream>
#include <unordered_map>
using namespace std;
int main(){
    unordered_map<string,int>m;
    pair<string,int>p;
    p.first = "utkarsh";
    p.second = 23;
    m.insert(p);
    m.insert(make_pair("raghav",12));
    m.insert(make_pair("vinay",11));
    m.insert(make_pair("rahul",13));
    m["uday"] = 23;
    cout<<"Size of map : "<<m.size()<<endl;
    m.erase("utkarsh");
    m.erase("sanket");
    cout<<"Size of map : "<<m.size()<<endl;
    for(pair<string,int>p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<"Size of map : "<<m.size()<<endl;
    if (m.find("utkarsh")!=m.end())
    {
        cout<<"Utkarsh is present in map"<<endl;
    }
    else{
        cout<<"utkarsh is not present in map"<<endl;
    }
    
    return 0;
}