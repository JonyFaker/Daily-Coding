#include<iostream>
#include<vector>
using namespace std;

int getMin(std::vector<int> arr)
{
    if(arr.empty())
        return -1;
    if(arr.size()==1)
        return arr[0];
    int left = 0, right = arr.size()-1, mid;
    while(left < right){
        if(arr[left] < arr[right])
            return arr[left];
        else{
            mid = left  + (right - left) / 2;
            if(arr[left] > arr[mid])
                right = mid;
            else if(arr[mid] > arr[right])
                left = mid+1;
            else
                break;  //只能通过遍历的方式去寻找  222222212222222,这种情况1出现在哪里都是可以的
        }
    }
    if(left==right)
        return arr[left];
    int min=arr[left];
    while(left<=right)
    {
        if(arr[left]<min)
            min=arr[left];
        left++;
    }
    return min;
}


int main(int argc, char const *argv[])
{
    int a[5]={3,3,4,1,2};
    vector<int> arr(a,a+5);
    cout<<getMin(arr)<<endl;
    return 0;
}