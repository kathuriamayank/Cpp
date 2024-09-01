#include <queue>

class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(LmaxHeap.empty())
        {
            LmaxHeap.push(num);
            return;
        }

        if(RminHeap.empty())
        {
            if(num<LmaxHeap.top())
            {
                int ltop=LmaxHeap.top();
                LmaxHeap.pop();
                LmaxHeap.push(num);
                RminHeap.push(ltop);
            }
            else
            {
                RminHeap.push(num);
            }

            return;
        }

        if(RminHeap.size()==LmaxHeap.size())
        {
            if(num<RminHeap.top())
            {
                LmaxHeap.push(num);
            }
            else
            {
                RminHeap.push(num);
            }

            return;
        }

        if(LmaxHeap.size()<RminHeap.size()) //Insertion at left LmaxHeap
        {
            if(num<=RminHeap.top())
            {
                LmaxHeap.push(num);
            }
            else if(num<RminHeap.top() && num>=LmaxHeap.top())
            {
               LmaxHeap.push(num); 
            }
            else
            {
                int rtop=RminHeap.top();
                RminHeap.pop();
                LmaxHeap.push(rtop);
                RminHeap.push(num);
            }
            return;
        }

        else        //Insertion at right LmaxHeap
        {
            

            if(num>RminHeap.top())
            {
                RminHeap.push(num);
            }
            else if(num<RminHeap.top() && num>LmaxHeap.top())
            {
                RminHeap.push(num);
            }
            // else if(num<RminHeap.top() && num> LmaxHeap.top())
            // {
            //     RminHeap.push(num);
            // }
            else
            {
                int ltop=LmaxHeap.top();
                LmaxHeap.pop();
                LmaxHeap.push(num);
                RminHeap.push(ltop);
            }
            return;
        }
    }
    
    double findMedian() {
        double result;
        if(RminHeap.size()==LmaxHeap.size())
        {
            double val1=RminHeap.top();
            double val2=LmaxHeap.top();
            return (val1 + val2)/2.0;
        }
        if(RminHeap.size()>LmaxHeap.size())
        {
            result= RminHeap.top();
        }
        else
        {
            result=LmaxHeap.top();
        }

        return result;

    }
    std::priority_queue<int,std::vector<int>,std::greater<int>> RminHeap;
    std::priority_queue<int> LmaxHeap; 
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    MedianFinder obj;
    obj.addNum(78);
    obj.addNum(14);
    obj.addNum(50);
    obj.addNum(20);
    obj.addNum(13);
    obj.addNum(9);
    obj.addNum(25);
    obj.addNum(8);
    obj.addNum(13);
    obj.addNum(37);
    obj.addNum(29);
    obj.addNum(33);
    obj.addNum(55);
    obj.addNum(52);
    obj.addNum(6);
    obj.addNum(17);
    obj.addNum(65);
    obj.addNum(23);
    obj.addNum(74);
    obj.addNum(43);
    obj.addNum(5);
    obj.addNum(29);
    obj.addNum(29);
    auto result=obj.findMedian();

    // obj.addNum(3);
    // auto result2=obj.findMedian();
    
    return 0;
}




/*

[[],[78],[],[14],[],[50],[],[20],[],[13],[],[9],[],[25]
,[],[8],[],[13],[],[37],[],[29],[],[33],[],[55],[],[52],[],[6],[],[17],[],[65],[],[23],[],[74],[],[43]
,[],[5],[],[29],[],[29],[],[72],[],[7],[],[13],[],[56],[],[21],[],[31],[],[66],[],[69],[],[69],[],[74],[],[12],[],[77],[],[23],[],[10],[],[6],[],[27],[],[63],[],[77],[],[21],[],[40],[],[10],[],[19],[],[59],[],[35],[],[40],[],[44],[],[4],[],[15],[],[29],[],[63],[],[27],[],[46],[],[56],[],[0],[],[60],[],[72],[],[35],[],[54],[],[50],[],[14],[],[29],[],[62],[],[24],[],[18],[],[79],[],[16],[],[19],[],[8],[],[77],[],[10],[],[21],[],[66],[],[4...





*/