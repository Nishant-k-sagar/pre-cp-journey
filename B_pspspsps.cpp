#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int flag = 1;
        int ptracker = 0;

        for (int i = n-1; i >=0; i--) {
            if(s[i] == 'p'){
                ptracker++;
                }
            else if(s[i] == 's'){
                flag = 0;
                }
        }

        if (flag || (ptracker == s.length())) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }

    return 0;
}
