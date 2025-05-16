#include<bits/stdc++.h>
using namespace std;

int main(){
    // int a[] = {8, 4, 2, 1};
    // int a[] = {1, 20, 6, 4, 5};
    int a[] = {5, 4, 3, 2, 1};
    int n= sizeof(a)/sizeof(a[0]);
    

    int count = 0;
    for(int i=0; i<n; ++i){
        for(int j=1; j<n; ++j){
            if(i<j and a[i]>a[j]){
                count++;
            }
        }
    }

    cout<<count<<endl;
    return 0;
}