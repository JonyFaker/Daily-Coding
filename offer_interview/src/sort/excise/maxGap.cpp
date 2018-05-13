#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//O(N)  O(N)
class maxGap
{
public:
    maxGap(int* A, int n){
        this->A = A;
        this->n = n;
    }
    // ~maxGap(){
    //     delete[] A;
    //     A = NULL;
    // };
    

    int gap(){
        //先找到数组的min max
        int min=A[0], max=A[0];
        for (int i = 1; i < n; ++i)
        {
            if(A[i] >= max)
                max = A[i];
            if(A[i] < min)
                min = A[i];
        }
        // cout<<"max :"<<max<<" min :"<<min<<endl;
        //把数组所有的数等分到[min, max)中，n个等量区间，最大值放在n+1个桶中
        float gap = 1.0 * (max - min) / n;
        cout<<"gap: "<<gap<<endl;
        std::vector<std::vector<int>> casks(n+1);
        for (int i = 0; i < n; ++i)
        {
            int index = static_cast<int>((A[i]-min)/gap);
            //每个桶中只需要防止该桶的最大值和最小值即可
            if (casks[index].empty())
            {
                casks[index].push_back(A[i]);   //0
                casks[index].push_back(A[i]);   //1
            }else
            {
                if(A[i] < casks[index][0])  //min  后一个桶的最小值
                    casks[index][0] = A[i];
                if(A[i] > casks[index][1])  //max  前一个桶的最大值
                    casks[index][1] = A[i];
            }
        }

        //开始比较桶前一个桶的最大值与后一个桶的最小值
        int maxgap = 0;
        for (int i=0,j=0; i < n; i=j)
        {
            while(casks[i].empty())
                i++;
            max = casks[i][1];
            j = i + 1;
            if(j < n+1){
                while(casks[j].empty())
                    j++;
                if(j >= n+1)
                    break;
                min = casks[j][0];
                // if(max-min > maxgap)
                //     maxgap = max-min;
                // cout<<"max: "<<max<<" min: "<<min<<endl;
                maxgap = (min-max) > maxgap ? (min-max) : maxgap;
                // cout<<"maxgap: "<<maxgap<<endl;
            }
        }

        return maxgap;
    }

private:
    int* A;
    int n;
};


int main(int argc, char const *argv[])
{
    int arr[6]={1,4,6,5,9,10};  //一个无序的数组排序之后相邻两数的最大差值
    int n = sizeof(arr)/sizeof(int);
    maxGap gap(arr, n);
    int result = gap.gap();
    cout<<"result: "<<result<<endl;
    return 0;
}