#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, index;
    double a, max(0);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (ceil(a / m) >= max)
        {
            index = i;
            max = ceil(a / m);
        }
    }

    cout << index << endl;
    return 0;
}
