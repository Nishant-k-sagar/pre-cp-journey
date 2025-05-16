#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
    int d, c, s1[3] , s2[3] , sum1= 0, sum2 = 0;
    cin >> d>> c;

    for (int i=0; i<3 ; ++i){
        cin >> s1[i];
        sum1 = sum1 +  s1[i];
    }
     for (int i=0; i<3 ; ++i){
        cin >> s2[i];
        sum2 = sum2 +  s2[i];
    }

    int costwocp= sum1 +sum2+ d+ d;
    int costwcp=sum1+sum2+c;

    if(sum1 <150){
        costwcp = costwcp + d;}

    if (sum2 < 150){
            costwcp = costwcp + d;
        }

    if (costwcp < costwocp){
        cout<< "YES"<<endl;}
        else
        cout<< "NO"<<endl;
    }
    return 0;
    }

