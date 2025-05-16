#include<bits/stdc++.h>
using namespace std;


int main(){
    string str1,str2,str;
    cin>>str1;
    cin>>str2;
    cin>>str;

    string str3 = str1+str2;
    sort(str3.begin(),str3.end());
    sort(str.begin(),str.end());
    if(str3 == str){
        cout<<"YES"<<endl;
    }
    else
    cout<<"NO"<<endl;

    
    return 0;
}