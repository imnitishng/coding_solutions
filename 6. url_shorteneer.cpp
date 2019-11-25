# include <iostream>
# include <bits/stdc++.h>

using namespace std;

int main()
{
    int t=1;
    
    int vocab[62];
    // int iters=26, nums=10;
    
    // Creating an index of the required source
    // for(int i=97, j=0; j<26; j++, i++)
    //    vocab[j] = i;
    // for(int i=65, j=26; j<52; j++, i++)
    //     vocab[j] = i;
    // for(int i=0, j=52; j<62; j++, i++)
    //     vocab[j] = i;

    string source = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    cin>>t;
    while(t--){
        unsigned int n;
        cin>>n;
        unsigned int val = n;
        vector<int> nos;
        unsigned int quotient = 1, base=62, rem;
        while(quotient != 0){
            quotient = n/base;
            rem = n % base;
            nos.push_back(rem);
            n = quotient;
        }
        reverse(nos.begin(), nos.end());
        for(auto it = nos.begin(); it!=nos.end(); it++)
            cout<<source[*it];
            // *it = vocab[*it];

        // for(int i=0; i<nos.size(); i++)
        //     cout<<(char)nos.at(i);
        cout<<endl<<val<<endl;
    }
}