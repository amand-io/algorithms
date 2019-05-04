#include <bits/stdc++.h>
#define MAX 200007

using namespace std;
typedef pair<int, int> pii;
int seg[4*MAX], acum[4*MAX], menor[4*MAX];

void build(int id, int l, int r){
    if(l == r) seg[id] = 1;
    else{
        int mid = (l+r)/2;
        build(2*id, l, mid);
        build(2*id+1, mid+1, r);
        seg[id] = seg[2*id] + seg[2*id+1];
    }
}
void add(int id, int l, int r, int val){
    menor[id] += val; 
    acum[id] += val;
}
void update(int id, int l, int r, int x, int y, int val){ 
    if(l > y || r < x) return;
    else if( x <= l && r <= y)  add(id, l, r, val);
    else{
        int mid = (l+r)/2;
        add(2*id,l, mid, acum[id]);      //LAZY
        add(2*id+1, mid+1, r, acum[id]);// LAZY
        acum[id] = 0;                  //  LAZY

        update(2*id, l, mid, x, y, val);
        update(2*id+1, mid+1, r, x, y, val);

        menor[id] = min(menor[2*id], menor[2*id+1]);
        seg[id] = (menor[2*id] <= menor[2*id+1])? seg[2*id]: seg[2*id+1];
        seg[id] += (menor[2*id] == menor[2*id+1])? seg[2*id+1]: 0;
    }
}

int query(int id, int l, int r, int x, int y){
    if(l > y || r < x) return 0;
    else if( x <= l && r <= y) return seg[id];
    else{
        int mid = (l+r)/2;
        return query(2*id, l, mid, x, y) + query(2*id+1, mid+1, r, x, y);
    }
}

int main(){
    int n, q; scanf("%d %d", &n, &q);
    build(1, 1, n);
    return 0;
}