#include <bits/stdc++.h>
using namespace std;

vector<string> v = {"hola", "hi", "bonjour"};
int n = 3;


void backtracking(int i, vector<bool> &bools){
    if (i == n) {   // cas base de la recursió
        cout << "{";
        for (int i = 0; i < n; i++)
            if (bools[i] == true)
                cout << v[i] << ", ";
        cout << "}" << endl;
        return;
    }
    bools[i] = 0;  // fem backtracking
    backtracking(i + 1, bools);  // cas recursiu
    bools[i] = 1;  // fem backtracking
    backtracking(i + 1, bools);  // cas recursiu
}


int main(){
    vector<bool> bools(n);
    backtracking(0, bools);
}
