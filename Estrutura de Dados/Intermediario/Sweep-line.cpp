#include <bits/stdc++.h>
#define ls (rt<<1)
#define rs ((rt<<1)|1)
#define MAX 200007
#define INF 0x3F3F3F3F


using namespace std;
typedef long long ll;


int n;

struct node{
    int x1, x2, y, type;
    bool operator <(const node&b) const{
        return y < b.y;
    }
} e[MAX];

int h[MAX];
ll len[MAX<<3], cover[MAX<<3];

void pushup(int rt, int l, int r){
    if(cover[rt]>0) len[rt] = h[r]-h[l];
    else{
        if(l==r) len[rt] = 0;
        else len[rt] = len[ls] + len[rs];
    }
}

void update(int rt, int l, int r, int L, int R, int v){
    if(l==r) return;
    if(L <= l && r <= R) cover[rt]+=v;
    else{
        int mid = (l+r)/2;
        if (mid > L) update(ls, l, mid, L, R, v);
        if (mid < R) update(rs, mid, r, L, R, v);
    }
    pushup(rt, l, r);
}

int main(){
	while(scanf("%d", &n) != EOF){
		memset(len, 0, sizeof(len));
		memset(cover, 0, sizeof(cover));
		
		int res = 0;
		for(int i = 1; i <= n; i++){
			int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			if(x1>x2 || y1>y2) swap(x1, x2), swap(y1, y2);
			--x1, --y1;
			e[res] = {x1, x2, y1, 1}; h[res++] = x1; 
			e[res] = {x1, x2, y2,-1}; h[res++] = x2; 
		}
		sort(h, h+res); res = unique(h, h+res) - h;
		sort(e, e+2*n);
		
		ll ans = 0;
		for(int i = 0; i < 2*n-1; i++){
			int L = lower_bound(h, h+res, e[i].x1) - h;
			int R = lower_bound(h, h+res, e[i].x2) - h;
			update(1, 0, res-1, L, R, e[i].type);
			ans += (ll)len[1] * (e[i+1].y-e[i].y);
		}
		printf("%lld\n", ans);
	}
}