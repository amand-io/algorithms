#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > grafo;
vector<pair<int, int> > env; // first = visitados, second = queue

bool ciclo(int no){
    env[no].second = true;
    env[no].first = true;

    for(int i = 0;i < grafo[no].size(); i++){
        if(!env[grafo[no][i]].first){
            if (ciclo(grafo[no][i])) return true;

        } if (env[grafo[no][i]].second) return true;//se ele foi acessado verifica se ele esta na fila
    }
    env[no].second = false;
    return false;
}