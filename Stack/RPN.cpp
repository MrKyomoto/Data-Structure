// 用stack实现后缀表达式的计算
#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

#define MAXSIZE 21

int main()
{
    char str[MAXSIZE];
    int length;
    int sum;
    cout << "Input a str no more than 20 char: " << endl;
    cin >> str;
    cout << "Input the length of the str you have typed:" << endl;
    cin >> length;
    stack<int> s;
    for (int i = 0; i < length; i++)
    {
        int num_r;
        int num_l;
        int num;
        switch (str[i])
        {
        case '+':
            num_r = s.top(); // 右操作数
            s.pop();
            num_l = s.top(); // 左操作数
            s.pop();

            sum = num_l + num_r;
            s.push(sum);
            break;
        case '-':
            num_r = s.top(); // 右操作数
            s.pop();
            num_l = s.top(); // 左操作数
            s.pop();

            sum = num_l - num_r;
            s.push(sum);
            break;
        case '*':
            num_r = s.top(); // 右操作数
            s.pop();
            num_l = s.top(); // 左操作数
            s.pop();

            sum = num_l * num_r;
            s.push(sum);
            break;
        case '/':
            num_r = s.top(); // 右操作数
            s.pop();
            num_l = s.top(); // 左操作数
            s.pop();

            sum = num_l / num_r;
            s.push(sum);
            break;
        default:
            num = str[i] - '0';
            s.push(num);
            break;
        }
    }
    sum = s.top();
    s.pop();
    if (s.empty())
    {
        cout << "The sum is: " << sum << endl;
    }
    else
    {
        cout << "Invalid input" << endl;
    }

    return 0;
}