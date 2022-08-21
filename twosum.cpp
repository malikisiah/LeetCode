#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target);

int main()
{

    vector<int> nums = {2,3,4};
    int target = 6;


    twoSum(nums, target);



}

vector<int> twoSum(vector<int> &nums, int target)
{
    vector <int> result;
    unordered_map<int,int> hashmap;




    for (int i =0; i<nums.size(); i++){
        int difference = target - nums[i];

        if (hashmap.find(difference) != hashmap.end()){ // if difference is found in hashmap
            result.push_back(hashmap[difference]);
            result.push_back(i);
            break;
        }

        hashmap.insert({nums[i], i}); // if difference is not found in hashmap
    }



    return result;

}
