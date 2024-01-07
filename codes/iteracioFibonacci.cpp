#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    vector <int> f(n+2); // llista on guardem els valors de les posicions de la sequencia
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++){ // iteració
        f[i] = f[i-1] + f[i-2]; 
    } 

    return f[n];
    
}

int main(){
    int n;
    cin >> n;
    cout << fib(n);
}
