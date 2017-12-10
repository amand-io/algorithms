#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b){
    if(b == 0) return a;
    return mdc(b, a%b);
}

int mmc(int a, int b){
    return a*b/mdc(a,b);
}

int main(){
    int n, m;

    cin >> n >> m;
    printf("mdc = %d\n", mdc(n,m));
    printf("mmc = %d\n", mmc(n,m));
    return 0;
}