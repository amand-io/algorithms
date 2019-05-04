#include <bits/stdc++.h>
#define LOG 20
#define MAX 100007

using namespace std;

int parent[LOG][MAX], vis[MAX], level[MAX];
vector<int> graph[MAX];

void dfs(int no){
    vis[no] = true;
    for(int i = 0; i < graph[no].size(); i++){
        int v = graph[no][i];
        if(!vis[v]){
            parent[0][v] = v;
            level[v] = level[no] + 1;
            dfs(v);
        }
    }
}

void build(){
    for(int i = 1; i < LOG; i++){
        for(int j = 0; j < MAX; j++){
            parent[i][j] = parent[i-1][parent[i-1][j]];
        }
    }
}

int lca(int a, int b){
    if(level[a] < level[b]) swap(a, b);

    int lg;
    for(int lg = 1; (1 << lg) <= level[a]; lg++); lg--;
    for(int i = lg; i >= 0; i--){
        if(level[parent[i][a]] >= level[b]) a = parent[i][a];
    }

    if(a == b) return a;

    for(int i = lg; i >= 0; i--){
        if(parent[i][a] != parent[i][b]){
            a = parent[i][a];
            b = parent[i][b];
        }
    }

    return parent[0][a];
}
int main(){
    return 0;
}