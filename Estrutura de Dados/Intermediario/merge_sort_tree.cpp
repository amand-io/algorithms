#include <bits/stdc++.h>
#define MAX 500007
#define INF 1e18 + 7
#define all(a) a.begin(),a.end()

using namespace std;
typedef long long ll;

ll acum[MAX];
 
vector<ll> seg[5*MAX];
void build(int cur, int l, int r){
    if(l == r) seg[cur].push_back(acum[l]);
    else{
        int mid = (l+r)/2;
        build(2*cur, l , mid ); // Build left seg 
        build(2*cur+1, mid+1 , r); // Build right seg
        seg[cur].assign(r-l+1, 0);
        merge(all(seg[2*cur]), all(seg[2*cur+1]), seg[cur].begin());
    }
}
 
ll query(int cur, int l, int r, int x, int y, ll k){
    if( r < x || l > y ) return 0LL; //out of range
    if(x<=l && r<=y ){
        //Binary search over the current sorted vector to find elements smaller than K
        auto part = upper_bound(all(seg[cur]), k);
        return part-seg[cur].begin();
    }
    int mid=l+(r-l)/2;
    return query(2*cur, l, mid, x, y, k) + query(2*cur+1, mid+1, r, x, y, k);
}

int main(){
    return 0;
}