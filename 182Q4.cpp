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

    vector<vector<int>> mat(n, vector<int>(n));
    int maxi = 0, mini = 1e9;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            maxi = max(maxi, mat[i][j]);
            mini = min(mini, mat[i][j]);
        }
    }

    int maxScore = -1;
    int minK = mini;

    for (int K = mini; K <= maxi; K++)
    {
        ll r1sum = 0;
        for (int j = 0; j < n; j++)
        {
            r1sum += min(mat[0][j], K);
        }

        int score = 0;
        for (int i = 1; i < n; i++)
        {
            int rsum = 0;
            for (int j = 0; j < n; j++)
            {
                rsum += min(mat[i][j], K);
            }
            if (rsum > r1sum)
            {
                score++;
            }
        }

        if (score > maxScore || (score == maxScore && K < minK))
        {
            maxScore = score;
            minK = K;
        }
    }

    cout << minK << endl;
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