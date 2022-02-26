#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int max_dif(int arr[],int n){
    
    int max_diff = arr[1]-arr[0];
    int min_val = arr[0];

    for(int i =1 ;i<=n ;i++){
        
        max_diff = max(max_diff, arr[i] - min_val);
        if(arr[i] < min_val) min_val = arr[i];
    }
    return max_diff;  
}
int main(){
    // int arr[] = {40, 20, 0, 0, 0, 1, 3, 3, 0, 0, 9, 21};
    // int arr[] = {2,3,10,6,4,8,1}; // ans = 8

    int n;
    cin>>n;
    int arr[n];
    srand((unsigned)time(0));

    for(int i=0;i<n;i++){
        arr[i] = rand();
    }

    auto start = high_resolution_clock::now();
    cout<<max_dif(arr,n)<<endl;
    auto stop = high_resolution_clock::now();

    auto duration = (stop - start);
 
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
    return 0;
}