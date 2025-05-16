#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    while(a!=b){
        if(a>b){
            a=a-b;
        }
        else
        b=b-a;
    }
    return b;
}
int main(){
    cout<<gcd(20,50);
    return 0;
}