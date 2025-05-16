#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false); cin.tie(0);

void nottryingenouf()
{
    // try it harder
    string s;
    cin >> s;

    int cnt0 = 0, cntnum = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            cnt0++;
        } else {
            if (cnt0 + 1 > cntnum) {
                cntnum = cnt0 + 1;
            }
        }
    }

    cout << s.size() - cntnum << endl;
}

int main()
{
    fast
    ll t;
    cin >> t;
    while (t--) {
        nottryingenouf();
    }
    return 0;
}
