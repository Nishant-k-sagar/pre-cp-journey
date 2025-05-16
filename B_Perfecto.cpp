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

    if(n==1){
        cout<<-1<<endl;
        return;
    }

    vector<int> arr(n);
    arr[0] = 2;
    arr[1] = 1;


    for(int i=2; i<n; i++){
        arr[i] = i+1;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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