#include <bits/stdc++.h>
using namespace std;

int main() {

    int a[] = {57,4,1,6,8,4,5,3,47,6,9,5,6,46,6,5,1,51};
    sort(a,a+sizeof(a)/sizeof(int));
    for(auto &x : a){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<endl;
    
    int *ptr = lower_bound(a,a+sizeof(a)/sizeof(int),59);
    cout<<(*ptr)<<endl;

    return 0;
}
