#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;

    int s[n], e[n];

    // cout<<"Enter the start and points of activities : "<<endl;
    for(int i=0;i<n;i++){
        cin >> s[i] >> e[i];
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

    cout<<"Activities selected for : ";
    for(int i=0;i<ans.size();i++){
        cout << ans[i].second << " " << ans[i].first << endl;
        count++;
    }
    cout<<"Max number Of activity : "<<count<<endl;

    // Total Time Complexity - O(nlogn)

    return 0;
}