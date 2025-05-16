#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int arr[200000];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr,arr+n);

    long long  k = count(arr,arr+n, arr[0]);
    long long  l = count(arr, arr+n, arr[n-1]);
    if(arr[0]==arr[n-1]) k = n*1LL*(n-1)/2;
    else k = 1LL*k*l;
    cout<<arr[n-1]-arr[0]<<" "<<k;
    return 0;
}


