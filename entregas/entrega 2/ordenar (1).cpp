#include <vector>
#include <iostream>

using namespace std;


/* auxiliar para el ejercicio ordenar (que ordena una seq no vacia de enteros) */



void ordenar1(vector<int>& v){
    for (int i = 0; i < v.size() -1; i++){

        for (int j = 0; j < v.size()-1; j++){
            if (v[j] > v[j + 1]){
                swap(v[j], v[j+1]);
            }
        }
    }
}

int main() {
    /* No hace falta modificar el main */

    // Leo las entradas
    int n; //Longitud del vector
    cin >> n;
    int i = 0;
    int x;
    vector<int> v;// En v leo el vector
    while (i<n){
        cin >> x;
        v.push_back(x);
        i++;
    }

    // Hago el ordenamiento
    ordenar1(v);

    // Imprimo el vector resultado
    i = 0;
    while (i < v.size()){
        cout << v[i] << " ";
        i++;
    }

    return 0;
}
