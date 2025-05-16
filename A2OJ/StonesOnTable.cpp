#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string str[n];
    for(int i=0; i<n; i++){
        cin>>str[i];
    }

    int count=0;
    for(int i=1; i<n-1; ++i){
        if(str[i-1] == str[i]){
            count++;
        }
        
    }
    cout<<count<<endl; 
    return 0;
}