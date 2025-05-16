int main(){
    int n;
    cin >> n;

    int start[n], end[n];

    // Taking input - O(n)
    for(int i=0;i<n;i++){
        cin >> start[i] >> end[i];
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;

    // Inserting in the priority queue - O(nlogn)
    for(int i = 0;i<n;i++){
        p.push({end[i],start[i]});
    }

    vector<pair<int,int>> ans;

    // O(nlogn)
    while(!p.empty()){
        pair<int,int> temp = p.top();
        p.pop();
        if(ans.size() == 0){
            ans.push_back(temp);
        }
        else{
            if(ans[ans.size()-1].first <= temp.second){
                ans.push_back(temp);
            }
        }
    }

    // O(n)
    for(int i=0;i<ans.size();i++){
        cout << ans[i].second << " " << ans[i].first << endl;
    }

    // Total Time Complexity - O(nlogn)
    // Space Complexity - O(n)

    return 0;
}