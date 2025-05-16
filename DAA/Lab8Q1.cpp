#include<bits/stdc++.h>
using namespace std;

int minCost(int n, vector<vector<int>> &g) {
    vector<int> dist(n,0);
 
    for(int i = n-2;i >= 0;i--){
        dist[i] = INT_MAX;
        for(int j = i;j<n;j++){
            if(g[i][j] == -1) continue;
            dist[i] = min(dist[i], g[i][j] + dist[j]);
        }
    }
 
    return dist[0];
}

int main(){
    int n,m;
    cin >> n >> m;

    vector<vector<int>> g(n,vector<int>(n,-1));

    int u,v,w;
    for(int i = 0;i<m;i++){
        cin >> u >> v >> w;
        u--;v--;
        g[u][v] = w;
    }

    cout << minCost(n,g) << endl;
}