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

       int ct=0;
       int max=v[0];
       for(int i=1; i<n; ++i){
           if(v[i]>max){
               max = v[i];
           }
           else{
                ct++;
           }
    }
    cout<<ct<<endl;
    }
    return 0;
}