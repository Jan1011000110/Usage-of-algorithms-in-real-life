#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
 
int n, m; // nombre de ciutats i centrals
 
vector<int> ciutats;  // vector amb coordenades X de ciutats
vector<int> centrals;  // vector amb coordenades X de centrals
 
bool check(int r){
    int ciutat_Actual = 0;  // iterador ciutat actual
    int central_Actual = 0;  // iterador central actual
    while (ciutat_Actual < n && central_Actual < m){
        if (centrals[central_Actual] + r >= ciutats[ciutat_Actual] && 
        centrals[central_Actual] <= ciutats[ciutat_Actual]) {
            // si la central actual pot proporcionar senyal a la ciutat actual,
            // llavors passem a la següent ciutat
            ciutat_Actual++;
        } else if (centrals[central_Actual] - r <= ciutats[ciutat_Actual] &&
        centrals[central_Actual] >= ciutats[ciutat_Actual]){
            // si la central actual pot proporcionar senyal a la ciutat actual,
            // llavors passem a la següent ciutat
            ciutat_Actual++;
        } else {
            // si la central actual NO pot proporciona senyal a la ciutat actual,
            // llavors passem a la següent central.
            central_Actual++;
        }
    }
    // Si hem cobert les n ciutats amb senyal, retornem true, sinó, false
    return ciutat_Actual == n;
    
}

signed main(){
    cin >> n >> m; // llegim n i m
    
    ciutats.resize(n); // actualitzem la capacitat del vector ciutats
    centrals.resize(m); // actualitzem la capacitat del vector centrals
    
    for (int i = 0; i < n; i++){
        cin >> ciutats[i]; // llegim les coordenades de les ciutats
    }
    
    for (int i = 0; i < m; i++){
        cin >> centrals[i]; // llegim les coordenades de les centrals
    }
    
    int dreta = 10e9;  // interval màxim de r
    int esquerra = -1; // interval mínim de r
    
    while (dreta > esquerra + 1){ // comença la cerca binària
        int mig = (dreta + esquerra) / 2; // agafem punt mig
        
        if (check(mig)){
            // si amb aquesta r podem donar senyal, minimitzem la dreta
            dreta = mig;
        } else {
            // si amb aquesta r NO podem donar senyal, augmentem l'esquerra
            esquerra = mig;
        }
    }
    
    cout << dreta << endl;
}
