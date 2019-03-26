#include <bits/stdc++.h>
#define LOGN 22
#define MAX (1 << LOGN)
 
using namespace std;
typedef long long ll;

void FST(vector<ll> &a) {
    for (int b = 0; b < LOGN; b++){
        for (int i = 0; i < MAX; i++){
            if((i & (1 << b)) == 0){
                a[i + (1 << b)] = (a[i] != MAX)? min(a[i], a[i + (1 << b)]): a[i + (1 << b)];
            }
        }
    }
}

int arr[MAX];
int main(){
    int n;scanf("%d", &n);

    vector<ll> a(MAX, MAX);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
        a[arr[i]] = arr[i];
    }
    FST(a);
    return 0;
}