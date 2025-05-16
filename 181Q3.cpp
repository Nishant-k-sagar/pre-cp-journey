#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

string solve(int num) {
    string res = "1";
    for (int i = 0; i < num; i++) {
        int carry = 0;
        for (int j = res.size() - 1; j >= 0; j--) {
            int dig = (res[j] - '0') * 2 + carry;
            res[j] = (dig % 10) + '0';
            carry = dig / 10;
        }
        if (carry) res = char(carry + '0') + res;
    }
    return res;
}

void nottryingenouf()
{
    // try it harder
    int n;
    string s;
    cin >> n >> s;

    int a = 0, b = 0, num = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == '0') a++;
        else b++;
        if (a == b) num++;
    }

    cout << solve(num) << endl;
}

int main()
{
    fast
        ll t;
    cin >> t;
    while (t--)
    {
        nottryingenouf();
    }
}