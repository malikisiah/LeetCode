#include <bits/stdc++.h>

using namespace std;


int countBinarySubstrings(string s);

int main(){


    string s = "11000110";

    countBinarySubstrings(s);
}


int countBinarySubstrings(string s) {
        int count = 0;
        int prev = 0;
        int curr = 1;

        for(int i =1;i<s.size(); i++){

        if (s[i] != s[i-1]){
        count+=min(prev,curr);
        prev = curr;
        curr = 1;


        }

        else{
        curr++;
        }
        }

        return count+=min(prev,curr);


    }