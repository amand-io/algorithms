#include <bits/stdc++.h>

using namespace std;

int fatorial(int n){
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else return n*fatorial(n-1);
}

int combinatoria(int n, int m){
    long long int resp = 1;

    if(m > (n-m)) m = n-m;

    for(int i = 0; i < m; i++) resp = resp*(n-i)/(i+1);

    return resp;
}

int arranjo(int n, int p){

    if(p > 1) return n*arranjo(n-1,p-1);
    return n;
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << combinatoria(n, m) << endl;

    return 0;

}