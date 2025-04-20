#include <iostream>
using namespace std;

int factorialIterative(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int factorialRecursive(int n) {
    if (n <= 1) return 1;
    return n * factorialRecursive(n - 1);
}

void fibonacciIterative(int n) {
    int a = 0, b = 1, c;
    cout << "Fibonacci Iterative series upto "<<n<<" terms : ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }
    cout << endl;
}

void fibonacciRecursiveHelper(int n, int a, int b) {
    if (n == 0) return;
    cout << a << " ";
    fibonacciRecursiveHelper(n - 1, b, a + b);
}

void fibonacciRecursive(int n) {
    cout << "Fibonacci Iterative series upto "<<n<<" terms : ";
    fibonacciRecursiveHelper(n, 0, 1);
    cout << endl;
}

int main() {
    int n;
    cout<<"Enter value of n : ";
    cin >> n;
    cout << "Factorial Iterative of " << n << " is " << factorialIterative(n) << endl;
    cout << "Factorial Recursive of " << n << " is " << factorialRecursive(n) << endl;
    
    fibonacciIterative(n);
    fibonacciRecursive(n);
    
    return 0;
}
