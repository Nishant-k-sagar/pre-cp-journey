#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        int sum=0;
       cin>>n;
       char str[n];
        scanf("%s",str);
       
       for(int i=0; i<n; ++i){
         if(str[i]=='+'){
            sum=sum+1;
        }
        else
        sum=sum-1;
       
       }
       cout<<abs(sum)<<endl;
       
    }
    return 0;
}