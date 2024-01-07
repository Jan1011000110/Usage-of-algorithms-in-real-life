#include <bits/stdc++.h>
using namespace std;

int nodes, arestes;
vector<int> adj[10000];
bool vis[100001];
vector<int> allNodes;

void dfs(){ 
    int nodeInicial; cin >> nodeInicial;
    stack<int> s;
    s.push(nodeInicial);

    while (!s.empty()){
        int node = s.top(); s.pop();
        vis[node] = true;
        allNodes.push_back(node);
        for (auto vei : adj[node])
            if (!vis[vei])
                s.push(vei);
    }
}


int main(){
    cin >> nodes >> arestes;
    
    for (int i = 0, nodeA, nodeB; i < arestes; i++){
        cin >> nodeA >> nodeB;
        adj[nodeA].push_back(nodeB);
        adj[nodeB].push_back(nodeA);
    }
    dfs();
    cout << "Aquests son tots els nodes als que es poden arribar desde el node inicial:\n"   ;
    for (auto node : allNodes)
        cout << node << " ";
}


