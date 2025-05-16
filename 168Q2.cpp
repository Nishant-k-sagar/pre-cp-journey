#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void codewithlove()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> res(n, 0);
    int maxScore = arr[0];
    res[0] = 1; 

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxScore)
        {
            res[i] = 1;
            maxScore = arr[i];
        }
        else
        {
            res[i] = 0;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        codewithlove();
    }

    return 0;
}
