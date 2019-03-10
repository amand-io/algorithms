#include "bits/stdc++.h"
#define MAX 100007
#define MID 10007
#define INF 1e9 + 7

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

struct node {
    ll val;
    node* l, *r;
    node() {}
    node(node* _l, node* _r, ll v) {
        l = _l;
        r = _r;
        val = v;
    }
};
 
node* version[2*MID];

ll check(node* no){
    return no? no->val: 0;
}

node* update(node* no, int l, int r, int x, ll value) {
    if (l == r) return new node(NULL, NULL, no->val+value);

    int mid = (l+r) / 2;

    node* ret = new node(no->l, no->r, 0);
    if(x <= mid) {
        if(no->l == NULL) ret->l = update(new node(NULL, NULL, 0), l, mid, x, value);
        else ret->l = update(no->l, l, mid, x, value);
    }else {
        if(no->r == NULL) ret->r = update(new node(NULL, NULL, 0), mid+1, r, x, value); 
        else ret->r = update(no->r, mid+1, r, x, value); 
    }
    ret->val = check(ret->l) + check(ret->r);
    //cout << ret->val << " " << l << " " << r << endl;
    return ret;
}
 
  
ll query(node* no, int l, int r, int x, int y) {
    if (x > r || y < l || l > r) return 0; 
    if (x <= l && r <= y) return no->val; 
    int mid = (l+r) >> 1;
    
    int q1 = (no->l != NULL)? query(no->l,l, mid,x,y): 0;
    int q2 = (no->r != NULL)? query(no->r,mid+1,r,x,y): 0;
    return q1 + q2;
}

int main(){
	return 0;
}