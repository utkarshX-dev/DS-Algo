#include <iostream>
using namespace std;
int countPrime(int n){
    int count=0;
    for (int i = 2; i < n; i++)
    {
        bool prime=true;
        for (int j=2; j < i; j++)
        {
            if (i%j==0)
            {
                prime=false;
                break;
            }
        }
        if(prime) count++;
    }
    return count;    
}
int main(){
    int n;
    cout<<"Enter number : ";
    cin>>n;
    cout<<"No of prime numebers less than "<<n<<" : "<<countPrime(n)<<endl;
    return 0;
}