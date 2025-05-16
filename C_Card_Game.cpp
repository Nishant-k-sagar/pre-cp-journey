#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n;
    string s;
    cin >> n >> s;

    bool flagA = false;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            int pos = i + 1;
            bool flagB = false;

            for (int j = 0; j < n; ++j) {
                if (s[j] == 'B') {
                    int bpos = j + 1;
                    if ((pos == 1 && bpos > 1 && bpos < n) ||  (pos == n && bpos == 1) || (pos > 1 && pos < n && bpos > pos)) {
                        flagB = true;
                        break;
                    }
                }
            }

            if (!flagB) {
                flagA = true;
                break;
            }
        }
    }

        if(flagA)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
}

int main()
{
    fast
        ll t = 1;
    // cin >> t;
    while (t--)
    {
        nottryingenouf();
    }
}