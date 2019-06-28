#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;

struct node{
    ll val, acum;
    node *l, *r;
 
    node(){
        val = acum = 0;
        l = r = NULL;
    }
} *root;

void init(){
    root = new node();
}
void add(node* no,ll l, ll r, ll v){
    no->val += (r-l+1)*v;
    no->acum += v;
}
 
void update(node* no, ll l, ll r, ll x, ll y, ll v){
    if(r < x || y < l) return;
    else if(x <= l && r <= y) add(no, l, r,  v);
    else{
        ll mid = (l+r)/2;
 
        no->l = (no->l == NULL)? new node(): no->l;
        no->r = (no->r == NULL)? new node(): no->r;
        add(no->l, l, mid, no->acum);
        add(no->r, mid+1, r,no->acum);
        no->acum = 0;
 
        update(no->l, l, mid, x, y, v);
        update(no->r, mid+1, r, x, y, v);
 
        no->val = no->l->val + no->r->val;
    }
}
 
ll query(node* no, ll l, ll r, ll x, ll y){
    if(r < x || y < l) return 0;
    else if(x <= l && r <= y) return no->val;
    else{
        ll mid = (l+r)/2;
 
        no->l = (no->l == NULL)? new node(): no->l;
        no->r = (no->r == NULL)? new node(): no->r;
        add(no->l, l, mid, no->acum);
        add(no->r, mid+1, r,no->acum);
        no->acum = 0;
 
        return query(no->l, l, mid, x, y) +
               query(no->r, mid+1, r, x, y);
 
    }
}

int main(){
    ll n, q; cin >> n >> q;
    
    init();
    while(q--){
        ll t; cin >> t;
        
        if(t == 1){
            ll l, r, v; cin >> l >> r >> v;
            update(root, 0, n-1, l, r, v);
        }else{
            ll l, r; cin >> l >> r;
            cout << query(root, 0, n-1, l, r) << endl;
        }
    }
    return 0;
}