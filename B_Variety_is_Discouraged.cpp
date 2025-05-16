#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int maxLen = 0, start = -1;
    int left = 0;

    for (int right = 0; right < n; right++)
    {
        if (freq[arr[right]] > 1)
        {
            left = right + 1;
        }
        else
        {
            int len = right - left + 1;
            if (len > maxLen)
            {
                maxLen = len;
                start = left;
            }
        }
    }

    if (maxLen == 0)
    {
        cout << "0\n";
    }
    else
    {
        cout << start + 1 << " " << start + maxLen << "\n";
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