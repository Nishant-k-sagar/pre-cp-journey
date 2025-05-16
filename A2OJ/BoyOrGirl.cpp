#include<bits/stdc++.h>
using namespace std;


int main(){
    string str1;
    string str2;

    cin>>str1;
    cin>>str2;

    int n= str1.length();

    for(int i=0; i<n; ++i){
        if(str1[i] != str2[i]){
            str1[i] = '1';
        }
        else
        str1[i] ='0';
    }

    for(int i=0; i<n; ++i){
        cout<<str1[i];
    }
    cout<<endl;
    
    return 0;
}