# include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a; 
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;
    for (int j = low; j <= high-1; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quicksort(int arr[], int low, int high){
    int pi;
    if(low < high){
        pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int main()
{
    int n = 12, low = 0; 
    int arr[n] = {22, 231, 1, 33, 5, 33, 232, 111, 32123, 1, 3, 99};
    // int arr[n];
    // for(int i=0; i<n; i++)  cin>>arr[i];
    for(int i=0; i < n; i++)  cout<<arr[i]<<" ";
    cout<<endl;
    quicksort(arr, low, n-1);
    for(int i = 0; i < n; i++)  cout<<arr[i]<<" ";
}