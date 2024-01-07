#include <bits/stdc++.h>
using namespace std;

int nodes, arestes;
vector<int> adj[10000], dist(nodes+1);
bool vis[100001];

void bfs(){ 
    int nodeInicial; cin >> nodeInicial;
    queue<int> q;
    q.push(nodeInicial);
    vis[nodeInicial] = true;
    dist[nodeInicial] = 0;

    while (!q.empty()){
        int node = q.front(); q.pop();
        for (auto vei : adj[node])
            if (!vis[vei]){
                q.push(vei);
                vis[vei] = true;
                dist[vei] = dist[node] + 1;
            }
    }
}
int main(){
    cin >> nodes >> arestes; 
    for (int i = 0, nodeA, nodeB; i < arestes; i++){
        cin >> nodeA >> nodeB;
        adj[nodeA].push_back(nodeB);
        adj[nodeB].push_back(nodeA);
    }
    bfs();
    cout << "Aquests son les distancies a la que estan els nodes del node inicial:\n";
    for (int i = 1; i <= nodes; i++){
        cout << "Distancia fins el node " << i << ": " << dist[i] << endl;
    }
        
}

// 5 4
// 1 2
// 1 3
// 2 4
// 2 5
// 1
