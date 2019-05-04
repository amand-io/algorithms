#include <bits/stdc++.h>
#define MAX 10000000

using namespace std;

vector<long long int> primos;
bitset<MAX> primes;
void sieve(){
    primes.set();
    primes[0] = primes[1] = 0;

    for(long long int i = 2; i < MAX; i++){
        if(primes[i]){
            for(long long int j = i*i; j < MAX; j += i) primes[j] = 0;
            primos.push_back(i);
            //printf("%lld ", i);
        }
    }
}

bool is_prime(long long int num){
    if(num < MAX) return primes[num];
    for(int i = 0; i < primos.size(); i++){
        if(num%primos[i] == 0) return false;
    }
    return true;
}
int main(){
    sieve();
    long long int num;
    cin >> num;
    printf("%c\n", is_prime(num)? 'S': 'N');
    return 0;
}