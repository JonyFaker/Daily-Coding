#include<iostream>
#include<vector>
using namespace std;


int getLocalMin(std::vector<int> arr)
{
    if(arr.size() == 0)
        return -1;
    if(arr.size() == 1 || arr[0] < arr[1])
        return 0;
    int length = arr.size();
    if(arr[length-2] > arr[length-1])
        return length-1;
    int low = 1, high = arr.size()-2, mid;
    while(low <= high){
        mid = low+(high-low)/2;
        if(arr[mid]>arr[mid-1])
            high=mid-1;
        else if(arr[mid]>arr[mid+1])
            low=mid+1;
        else
            return mid;
    }
    return -1;
}


int main(int argc, char const *argv[])
{
    int a[30]={10,5,10,5,0,1,2,4,7,3,2,9,5,4,6,5,10,6,7,10,9,4,3,7,2,9,5,4,6,10};
    vector<int> arr(a,a+30);
    cout<<getLocalMin(arr)<<endl;
    return 0;
}