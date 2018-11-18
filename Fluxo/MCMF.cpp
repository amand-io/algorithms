#include <bits/stdc++.h>
#define MAX 10007
#define INF 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct edge{
    int to, cap, cost, rev;

    edge(int _to, int _cap, int _cost, int _rev): to(_to), cap(_cap), cost(_cost), rev(_rev){}
};

struct cost{
    vector<edge> graph[MAX];
    int pre[MAX], pre_e[MAX], inq[MAX], F, C;
    int dist[MAX];

    cost(){
        F = 0;
        C = 0;
        fill(graph, graph+MAX, vector<edge>());
    }

    void add(int from, int to, int cap, int cost){
        graph[from].push_back(edge(to, cap, cost, graph[to].size()));
        graph[to].push_back(edge(from, 0, -cost, graph[from].size()-1));
    }

    bool bfs(int ini, int fim){
        fill(dist, dist+MAX, INF);
        fill(inq, inq+MAX, 0);

        dist[ini] = 0;
        queue<int> q;
        q.push(ini);
        while(!q.empty()){
            int u = q.front();
            q.pop();

            inq[u] = 0;
            for(int i = 0; i < graph[u].size(); i++){
                int v = graph[u][i].to;
                int w = graph[u][i].cost;
                if(graph[u][i].cap > 0 && dist[v] > dist[u]+w){
                    pre[v] = u;
                    pre_e[v] = i;
                    dist[v] = dist[u] + w;
                    if(!inq[v]){
                        inq[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        return dist[fim] != INF;
    }
    pii flow(int ini, int fim){
        while(bfs(ini, fim)){
            int tf = INF;
            for(int v = fim, u, l; v != ini; v = u){
                u = pre[v];
                l = pre_e[v];
                tf = min(tf, graph[u][l].cap);
            }

            for(int v = fim, u, l; v != ini; v = u){
                u = pre[v];
                l = pre_e[v];
                graph[u][l].cap -= tf;
                graph[v][graph[u][l].rev].cap += tf;
            }
            C += tf*dist[fim];
            F += tf;
        }
        return make_pair(F, C);
    }
};

int T = 0, P = MAX-1;
int main(){
    return 0;
}