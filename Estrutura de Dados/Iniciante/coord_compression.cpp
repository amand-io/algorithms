#include <bits/stdc++.h>
#define MAX 100007

using namespace std;

int a[MAX], aux[MAX];

void coord(int n){
    memcpy(aux, a, sizeof a);

    sort(aux, aux+n);
    int sz = unique(aux, aux+n) - aux;

    for(int i = 0; i < n; i++){
        a[i] = lower_bound(aux, aux+sz, a[i])-aux;
    }
}
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    coord(n);

    for(int i = 0; i < n; i++) cout << a[i] << " \n"[i == n-1];
    return 0;
}