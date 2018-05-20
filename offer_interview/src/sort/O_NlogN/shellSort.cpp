#include<iostream>
#include <algorithm>
using namespace std;

class shellSort
{
public:
    shellSort(int* arr_v, int length_v) : arr(arr_v), length(length_v){}
    ~shellSort(){delete[] arr;}

    //可变步长的插入排序
    int* shellsort(){
        int index = 0;
        int index_temp = 0;
        int end = length-1;
        for (int s = length/2; s > 0; s=s/2)
        {
            // cout<<"s:"<<s<<" ";
            index = s;
            while(index <= end){
                // cout<<"index:"<<index<<endl;
                index_temp = index;
                while(index_temp >= 0 && (index_temp-s) >= 0 && arr[index_temp] <= arr[index_temp-s]){
                    // cout<<"index_temp:"<<index_temp<<" index_temp-s:"<<index_temp-s<<endl;
                    swap(arr[index_temp], arr[index_temp-s]);
                    index_temp -= s;
                }
                index++;
            }
            for (int i = 0; i < length; ++i)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        return arr;
    }

private:
    int* arr;
    int length;
};

int main(int argc, char const *argv[])
{
    int arr[]={54,35,48,36,27,12,44,44,8,14,26,17,28};
    int length = sizeof(arr)/sizeof(int);
    shellSort* shellsort = new shellSort(arr, length);
    int* result = shellsort->shellsort();
    cout<<"result:";
    for (int i = 0; i < length; ++i)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}