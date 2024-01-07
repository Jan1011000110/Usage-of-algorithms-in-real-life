#include<bits/stdc++.h>
using namespace std;

void Endevina_Nombre(){
    int mid, intents = 0, low = 1, high = 100;
    char resposta;
    // Aquí comença la cerca binària
    while (high > low + 1){
        intents += 1;
        mid = (low + high) / 2;
        cout << "L'algorisme ha provat el numero: " << mid << endl;
        cin >> resposta;
        if (resposta == '='){
            cout << "Nombre secret: " << mid << endl;
            cout << "Intents: " << intents << endl;
            break;
        }
        else if (resposta == '>')
            low = mid;
        
        else if (resposta == '<')
            high = mid;
    }
}

int main(){
    Endevina_Nombre();
}
