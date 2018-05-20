#include<iostream>
#include<stack>
using namespace std;

//使用一个辅助stack，将一个stack的内容变成由栈顶开始从大到小的顺序

template <typename T>
void stackSort(stack<T>& stack_main){
    stack<T> stack_temp;
    T temp;
    while(!stack_main.empty()){
        temp = stack_main.top();
        stack_main.pop();
        if(stack_temp.empty() || temp <= stack_temp.top())
            stack_temp.push(temp);
        else
        {
            while(!stack_temp.empty())
            {
                T v = stack_temp.top();
                stack_temp.pop();
                stack_main.push(v);
            }
            stack_temp.push(temp);
        }
    }
    while(!stack_temp.empty())
    {
        T v = stack_temp.top();
        stack_temp.pop();
        stack_main.push(v);
    }
}


int main(int argc, char const *argv[])
{
    stack<int> s;
    for (int i = 0; i < 10; ++i)
    {
        s.push(10-i);
    }

    stackSort(s);

    for (int i = 0; i < 10; ++i)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}