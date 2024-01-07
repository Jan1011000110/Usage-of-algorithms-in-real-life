#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    if (n <= 1){  // cas base
        return n;
    } 
    return fib(n-1) + fib(n-2); // cas recursiu
}

int main(){
    cout << "Introdueix la posicio del nombre de la sequencia de fibonacci que vulguis coneixer:\n";
    int nombre;
    cin >> nombre;
    cout << fib(nombre);
}
