#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        double e,k;
        cin>>e>>k;
        int ct=0;
        while(e){
            e=floor(e/k);
            ct++;
        }
        cout<<ct<<endl;
    }
    return 0;
}