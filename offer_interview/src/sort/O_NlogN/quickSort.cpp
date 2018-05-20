#include <iostream>
using namespace std;

class quickSort
{
public:
    quickSort(int* arr_v, int length_v) : arr(arr_v), length(length_v){}
    ~quickSort(){delete[] arr;}

    int* Qsort(){
        quicksort(arr, 0, length-1);
        return arr;
    }

    void quicksort(int* arr, int start, int end){
        if (end > start)
        {
            int mid = partition(arr, start, end);
            quicksort(arr, start, mid-1);
            quicksort(arr, mid+1, end);
        }
    }

    int partition(int* A, int low, int high){

        //思想来自Blog：https://blog.csdn.net/morewindows/article/details/6684558
        int key=A[low];
        while(low<high)
        {
            while(low<high&&A[high]>=key)
                high--;
            A[low]=A[high];
            while(low<high&&A[low]<=key)
                low++;
            A[high]=A[low];
        }
        A[low]=key;
        return low;

        /*
        int index = (start + end) / 2;
        int partition_num = A[index];
        //将partition数字放到数组的最后
        int temp = A[end];
        A[end] = partition_num;
        A[index] = temp;

        int lt_count = 0;
        for (int i = start; i < end; ++i)
        {
            if(A[i] <= partition_num)
            {
                lt_count ++;
                int temp = A[i];
                A[i] = A[lt_count-1];
                A[lt_count-1] = temp;
            }
        }
        //<= partition_num 的一共有lt_count 个, 所在的下标为A[lt_count-1]
        for (int i = start; i <= end; ++i)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
        return lt_count-1;
        */
    }

private:
    int* arr;
    int length;
};


int main(int argc, char const *argv[])
{
    int arr[]={2,4,7,9,8,6};
    int length = sizeof(arr)/sizeof(int);
    quickSort* quicksort = new quickSort(arr, length);
    int* result = quicksort->Qsort();
    for (int i = 0; i < length; ++i)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}