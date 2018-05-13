#include<iostream>
#include<algorithm>
using namespace std;


//{1,4,6,5,9,10},6  ==>  2  需要排序的最短子串长度
class subSequence
{
public:
    subSequence(int* A, int n){
        this->A = A;
        this->n = n;
    }
    ~subSequence(){
        delete[] A;
        A = NULL;
    }

    int shortestSubsequence(){
        int max = A[0], min = A[n-1];
        int index_max, index_min;
        for (int i = 0; i < n; ++i)
        {
            if(A[i] >= max)
                max = A[i];
            if(A[i] < max)
                index_max = i;
        }

        for (int i = n-1; i >= 0; --i)
        {
            if(A[i] <= min)
                min = A[i];
            if(A[i] > min)
                index_min = i;
        }
        cout<<index_max<<" "<<index_min<<endl;
        if(!index_min || !index_max)
            return 0;
        return index_max-index_min+1;
    }
    
private:
    int* A;
    int n;
};


int main(int argc, char const *argv[])
{
    int arr[6]={1,4,6,5,9,10};
    int n = sizeof(arr)/sizeof(int);
    subSequence s(arr, n);
    int result = s.shortestSubsequence();
    cout<<"result: "<<result<<endl;
    return 0;
}