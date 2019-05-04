#include <bits/stdc++.h>
#define MAX 1000007

using namespace std;
int seg[4*MAX], acum[4*MAX], arr[MAX];

void build(int id, int l, int r){
    if(l == r) seg[id] = arr[l];
    else{
        int mid = (l+r)/2;
        build(2*id, l, mid);
        build(2*id+1, mid+1, r);

        seg[id] = seg[2*id] + seg[2*id+1];
    }
}

void update(int id, int l, int r, int val, int x){
    if(l == r) seg[id] = val;
    else{
        int mid = (l+r)/2;
        if(mid >= x) update(2*id, l, mid, val, x);
        else update(2*id+1, mid+1, r, val, x);

        seg[id] = seg[2*id] + seg[2*id+1];
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
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    build(1, 0, n-1);
    return 0;
}