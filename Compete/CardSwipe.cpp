#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
     int n;
     cin>>n;
     vector <int> v(n);
     unordered_map<int,int>mp;
     for(int i=0; i<n; i++){
        cin>>v[i];
     }
     int ans=0; int maxi=0;
     for(int i=0;i<n;i++){
        if(mp[v[i]]==0){
            mp[v[i]]++;
            ans++;
        }
        else{
        mp[v[i]]--;
        ans--;
        }
         maxi=max(maxi,ans);
     }
    
     cout<<maxi<<endl;
    }
    return 0;
}