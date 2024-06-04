#include <iostream>
#include <queue>
using namespace std;
//使用queue库函数实现queue的所有操作

int main()
{
    queue<int> q;
    if(q.empty())
    {
        cout << "The queue is empty" << endl;
    }
    else
    {
        cout << "The queue is not empty" << endl;
    }
    q.push(1);
    q.push(2);
    q.push(3);
    cout << "The size of the queue is " << q.size() << endl;
    cout << "The front data is " << q.front() << endl;
    cout << "The last data is " << q.back() << endl;

    q.pop();
    cout << "The front data is " << q.front() << endl;
    cout << "The size of the queue is " << q.size() << endl;
    return 0;
}