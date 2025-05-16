#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        
        long long maxXOR = -1;
        array<int, 4> bestPair = {0, 0, 0, 0}; // Using array instead of tuple for simplicity
        
        vector<long long> prefixValues(n + 1, 0);
        
        // Precompute prefix values
        for (int i = 0; i < n; ++i) {
            prefixValues[i + 1] = (prefixValues[i] << 1) | (s[i] - '0');
        }
        
        unordered_map<long long, pair<int, int>> seen;
        
        for (int l1 = 0; l1 < n; ++l1) {
            for (int r1 = l1; r1 < n; ++r1) {
                // Calculate value of current substring using XOR of prefix values
                long long num1 = prefixValues[r1 + 1] ^ prefixValues[l1];
                
                // Check against all previously seen values
                for (const auto& [num2, pos] : seen) {
                    long long currentXOR = num1 ^ num2;
                    if (currentXOR > maxXOR) {
                        maxXOR = currentXOR;
                        bestPair = {pos.first + 1, pos.second + 1, l1 + 1, r1 + 1};
                    }
                }
                
                seen[num1] = {l1, r1};
            }
        }
        
        // Output result with spaces between indices
        cout << bestPair[0] << " " << bestPair[1] << " " 
             << bestPair[2] << " " << bestPair[3] << "\n";
    }
    
    return 0;
}