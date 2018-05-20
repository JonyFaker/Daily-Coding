#include<iostream>
#include<stack>
using namespace std;


template<class T>
class getminStack
{
public:
    getminStack(){};
    ~getminStack(){};
    
    void pop(){
        stack_data.pop();
        stack_min.pop();
    }

    void push(T value){
        stack_data.push(value);
        if(stack_min.empty() || value <= stack_min.top())
            stack_min.push(value);
        else
            stack_min.push(stack_min.top());
    }

    T getMin(){
        T value = stack_min.top();
        return value;
    }

private:
    stack<T> stack_data;
    stack<T> stack_min;
};


int main(int argc, char const *argv[])
{
    getminStack<int> stack;
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(1);
    stack.push(2);
    stack.push(1);

    cout<<"min: "<<stack.getMin()<<endl;
    stack.pop();
    cout<<"min: "<<stack.getMin()<<endl;
    stack.pop();
    cout<<"min: "<<stack.getMin()<<endl;
    stack.pop();
    cout<<"min: "<<stack.getMin()<<endl;
    stack.pop();

    return 0;
}