#include <bits/stdc++.h>
#define MAX 200007
#define BUCKET 2500

using namespace std;

typedef long long ll;

struct upd{int pos,velho,novo;};
struct que{int l,r,t,id;};

bool comp(que A,que B){
    
	if(A.l/BUCKET != B.l/BUCKET ) return A.l/BUCKET < B.l/BUCKET;
	if(A.r/BUCKET != B.r/BUCKET) return A.r/BUCKET < B.r/BUCKET;
	return A.t < B.t;
}

int mleft,mright,mtime;
int freq[MAX],arr[MAX],angry[MAX];
ll exibir[MAX],resp;
vector<que> Q;
vector<upd> U;

void add(int val){
	freq[val]++;
	resp += (freq[val] == 1);
    resp -= (freq[val] == 2);
}
void remove(int val){
	resp -= (freq[val] == 1);
    resp += (freq[val] == 2);
	freq[val]--;
}
void update(int idx,int novo){
	if(mleft <= idx && idx <= mright){
		remove(arr[idx]);
		arr[idx] = novo;
		add(arr[idx]); 
	}else arr[idx] = novo;
}
void query(int idx){
    // Tempo
	for(int t = mtime+1;t<=Q[idx].t; t++) update(U[t-1].pos,U[t-1].novo);
	for(int t = mtime;t>Q[idx].t; t--) update(U[t-1].pos,U[t-1].velho);

    // Add
	for(int i = mright + 1;i <= Q[idx].r; i++) add(arr[i]);
	for(int i = mleft - 1;i >= Q[idx].l; i--) add(arr[i]);

    // Remove
	for(int i = mright;i > Q[idx].r; i--) remove(arr[i]);
	for(int i = mleft;i<Q[idx].l; i++) remove(arr[i]);
	mleft = Q[idx].l; mright = Q[idx].r; mtime = Q[idx].t;
	exibir[Q[idx].id] = resp;
}

void mos(int n){
    sort(Q.begin(),Q.end(),comp);
	for(int i = 0;i < n;i++) add(arr[i]);
	mleft = 0; mright = n-1;
	for(int i = 0; i < Q.size();i++) query(i);
}
int main(){
	int n, q; scanf("%d %d",&n, &q);
	for(int i = 0; i< n; i++) scanf("%d", &arr[i]);

    mtime = 0;
	for(int i = 0; i < q;i++){
		int tipo,l ,r; scanf("%d %d %d",&tipo,&l,&r);
		if(tipo == 2){
			que aux;
			aux.l = l; aux.r = r; aux.t = mtime; aux.id = i;
			Q.push_back(aux);
		}else{
			mtime++;
			upd aux;
			aux.pos = l; aux.velho = arr[l]; aux.novo = r;
			arr[l] = r;
			U.push_back(aux);
			exibir[i] = -1;
		}
	}
	mos(n);
	for(int i = 0;i < q; i++) {
        if(exibir[i] != -1) printf("%lld\n",exibir[i]);
    }
	return 0;
} 