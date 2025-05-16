#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;

    string s,snew;
    cin>>s;

    sort(s.begin(), s.end());

    int  n = s.length();
    for(int i=0; i<n; i+=k){
        if(s[i] == s[i+k-1]){
            snew += s[i];
        }
        else {cout<< "-1";
        exit(0);}
    }

    while(k--){
        cout<<snew;
    }
}