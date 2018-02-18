#include <bits/stdc++.h>

using namespace std;

int num, arr[1000000];

int bb(int val){
	int l = 1, r = num;
	while(l < r){
		int mid = (l + r)/2;
		if(arr[mid] >= val) r =  mid;
		else l = mid+1;
	}

	return r;
}
int main(){
	scanf("%d", &num);
	for(int i = 1; i <= num; i++) cin >> arr[i]; //Array ordenado
	int val; scanf("%d", &val);
	printf("%d\n",bb(val));
	return 0;
}