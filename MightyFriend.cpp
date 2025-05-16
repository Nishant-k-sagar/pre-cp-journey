#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(false), cin.tie(0);

void nottryingenouf()
{
    // try it harder
    int n, k;
    cin>>n>>k;

    vector<int> vec(n);

    for(int i=0; i<n; i++){
        cin>>>vec[i];
    }

    vector<int> m, t;

    for(int i=0; i<n; i++){
        if(i&1)t.push_back(vec[i]);
        else m.push_back(vec[i]);
    }

    sort(t.begin(), t.end());

    sort(m.begin(), m.end(), greater<int> ());

    for(int i=0; i<min(t.size(), m.size()) && k>0; i++){
        if(t[i]< m[i]){
            swap(t[i], m[i]);
            k--;
        }
    }

    int msum = accumulate(m.begin(), m.end(), 0);
    int tsum = accumulate(t.begin(), t.end(), 0);

    if(tsum>msum)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

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