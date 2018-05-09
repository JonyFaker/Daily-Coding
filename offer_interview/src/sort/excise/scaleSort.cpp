#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

//小范围排序 O(n*logK)
//整个数组的最小值一定是在arr[0]~arr[k-1]中，因为移动距离不超过k，因此可以使用小根堆

class scaleSort
{
public:
    scaleSort(int* arr_v, int length_v, int k_v) : arr(arr_v), length(length_v), k(k_v){}
    ~scaleSort(){delete[] arr; arr=NULL;}
    
    int* scalesort(){
        
    }


    void heapsort(int* arr, int n){
        //建立小根堆
        for (int i = n/2 - 1; i >= 0; --i)
            MinHeapInit(arr, i, n-1);

        for (int i = n-1; i >= 0; --i)
        {
            int temp = arr[0];
            arr[0] = arr[i];
            arr[i] = temp;
            MinHeapInit(arr, 0, i-1);
        }
    }

    void MinHeapInit(int* arr, int start, int end){
        int dad = start;
        int son = 2*dad + 1;//因为下标是从0开始计算的，所以左孩子节点下标+1
        while(son <= end){ //若子節點指標在範圍內才做比較
            if (son+1 < end && arr[son] > arr[son+1])   //先比較兩個子節點大小，選擇最小的
                son++;
            if(arr[dad] < arr[son]) //如果父節點大於子節點代表調整完畢，直接跳出函數
                return;
            else{   //否則交換父子內容再繼續子節點和孫節點比較,一旦上层调整了，下层有可能要接着调整
                swap(arr[dad], arr[son]);
                dad = son;
                son = dad*2 + 1;
            }
        }
    }

private:
    int* arr;
    int length;
    int k;
};


int main(int argc, char const *argv[])
{
    int arr[]={2,1,4,3,6,5,8,7,10,9};  //几乎有序，如果把这个数组排好序的话，每个元素移动的距离不超过K，使用改进堆排序
    int length = sizeof(arr)/sizeof(int);
    int k = 10;
    return 0;
}