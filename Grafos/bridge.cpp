#define MAX 20007
using namespace std;
 
bitset<MAX> vis;
vector<int> graph[MAX];
int sz, n, q, ans, num[MAX], parent[MAX], low[MAX];
 
void dfs(int no){
    vis[no] = true;
    num[no] = low[no] = sz++;
    for(int i = 0; i < graph[no].size(); i++){
        int child = graph[no][i];
        if(!vis[child]){
            parent[child] = no;
            dfs(child);
            if(low[child] > num[no]) ans++;
            low[no] = min(low[no], low[child]);
        }else if(child != parent[no]) low[no] = min(low[no], num[child]);
    }
}
 
void ponte(){
    sz = 0;
    ans = 0;
    vis.reset();
    memset(low, -1, sizeof low);
    memset(num, -1, sizeof num);
    memset(parent, -1, sizeof parent);
    dfs(1);
}
int main(){
    while(cin >> n >> q){
        for(int i = 0; i <= n; i++){
            graph[i].clear();
        }
        for(int i = 0; i < q; i++){
            int a, b; cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        ponte();
        cout << ans << endl;
    }
    return 0;
}