#include <bits/stdc++.h>
#define MAX 100007
#define SQ 327
#define  mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct SQRTT {
    int bucket[MAX], freq[SQ][MAX];
    pii interval[SQ][SQ];
    int ini[MAX], fim[MAX], a[MAX], n;

    int actual[MAX];
    void build(){
        memset(ini, -1, sizeof ini);
	    memset(fim, -1, sizeof fim);
        // Delimitando intervalos dos buckets
        bucket[0] = 0; ini[0] = 0;
        for(int i = 1; i < n; i++){
            bucket[i] = i/SQ;
            ini[bucket[i]] = (bucket[i] != bucket[i-1])? i: ini[bucket[i]];
            fim[bucket[i-1]] = (bucket[i] != bucket[i-1])? i-1: fim[bucket[i-1]];
        }
        fim[bucket[n-1]] = n-1;

        // Acumulando
        for(int i = 0; i < n; i++) freq[bucket[i]][a[i]]++;

        for(int i = 1; i < SQ && ini[i] != -1; i++){
            for(int j = 0; j < MAX; j++) freq[i][j] += freq[i-1][j];
        }

        // pegando a melhor resposta entre os buckets
        for(int i = 0; i < SQ && ini[i] != -1; i++){
            memset(actual, 0, sizeof actual);
            int best = a[ini[i]];
            for(int j = ini[i]; j < n; j++){
                actual[a[j]]++;

                if(actual[a[j]] == actual[best]) best = min(a[j], best);
                else if(actual[a[j]] > actual[best]) best = a[j];

                if(fim[bucket[j]] == j) {interval[i][bucket[j]].first = best; interval[i][bucket[j]].second = actual[best];}
            }
        }
        memset(actual, 0, sizeof actual);
    }

    int query(int l, int r){
        if(bucket[l] == bucket[r]){
            int best = l;
            for(int i = l; i <= r; i++){
                actual[a[i]]++;
                if(actual[a[i]] == actual[best]) best = min(a[i], best);
                else if(actual[a[i]] > actual[best]) best = a[i];
            }

            // limpando
            for(int i = l; i <= r; i++) actual[a[i]] = 0;
            return best;
        }

        int bl = bucket[l]+1, br = bucket[r]-1;
        pii best;
        if(bl <= br) best = interval[bl][br];
        else best = mp(-1, -1);

        for(int i = l; i <= fim[bucket[l]]; i++) actual[a[i]]++;
        for(int i = ini[bucket[r]]; i <= r; i++) actual[a[i]]++;
        
        for(int i = l; i <= fim[bucket[l]]; i++) {
            int total = freq[br][a[i]];
            total -= freq[bl-1][a[i]];
            total = total + actual[a[i]];
            if(total == best.second) best.first = min(best.first, a[i]);
            else if(total > best.second) {best.first = a[i]; best.second = total;}
        }
        for(int i = ini[bucket[r]]; i <= r; i++) {
            int total = freq[br][a[i]];
            total -= freq[bl-1][a[i]];
            total = total + actual[a[i]];
            if(total == best.second) best.first = min(best.first, a[i]);
            else if(total > best.second) {best.first = a[i]; best.second = total;}
        }

        // limpando
        for(int i = l; i <= fim[bucket[l]]; i++) actual[a[i]] = 0;
        for(int i = ini[bucket[r]]; i <= r; i++) actual[a[i]] = 0;
        return best.first;
    }
} ds;

int main(){
    int m; scanf("%d %d", &ds.n, &m);

    for(int i = 0; i < ds.n; i++) scanf("%d", &ds.a[i]);

    ds.build();
    while((m--)){
        int l, r; scanf("%d %d", &l, &r);
        printf("%d\n", ds.query(l, r));
    }
    
    return 0;
}