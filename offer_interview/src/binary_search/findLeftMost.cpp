#include <iostream>
#include <vector>
using namespace std;

int findLeftMost(std::vector<int> arr)
{
    //arr[i] == [i]
    if(arr.size() == 0)
        return -1;
    if(arr.size() == 1 && arr[0] != 0)
        return -1;
    if(arr[0] > arr[arr.size()-1] || arr[arr.size()-1] < 0)
        return -1;
    int low=0, high=arr.size()-1, mid;
    int index = -1;
    while(low <= high){
        mid = low+(high-low)/2;
        // printf("arr[%d]=%d", mid, arr[mid]);
        if(arr[mid] > mid)
            high = mid-1;
        else if(arr[mid] < mid)
            low = mid+1;
        else{
            index = mid;
            high = mid-1;
        }
    }
    return index;
}


int main(int argc, char const *argv[])
{
    int a[4]={-1,0,2,3};
    vector<int> arr(a,a+4);
    cout<<findLeftMost(arr)<<endl;
    return 0;
}