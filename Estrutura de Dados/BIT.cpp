#include <bits/stdc++.h>
#define MAX 1000007
using namespace std;

int arr[MAX], bit[3*MAX], n;

void update(int index, int val){
	index = index + 1;
	 while(index <= n){
	 	bit[index] += val;

	 	index += index&(-index);
	 }
}

int query(int index){
	int soma = 0;
	while(index > 0){
		soma += bit[index];

		index -= index&(-index);
	}

	return soma;
}

void init(){
	for(int i = 0; i < n; i++) update(i, arr[i]);
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> arr[i];
	init();
	int op; cin >> op;
	while(op--){
		string letra; cin >> letra;
		if(letra == "s"){
			int l, r; cin >> l >> r;
			cout << query(r+1)-query(l) << endl;
		}else if(letra == "u"){
			int index, val; cin >> index >> val;
			update(index, val);
		}
 	}
	return 0;
}