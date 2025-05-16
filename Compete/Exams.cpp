#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,z;
        cin>>x>>y>>z;
        if(z>(x*y)*0.5){
            cout<<"YES"<<endl;
        }
        else
        cout<<"NO"<<endl;

    }
    return 0;
    }