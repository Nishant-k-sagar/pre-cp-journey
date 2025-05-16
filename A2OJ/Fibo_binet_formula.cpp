#include<bits/stdc++.h>
using namespace std;

long long int fibo(int n){
    long long int b;
    b=(pow(1+sqrt(5),n)-pow(1-sqrt(5),n))/(pow(2,n)*sqrt(5));
    return b;
}
int main(){
    for(int i=1; i<90; i++){
        cout<<fibo(i)<<" ";
    }
    return 0;
}
