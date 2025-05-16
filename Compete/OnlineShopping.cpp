#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,s,k;
    cin>>n>>s>>k;
    int p[n],q[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>p[i]>>q[i];
        sum+=p[i]*q[i];
    }
    if(sum>=s){
        cout<<sum;
    }
    else
    cout<<sum+k;
    return 0;
}