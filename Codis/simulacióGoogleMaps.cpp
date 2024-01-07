#include <bits/stdc++.h>
using namespace std;

int ciutats, carreteres; 
// nombre de ciutats i carreteres

int ciutatInicial, ciutatFinal;

vector<vector<pair<int,int>>> adjacents;
// vector de nodes adjacents a cada node

vector<int> dijkstra(int nodeInicial){

    vector<int> pare(ciutats + 1, 0); // llista de pares
    vector<int> dist(ciutats + 1, INF); // llista de distancies

    priority_queue<pair<int,int>> cua; // distància - node
    cua.push({0, nodeInicial}); // afegim a la cua node 0 amb distància 0

    dist[nodeInicial] = 0;
    pare[ciutatInicial] = 0;

    while (!cua.empty()){
        int nodeActual = cua.top().second; 
        // agafem el node amb menys distància
        int distanciaActual = cua.top().first;
        cua.pop(); // traiem el node de la cua
        
        if (abs(distanciaActual) > dist[nodeActual]) continue;
        // si el valor absolut de la distància del nodeActual és menor,
        // no la volem actualitzar
        
        for (auto parella : adjacents[nodeActual]){ // mirem els nodes adjacents
            int nodeAdjacent = parella.first;
            int distancia = parella.second;
            
            if (dist[nodeActual] + distancia < dist[nodeAdjacent]){
                // si podem acurtar la distancia al nodeAdjacent mitjançant
                // el nodeActual, l'actualitzem
                dist[nodeAdjacent] = dist[nodeActual] + distancia;

                // actualitzem el pare
                pare[nodeAdjacent] = nodeActual;

                // afegim la nova distància i el nodeAdjacent
                cua.push({-dist[nodeAdjacent], nodeAdjacent});
            }
        }
    }

    vector<int> cami;

    int ciutatCami = ciutatFinal;
    cami.push_back(ciutatCami);

    while (ciutatCami != 0){
        dbg(ciutatCami)
        ciutatCami = pare[ciutatCami];
        // mirem l'anterior ciutat 
        // per la qual hem de passar
        cami.push_back(ciutatCami);
    }
    cami.pop_back();

    reverse(cami.begin(), cami.end());

    return cami;
}





int main(){
    cin >> ciutats >> carreteres;
    
    adjacents.resize(ciutats + 1);
    

    for (int i = 0; i < carreteres; i++){
        int ciutatA, ciutatB, llargada; 
        cin >> ciutatA >> ciutatB >> llargada;

        adjacents[ciutatA].push_back({ciutatB, llargada});
        adjacents[ciutatB].push_back({ciutatA, llargada});
        // llegeixo el graf
    }

    int nombreCiutatsQuePasso; cin >> nombreCiutatsQuePasso;
    // nombre de ciutats que passo durant tota la ruta

    vector<int> ciutatQuePasso(nombreCiutatsQuePasso);


    for (int i = 0; i < nombreCiutatsQuePasso; i++){
        cin >> ciutatQuePasso[i];
        // llegeixo totes les ciutats que passo durant la ruta
    }

    ciutatInicial = ciutatQuePasso[0];
    // ciutat en la qual començo la ruta
    ciutatFinal = ciutatQuePasso[nombreCiutatsQuePasso - 1];
    // ciutat en la qual acabo la ruta

    for (int i = 0; i < nombreCiutatsQuePasso; i++){
        int ciutatActual = ciutatQuePasso[i];

        vector<int> camiOptim = dijkstra(ciutatActual);
        // agafo el cami òptim per arribar a la ciutat final


        cout << "Cami òptim des de la ciutat actual: " << endl;

        for (int j = 0; j < camiOptim.size(); j++){
            cout << camiOptim[j] << " ";
            // imprimim el cami optim 
        }
        cout << endl;
    }
}
