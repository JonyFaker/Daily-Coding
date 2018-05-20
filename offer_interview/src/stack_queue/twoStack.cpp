#include<iostream>
#include<stack>
using namespace std;

template<class T>
class queue
{
public:
    queue(){};
    ~queue(){};

    void add(T value){
        stack_A.push(value);
    }


    //删除头部元素
    void poll(){
        if(!stack_B.empty())
            stack_B.pop();
        else
            while(!stack_A.empty()){
                stack_B.push(stack_A.top());
                stack_A.pop();
            }
    }

    //查询头部元素
    T peek(){
        if(!stack_B.empty())
            return stack_B.top();
        else
            while(!stack_A.empty()){
                stack_B.push(stack_A.top());
                stack_A.pop();
            }
            return stack_B.top();
    }

private:
    stack<T> stack_A;
    stack<T> stack_B;
    
};


int main(int argc, char const *argv[])
{
    queue<int> q;
    q.add(1);
    q.add(2);
    q.add(3);
    q.add(4);

    cout<<"peek 1: "<<q.peek()<<endl;
    q.poll();
    cout<<"peek 2: "<<q.peek()<<endl;
    q.poll();
    cout<<"peek 3: "<<q.peek()<<endl;
    q.poll();
    cout<<"peek 4: "<<q.peek()<<endl;
    return 0;
}