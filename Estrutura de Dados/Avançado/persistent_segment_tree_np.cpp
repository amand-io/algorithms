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
 
int update(int node, int l, int r, int p, int v){
	if(p < l || r < p) return node; 
	if(l == r){
		st[ptr].qt = st[node].qt + v;
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
 
int query(int a, int b, int l, int r, int k){
	if(l==r) return l;

	int mid = (l+r)>>1;

	int vv = st[st[b].l].qt - st[st[a].l].qt;
	if(vv >= k) return query(st[a].l, st[b].l, l, mid, k);
	return query(st[a].r, st[b].r, mid+1, r, k-vv);
}

int main(){
	return 0;
}