#include <iostream>
using namespace std;
long long solve(int n, int from, int to, int aux){
    if (n == 0)return 0;
    if (n == 1){
        cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
        return 1;
    }
    long long count = solve(n - 1, from, aux, to);
    cout << "move disk " << n << " from rod " << from << " to rod " << to << endl;
    count += 1;
    count += solve(n - 1, aux, to, from);
    return count;
}
long long towerOfHanoi(int n, int from, int to, int aux){
    return solve(n, from, to, aux);
}

int main(){
    int n = 4;
    cout << "No of Disks : " <<n<<endl;
    cout << "total no of moves required :" <<towerOfHanoi(n,1,2,3);
    return 0;
}
