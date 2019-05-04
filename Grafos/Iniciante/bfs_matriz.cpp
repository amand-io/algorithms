#include <bits/stdc++.h>
#define MAX 1000007
#define pii pair<int,int>

using namespace std;

bitset<MAX> vis;
int dist[MAX],n, m;

int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, -1, 1};

bool check(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m && !vis[(x*m) + y];
}
void bfs(pii no){
    queue<pii> q;

    vis[(no.first*m) + no.second] = true;
    dist[(no.first*m) + no.second] = 1;
    
    q.push(no);
    while(!q.empty()){
        pii top = q.front();
        q.pop();

        for(int i = 0; i < 4; i++){
            int x = top.first + mx[i];
            int y = top.second + my[i];
            if(check(x,y)){
                dist[(x*m) + y] = dist[(top.first*m)+top.second] + 1;
                vis[(x*m) + y] = true;
                q.push(make_pair(x,y));
            }
        }
        
    }
}
