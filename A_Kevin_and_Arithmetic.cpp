#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int codewithlove()
{
    int n;
    cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int cnt = 0;
    ll sum = 0;
    vector<bool> used(n, false);

    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int j = 0; j < n; j++)
        {
            if (!used[j] && (sum + arr[j]) % 2 == 0)
            {
                sum += arr[j];
                cnt++;
                used[j] = true;
                while (sum % 2 == 0)
                    sum /= 2;
                found = true;
                break;
            }
        }

        if (!found)
        {
            for (int j = 0; j < n; j++)
            {
                if (!used[j])
                {
                    sum += arr[j];
                    used[j] = true;
                    break;
                }
            }
        }
    }

    cout<<cnt<<endl;;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        codewithlove();
    }

    return 0;
}