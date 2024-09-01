#include <vector>
#include <queue>
#include <unordered_map>
#include <vector>

using pp=std::pair<int,int>;


struct mycomp
{
    bool operator()(const pp&a, const pp&b)
    {
        return a.second<b.second;
    }
};

class Solutio0n {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::vector<int> result;
        std::unordered_map<int,int> frequencyMap;
        std::priority_queue<pp,std::vector<pp>, mycomp> frequencyHeap;

        for(const auto &it:nums)
        {
            frequencyMap[it]+=1;
        }


        for(const auto &it: frequencyMap)
        {
            frequencyHeap.push(std::make_pair(it.first,it.second));
        }
        
        while(k--)
        {
            result.push_back(frequencyHeap.top().first);
            frequencyHeap.pop();
        }
        return result;

    }
};

int main()
{
    return 0;
}