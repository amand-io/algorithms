#include <bits/stdc++.h>

using namespace std;

long long int fast(long long int a, long long int b){
    if(b == 0) return 1;
    if(b%2 == 0){
        int x = fast(a, b/2);
        return x*x;
    } 
    return fast(a, b-1)*a;
}

int main(){
    long long int n, m;
    cin >> n >> m;
    printf("%lld\n", fast(n,m));
    return 0;
}