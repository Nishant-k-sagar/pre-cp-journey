#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
     vector<int> vec(5);
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        cin >> vec[i];
        sum += vec[i];
    }

    if (sum >= 35) {
        cout << 0 << endl;
        return;
    }

    sort(vec.begin(), vec.end());

    int ans = 0;
    for (int i = 0; i < 5 && sum < 35; i++) {
        sum += (10 - vec[i]);
        ans++;
    }

    cout << ans * 100 << endl;
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