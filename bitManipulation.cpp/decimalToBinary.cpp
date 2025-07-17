#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cout << "Enter number : " ;
    cin >> n;
    int temp = n;
    string binary = "";
    while (n > 0)
    {
        int remainder = (n % 2);
        char digit = remainder + '0';
        binary.insert(binary.begin(), digit);
        n = n/2;
    }
    cout << "Binary value of " << temp << " "  << binary;
    return 0;
}