#include <bits/stdc++.h>
#define MAX 1000007

using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

ll h[MAX], power[MAX], inv[MAX];
ll base[2] = {317, 307};
ll mod[2] = {104000717, 104000711};

ll inverse(int a, int b, int s0 = 1, int s1 = 0){
    return b == 0? s0: inverse(b, a%b, s1, s0-s1*(a/b));
}

void init(){
    power[0] = inv[0] = 1;
    power[1] = base[0];
    inv[1] = inverse(base[0], mod[0]);

    for(int i = 2; i < MAX; i++){
        power[i] = (power[i-1]*power[1])%mod[0];
        inv[i] = (inv[i-1]*inv[1])%mod[0];
    }
}

ll build(string &s){
    h[0] = s[0];
    for(int i = 1; i < s.size(); i++){
        h[i] = (h[i-1] + (s[i]*power[i])%mod[0])%mod[0];
    }

    return h[s.size()-1];
}

ll sub(int l, int r){
    ll hr = h[r];
    ll hl = (l > 0)? h[l-1]:0;
    ll ans = ((hr+mod[0] - hl) * inv[l])%mod[0];
    return ans;
}

int main(){
    return 0;
}