#include <bits/stdc++.h>
using namespace std;



int main(){
    string caractersPossibles = "!#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    cout << sz(caractersPossibles);
    int maximaLlargada = 16;

    string contrasenyaUsuari = "abc123#";

    do {
        // miro totes les possible permutacions
        // de tots els caracters
        string contrasenyaProva = "";
        for (int i = 1; i <= maximaLlargada; i++){
            // probo una contrasenya per cada 
            // llargada possible
            contrasenyaProva += caractersPossibles[i];

            if (contrasenyaProva == contrasenyaUsuari) {
                // les contrasenyes coincideixen
                cout << "He trobat la teva contrasenya !" 
                return 0;
            }
        
        }
    } while (next_permutation(all(caractersPossibles)));
        
    
}
