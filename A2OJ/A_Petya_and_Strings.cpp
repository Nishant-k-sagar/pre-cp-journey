#include<bits/stdc++.h>
using namespace std;


int main(){
    string str1, str2;
    cin>>str1>>str2;

    for(int i=0; i<str1.size(); i++){
        str1[i] = (char) tolower(str1[i]);
        str2[i] = (char) tolower(str2[i]);     
        }
    
    int x= str1.compare(str2);
    
    if(x==0){
        cout<<0<<endl;
    }
    else if(x>0){
        cout<<1<<endl;
    }
    else cout<<-1<<endl;

    return 0;
}