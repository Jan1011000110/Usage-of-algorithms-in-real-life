#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj; // llista d'adjacència
vector<int> dist, used; // llista de distàncies

void dijkstra(){
    priority_queue<pair<int,int>> cua; // dist - node
    cua.push({0, 0}); // afegim a la cua node 0 amb distància 0

    while (!cua.empty()){
        int nodeActual = cua.top().second; // agafem el node 
                                            // amb menys distància
        cua.pop(); // traiem el node de la cua
        
        if (used[nodeActual]) continue;
        used[nodeActual] = 1;
        
        for (auto u : adj[nodeActual]){  // mirem els nodes adjacents
            int nodeAdjacent = u.first;
            int distància = u.second;      
            
            if (used[nodeAdjacent]) continue;

            if (dist[nodeActual] + distància < dist[nodeAdjacent]){ 
                // si podem acurtar la distancia al nodeAdjacent mitjançant
                // el nodeActual, l'actualitzem
                dist[nodeAdjacent] = dist[nodeActual] + distància;
                // afegim la nova distància i el nodeAdjacent
                cua.push({-dist[nodeAdjacent], nodeAdjacent});
            }
        }
    }
}


void solve(){
    int n,m; cin >> n >> m;
    adj.resize(n);
    dist.assign(n, INF);
    used.assign(n, 0);
    dist[0] = 0;
    for (int i=0; i<m; i++){
        int a,b,w; cin >> a >> b >> w;
        a--; b--;
        adj[a].pb({b,w});
        adj[b].pb({a,w});
    }
    dijkstra();

    for (int i=0; i<n; i++){
        cout << dist[i] << " ";
    }
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //int tt; cin >> tt;
    int tt = 1; 
    while(tt--){
        solve();
    }
    return 0;
}
