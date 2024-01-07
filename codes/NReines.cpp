#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> Tauler;

void printSol(){
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++){
            cout << Tauler[x][y] << " ";
        }
        cout << endl;
    }
}

bool esSegur(int fil, int col){
    int i, j;
    
    // mirem si algunes reines s'ataquen entre elles
    for (i = 0; i < col; i++)
        if (Tauler[fil][i])
            return false;
 
    for (i = fil, j = col; i >= 0 && j >= 0; i--, j--)
        if (Tauler[i][j])
            return false;
 
    for (i = fil, j = col; j >= 0 && i < n; i++, j--)
        if (Tauler[i][j])
            return false;
 
    return true;
}

bool backtracking(int col){
    if (col == n){ // hem colocat les n reines
        printSol();
        return true;  
    }      

    for (int i = 0; i < n; i++){
        if (esSegur(i, col)){
            Tauler[i][col] = 1; // la posició és vàlida (reina) 
            if (backtracking(col + 1))
                return true;
            
            Tauler[i][col] = 0; // provem una altra possibilitat
        }
    }   
    return false;
}


int main(){
    cout << "Introdueix una n: " << endl;
    cin >> n;
    Tauler.resize(n, vector<int>(n,0));
    if (backtracking(0) == false)
        cout << "No hi ha ninguna solucio posible per a aquesta n" << endl;
}
