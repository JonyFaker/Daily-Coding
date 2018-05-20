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
        int* result = new int[length];
        //先将0~k-1位置上的数字调整为小根堆
        for (int i = k/2-1; i >= 0; --i)
            MinHeapInit(arr, i, k-1);
        result[0] = arr[0];
        cout<<result[0]<<" ";
        //依次将k-1之后的数字插入堆顶，再调整为小根堆
        for (int i = k, j = 1; i < length; ++i,++j)
        {
            //将下一个数插入到堆顶，再进行调整
            arr[0] = arr[i];
            MinHeapInit(arr, 0, k-1);
            for (int temp = 0; temp < length; ++temp)
            {
                cout<<arr[temp]<<" ";
            }
            cout<<endl;
            result[j] = arr[0];
            // cout<<result[j]<<" ";
        }
        cout<<endl;
        //到此刻，前k-1个从小到大的数字已经找到，由小根堆的性质可以知道，arr[0]作为堆顶，此时他的子节点一定比他大
        //所以，进行一次调整并将最小值放到堆顶
        heapsort(arr, k);
        result[length-1] = arr[0];
        for (int i = 0; i < length; ++i)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        return result;
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
    int k = 3;
    scaleSort* scalesort = new scaleSort(arr, length, k);
    int* result = scalesort->scalesort();
    cout<<"result: ";
    for (int i = 0; i < length; ++i)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}