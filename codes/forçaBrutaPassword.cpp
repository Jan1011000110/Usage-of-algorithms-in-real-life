#include <bits/stdc++.h>
using namespace std;

void endivinarContrasenya(int contrasenya){
    for (int i = 0; i < 10000; i++){
        if (i == contrasenya){
            cout << "L'algorisme ha endevinat la teva contrasenya!" << endl;
            cout << "La contrasenya es: " << i << endl;
        }
    }
}

int main(){
    int contrasenya;
    cout << "Introdueix una contrasenya, entre 0000 i 9999:" << endl;
    cin >> contrasenya;
    endivinarContrasenya(contrasenya);
}


