# include <iostream>

using namespace std;

void insertionsort(int arr[], int high){
    int i, j, key;
    for(int i=1; i<high; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int n=5; 
    int arr[n] = {22,231,1,33,5};
    // int arr[n];
    // for(int i=0; i<n; i++)  cin>>arr[i];
    for(int i=0; i<n; i++)  cout<<arr[i]<<" ";
    cout<<endl;
    insertionsort(arr, n);
    for(int i=0; i<n; i++)  cout<<arr[i]<<" ";
}