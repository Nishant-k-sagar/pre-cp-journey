#include <bits/stdc++.h>
using namespace std;
// Custom comparison function
bool comp(string a, string b) {
    if (a.size() != b.size()) {
        // Compare by string length
        return a.size() < b.size();
    } else {
        // If lengths are equal, compare lexicographically
        return a < b;
    }
}

int main() {
    // vector<string> strings = {"apple", "banana", "kiwi", "grape"};

    vector<string> v;
    
    for(int i=0; i<5; i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    // Sort the vector using the custom comparison function
    sort(v.begin(), v.end(), comp);

    // Print the sorted strings
    for (const auto& str : v) {
        std::cout << str << std::endl;
    }

    return 0;
}
