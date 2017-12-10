#include <bits/stdc++.h>
#define MAX 10000007

using namespace std;
 
vector<int> primes;
bitset<MAX> is_prime;

void crivo(){
    is_prime.set();

    is_prime[0] = is_prime[1] = 0;

    for(int i = 2; i < MAX; i++){
        if(is_prime[i]) {
            primes.push_back(i);
            //printf("%d ", i);
        }

        for(int j = 0; j < primes.size() && i*primes[j] < MAX; j++){
            is_prime[i*primes[j]] = 0;
        }
    }
}
int main(){
    crivo();
    printf("\n");
    return 0;
}