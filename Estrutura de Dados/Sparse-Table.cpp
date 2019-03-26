#include <bits/stdc++.h>
#define MAX 100007
#define LG 20

using namespace std;
typedef long long ll;

ll N,a[MAX], sptable[LG][MAX];

void build() {
    for(int i=0;i<N;i++) sptable[0][i] = a[i];

    for(int i = 1; (1 << i) <= N; i++){
        for(int j=0; j + (1 << i) <= N; j++){
            sptable[i][j] = min(sptable[i-1][j], sptable[i-1][j + (1 << (i-1))]);
        }
    }
}

ll query(int a, int b) {
    if(a > b) swap(a,b);
    int lg = __builtin_clz(1) - __builtin_clz(b - a + 1);

    return min(sptable[lg][a], sptable[lg][b -(1 << lg)+1]);
}

int main(){
    return 0;
}