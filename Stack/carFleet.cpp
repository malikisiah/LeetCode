#include <bits/stdc++.h>
using namespace std;

int carFleet(int target, vector<int> &position, vector<int> &speed)
{
    deque<pair<int, double>> cars;

    for (int i = 0; i < position.size(); i++){
        double time = (double) (target - position[i]) / speed[i];


        cars.push_back({position[i], time});
    }

    sort(cars.begin(), cars.end());

    double maxTime = 0.0;
    int result = 0;
    for (int i = cars.size() -1; i>=0; i--){
        double time = cars[i].second;

        if (time > maxTime){
            maxTime = time;
            result ++;
        }



    }

    return result;
}