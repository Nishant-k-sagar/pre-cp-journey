#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class UnionFind {
    vector<int> parent, rank;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return;
        if(rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if(rank[px] == rank[py]) rank[px]++;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    vector<set<int>> getComponents() {
        vector<set<int>> components(parent.size());
        for(int i = 0; i < parent.size(); i++) {
            components[find(i)].insert(i);
        }
        components.erase(remove_if(components.begin(), components.end(), [](const set<int>& s) { return s.empty(); }), components.end());
        return components;
    }
};

int solve(int n, int m1, int m2, vector<pair<int,int>>& edges1, vector<pair<int,int>>& edges2) {
    UnionFind uf1(n), uf2(n);
    
    for(auto& e : edges1) uf1.unite(e.first-1, e.second-1);
    for(auto& e : edges2) uf2.unite(e.first-1, e.second-1);
    
    auto comp1 = uf1.getComponents();
    auto comp2 = uf2.getComponents();
    
    int operations = 0;
    
    if(comp1.size() != comp2.size()) {
        operations += abs((int)comp1.size() - (int)comp2.size());
    }
    
    set<pair<int,int>> currentEdges;
    for(auto& e : edges1) {
        currentEdges.insert({min(e.first-1, e.second-1), max(e.first-1, e.second-1)});
    }
    
    set<pair<int,int>> targetEdges;
    for(auto& e : edges2) {
        targetEdges.insert({min(e.first-1, e.second-1), max(e.first-1, e.second-1)});
    }
    
    for(auto& e : currentEdges) {
        if(!targetEdges.count(e)) operations++;
    }
    
    for(auto& e : targetEdges) {
        if(!currentEdges.count(e)) operations++;
    }
    
    return operations;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, m1, m2;
        cin >> n >> m1 >> m2;
        
        vector<pair<int,int>> edges1(m1), edges2(m2);
        
        for(int i = 0; i < m1; i++) {
            cin >> edges1[i].first >> edges1[i].second;
        }
        
        for(int i = 0; i < m2; i++) {
            cin >> edges2[i].first >> edges2[i].second;
        }
        
        cout << solve(n, m1, m2, edges1, edges2) << "\n";
    }
    
    return 0;
}
