
#include <bits/stdc++.h>
using namespace std;

int main(){
    int preu_total;
    cout << "Introdueix el preu a pagar: ";
    cin >> preu_total;
    int preu_a_pagar = preu_total;

    vector<int> monedes = {200,100,50,20,10,5,2,1};
    vector<int> monedes_utilitzades;
    int index = 0;
    int monedes_pagades = 0;

    while (preu_a_pagar > 0){
        if (preu_a_pagar >= monedes[index]){
            preu_a_pagar -= monedes[index];
            monedes_utilitzades.push_back(monedes[index]);
            monedes_pagades++;
        } else
            index++;
    }
    cout << "Hem pagat: " << preu_total << " centims amb: " 
    << monedes_pagades << " monedes." << endl;
    cout << "{";
    for (auto e : monedes_utilitzades){
        cout << e << ",";
    }
    cout << "}";
}
