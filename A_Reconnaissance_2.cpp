#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,diff,idx1,idx2;
    cin>>n;

int a[n];
for(int i=0;i<=n-1;i++)
cin>>a[i];

int min=abs(a[0]-a[n-1]);
idx1=1;idx2=n;
for(int i=0;i<=n-2;i++){
    diff=abs(a[i+1]-a[i]);
    if (min>diff){min=diff;
    idx1=i+1;idx2=i+2;}
    }
cout<<idx1<<" "<<idx2;
}