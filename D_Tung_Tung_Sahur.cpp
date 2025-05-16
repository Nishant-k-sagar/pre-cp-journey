#include <iostream>
#include <vector>
#include <string>

using namespace std;

string p, s;

bool nottryingenouf() {
    int l = 0; //for p
    int r = 0; // for s
    int plen = p.size(), slen = s.size();

    while (l < plen && r < slen) {
        char pchar = p[l];

        int pcnt = 0;
        while (l < plen && p[l] == pchar) {
            pcnt++;
            l++;
        }

        int scnt = 0;
        while (r < slen && s[r] == pchar) {
            scnt++;
            r++;
        }

        if (scnt < pcnt || scnt > 2 * pcnt) {
            return false;
        }
    }

    return l == plen && r == slen;
}

int main() {
    int t;
    cin >> t;
    vector<string> ans;

    while (t--) {
        cin >> p >> s;

        nottryingenouf();

        if (nottryingenouf()) {
            ans.push_back("YES");
        } else {
            ans.push_back("NO");
        }
    }

    for (auto it : ans) {
        cout << it << endl;
    }

    return 0;
}
