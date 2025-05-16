#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf(vector<int> &arr, vector<int> &q, int i)
{
    // try it harder





    // int idx = 0;

    // int n = arr.size();
    // int low = 0;
    // int high = n;

    // while(low+1 < high){
    //     int mid = low + (high - low)/2;

    //     if(arr[mid] <= q[i]){
    //         low = mid;
    //         // if(arr[high] <= q[i]) idx = high;
    //     }
    //     else {
    //         high = mid;
    //     }
    // }

    // if(q[i]> arr[n-1]){
    //     cout<<n-1<<endl;
    // }
    // else {
        // cout<<low<<endl;
    // }



    int ans = upper_bound(arr.begin(), arr.end(), q[i]) - arr.begin();

    cout<<ans<<endl;
}

int main()
{
    fast
    
    int n, k;
    cin>>n>>k;

    vector<int> arr(n+1);
    vector<int> q(k+1);

    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i = 1; i<=k; i++){
        cin>> q[i];
    }

    int i = 1;

    while (i)
    {   
        if(i == k+1)break;
        nottryingenouf(arr, q, i);
        i++;
    }
}