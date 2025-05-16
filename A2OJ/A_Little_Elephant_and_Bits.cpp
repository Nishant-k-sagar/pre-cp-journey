#include<bits/stdc++.h>
using namespace std;


int main(){
    string str;
    cin>>str;

    int n = str.length();

    for(int i=0; i<n; i++){
        if(str[i] == '0'){
            str.erase(str.begin()+i);
            break;
        }
    }

    for(int i=0; i<n-1; i++){
        cout<<str[i];
    }

    return 0;
}