#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int sizeB = 2 * n;
        vector<long long> b(sizeB);
        for (int i = 0; i < sizeB; i++){
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        unordered_set<long long> bset;
        bset.reserve(sizeB * 2);
        for(auto x : b) bset.insert(x);
 
        vector<long long> oddGroup(b.begin(), b.begin() + n);
        vector<long long> evenGroup(b.begin() + n, b.end());
 
        long long sumOdd = 0, sumEven = 0;
        for(auto x : oddGroup) sumOdd += x;
        for(auto x : evenGroup) sumEven += x;
 
        long long candidate = sumEven - sumOdd;
        bool validA = (candidate > 0 && candidate <= 1000000000000000000LL && bset.find(candidate) == bset.end());
 
        if(!validA){
            for (int i = 0; i < n; i++){
                long long newCandidate = candidate - 2 * ( evenGroup[i] - oddGroup[n-1-i] );
                if(newCandidate > 0 && newCandidate <= 1000000000000000000LL && bset.find(newCandidate) == bset.end()){
                    swap(evenGroup[i], oddGroup[n-1-i]);
                    candidate = newCandidate;
                    validA = true;
                    break;
                }
            }
        }
 
        if(validA){
            vector<long long> a;
            a.push_back(candidate);
            for (int i = 0; i < n; i++){
                a.push_back(evenGroup[i]);
                a.push_back(oddGroup[i]);
            }
            for(auto x : a) cout << x << " ";
            cout << "\n";
            continue;
        }
 
        long long a1 = b.back();
        vector<long long> bprime(b.begin(), b.end()-1);
        long long S = 0;
        for(auto x : bprime) S += x;
 
        bool foundB = false;
        long long xCandidate = 0;
        vector<long long> evenGroupB, oddGroupB;
 
        int sz = (int)bprime.size();
        vector<long long> O(bprime.begin() + (sz - n), bprime.end());
        long long sumO = 0;
        for(auto x : O) sumO += x;
        xCandidate = a1 + 2 * sumO - S;
        if(xCandidate > 0 && xCandidate <= 1000000000000000000LL && bset.find(xCandidate) == bset.end() && xCandidate != a1){
            evenGroupB = vector<long long>(bprime.begin(), bprime.begin() + (sz - n));
            evenGroupB.push_back(xCandidate);
            oddGroupB = O;
            foundB = true;
        } else {
            O = vector<long long>(bprime.begin(), bprime.begin() + n);
            sumO = 0;
            for(auto x : O) sumO += x;
            xCandidate = a1 + 2 * sumO - S;
            if(xCandidate > 0 && xCandidate <= 1000000000000000000LL && bset.find(xCandidate) == bset.end() && xCandidate != a1){
                evenGroupB = vector<long long>(bprime.begin() + n, bprime.end());
                evenGroupB.push_back(xCandidate);
                oddGroupB = O;
                foundB = true;
            }
        }
 
        if(!foundB){
            vector<long long> a;
            a.push_back(candidate);
            for (int i = 0; i < n; i++){
                a.push_back(evenGroup[i]);
                a.push_back(oddGroup[i]);
            }
            for(auto x : a) cout << x << " ";
            cout << "\n";
            continue;
        }
 
        vector<long long> a;
        a.push_back(a1);
        for (int i = 0; i < n; i++){
            a.push_back(evenGroupB[i]);
            a.push_back(oddGroupB[i]);
        }
        for(auto x : a) cout << x << " ";
        cout << "\n";
    }
    return 0;
}