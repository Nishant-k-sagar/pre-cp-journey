#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n;
    cin >> n; // This was missing
    vector<int> arr(n);

    int cnt1 = 0;
    int cnt2 = 0;
    int cnt0 = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 1) {
            cnt1++;
        } else if (arr[i] == 2) {
            cnt2++;
        } else if (arr[i] == 0) {
            cnt0++;
        }
    }

    if (n % 2 == 1) {
        cout << "No" << endl;
        return;
    }

    if (cnt1 > n / 2 || cnt2 > n / 2) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

int main()
{
    fast
    ll t;
    cin >> t;
    while (t--) {
        nottryingenouf();
    }
}
