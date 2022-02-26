#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int find_maj(int arr[], int n){
    int count =0;
    int num =0;
    for(int i=0;i<n;i++){
        if(count ==0){
            num = arr[i];
            }
        if(num ==arr[i]) count += 1;
        else count -= 1;
    }
    return num;
}
int main(){
    int n;
    cin>>n;

    int arr[n];
    int temp = 3*n/4; 
    srand((unsigned)time(0));

    for(int i=0;i<temp;i++){
        if(i%2 == 0) arr[i] =2;
        else arr[i] = rand();
    }
    for(int i=temp;i<n;i++){
        arr[i] = 2;
    }
    
    auto start = high_resolution_clock::now();
    cout<<find_maj(arr,n)<<endl;
    auto stop = high_resolution_clock::now();

    auto duration = (stop - start);
    
    // for(auto a:arr){
    //     cout<<a<<" ";
    // }
    // cout<<endl<<endl;
    
    cout << "Time taken by function: "<< duration.count() << " milliseconds" << endl;
    return 0;
}