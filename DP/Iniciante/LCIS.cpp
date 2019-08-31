#include <bits/stdc++.h>
#define MAX 5007

using namespace std;
int n,m,a[MAX],b[MAX],f[MAX],g[MAX];

void ord(int x){
	if(!x)return;
	ord(g[x]);
	printf("%d ",b[x]);
}

void LCIS(){
    int x = 0;
	for(int i = 1; i <= n; i++){
		int k = 0;
		for(int j = 1; j <= m;j++){
			if(a[i]==b[j]) { f[j]=f[k]+1; g[j]=k; }
			if(a[i]>b[j]&&f[k]<f[j]) k = j;
		}
	}
	for(int i = 1; i <= m;i++){
		if(f[i]>f[x]) x = i;
    }

    cout << f[x] << endl;
    ord(x);
}
int main(){
}