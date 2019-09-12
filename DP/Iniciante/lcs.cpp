#include <bits/stdc++.h>
#define MAX 1007

using namespace std;

int dp[2][MAX];
string s, t;
int solve(int n, int m){
    memset(dp, 0, sizeof dp);
    int b;
	for(int i = 1; i <= n; i++){
		b = i&1; 
		for(int j = 1; j <= m; j++){
			if(i == 0 || j == 0) dp[b][j] = 0;
			else if(s[i-1] == t[j-1]) dp[b][j] = dp[1-b][j-1] + 1;
			else dp[b][j] = max(dp[1-b][j], dp[b][j-1]);
		}
	}

    return dp[n][m];
}
int main(){
    cin >> s >> t;
    cout << solve(s.size()-1, t.size()-1) << endl;
    return 0;
}