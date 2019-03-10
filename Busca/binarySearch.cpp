#include <bits/stdc++.h>
#define MAX 100007

using namespace std;

int num, arr[1000000];

int leftmost(int val, int left = 0, int right = num+1){
	if(left == right) return left;
	int mid = (left + right)/2;

	if(arr[mid] < val) return leftmost(val, mid+1, right);
	else return leftmost(val, left, mid);
}

int rightmost(int val, int left = 0, int right = num+1){
	if(left == right) return left;
	int mid = (left + right + 1)/2;

	if(arr[mid] > val) return rightmost(val, left, mid-1);
	else return rightmost(val, mid, right);
}
int main(){
	scanf("%d", &num);
	for(int i = 1; i <= num; i++) cin >> arr[i]; //Array ordenado
	arr[num+1] = 100000007;

	while(true){
		int l, r; scanf("%d %d", &l, &r);
		printf("---- %d %d\n",leftmost(l), rightmost(r));
	}

	return 0;
}