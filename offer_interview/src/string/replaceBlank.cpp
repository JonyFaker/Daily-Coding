#include<iostream>
#include<string>
using namespace std;

string replace(const char* A, int n){
    int spaceCount = 0;
    for (int i = 0; i < n; ++i)
        if(A[i] == ' ')
            spaceCount++;
    char* result = new char[n+spaceCount*2];
    int index_A = n-1;
    int index_res = n+spaceCount*2-1;
    while(index_A >= 0 && index_res >= 0){
        if(A[index_A] != ' ')
            result[index_res--] = A[index_A--];
        if(A[index_A] == ' '){
            index_A--;
            result[index_res--] = '0';
            result[index_res--] = '2';
            result[index_res--] = '%';
        }
    }
    string temp;
    int i = 0;
    while(i < n+spaceCount*2){
        temp += result[i];
        i++;
    }
    return temp;
}


int main(int argc, char const *argv[])
{
    string A = "a b c";
    const char* str = A.c_str();
    string result = replace(str, A.length());
    cout<<result<<endl;
    return 0;
}