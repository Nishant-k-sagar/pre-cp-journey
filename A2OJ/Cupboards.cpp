#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;

    vector< pair <int, int> > p;

    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        p.push_back(make_pair(a,b));
    }

    int count1=0, count2=0, count3=0, count4=0;
    for(int i=0; i<n; i++){
        if(p[i].first==0){
            count1++;
        }
        if(p[i].first==1){
            count2++;
        }
        if(p[i].second==0){
            count3++;
        }
        if(p[i].second==1){
            count4++;
        }
    }

    cout<<min(count1,count2)+min(count3,count4)<<endl;

    
    return 0;
}