#include <bits/stdc++.h>
#define MAX 100007

using namespace std;

typedef long long ll;

ll h[4*MAX], power[MAX], inv[MAX];
ll base[2] = {317, 307};
ll mod[2] = {104000717, 104000711};
int n;

ll gcd(ll a, ll m){
    ll x = 1, y = 0, ini = m;
    if(m == 1) return 0;

    while(a > 1){
        ll q = a/m;

        ll t = m;
        m = a%m;
        a = t;
        t = y;
        y = x-q*y;
        x = t;
    }

    if(x < 0) x += ini;
    return x;
}

void init(){
    power[0] = base[0];
    inv[0] = gcd(base[0], mod[0]);
    cout << inv[0] << endl;
    for(int i = 1; i < MAX; i++){
        power[i] = (power[i-1]*base[0])%mod[0];
        inv[i] = (inv[i-1]*inv[0])%mod[0];
    }
}

void update(int idx, char now, char old = '$'){
    cout << now << " " << old << endl;
    int pos = idx;
    if(old == '$') for(; idx <= n; idx += idx&(-idx)) h[idx] = (h[idx] + (now-'a'+1)*power[pos])%mod[0];
    else{
        for(; idx <= n; idx += idx&(-idx)) {
            h[idx] = (h[idx] - (old-'a'+1)*power[pos])%mod[0];
            while(h[idx] < 0) h[idx] += mod[0];
            h[idx] = (h[idx] + (now-'a'+1)*power[pos])%mod[0];
            while(h[idx] < 0) h[idx] += mod[0];
        }
    }
}
void getHash(string s){
    for(int i = 1; i <= s.size(); i++) update(i, s[i-1]);
}

ll query(int idx){
    ll hash = 0;
    for(; idx > 0; idx -= idx&(-idx)) hash = (hash + h[idx])%mod[0];
    return hash;
}

ll query(int l, int r){
    return (((query(r)-query(l-1)+ mod[0])%mod[0])*inv[l])%mod[0];
}
int main(){
    string txt; cin >> txt;
    n = txt.size();
    init();
    getHash(txt);
    int k; cin >> k;
    while(k--){
        int tipo; cin >> tipo;
        if(!tipo){
            int l, r; cin >> l >> r;
            cout << query(l, r) << endl;
        }else{
            int idx;
            char letra; cin >> idx >> letra;
            update(idx, letra, txt[idx-1]);
            txt[idx-1] = letra;
        }
    }
    return 0;
}