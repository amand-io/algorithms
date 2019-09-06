#include <bits/stdc++.h>
#include <ext/rope> 
#define MAX 1000007

using namespace std;
using namespace __gnu_cxx; //namespace with rope and some additional stuff

char a[MAX], b[10], c[MAX];
int main(){
    /*              ROPE             */
    string a; cin >> a;
    rope< int > s;
    for(int i = 0; i < a.size(); i++) s.push_back(a[i]);
    
    //insert
    int idx = 4;
    rope< int > curr;
    s.insert(idx, curr);

    // substr
    int l = 3, r = 15;
    rope< int > curr = s.substr(l, r-l+1);
    for(auto it = curr.mutable_begin(); curr.mutable_end() != it; ++it) printf("%c", (char)(*it));

    /* --------------------------- */
    
    return 0;
}