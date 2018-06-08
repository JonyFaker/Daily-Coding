#include<iostream>
#include<vector>
using namespace std;


int leftMostIndex(std::vector<int> arr, int num)
{
    if(arr.empty())
        return -1;
    int low = 0, high = arr.size()-1, mid;
    int index = -1;
    while(low <= high){
        mid = low + (high - low) / 2;
        if(arr[mid] < num)
            low = mid+1;
        else if(arr[mid] > num)
            high = mid-1;
        else{
            index = mid;
            high = mid-1;   //keep search left
        }
    }
    return index;
}

int main(int argc, char const *argv[])
{
    int a[5]={1,2,3,3,4};
    vector<int> arr(a,a+5);
    cout<<leftMostIndex(arr, 3)<<endl;
    return 0;
}