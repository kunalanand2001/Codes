#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {3,3,2,5,1,3,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ele = arr[0];
    int count = 1;

    for(int i =1;i<n;i++){
        if(arr[i] == ele) count++;
        else count --;
        if(count == 0){
            ele = arr[i];
            count = 1;
        }
    }
    cout<<ele<<endl;
    return 0;
}