#include <bits/stdc++.h>
#define MAX 1 << 17
#define LOGN 17
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll inverse_m(ll a, ll b, ll s0 = 1LL, ll s1 = 0LL){
    return b == 0? s0: inverse_m(b, a%b, s1, s0-s1*(a/b));
}

// OR em que o AND é 0
vector<ll> ORANDO(vector<ll> &a) {
    vector<ll> ans(MAX, 0LL);
    for (int i = 0; i < MAX; i++){
        for (int j = i; j >= 0; j = (j-1)&i){ 
            ll mult = a[i^j]*a[j];
            ans[i] = (ans[i] + mult)%MOD;
            if(j == 0) break;
        }
    }

    return ans;
}

int T[3][2][2][2] = {
    { { {1,  1}, {1, -1} }, { {1,  1}, {1, -1} } }, /// xor
    { { {0,  1}, {1,  1} }, { {-1, 1}, {1,  0} } }, /// and
    { { {1,  1}, {1,  0} }, { {0,  1}, {1, -1} } }  /// or
};
 
void FFT(vector<ll> &a, int op, bool inverse = false) {
    ll u1 = T[op][inverse][0][0], v1 = T[op][inverse][0][1];
    ll u2 = T[op][inverse][1][0], v2 = T[op][inverse][1][1];
 
    for(int b = 0; b < LOGN; b++)
        for(int i = 0; i < MAX; i++)
            if((i & (1 << b)) == 0) {
                ll u = a[i], v	 = a[i + (1 << b)];
                a[i] = (u*u1) + (v*v1);
                if(a[i] >= MOD) a[i] -= MOD;
                if(a[i] < 0) a[i] += MOD;

                a[i + (1 << b)] = (u*u2) + (v*v2);
                if(a[i + (1 << b)] >= MOD) a[i + (1 << b)] -= MOD;
                if(a[i + (1 << b)] < 0) a[i + (1 << b)] += MOD;
            }
 
	if (op == 0 && inverse){
        ll inv = inverse_m(1 << 17, MOD);
		for (int i=0; i<a.size(); i++) a[i] = (a[i]*inv)%MOD;
    }
}
 
/// op is 0 for XOR, 1 for AND, 2 for OR
vector<ll> convolution(vector<ll> a, vector<ll> b, int op) {
    FFT(a, op, false);
    FFT(b, op, false);
    for(int i=0; i<a.size(); i++)
        a[i] = (a[i] * b[i])%MOD;
    FFT(a, op, true);
    return a;
}

void print(vector<ll> &a, int sz){
    for(int i = 0; i < sz; i++) cout << a[i] << " ";
    cout << endl;
}
int main(){
    
    return 0;
}