#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using pp=std::pair<int,int>;

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        using pp=std::pair<int,int>;

        std::priority_queue<pp, std::vector<pp>> heap;
        std::vector<int> result;

        for(int i=0; i<k; i++)
        {
            heap.push(std::make_pair(result[i],i));
        }

        result.push_back(heap.top().first);

        for(int i=k; i<nums.size(); i++)
        {
            while(heap.top().second < i-k+1)
            {
                heap.pop();
            }

            heap.push(std::make_pair(nums[i],i));
            
            result.push_back(heap.top().first);
        }

        return result;
        
    }
};

int main()
{
    // //Max Heap
    // std::priority_queue<int> pq;

    // pq.push(1);
    // pq.push(2);
    // pq.push(3);
    // pq.push(4);
    // pq.push(5);

    // // std::cout<<"Element at top:"<<pq.top()<<std::endl;

    // while(!pq.empty())
    // {
    //     std::cout<<"Top:"<<pq.top()<<std::endl;
    //     pq.pop();
    // }


    // std::cout<<"\n\n";

    // std::priority_queue<int, std::vector<int>, std::greater<int>> pq_min;

    // pq_min.emplace(10);
    // pq_min.emplace(9);
    // pq_min.emplace(8);
    // pq_min.emplace(7);
    // pq_min.emplace(6);

    // while (!pq_min.empty())
    // {
    //     std::cout<<"Top:"<<pq_min.top()<<std::endl;
    //     pq_min.pop();
    // }
    

    Solution s;

    std::vector<int> v{1,3,-1,-3,5,3,6,7};
    auto ans=s.maxSlidingWindow(v,3);
    
    
    
    return 0;
}
