#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;

    int total = 0;
    int max1 = 0;

    int a,b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        total -=a;
        total+=b;

        max1 = max(max1,total);
    }
    cout<<max1<<endl;
    return 0;
}