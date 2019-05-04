#include <bits/stdc++.h>
#define MAX 100007
#define INF 1e9 + 7

using namespace std;

typedef struct item * pitem;
struct item {
    int prior, value, cnt;
    long long sum, lazy;
    bool rev;
    pitem l, r;
	
};

pitem create(int val){
	pitem a = new item();
	a->prior = rand();
	a->value = val;
	return a;
}
int cnt (pitem it) {
    return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
    if (it)
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void lazy(pitem t){
    if(!t || !t->lazy)return;
    t->value += t->lazy;//operation of lazy
    t->sum += t->lazy*cnt(t);
    if(t->l) t->l->lazy += t->lazy;//propagate lazy
    if(t->r) t->r->lazy += t->lazy;
    t->lazy=0;
}
void reset(pitem t){
    if(t)t->sum = t->value;//no need to reset lazy coz when we call this lazy would itself be propagated
}
void combine(pitem& t,pitem l,pitem r){//combining two ranges of segtree
    if(!l || !r)return void(t = l?l:r);
    t->sum = l->sum + r->sum;
}
void operation(pitem t){//operation of segtree
    if(!t)return;
    reset(t);//reset the value of current node assuming it now represents a single element of the array
    lazy(t->l);lazy(t->r);//imp:propagate lazy before combining t->l,t->r;
    combine(t,t->l,t);
    combine(t,t,t->r);
}

void merge (pitem & t, pitem l, pitem r) {
    lazy(l);
    lazy(r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
    operation(t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    
    lazy(t);
    int cur_key = add + cnt(t->l);
    if (key < t->value)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
    operation(t);
}


void output (pitem t) {
    if (!t)  return;
    output (t->l);
	cout << t->value << " ";
    output (t->r);
}

void print(pitem it){
	cout << it->value << " " << it->prior << endl;
}

int main() { 
    pitem root = create(-INF);
    return 0; 
} 