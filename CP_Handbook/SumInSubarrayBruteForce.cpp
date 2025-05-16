#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {-5,10,11,-19,20,1,2,6,7,8,-1};
    int n= sizeof(a)/sizeof(a[0]);

    int max1 = INT_MIN;
    for(int i=0; i<n; ++i){
        for(int j=i; j<n; j++){
            int sum=0;
            for(int k=i; k<=j; ++k){
                sum +=a[k];
            }
            max1 = max(sum, max1);
        }
    }

    cout<<max1<<endl;
    return 0;
}