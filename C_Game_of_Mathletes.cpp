#include <bits/stdc++.h>
using namespace std;

void codewithlove() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int cnt = 0;
    int left = 0;
    int right = n-1;

    while(left<right){
        if(arr[left]+arr[right] == k){
            cnt++;
            left++;
            right--;
        }
        else if(arr[left]+arr[right]<k)left++;
        else right--;
    }


    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

     int t;
    cin >> t;
    while (t--)
    {
        codewithlove();
        // cout << (codewithlove() ? "YES\n" : "NO\n");
    }
    return 0;
}
