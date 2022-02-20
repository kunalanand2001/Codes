#include<bits/stdc++.h>
using namespace std;
int main(){
    // int arr[] = {40, 20, 0, 0, 0, 1, 3, 3, 0, 0, 9, 21};
    int arr[] = {2,3,10,6,4,8,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int max_diff = arr[1]-arr[0];
    int min_val = arr[0];

    for(int i =1 ;i<=n ;i++){
        
        max_diff = max(max_diff, arr[i] - min_val);
        if(arr[i] < min_val) min_val = arr[i];
    }  

    cout<<max_diff<<endl;
    return 0;
}