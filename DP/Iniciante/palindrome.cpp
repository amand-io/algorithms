#include <bits/stdc++.h>
#define MAX 1007

using namespace std;
char s[MAX];
int palin[MAX][MAX];
void build(){
    int len = strlen(s);
	for(int i = 0; i < len; i++){
		for(int j = i; j < len; j++){
			if(!i) palin[j][j] = 1;
			else if(i == 1) palin[j-i][j] = s[j-i] == s[j];
			else palin[j-i][j] = (s[j] == s[j-i]) && palin[j-i+1][j-1];
		}
	}
}

int main(){
    return 0;
}