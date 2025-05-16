#include<bits/stdc++.h>
using namespace std;

// Prim's Algorithm
// E = n^2
    // ElogE = n^2logn^2 = n^2logn
    // Time Complexity - O(n^2logn)
int spanningTree(int n, vector<pair<int,int>> adj[]){
    //Min Heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<bool> vis(n, false);
    pq.push({0,0});

    int sum = 0;

    while(!pq.empty()){
        auto it = pq.top(); //loge
        pq.pop();

        int node = it.second;
        int weight = it.first;

        if(vis[node]) continue;
        
        vis[node] = 1;
        sum += weight;

        //Time Complexity: E log(E)
        for(auto child : adj[node]){
            int adjNode = child.first;
            int adjWeight = child.second;

            if(!vis[child.first]){
                pq.push({adjWeight, adjNode}); //log(E)
            }
        }
    }

    return sum;
}

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> points;
    vector<pair<int,int>> adj[n];

    int x,y;
    for(int i = 0;i<n;i++){
        cin >> x >> y;
        points.push_back({x,y});
    }

    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            int x1 = points[i].first;
            int y1 = points[i].second;

            int x2 = points[j].first;
            int y2 = points[j].second;

            int dist = abs(x2-x1) + abs(y2-y1);
            adj[i].push_back({j,dist});
            adj[j].push_back({i,dist});
        }
    }

    // Time Complexity: O(ElogE)
    
    cout << spanningTree(n,adj) << endl;
    
    
}