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
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    unordered_set<int> st(arr.begin(), arr.end());
    sort(arr.begin(), arr.end());

    if (st.size() == 1 && st.count(0)) {
        cout << -1 << endl;
    } else {
        int maxi = *max_element(arr.begin(), arr.end());
        if (maxi > 0) {
            cout << maxi << " " << maxi << endl;
        } else {
            int mini = *min_element(arr.begin(), arr.end());
            cout << mini << " " << mini << endl;
        }
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