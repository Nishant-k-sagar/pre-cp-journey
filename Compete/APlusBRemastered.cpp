#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int a[n], b[n];

        for(int i = 0; i<n; ++i){
            cin>>a[i];
        }
        for(int i=0; i<n; ++i){
            cin>>b[i];
        }

        sort(a,a+n);
        sort(b,b+n);
        reverse(b,b+n);

        bool flag=true;
        for(int i=0; i<n; ++i){
            if(a[i]+b[i] != a[0]+b[0]){
                flag=false;
            
            break;}
        }
        
        if (flag) {
            
            for (int i = 0; i < n; ++i) {
                cout << a[i]<<" ";
            }
            cout << endl;

            for (int i = 0; i < n; ++i) {
                cout <<b[i] <<" ";
            }
            cout<<endl;
        } else {

            cout << -1 << endl;
        }
    }

    return 0;
}
