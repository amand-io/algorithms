#include <bits/stdc++.h>
#define MAX 1000007

using namespace std;

int bit[MAX];
void update(int idx, int val){
    for(; idx < MAX; idx += (idx&-idx)) bit[idx] += val;
}

int query(int idx){
    int sum = 0;
    for(; idx > 0; idx += (idx&-idx)) sum += bit[idx];
    return sum;
}

int query(int l, int r){
    return query(r)-query(l-1);
}
int main(){
    return 0;
}