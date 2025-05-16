#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    for (int x = 1; x <= 100; x++) {
        bool flags = false, flagg = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] < x) flags = true;
            if (arr[i] > x) flagg = true;
        }
        if (flags && flagg) {
            count++;
        }
    }

    cout << count << endl;
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