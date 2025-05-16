#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> H(N);
    
    for (int i = 0; i < N; i++) cin >> H[i];
    
    unordered_map<int, int> height_count;
    int friendships = 0;
    
    for (int i = 0; i < N; i++) {
        friendships += height_count[H[i]];
        height_count[H[i]]++;
    }
    
    cout << friendships << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
