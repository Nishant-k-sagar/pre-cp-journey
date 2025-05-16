#include<bits/stdc++.h>
using namespace std;


int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if(dp[amount] != INT_MAX){
        return dp[amount];}
        else
        return -1;
}

int main() {
    vector<int> coins = {9,6,5,1};
    int amount = 11;
    cout << minCoins(coins, amount) << endl; 

    amount =7;
    cout<< minCoins(coins, amount) <<endl;
    return 0;
}