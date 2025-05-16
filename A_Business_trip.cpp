#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin >> k;
    
    int a[12];

    for(int i=0; i<12; i++){
        cin>>a[i];
    }

    sort(a, a+12, greater<int>());

    int i;
    for(i=0; i<12; i++){

        if(k<=0) break;
        if(i == 11 and k-a[i] > 0) {i = -1;
        break;}
        
        k=k-a[i];
        
    }

    cout<<i<<endl;

    return 0;
}
