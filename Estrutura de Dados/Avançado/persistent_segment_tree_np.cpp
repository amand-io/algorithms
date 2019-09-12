#include "bits/stdc++.h"
#define MAX 100007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

struct Node {
    int qt, l, r;
    Node():qt(0),l(0),r(0){}
} st[40*MAX];
 
int ptr = 1;
 
int update(int node, int l, int r, int p, int v){
    if(p < l || r < p) return node;
    if(l == r){
        st[ptr].qt = v;
        st[ptr].l = st[node].l;
        st[ptr].r = st[node].r;
        return ptr++;
    }
 
    int mid = (l+r)>>1;
    int fe = update(st[node].l, l, mid, p, v);
    int fd = update(st[node].r, mid+1,r,p, v);
 
    st[ptr].qt = st[fe].qt + st[fd].qt;
    st[ptr].l = fe;
    st[ptr].r = fd;
    return ptr++;
}
 
int version[MAX], a[MAX], lst[MAX];
int kth(int node, int l, int r, int v){
    if(l == r) return l;

    int mid = (l+r)/2;
    int vv = st[st[node].l].qt;
    if(vv >= v) return kth(st[node].l, l, mid, v);
    else return kth(st[node].r, mid+1, r, v-vv);
}

int main(){return 0;}