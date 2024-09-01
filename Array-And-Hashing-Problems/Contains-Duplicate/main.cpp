#include <vector>
#include <algorithm>
#include <unordered_map>

/*
    Sorting Solution
*/

// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {

//         std::sort(nums.begin(),nums.end());

//         bool isDuplicate{false};

//         for(int i=0; i<nums.size()-1; i++)
//         {
//             if(nums[i]==nums[i+1])
//             {
//                 isDuplicate=true;
//                 break;
//             }
//         }
        
//         return isDuplicate;
//     }
// };


class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {

        std::unordered_map<int,int> countMap;
        
        for(const auto&it: nums)
        {
            countMap[it]+=1;
        }

        bool isDuplicate=false;

        for(const auto&i: countMap)
        {
            if(i.second >1)
            {
                isDuplicate=true;
                break;
            }
        }

        return isDuplicate;
    }
};