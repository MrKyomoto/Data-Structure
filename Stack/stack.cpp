#include <iostream>
#include <stack>
using namespace std;
// 调用stack库函数来实现栈的所有功能

int main()
{
    stack<int> s; //<>里决定了该stack存储的数据类型
    if (s.empty())
    {
        cout << "The stack is empty right now" << endl;
    }
    else
    {
        cout << "The stack is not empty";
    }
    s.push(1);
    s.push(2);
    s.push(3);

    s.pop();//直接弹出
    cout << "The top data is : " << s.top() << endl; //获取而非弹出
    cout << "The volume is : " << s.size() << endl; //目前长度
    return 0;
}