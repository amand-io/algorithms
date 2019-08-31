#include <bits/stdc++.h>
#define MAX 1007

using namespace std;

int dp[MAX][MAX];

string s, t;
int solve(int x, int y){
    if(x < 0 || y < 0) return 0;
    if(dp[x][y] != -1) return dp[x][y];

    int ans = (s[x] == t[y]) ? (1 + solve(x-1, y-1)): 
                               max(solve(x, y-1), solve(x-1, y));

    return dp[x][y] = ans;
}
int main(){
    cin >> s >> t;
    memset(dp, -1, sizeof dp);
    cout << solve(s.size()-1, t.size()-1) << endl;
    return 0;
}