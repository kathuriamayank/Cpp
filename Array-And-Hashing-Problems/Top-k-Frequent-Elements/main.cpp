#include <iostream>
#include <vector>
#include <map>


// class Solution {
// public:
//     std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
//         std::map<int,int> countMap;
//         std::multimap<int,int> countToNumbermap;
//         std::vector<int> result;

//         for(const auto&it:nums)
//         {
//             countMap[it]+=1;
//         }

//         for(auto &it:countMap)
//         {
//             countToNumbermap.insert(std::make_pair(it.second,it.first));
//         }

//         auto revIt= countToNumbermap.rbegin();

//         while(k-- && revIt!=countToNumbermap.rend())
//         {
//             // auto revIt=countToNumbermap.begin();
//             result.push_back(revIt->second);
//             ++revIt;
//         }

//         return result;
//     }
// };


class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> preVector(nums.size()+1,1);
        std::vector<int> postVector(nums.size()+1,1);
        std::vector<int> result;

        int i=1,j=nums.size()-1;
        while(i<=nums.size())
        {
            preVector[i]=preVector[i-1]*nums[i-1];
            i++;
        }

        while(j>=0)
        {
            postVector[j]=postVector[j+1]*nums[j];
            j--;
        }

        for(int i=0; i<nums.size(); i++)
        {
            result.push_back(preVector[i]*postVector[i+1]);
        }

        return result;    
    }
};

int main()
{
    Solution s;
    std::vector<int> vec{2,3,4,5,6};
    auto result=s.productExceptSelf(vec);
    return 0;
}

