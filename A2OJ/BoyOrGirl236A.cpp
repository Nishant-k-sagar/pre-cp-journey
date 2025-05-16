#include<bits/stdc++.h>
using namespace std;


int main(){
    string str;
    cin>>str;

    sort(str.begin(), str.end());

    int n = str.length();
    int count = 0;
    for(int i=0; i<n-1; i++){
        if(str[i] != str[i+1]){
            count++;
        }
    }
    if(count %2 != 0){
        cout<<"CHAT WITH HER!";
    }
    else cout<<"IGNORE HIM!";
    return 0;
}