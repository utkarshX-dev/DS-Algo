#include <iostream>
using namespace std;
int sumUpton(int n){
    if(n == 0) return 0;
    else return n + sumUpton(n - 1);
}
int main(){
    int n;
    cout << "Enter natural number : " ;
    cin >> n;
    cout << "Sum of natural numbers upto " << n << " is " << sumUpton(n);
    return 0;
}