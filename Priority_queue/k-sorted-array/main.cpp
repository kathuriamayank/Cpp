#include <iostream>
#include <vector>
#include <queue>

void swap(std::vector<int> &v,int i,int j)
{
    int temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}

void insertionSort(std::vector<int> &v)
{
    for(int i=1; i<v.size(); i++)
    {
        int j=i;
        while(j>=1 && v[j]<v[j-1])
        {
            swap(v,j,j-1);
            j--;
        }
    }
}

void disp(const std::vector<int> &v)
{
    for(const auto &it:v)
    {
        std::cout<<it<<" ";
    }

    std::cout<<"\n";
}

std::vector <int> nearlySorted(int arr[], int num, int K){
    // Your code here
    
    std::vector<int> result;
    
    std::priority_queue<int,std::vector<int>,std::greater<int>> heap;
    int i=0;
    int k=K=1;
    while(k--)
    {
        heap.push(arr[i++]);
    }
    
    while(i<num)
    {
        result.push_back(heap.top());
        heap.pop();
        heap.push(arr[i]);
        i++;
    }
    
    while(!heap.empty())
    {
        result.push_back(heap.top());
        heap.pop();
    }
    
    
    return result;
    
    
    

}


int main()
{
    std::vector<int> arr{6,5,3,2,8,10,9};
    // insertionSort(arr);
    // disp(arr);

    int arr2[]{6,5,3,2,8,10,9};
    auto result=nearlySorted(arr2,7,3);
    disp(result);
    return 0;
}