/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;



bool estaOrdenadoAscendente(vector<int> v){
    for (int i = 0; i < v.size() - 1; i++) {
        if ( v[i] <= v[i+1]){
            
        } return true;
    } return false;
} 
 
 
 
bool estaOrdenadoDescendente(vector<int> v){
    
    for (int i = 0; i < v.size() - 1; i++) {
        if ( v[i+1] >= v[i]){
            
        } return true;
    } return false;
}  
  
bool estaOrdenado(vector <int> v){
    if (v.size() <= 1){
        return true;
    }
    if (estaOrdenadoDescendente(v) == false && estaOrdenadoAscendente(v) == false){
        return false;
    }
    else {
        return true;
    }
} 
  
    
int main() {
    /* No hace falta modificar el main */
    // Leo las entradas
    int n; 
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
    bool res = estaOrdenado(v);
    
    // Imprimo la salida
    cout << (res?"True":"False");
    
    return 0;
}