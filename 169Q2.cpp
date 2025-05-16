#include <bits/stdc++.h>
using namespace std;

void codewithlove() {
   int n;
   cin >> n;
   string s;
   cin >> s;

   string dummy(n, '1');

   string res = "";
   for (int i = 0; i < n; i++) {
       if (dummy[i] == '1' && s[i] == '1') {
           res += '0';
       } else if (dummy[i] == '1' && s[i] == '0') {
           res += '1';
       }
   }

   cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        codewithlove();
    }
    return 0;
}
