#include<bits/stdc++.h>
using namespace std;

int main()
{   
    long long n,k;
    cin>>n>>k;

    n = k-(n+1)/2;
    if(n>0){
        cout<<2*n<<endl;}
        
    else
        cout<<2*k-1<<endl;
    
    return 0;
}
