#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    string s;

    int count =0;
    while(n--){
        cin >>s;
        if(s[1] == '+'){
            ++count;
        }
        else{
            --count;
        }
    }
    cout<<count<<endl;
    return 0;
}