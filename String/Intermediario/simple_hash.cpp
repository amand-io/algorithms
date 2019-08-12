#include <bits/stdc++.h>
#define MAX 1000007
#define HMAX 2
 
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
 
 
ll inverse(int a, int b, int s0 = 1, int s1 = 0){
    return b == 0? s0: inverse(b, a%b, s1, s0-s1*(a/b));
}
 
ll base[HMAX] = {317, 307};
ll mod[HMAX] = {104000717, 104000711};
ll power[HMAX][MAX], inv[HMAX][MAX];
 
struct H{
    ll h[HMAX][MAX];
    int n;
 
    void init(){
        for(int k = 0; k < HMAX; k++){
            power[k][0] = inv[k][0] = 1;
            power[k][1] = base[k];
            inv[k][1] = inverse(base[k], mod[k]);
            for(int i = 2; i < MAX; i++){
                power[k][i] = (power[k][i-1]*power[k][1])%mod[k];
                inv[k][i] = (inv[k][i-1]*inv[k][1])%mod[k];
            }
        }
    }
    H() { 
        n = 0;
    }
 
    H(char *s){
        n = 0;
        int m = strlen(s);
        for(int i = 0; i < m; i++) add(s[i]);
    }
    vector<ll> add(char s){
        vector<ll> ret;
 
        for(int k = 0; k < HMAX; k++){
            ll past = (n-1 < 0)? 0LL:h[k][n-1];
            h[k][n] = (past + (s*power[k][n])%mod[k])%mod[k];
            ret.push_back(h[k][n]);
        }
        n++;
        return ret;
    }
 
    vector<ll> sub(int l, int r){
        vector<ll> ret;
        for(int k = 0; k < HMAX; k++){
            ll hr = h[k][r];
            ll hl = (l > 0)? h[k][l-1]:0;
            ll inter = ((hr+mod[k] - hl) * inv[k][l])%mod[k];
 
            ret.push_back(inter);
        }
 
        return ret;
    }
};
 
bool hcmp(vector<ll> a, vector<ll> b){
    for(int i = 0; i < HMAX; i++){
        if(a[i] != b[i]) return false;
    }    
 
    return true;
}
int main(){
    return 0;
}