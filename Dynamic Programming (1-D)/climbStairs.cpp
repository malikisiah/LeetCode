#include <bits/stdc++.h>

using namespace std;

int climbingStairs(int n ){
    vector <int> fib;

    fib.push_back(1);
    fib.push_back(2);


    for(int i =0, j=i+2; fib.size() <= n; i++, j++){
        fib.push_back (fib[i] + fib[i+1]);
    }

    return fib[n-1];
}


int main(){
    cout << climbingStairs(6) << endl;
}