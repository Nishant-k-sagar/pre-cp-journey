#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

bool isUniversal(string &s) {
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - 1 - i]){
            continue;
        } 
        else {
            return s[i] < s[n - 1 - i];
        }
    }
    return false;
}


void nottryingenouf()
{
    // try it harder
    int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        string temp = string(n, s[0]);
        if (n == 1 || s == temp ) {
            cout << "NO"<<endl;
            return;
        }

        if (isUniversal(s) || k >= 1) {
            cout << "YES"<<endl;
        } else {
            cout << "NO"<<endl;
        }

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



        