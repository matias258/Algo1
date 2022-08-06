#include <iostream>
using namespace std;


int sumaDivisores (int n){

    int res = 0;
    int i = 1;
    while ( i < n){
        if (n % i == 0){
            res = res + i;
        }
        else {
            res = res;
        }
        i++;
    }
    return res;
}


int main() {
    int n;
    cin >> n ;
    cout << sumaDivisores(n)<< endl;
}
