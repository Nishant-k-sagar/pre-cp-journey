#include <bits/stdc++.h>
using namespace std;

void codewithlove()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), brr(m);

    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    for (int i = 0; i < m; i++) 
        cin >> brr[i];

    priority_queue<int> pq;

    for (int i = 0; i < m; i++) 
        pq.push(brr[i]);

    map<int, int> mp;

    for (int i = 0; i < n; i++) 
        mp[arr[i]]++;

    bool flag = 1;

    for (int i = 0; i < n - m + n; i++) {
        if (pq.empty()) {
            flag = 0;
            break;
        }

        int x = pq.top();
        pq.pop();

        if (mp[x] == 0) {
            pq.push(x / 2);
            pq.push((x + 1) / 2);
        } else {
            mp[x]--;
        }
    }

    if (flag && pq.empty()) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        codewithlove();
    }
    return 0;
}
