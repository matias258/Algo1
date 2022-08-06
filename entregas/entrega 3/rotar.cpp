#include <iostream>
#include <string>

using namespace std;

string rotar(string s, int n) {
    int swap = 0;
    for (int i = 0; i < n ; i++){
        s = s[s.size()-1] + s;
        s.pop_back();            //elimino el ultimo termino
        swap = swap + 1;         //cuento las rotaciones
    }
    return s;
}
int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s;
    int j;
    cin >> s >> j;
    
    string res = rotar(s, j);
    cout << res;
    return 0;
}
