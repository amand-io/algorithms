#include <bits/stdc++.h>
#define MAX 1000007

using namespace std;

int k[MAX];
string txt;

void kmp(){
	int i = 0, j = -1;
	k[0] = -1;
	while(i < txt.size()){
		while(j >= 0 && txt[i] != txt[j]) j = k[j];
		i++; j++;
		k[i] = j;
	}
}
int main(){
	cin >> txt;
	kmp();
	return 0;
}