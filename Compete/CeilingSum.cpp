#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        double a,b;
        int c,d;
        d=max(a,b);
        double max=0;
        c=min(a,b);
        for(int i=c;i<=d;++i){
            a = ceil((b-i)/2) +ceil((i-a))/2;
            if(a>max){
                max=a;
                b=i;
            }
            cout<<i<<endl;
        }
    }
    return 0;
}