// 括号匹配问题 用 stack解决
#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

#define Length 11

int main()
{
    char str[Length];
    char temp;
    cout << "Please input a str with the length 10" << endl;
    cin >> str;
    stack<char> s;
    int length = Length - 1;
    for (int i = 0; i < length; i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            s.push(str[i]);
        }
        else
        {
            if (s.empty())
            {
                cout << "False" << endl;
                break;
            }
            else
            {
                temp = s.top();
                if ((temp == '(' && str[i] == ')') || (temp == '[' && str[i] == ']') || (temp == '{' && str[i] == '}'))
                {
                    s.pop();
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
    }
    if (s.empty())
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}