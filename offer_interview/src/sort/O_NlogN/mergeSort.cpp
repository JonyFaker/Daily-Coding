#include<iostream>
using namespace std;

//O(N*logN)
class mergeSort
{
public:
    mergeSort(int* arr_v, int length_v) : arr(arr_v), length(length_v){}
    ~mergeSort();

    int* mergesort(){
        Msort(arr, arr, 0, length-1);
        return arr;
    }
    
    //将A[s,...,t]归并排序为B[s,...,t]
    void Msort(int* A, int* B, int s, int t){
        if (s == t)
            B[s] = A[s]; //长度为1的有序区间
        else{
            //将数组划分为小的区间再去排序
            int m = (s+t)/2;
            int C[100] = {0};
            Msort(A, C, s, m);  //左边有序
            Msort(A, C, m+1, t);    //右边有序
            Mmerge(C, B, s ,m ,t);  //合并两个有序数组
        }
    }

    //将有序的A[i,...,m]和A[m+1，...,n]归并为有序的B[i,...,n]
    //合并两个有序的数组复杂度为O(N)
    void Mmerge(int *A, int *B, int i, int m, int n){
        int head1 = i, head2 = m+1;
        int k = i;
        while(head1 <= m && head2 <= n){
            if(A[head1] <= A[head2])
                B[k++] = A[head1++];
            else
                B[k++] = A[head2++];
        }

        while(head1 <= m)
            B[k++] = A[head1++];
        
        while(head2 <= n)
            B[k++] = A[head2++];

    }

private:
    int* arr;
    int length;
    
};

int main(int argc, char const *argv[])
{
    int arr[] = {54,35,48,36,27,12,44,44,8,14,26,17,28};
    int length = sizeof(arr)/sizeof(int);
    cout<<length<<endl;
    mergeSort* mergesort = new mergeSort(arr, length);
    int* result = mergesort->mergesort();
    cout<<"result: ";
    for (int i = 0; i < length; ++i)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}