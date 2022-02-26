#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class point{
    public:
    int x, y;
};

float dist(point p1, point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}
float min(float x, float y){
    return (x < y)? x : y;
}
 //-------------------------------------------
 // brute force approach.

float find_min_diss_brutef(point p[], int n){

    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(p[i], p[j]) < min)
                min = dist(p[i], p[j]);
    return min;
}
 //-------------------------------------------

int main(){
    int N,x,y;
    cin>>N;
    point p[N];

    srand((unsigned)time(0));

    for(int i=0;i<N;i++){
        int rnd = rand();

        if(i%2 == 0) p[i] = {(rnd%N),(rnd/N)};
        else p[i] = {(rnd/N),(rnd%N)};
    }

    auto start = high_resolution_clock::now();
    cout<<find_min_diss_brutef(p,N)<<endl;
    auto stop = high_resolution_clock::now();

    auto duration = (stop - start);
 
    cout << "Time taken by function: "<< duration.count() << " milliseconds" << endl;
    
    return 0;
}