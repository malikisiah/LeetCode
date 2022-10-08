#include <bits/stdc++.h>
using namespace std;


int minCostClimbingStairs(vector <int> &cost){
    cost.push_back(0);

    int i = cost.size()-3;

    while (i >= 0){
        cost[i] = min((cost[i] + cost[i+1]), (cost[i] + cost[i+2]));
        i--;
    }

    return min(cost[0], cost[1]);




}