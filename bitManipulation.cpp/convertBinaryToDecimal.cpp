#include <iostream>
#include <math.h>
using namespace std;
int decimalVal(string binary)
{
    int n = binary.length();
    int decimal = 0;
    int power = 1;
    for (int i = n - 1; i >= 0; i--){
        char ch = binary[i];
        int digit = ch - '0';
        if (digit != 0){
            decimal += power;
        }
        power *= 2;
    }
    return decimal;
}
int main()
{
    string binary = "11111";
    cout << decimalVal(binary);
    return 0;
}