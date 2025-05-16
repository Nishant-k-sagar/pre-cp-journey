#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    
    bool choice = false; 
    int cnt = 0;
    
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            choice = true;
        } else {
            if(a[i] == '1') {
                cnt++;
            }
        }
    }
    
    if(cnt % 2 == 1) {
        cout << "YES\n";
        return;
    }
    
    if(choice) {
        cout << "YES\n";
        return;
    }
    
    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}