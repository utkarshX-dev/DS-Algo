#include <iostream>
using namespace std;
void permutations(string input , string output){
    if(input.length() == 0){
        cout << output << " \n";
        return;
    }
    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];
        string left = input.substr(0,i);
        string right = input.substr(i+1);
        string sub = left + right;
        permutations(sub , output + ch);
    }
    
}
int main(){
    permutations("abc","");
    return 0;
}