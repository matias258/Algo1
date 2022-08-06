#include <vector>
#include <iostream>

using namespace std;

bool existePico(vector<int> v){
    int i= 1;
    int picos = 0;
    while (i < v.size()-2){
        if (v[i] > v[i-1] && v[i]> v[i+1]){
            picos = picos + 1;
        }
        else{
            picos = picos;
        }
        i++;
    }
    if (picos > 0){
        return true;
    }
    else {
        return false;
    }
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
    
    // Evaluo si el vector v esta ordenado
    bool res = existePico(v);
    
    // Imprimo la salida
    cout << (res?"True":"False");
    
    return 0;
}
