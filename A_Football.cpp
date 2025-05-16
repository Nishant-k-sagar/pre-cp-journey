#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    int n = s.length();

    bool flag = false;
    int count0 = 0,count1 = 0; 
    for(int i=0; i<n; i++){
        if(s[i] == '0'){
            count0++;
            count1 = 0;
        }
        if(s[i] == '1'){
            count1++;
            count0 = 0;
        }

        if(count0 == 7 || count1 == 7){
            flag = true;
        }
    }
    
    flag? cout<< "YES" : cout<< "NO";
    cout<<endl;
    return 0;
}