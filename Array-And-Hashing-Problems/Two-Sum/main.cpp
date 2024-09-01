#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {

        std::unordered_map<int,int> valueIndexMap;
         std::vector<int> result(2,0);
        for(int i=0; i<nums.size(); i++)
        {
            if(valueIndexMap.find(target-nums[i])!=valueIndexMap.end())
            {
                result[0]=valueIndexMap.find(target-nums[i])->second;
                result[1]=i;
                break;
            }
            else
            {
                valueIndexMap[nums[i]]=i;
            }
        }
        return result;
    }
};

int main()
{
    std::vector<int> v{3,3};
    int target=6;
    Solution s;
    auto result=s.twoSum(v,target);
    
    return 0;

}

