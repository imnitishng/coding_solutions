#include <iostream>

using namespace std;

int main() {
	int t=1;
//	cin>>t;
	while(t--) {
	    int n=5,k=3,r=0,p=0;
//	    cin>>n;
	    int arr[n] = {48,974,5,-59,-451};
//	    for(int i=0; i<n; i++)
//	        cin>>arr[i]; 
//        cin>>k;
		int flag=0;
        for(int i=0; i<n-k+1; i++){
//            if(arr[i]<0)
//                cout<<arr[i];
//            else if(arr[i+1]<0)
//                cout<<arr[i];
			for(int j=0; j<k; j++){
				if(arr[i+j]<0){
					cout<<arr[i+j]<<" ";
					// cout<<endl;
					flag = 1;
					break;
				}
			}
			if(!flag)
				cout<<0<<" ";
			flag = 0;
	    }
        cout<<endl;
    }
}
