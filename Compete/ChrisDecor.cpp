#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
    int temp1 = y/3;
    int temp2 = 0;
    
    if( temp1 > x){
      temp1 = x;
    }
    else{
    temp2 = (x - temp1)/2;
    }
    if(temp2+temp1 < n){
      cout<<"NO"<<"\n";
    }
    else{
      cout<<"YES"<<endl;
       
    }
    }
    return 0;
}