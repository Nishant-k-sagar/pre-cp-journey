#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0)return a;
    else return(b,a%b);
}
int main(){
    int a =10;
    int b= 50;
    cout<<gcd(a,b);
    return 0;
}