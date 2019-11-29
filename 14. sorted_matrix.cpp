#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t>>n;
    while(t--){
        // int arr[n][n];
        vector <int> v(n*n);
        
        for(int i=0; i<(n*n); i++)
            cin>>v[i];
        
        sort(v.begin(), v.end());
        for(int i=0; i<(n*n); i++){
            cout<<v[i]<<" ";
        }
    }
}