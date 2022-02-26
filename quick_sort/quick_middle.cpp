#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
int comp = 0;
void partition_middle(int arr[], int l, int h){
	int pivot = arr[h/2];
	int i=l,j=h-1;
	while(i<=j){
		while(arr[i]<pivot) i++,comp++;
		while(arr[j]>pivot) j--,comp++;
		if(i<=j){
			swap(arr[i],arr[j]);
			i++;
			j--;
		}
	}
	if(l<j) partition_middle(arr,l,j);
	if(i<h-1) partition_middle(arr,i,h-1);
}



int main()
{
  int a[] = {5, 2, 3, 4, 1, 6};
  int n = sizeof(a)/sizeof(a[0]);
  cout<<"Before sorting"<<endl;
  for(int i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
  partition_middle(a,0, n-1);
  cout<<"After sorting"<<endl;
  for(int i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
  cout<<"number of comparisions are "<<comp<<endl;
  return 0;
}