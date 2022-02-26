#include<bits/stdc++.h>
using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
int comp = 0;


// ----- first -----

int partition_first(int Ar[],int start, int end)
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
void quickSort_first(int Ar[],int start, int end)
{
    if (start < end)
    {
        int pivot = partition_first(Ar,start, end);

        quickSort_first(Ar,start, pivot - 1);
        quickSort_first(Ar,pivot + 1, end);
    }
}

// ----- last -----

int partition_last(int Ar[],int start, int end)
{
    int pivot = Ar[end];
    int i = start;
    int j = end;
    while (i < j)
    {
        while (Ar[i] < pivot) i++,comp++;
        while (Ar[j] >= pivot) j--,comp++;

        if (i < j)
            swap(Ar[i], Ar[j]);
    }
    swap(Ar[end], Ar[i]);
    return i;
}
void quickSort_last(int Ar[],int start, int end)
{
    if (start < end)
    {
        int pivot_element_index = partition_last(Ar,start, end);

        quickSort_last(Ar,start, pivot_element_index - 1);
        quickSort_last(Ar,pivot_element_index + 1, end);
    }
}

// ----- random -----

int partition_random(int Ar[],int start, int end)
{
    int pivot = Ar[end];
    int i = start;
    int j = end;
    while (i < j)
    {
        while (Ar[i] < pivot) i++,comp++;
        while (Ar[j] >= pivot) j--,comp++;

        if (i < j)
            swap(Ar[i], Ar[j]);
    }
    swap(Ar[end], Ar[i]);
    return i;
}

int partition_r(int arr[], int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);

    swap(arr[random], arr[high]);

    return partition_random(arr, low, high);
}

void quickSort_random(int arr[], int low, int high)
{
    if (low < high) {

        int pi = partition_r(arr, low, high);

       
        quickSort_random(arr, low, pi - 1);
        quickSort_random(arr, pi + 1, high);
    }
}

// ----- middle -----

void quickSort_middle(int arr[], int left, int right) {

      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];

      while (i <= j) {
            while (arr[i] < pivot) i++,comp++;
            while (arr[j] > pivot) j--,comp++;

            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  
                  i++; j--;
                }
        };

      if (left < j)
        quickSort_middle(arr, left, j);

      if (i < right)
        quickSort_middle(arr, i, right);

}

// ----- over -----

int main()
{
    int n=2000;

  int a[n];
  srand(time(NULL));
  for(int i=0;i<n;i++){
     a[i] = rand();

  }

  cout<<"Before sorting"<<endl;
  for(int i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;

  quickSort_first(a,0, n-1);       // first.
//   quickSort_last(a,0, n-1);      // last.
//   quickSort_random(a,0, n-1);      // reandom.
//   quickSort_middle(a,0, n-1);      // middle.
  
  cout<<"After sorting"<<endl;
  for(int i=0; i<n; i++) cout<<a[i]<<" "; cout<<endl;
  cout<<"number of comparisions are "<<comp<<endl;
  return 0;
}