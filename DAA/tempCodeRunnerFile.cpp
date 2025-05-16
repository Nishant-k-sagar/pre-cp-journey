#include<bits/stdc++.h>
using namespace std;

int maxPoints(vector<int>& points,vector<int>& fi) {
    int n = points.size();
    vector<int> dp(n + 1, 0);

    for (int i = n; i >=1; ++i) {
        int skip = dp[i - 1];
        int ans = 0;
        if (i > 1 + fi[i - 1]) {
            ans = dp[i - 1 - fi[i - 1]] + points[i - 1];
        }
        dp[i] = max(skip, ans);
    }

    return dp[n];
}

int main() {
    vector<int> points = {3, 2, 5, 8};
    vector<int> fi = {1, 1, 1, 2};

    cout << "Maximum points that can be obtained: " << maxPoints(points, fi) << std::endl;
    
    return 0;
}