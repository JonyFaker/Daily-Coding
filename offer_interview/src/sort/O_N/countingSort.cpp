#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;

//计数排序 思想基于桶排序
class countingSort
{
public:
    countingSort(int* arr_v, int length_v) : arr(arr_v), length(length_v){}
    ~countingSort(){delete[] arr; arr=NULL;}

    int* countingsort(){
        int min, max = arr[0];
        for (int i = 0; i < length; ++i)
        {
            if(arr[i] < min)
                min = arr[i];
            if(arr[i] > max)
                max = arr[i];
            // cout<<"min:"<<min<<" max:"<<max<<endl;
        }
        // cout<<"min:"<<min<<" max:"<<max<<endl;
        int* count = new int[max-min+1];
        if(!count)
            exit(-1);
        for (int i = 0; i < length; ++i)
            count[arr[i]-min]++;

        for (int i = 0, j = 0; i < max-min+1; ++i)
            while(count[i]){
                arr[j] = i+min;
                count[i]--;
                j++;
            }

        delete[] count;
        count=NULL; //注意将指针置为NULL，否则为野指针
        if (count != NULL)
        {
            cout<<"count is no NULL!"<<endl;
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
    countingSort* countingsort = new countingSort(arr, length);
    int* result = countingsort->countingsort();
    cout<<"result:";
    for (int i = 0; i < length; ++i)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}