#include<bits/stdc++.h>
using namespace std;

bool codewithlove(const vector<vector<int>>& cards, vector<int>& p, int n, int m) {
    int last = -1;
    vector<int> pos(n, 0);
    
    for(int round = 0; round < m; round++) {
        for(int i = 0; i < n; i++) {
            int cow = p[i] - 1;
            if(pos[cow] >= m || cards[cow][pos[cow]] <= last) {
                return false;
            }
            last = cards[cow][pos[cow]];
            pos[cow]++;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        vector<vector<int>> cards(n, vector<int>(m));
        vector<pair<int, int>> first(n);
        vector<pair<int, int>> last(n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> cards[i][j];
            }
            sort(cards[i].begin(), cards[i].end());
            first[i] = {cards[i][0], i};
            last[i] = {cards[i][m-1], i};
        }
        
        vector<int> order(n);
        for(int i = 0; i < n; i++) order[i] = i;
        
        sort(order.begin(), order.end(), [&](int a, int b) {
            if(first[a].first != first[b].first)
                return first[a].first < first[b].first;
            return last[a].first < last[b].first;
        });
        
        vector<int> p(n);
        for(int i = 0; i < n; i++) {
            p[i] = order[i] + 1;
        }
        
        if(codewithlove(cards, p, n, m)) {
            for(int i = 0; i < n; i++) {
                cout << p[i] << (i < n-1 ? " " : "\n");
            }
        } else {
            cout << "-1"<<endl;
        }
    }
    return 0;
}