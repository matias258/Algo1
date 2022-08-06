#include <iostream>

using namespace std;

// Funcion de fibonacci que calcula n-esimo termino
int fibonacci(int n){
    //COMPLETAR
    int x = 0, y = 1, z = 1;
    if (n < 0){ cout << "El numero ingresado debe ser mayor o igual a 0." << endl;}
    if (n == 0){ cout << 0 << endl;}
    for (int i = 1; i < n; i = i + 1)
    {
        z = x + y;

        x=y;
        y=z;
    }
    return z;
}
int main() 
{
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;    
    return 0;
}