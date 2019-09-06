#include "bits/stdc++.h"
#define MAX 100007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

struct Node {
	int qt, l, r;
	Node():qt(0),l(0),r(0){}
} st[100*MAX];

int ptr = 1;

int nl(int value, int l, int r) {
    int p = ++ptr;
    st[p].l = l;
	st[p].r = r;
    st[p].qt = value;
    return p;
}

int update(int node, int l, int r, int p, int v){
	if(p < l || r < p) return node; 
	if(l == r) return nl(st[node].qt + v, st[node].l, st[node].r);

	int mid = (l+r)>>1;
	int fe = update(st[node].l, l, mid, p, v);
	int fd = update(st[node].r, mid+1,r,p, v);

	return nl(st[fe].qt + st[fd].qt, fe, fd);
}

int cpy(int node, int ins, int l, int r, int x, int y){
    if(y < l || r < x) return node;
    if(x <= l && r <= y) return ins;
 
    int mid = (l+r)>>1;
    int fe = cpy(st[node].l, st[ins].l, l, mid, x, y);
    int fd = cpy(st[node].r, st[ins].r, mid+1,r,x, y);

    return nl(st[fe].qt + st[fd].qt, fe, fd);
}
int main(){
	return 0;
}