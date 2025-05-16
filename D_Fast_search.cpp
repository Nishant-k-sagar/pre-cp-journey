#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

int lowbound(vector<int> &arr, int l){
    int n = arr.size();

    int lowerBoundIdx = 0;

    int low = 0;
    int high = n;

    while( low  < high){
        int mid = low + (high - low)/2;

        // if(arr[mid] == r){
        //     lowerBoundIdx = mid - 1;
        // }
        if(arr[mid] < l){
            low = mid + 1;
        }
        else {

            high = mid;
        }
    }
    return low;
}

int upbound(vector<int> &arr, int r){
    int n = arr.size();

    int low = 0;
    int high = n;

    while( low < high){
        int mid = low + (high - low)/2;

        if(arr[mid] <= r){
            low = mid + 1;
        }
        
        else {

            high = mid;
        }
    }
    return low;
}


void nottryingenouf(vector<int> &arr, int &l, int &r)
{
    // try it harder
    cout<<upbound(arr , r) - (lowbound(arr, l)) << " ";

}

int main()
{
    fast

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    int k;
    cin>>k;

    //     ll t;
    // cin >> t;
    while (k--)
    {   
        int l,r;
        cin>>l>>r;

        nottryingenouf(arr, l, r);
    }
}