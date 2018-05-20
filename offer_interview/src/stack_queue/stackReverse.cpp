#include<iostream>
#include<stack>
using namespace std;

//移除栈底元素并返回
template <typename T>
T get(stack<T> s){
    T result = s.pop();
    if(s.empty())
        return result;
    else{
        T last = get(s);
        s.push(result);
        return last;
    }
}


template <typename T>
void reverseStack(stack<T>& s){
    if(s.empty())
        return;
    T i = get(s);
    reverseStack(s);
    s.push(i);
}


int main(int argc, char const *argv[])
{
    stack<int> stack;
    for (int i = 0; i < 10; ++i)
    {
        stack.push(i);
    }

    int value;
    for (int i = 0; i < 10; ++i)
    {
        value = stack.top();
        stack.pop();
        cout<<value<<" "<<endl;
    }
    return 0;
}