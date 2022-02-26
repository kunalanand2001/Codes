#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int comp=0;
int partition(int Ar[],int start, int end)
{
    int pivot = Ar[start];
    int i = start;
    int j = end;

    while (i < j)
    {
        while (Ar[i] <= pivot) i++,comp++;
        while (Ar[j] > pivot) j--,comp++;

        if (i < j)
            swap(Ar[i], Ar[j]);
    }
    swap(Ar[start], Ar[j]);
    return j;
}
void quickSort(int Ar[],int start, int end)
{
    if (start < end)
    {
        int pivot = partition(Ar,start, end);

        quickSort(Ar,start, pivot - 1);
        quickSort(Ar,pivot + 1, end);
    }
}

int main()
{
  int a[] = {5, 2, 3, 4, 1, 6};
  int n = sizeof(a)/sizeof(a[0]);
  cout<<"Before sorting"<<endl;
  for(int i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
  quickSort(a,0, n-1);
  cout<<"After sorting"<<endl;
  for(int i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
  cout<<"number of comparisions are "<<comp<<endl;
  return 0;
}