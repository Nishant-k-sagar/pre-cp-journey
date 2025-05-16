#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int solve(vector<int> &arr, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
    unordered_map<int, int> mp;
    int maxi = -1;
    
    for (int i = 0; i < arr.size(); i++) { 
        mp[arr[i]]++;
        maxi = max(maxi, arr[i]);
    }
    
    for (auto it : mp) {
        pq.push({it.second, it.first});
    }
    
    while (k > 0 && !pq.empty()) {
        auto val = pq.top();
        pq.pop();
        int count = val.first;
        int value = val.second;
        
        if (count > k) {
            count -= k;
            pq.push({count, value});
            k = 0;
        } else {
            k -= count;
        }
    }
    if(pq.size()==0){
        return 1;
    }
    
    return pq.size();
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr, k) << endl; // Fixed function call to print the result
    }

    return 0;
}
