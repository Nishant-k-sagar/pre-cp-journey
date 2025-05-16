#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, min, max, str = -1;

    cin>>n;

    for(int i=0; i<n; i++){
        cin>>a>>b;
        if( i == 0) min = a, max = b;
        if(a< min) min = a, str = -1;
        if(b> max) max = b, str = -1;
        if(a==min and b == max) str = i+1;
    }

    cout<<str<<endl;
    return 0;
}
