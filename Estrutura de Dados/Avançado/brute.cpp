#include <bits/stdc++.h>
#define MAX 100007

using namespace std;

int freq[MAX], arr[MAX];
int query(int l, int r){
    memset(freq, 0, sizeof freq);

    int ans = arr[l], maxi = 1;
    for(int i = l; i <= r; i++){
        freq[arr[i]]++;
        if(freq[arr[i]] == maxi) ans = min(arr[i], ans);
        else if(freq[arr[i]] > maxi) {ans = arr[i]; maxi = freq[arr[i]];}
    }

    return ans;
}
int main(){
    int n, q; scanf("%d %d", &n, &q);

    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    while(q--){
        int l, r; scanf("%d %d", &l, &r);
        printf("%d\n", query(l, r));
    }
    return 0;
}