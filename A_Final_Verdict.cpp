#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n, x;
    cin>>n>>x;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int sum = 0;
    for(int i=0; i<n ;i++){
        sum+=arr[i];
    }
    if(sum % n == 0 && sum / n == x){
        cout<<"YES"<<endl;
    }
    else
    cout<<"NO"<<endl;
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