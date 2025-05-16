#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,ph;
        double k;
        cin>>n>>k;
        ph=int(n/(k+1));
        cout<<n-k*ph<<endl;        
    }
    return 0;
}