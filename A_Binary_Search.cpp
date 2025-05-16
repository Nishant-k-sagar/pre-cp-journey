#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf(vector<ll> &arr, vector<ll> &q, int i)
{
    // try it harder

    bool flag = true;

    int n = arr.size();
    int low = 1;
    int high = n;

    while(low<=high){
        int mid = low + (high - low)/2;

        if(arr[mid] == q[i]){
            cout<<"YES"<<endl;
            flag = false;
            break;
        }
        else if(arr[mid]< q[i]){
            low = mid + 1;
        }
        else high = mid - 1;
    }

    if(flag){
        cout<<"NO"<<endl;
    }

}

int main()
{
    fast
        
    ll n, k;
    cin>>n>>k;

    vector<ll> arr(n+1);

    for(ll i=1; i<=n; i++){
        cin>>arr[i];
    }

    vector<ll> queries(k+1);

    for(ll i=1; i<=k; i++){
        cin>>queries[i];
    }
        
        // ll t;
    // cin >> t;
    ll i=1;
    while (i)
    {   
        if(i == k+1)break;
        nottryingenouf(arr, queries, i);
        i++;
    }
}