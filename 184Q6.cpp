#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n;
    cin>>n;

    vector<int> arr(n);
    vector<int> brr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<n; i++){
        cin>>brr[i];
    }

    if((arr[0] != brr[0]) || arr[n-1] != brr[n-1]){
        cout<<"No"<<endl;
        return;
    }
    for(int i = 1; i<n-1; i++){
        int temp = arr[i-1]|arr[i+1];
        // brr[i] = temp;

        if(brr[i]!=arr[i])brr[i] = temp;
    }

    int flag = false;

    for(int i=0; i<n; i++){
        if(arr[i]!=brr[i]){
            flag = true;
            break;
        }
    }

    if(!flag){
        cout<<"No"<<endl;
    }
    else cout<<"Yes"<<endl;
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