#include <iostream>
#include <string>

using namespace std;

bool subsecuencia(string s, string t) { 

    int letras = 0;
    for (int i = 0; i < s.size(); i++){
        for (int j = 0; j < t.size(); j++){
            if (s[i] == t[j]){
                letras ++;
            }
        }
    }
    return letras == s.size();
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s, t;
    cin >> s >> t;
    
    bool res = subsecuencia(s, t);
    cout << (res ? "true" : "false");
    return 0;
}

