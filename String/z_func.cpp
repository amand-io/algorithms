#include <bits/stdc++.h>
#define MAX 1000007

using namespace std;

int z[MAX];
string txt;

void func(){
	int l = 0, r = 0;

	for(int i = 1; i < txt.size(); i++){
		if(i > r){
			l = r = i;
			while( r < txt.size() && txt[r] == txt[r-l]) r++;
			z[i] = r-l; r--;
		}else{
			int  k = i-l;
			if(z[k] < r-i+1) z[i] = z[k];
			else{
				l = i;
				while( r < txt.size() && txt[r] == txt[r-l]) r++;
				z[i] = r-l; r--;
			}
		}
	}
}
int main(){
	cin >> txt;
	func();
	return 0;
}