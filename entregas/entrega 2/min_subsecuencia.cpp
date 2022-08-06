#include <iostream>
#include <vector>

using namespace std;

int indiceMinSubsec(vector<int> v, int l, int r){
    int minimo = l;
    for(int i = l; i <= r; i = i + 1){
        if (v[i]<v[minimo] && i>=0){
            minimo = i;
        } else{
            minimo = minimo;
        }
    }
    return minimo;
}

int main() {
    /* No hace falta modificar el main */
    // Leo las entradas
    int n; //Longitud del vector a rotar
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }

    int l,r;
    cin >> l >> r;
    // Calculo el minimo
    int min = indiceMinSubsec(v,l,r);

    // Impimo salida
    cout << min;

    return 0;
}
