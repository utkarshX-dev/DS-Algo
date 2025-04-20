#include <iostream>
#include <unordered_set>
using namespace std;
void permutations(string& input, int i){
    if (i == input.length() - 1)
    {
        cout << input << " ";
        return;
    }
    unordered_set<char>s;
    for (int idx = i; idx < input.length() ; idx++)
    {
        if(s.find(input[idx]) != s.end()) continue; 
        swap(input[idx],input[i]);
        s.insert(input[idx]);
        permutations(input,i+1);
        swap(input[idx],input[i]);
    }
    
}
int main(){
    string input = "aba";
    permutations(input,0);
    return 0;
}