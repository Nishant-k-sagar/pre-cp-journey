#include<bits/stdc++.h>
using namespace std;

int main (){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin >>k;
        bool flag =false;

        int l1=0;int l2=0;
        while(k--){
            string str;
            cin >> str;
        l1=0;l2=0;
            for(char it : str ){
                if(it >='a' & it <='m'){
                    l1++;
                }
                else if(it >='N' & it <='Z'){
                    l2++;
               }
               else flag =true;
        }
    }

    if(flag){
        cout << "NO" << endl;
        continue;
    }
    if(l1==0 || l2==0){
        cout << "YES" << endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
}