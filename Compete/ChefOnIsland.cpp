#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,a,b,d;
        cin>>x>>y>>a>>b>>d;
        if(x>=(d*a) & y>=(d*b)){
            cout<<"YES"<<endl;
        }
        else
        cout<<"NO"<<endl;
    }
    return 0;
    }