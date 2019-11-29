#include<bits/stdc++.h>
#include<string.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--){
        string str;
        cin>>str;
        string temp = "";
        int sum = 0;
        for(char ch: str){
            if(!isalpha(ch)){
                temp += ch;
            }
            else{
                sum += atoi(temp.c_str());
                temp = "";
            }
        }
        sum += atoi(temp.c_str());
        cout<<sum<<endl;
    }
}