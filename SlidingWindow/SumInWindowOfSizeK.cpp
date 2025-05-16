#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(a)/sizeof(a[0]);
    int k = 4;
    int i =0, j=0;

    int mx = INT_MIN;

    int sum = 0;
    while(j<n){
        sum = sum + a[j];
        if(j-i+1<k)
        j++;

        else
        if(j-i+1==k){
            mx = max(mx , sum);
            sum = sum - a[i];
            i++;
            j++;
            
        }
    }
    cout<<mx<<endl;
    return 0;
}