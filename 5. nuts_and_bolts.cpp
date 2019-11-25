# include <iostream>

using namespace std;

void swap(int *a, int *b){
    int temp = *a; 
    *a = *b;
    *b = temp;
}

int partition(int nuts[], int bolts[], int low, int high){
    int pivot = bolts[high];
    int i = low-1;
    for (int j = low; j <= high-1; j++){
        if (nuts[j] < pivot){
            i++;
            swap(&nuts[i], &nuts[j]);
        }
    }
    swap(&nuts[i+1], &nuts[high]);
    return (i+1);
}

void quicksort(int nuts[], int bolts[], int low, int high){
    if(low < high){
        int pi = partition(nuts, bolts, low, high);
        quicksort(nuts, bolts, low, pi-1);
        quicksort(nuts, bolts, pi+1, high);
    }
}

int main()
{
    int n = 5, low = 0; 
    int nuts[n] = {'@', '%', '$', '#', '^'};
    int bolts[n] = {'%', '@', '#', '$', '^'};
    // int arr[n];
    // for(int i=0; i<n; i++)  cin>>arr[i];
    for(int i=0; i < n; i++)    cout<<(char)nuts[i]<<" ";
    cout<<endl;
    for(int i=0; i < n; i++)    cout<<(char)bolts[i]<<" ";
    cout<<endl<<endl;
    quicksort(nuts, bolts, low, n-1);
    for(int i=0; i < n; i++)    cout<<(char)nuts[i]<<" ";
    cout<<endl;
    for(int i=0; i < n; i++)    cout<<(char)bolts[i]<<" ";
    
}