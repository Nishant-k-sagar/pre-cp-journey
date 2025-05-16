#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--){
        int x;
        cin>>x;

        bool flag = false;
            if(x%33==0){
                flag = true;
                }
            
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
            }

    }
    return 0;
}