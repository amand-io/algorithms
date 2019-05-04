#include <bits/stdc++.h>
#define MAX 1000007

using namespace std;

int parent[MAX], sz[MAX], resp;
vector<pair<int, pair<int, int> > > grafo;

int find(int a){
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void unhonho(int a, int b){
    int parentA = find(a);
    int parentB = find(b);
    if(parentA == parentB) return;

    if(sz[parentA] < sz[parentB]){
        parent[parentA] = parentB;
        sz[parentB] += sz[parentA];
    }else{
        parent[parentB] = parentA;
        sz[parentA] += sz[parentB];
    }
}

void kruskal(){
    for(int i = 0; i < MAX; i++) parent[i] = i;

    sort(grafo.begin(), grafo.end());

    resp = 0;
    for(int i = 0; i < grafo.size(); i++){
        int x = grafo[i].second.first;
        int y = grafo[i].second.second;
        if(find(x) != find(y)){
            unhonho(x,y);
            resp += grafo[i].first;
        }
    }
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a, b , c;
        cin >> a >> b >> c;
        grafo.push_back(make_pair(c, make_pair(a, b)));
    }

    kruskal();
    cout << resp << endl;
    return 0;
}

