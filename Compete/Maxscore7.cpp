#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
       cin>>n;
       vector<int> v(n);
       for(int i=0; i<n; ++i){
        cin>>v[i];
       }
       int ct1=0;
       int ct0=0;
       for (int i=0; i<n; ++i){
        if(v[i]==1){
            ct1++;
        }
        else
        ct0++;
       }
       cout<<min(ct1,ct0)<<endl;
    }
    return 0;
}