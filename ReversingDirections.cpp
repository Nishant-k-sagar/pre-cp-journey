#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    int n;
    cin >> n;
    cin.ignore();
    
    vector<string> vec(n);
    vector<string> dir(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        
        vec[i] = s.substr(s.find(' ') + 1);
        
        if (s[0] == 'R') {
            dir[i] = "Left";
        } else {
            dir[i] = "Right";
        }
    }

    cout << "Begin " << vec[n - 1] << "\n";

    for (int i = n - 2; i >= 0; i--)
    {
        cout << dir[i + 1] << " " << vec[i] << "\n";
    }
    cout << endl;
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        nottryingenouf();
    }
}