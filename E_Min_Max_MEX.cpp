#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

bool chkSplit(vector<int> &arr, int k, int x)
{
    int n = arr.size();
    int parts = 0;
    int i = 0;
    
    while (i < n)
    {
        vector<bool> temp(x, false);
        int tofind = x;
        
        while (i < n && tofind > 0)
        {
            if (arr[i] < x && !temp[arr[i]])
            {
                temp[arr[i]] = true;
                tofind--;
            }
            i++;
        }
        
        if (tofind == 0)
        {
            parts++;
            if (parts >= k) return true;
        }
        else
        {
            break;
        }
    }
    
    return false;
}

int nottryingenouf()
{
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    if (k == n)
    {
        int minmex = INT_MAX;
        for (int i = 0; i < arr.size(); i++)
        {
            int temp1 = 0;
            if (arr[i] == 0)
            {
                temp1 = 1;
            }
            minmex = min(minmex, temp1);
        }
        return minmex;
    }
    
    int l = 0;
    int h = n + 1;
    
    while (l < h)
    {
        int mid = l + (h - l) / 2;
        
        if (chkSplit(arr, k, mid))
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    
    return l - 1;
}

int main()
{
    fast
    ll t;
    cin >> t;
    while (t--)
    {
        cout << nottryingenouf() << endl;
    }
    return 0;
}