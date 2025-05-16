#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int num;
    cin>>num;

    bool flag = false;
    while(num !=0){
        long long int a = num%10;
        if(a == 4 or a== 7){
            flag = true;
        }
        else{
        flag = false;
        break;
        }

        num = num /10;
    }
    if(flag) cout<<"YES"<<endl;
    else cout <<"NO"<<endl;
    return 0;
}