#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m; cin >> n >> m;
    vector<vector<char>> mapa(n+1,vector<char>(m+1));
    vector<vector<int>> dp(n+1, vector<int>(m+1));

    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> mapa[i][j];
    dp[1][1] = 1;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
        if (mapa[i][j] == 'X') continue;
        if (i == 1 && j > 1)
            dp[i][j] = dp[i][j-1];
         else if (j == 1 && i > 1)
            dp[i][j] = dp[i-1][j];
         else if (i > 1 && j > 1)
            dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
        }
    }
    cout << dp[n][m] << endl;
}
