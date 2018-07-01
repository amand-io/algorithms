#include <bits/stdc++.h>
#define MAX 100007

using namespace std;

bitset<MAX> vis;
vector<int> graph[MAX];
int ans[MAX];

void cover(int no){
    int cont = 0;
    for(int i = 0; i < graph[no].size(); i++){
        int filho  = graph[no][i];
        if(!vis[filho]){
            vis[filho] = true;
            cont = dfs(filho) || cont;
        }
    }

    ans[no] = cont;
    return !cont;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vis[1] = true;
    cover(1);
    return 0;
}