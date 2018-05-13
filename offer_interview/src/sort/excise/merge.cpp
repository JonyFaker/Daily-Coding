#include<iostream>
using namespace std;


class merge
{
public:
    merge(int* A, int* B, int lengthA, int lengthB){
        this->A = A;
        this->B = B;
        this->lengthA = lengthA;
        this->lengthB = lengthB;
    }
    ~merge(){
        delete[] A;
        A = NULL;
        delete[] B;
        B = NULL;
    }

    int* mergeAB()
    {
        int indexA = lengthA-1;
        int indexB = lengthB-1;
        int newlength = lengthA + lengthB;
        int index = newlength-1;
        while(indexA >= 0 && indexB >= 0 && index >= 0)
        {
            if(A[indexA] > B[indexB]){
                A[index] = A[indexA];
                indexA --;
                index --;
            }else{
                A[index] = B[indexB];
                indexB --;
                index --;
            }
        }

        while(indexA >= 0 && index >= 0){
            A[index] = A[indexA];
            indexA --;
            index --;
        }

        while(indexB >= 0 && index >= 0){
            A[index] = B[indexB];
            indexB --;
            index --;
        }

        return A;
    }

 
private:
    int* A;
    int* B;
    int lengthA;
    int lengthB;
};


int main(int argc, char const *argv[])
{
    int a[10]={1,3,7,8,8};
    int b[]={0,2,5,9};
    int lengthA = sizeof(a)/sizeof(int);
    int lengthB = sizeof(b)/sizeof(int);
    cout<<"lengthA: "<<lengthA<<" lengthB: "<<lengthB<<endl;
    merge* mergeab = new merge(a, b, 5, 4);
    int* result = mergeab->mergeAB();
    for (int i = 0; i < 9; ++i)
    {
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}