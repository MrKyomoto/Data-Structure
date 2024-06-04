#include <iostream>
#include <stdlib.h>
using namespace std;
//双向栈 - 共用一个内存空间以高效利用内存
#define MAXSIZE 15
typedef struct 
{
    int data[MAXSIZE];
    int top_1;
    int top_2;
} stack;

bool iniStack(stack &S); // Initialize the double stack;
bool delStack(stack &S); // Delete the double stack;
bool push(stack &S, int data, int type); // insert a data in to the stack, the type decide where the data are going into;
int pop(stack &S, int type);             // Pop the top data from the stack;
int getTop(stack &S, int type); // Get the top data from the stack;
bool empty(stack S, int type);  // Find if the stack is empty;
int findLength(stack S, int type); // Find the length of the stack;
bool outputStack(stack S, int type); // Output the stack;

int main()
{
    stack Stack;
    stack &S = Stack;
    iniStack(S);
    int data;
    int type;
    for (int i = 0; i < 5; i++)
    {
        cout << "Input the data: " << endl;
        cin >> data;
        cout << "Input the type: " << endl;
        cin >> type;
        push(S, data, type);
    }
    cout << pop(S, 1) << " is the top data in the type 1" << endl;
    cout << getTop(S, 2) << " is the top data in the type 2" << endl;
    cout << "The length of the type 1 is : " << findLength(S, 1) << endl;
    cout << "The length of the type 2 is : " << findLength(S, 1) << endl;
    outputStack(S, 1);
    outputStack(S, 2);

    return 0;
}

bool iniStack(stack &S) // Initialize the double stack;
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        S.data[i] = -1; // -1 is considered invalid in this case
    }
    S.top_1 = -1;
    S.top_2 = MAXSIZE;
    return true;
}

bool delStack(stack &S) // Delete the double stack;
{
    S.top_1 = -1;
    S.top_2 = MAXSIZE;
    return true;
}

bool push(stack &S, int data, int type) // insert a data in to the stack, the type decide where the data are going into;
{
    switch(type)
    {
        case 1:
            if(S.top_1 + 1 == S.top_2)
            {
                return false;
            }
            else
            {
             S.top_1++;
                S.data[S.top_1] = data;
                return true;
            }
            break;
        case 2:
            if(S.top_2 - 1 == S.top_1)
            {
                return false;
            }
            else
            {
                S.top_2--;
                S.data[S.top_2] = data;
                return true;
            }
        break;
        default:
            return false;
    }
}

int pop(stack &S, int type)             // Pop the top data from the stack;
{
    switch(type)
    {
        case 1:
            if(empty(S, type))
            {
                return -1; // -1 is considered empty in this case
            }
            else
            {
                int topData = S.data[S.top_1];
                S.top_1--;
                return topData;
            }
            break;
        case 2:
            if(empty(S, type))
            {
                return -1;
            }
            else
            {
                int topData = S.data[S.top_2];
                S.top_2--;
                return topData;
            }
            break;
        default:
            return -2; // -2 is considered invalid input in this case
    }
}

int getTop(stack &S, int type) // Get the top data from the stack;
{
    switch(type)
    {
        case 1:
            if(empty(S, type))
            {
                return -1;
            }
            else
            {
                return S.data[S.top_1];
            }
            break;
        case 2:
            if(empty(S, type))
            {
                return -1;
            }
            else
            {
                return S.data[S.top_2];
            }
            break;
        default:
            return -2;
    }

}

bool empty(stack S, int type)  // Find if the stack is empty;
{
    switch(type)
    {
        case 1:
            if(S.top_1 == -1)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        case 2:
            if(S.top_2 == MAXSIZE)
            {
                return true;
            }
            else
            {
                return false;
            }
            break;
        default:
            return false;
    }
}

int findLength(stack S, int type) // Find the length of the stack;
{
    switch(type)
    {
        case 1:
            return S.top_1 + 1;
            break;
        case 2:
            return MAXSIZE - S.top_2;
            break;
        default:
            return -1;
        }
}

bool outputStack(stack S, int type) // Output the stack;
{
    switch(type)
    {
        case 1:
            if(empty(S, type))
            {
                return false;
            }
            else
            {
                int length = findLength(S, type);
                for (int i = 0; i < length; i++)
                {
                    cout << S.data[i] << endl;
                }
                return true;
            }
            break;
        case 2:
            if(empty(S,type))
            {
                return false;
            }
            else
            {
                int length = findLength(S, type);
                for (int i = 0; i < length; i++)
                {
                    cout << S.data[MAXSIZE - i - 1] << endl;
                }
                return true;
            }
        default:
            return false;
    }
}