#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.size();

    string checker = "hello";
    int cnt = 5;
    
    
    bool flag = false;

        while(cnt){
        for(int i=0; i<5; i++){
            for(int j=0; j<n; j++){
                if(n<=5){
                    break;  
                }
                if(checker[i] == s[j]){
                    flag = true;
                    cnt--;
                }
            }
        }


        
        
        }

    if(flag){
        cout<<"YES"<<endl;
    }
    else
    cout<<"NO"<<endl;
    return 0;
}