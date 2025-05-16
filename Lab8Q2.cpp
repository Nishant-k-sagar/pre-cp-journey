#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;

    int s[n], e[n];

    for(int i=0;i<n;i++){
        s[i] = i;
    }

    for(int i=0;i<n;i++){
        cin >> e[i];
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;

    
    for(int i = 0;i<n;i++){
        p.push({e[i],s[i]});
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

    int count = 0;
    for(int i=0;i<ans.size();i++){
        cout << ans[i].second << " " << ans[i].first << endl;
        count++;
    }
    cout<<count<<endl;

    // Total Time Complexity - O(nlogn)

    return 0;
}