#include<bits/stdc++.h>

using namespace std; 

// N^2
int lis(vector<int> &arr){ 
    int n = arr.size();
    vector<int> lis(n, 0);
   
    lis[0] = 1;    
    for (int i = 1; i < n; i++ ){ 
        lis[i] = 1; 
        for (int j = 0; j < i; j++ ){
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
            }
        }
    } 
    
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, lis[i]);
    return ans;
} 

int main(){
    return 0; 
}