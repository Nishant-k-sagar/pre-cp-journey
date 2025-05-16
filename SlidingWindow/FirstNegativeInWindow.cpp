#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {12,-1,7,8,-15,30,16,28};
    int n= sizeof(a)/sizeof(a[0]);

    int k = 3;//window size
    int i = 0;
    int j=0;

    list<int> p;
    
    while(j<n){
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1 == k){
            if(a[i]<0){
                p.push_back(a[i]);
                j++;
                i++;
            }
            else
            i++;
        }
    }

    for( auto it:p){
        cout<<it<<" ";
    }
    return 0;
}