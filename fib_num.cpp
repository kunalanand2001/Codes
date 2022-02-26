#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define int unsigned long long int

vector<vector<int>> mult_mat(vector<vector<int>> &a,vector<vector<int>> &b){     // function to multiply two matrices.
    int n = a.size();
    vector<vector<int>> ans(n,vector<int>(n,0));

    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

vector<vector<int>> matrix_exp(vector<vector<int>> &a,int n){    //function to exponentiate the matrix.

    if (n==0){                                           //return identity matrix.
        int s = a.size();
        vector<vector<int>> ans(s,vector<int>(s,0));
        for(int i=0;i<s;i++)
        ans[i][i] = 1;

        return ans;
    } 

    if(n==1){                                          // return a matrix itself.
        return a;
    }

    vector<vector<int>> temp = matrix_exp(a,n/2);      //for finding a^n we are doing a^(n/2) * a^(n/2);
    vector<vector<int>> ans = mult_mat(temp,temp);

    if(n&1){                                          // n is odd then a^n = a^(n/2) * a^(n/2) * a.
        ans = mult_mat(ans,a);
    }    

    return ans;
}

 signed main(){
    int n;
    cin>>n;
    vector<vector<int>> a = {{1,1},{1,0}};
    vector<vector<int>> ans = matrix_exp(a,n);

    cout<<"The matrix is :- "<<endl;
    for(int i= 0;i<ans.size();i++){
        for(int j=0;j<ans.size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    auto start = high_resolution_clock::now();
    cout<<"The "<<n<<"th fib. number is "<<ans[0][1]<<endl;
    auto stop = high_resolution_clock::now();

    auto duration = (stop - start);
    cout << "Time taken by function: "<< duration.count() << " milliseconds" << endl;
    return 0;
}

    