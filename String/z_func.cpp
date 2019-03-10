#include <bits/stdc++.h>
#define MAX 1000007

using namespace std;

int z[MAX];
string s;

void func(){
	int l = 0, r = 0;
	for(int i = 1; i < s.size(); i++){
		z[i] = max(0, min(z[i-l], r-i+1));
		while(i+z[i] < s.size() && s[z[i]] == s[i+z[i]]){
			l = i; r = i+z[i]; z[i]++;
		}
	}
	z[0] = s.size();
}
int main(){
	cin >> s;
	func();
	return 0;
}