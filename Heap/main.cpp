#include <vector>
#include <iostream>

// void swap(std::vector<int> & heap,int largest,int i)
// {
//     int temp=heap[largest];
//     heap[largest]=heap[i];
//     heap[i]=temp;
// }


void heapify(std::vector<int> & heap,int i,int size)
{
    int left=2*i+1;
    int right= 2*i +2;
    int largest=i;

    if(left<=size and heap[left] > heap[largest])
        largest=left;
    
    if(right <=size and heap[right] > heap[largest])
        largest=right;
    
    if(largest!=i)
    {
        int temp=heap[largest];
        heap[largest]=heap[i];
        heap[i]=temp;
        heapify(heap,largest,size);
    }

}

int main()
{
    // Already Created Max Heap
    std::vector<int> heap{9,8,7,6,5,4,3,2,1};

    // heapify(heap,0,heap.size()-1);

    for(int i=heap.size()-1; i>0; i--)
    {
        int temp=heap[0];
        heap[0]=heap[i];
        heap[i]=temp;

        // swap(heap,0,i);
        
        heapify(heap,0,i-1);
    }


    for(const auto &it: heap)
    {
        std::cout<<it<<" ";
    }

    return 0;
}


