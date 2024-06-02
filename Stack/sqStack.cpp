#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAXSIZE 10

typedef struct
{
    int data[MAXSIZE];
    int top;
} sqStack;

bool iniStack(sqStack &S); // Initialize the stack
bool delStack(sqStack &S); // Delete the stack
bool push(sqStack &S, int data); // Push a data into the stack
int pop_(sqStack &S); // Pop the top data from the stack which means delete the pop data and then return it to the main
int getTop(sqStack S); // get the top data of the stack and return it the main
int findLength(sqStack S); // Find the length of the stack and return it to the main
bool empty(sqStack S); // Find is the stack is empty or not

int main()
{
    sqStack stack;
    sqStack &S = stack;
    iniStack(S);

    int data;
    for (int i = 0; i < 3; i++)
    {
        cout << "Input the data you wanna push in:" << endl;
        cin >> data;
        push(S, data);
    }

    cout << "The top data in the stack is: " << getTop(stack) << endl;
    cout << "Now we delete the top data " << pop_(S) << endl;
    cout << "The new top data in the stack is: " << getTop(stack) << endl;
    cout << "The length of the stack is: " << findLength(stack) << endl;
    if(empty(stack))
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        cout << "The stack is not empty" << endl;
    }
    return 0;
}

bool iniStack(sqStack &S) // Initialize the stack
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        S.data[i] = -1; // -1 is considered invalid in this case
    }
    S.top = -1;
    return true;
}

bool delStack(sqStack &S) // Delete the stack
{
    S.top = -1;
    return true;
}

bool push(sqStack &S, int data) // Push a data into the stack
{
    if(S.top == MAXSIZE - 1)
    {
        return false; // The stack is already full
    }
    else
    {
        S.top++;
        S.data[S.top] = data;
        return true;
    }
}

int pop_(sqStack &S) // Pop the top data from the stack which means delete the pop data and then return it to the main
{
    if(empty(S))
    {
        return -1; // -1 is considered invalid in this case
    }
    else
    {
        int topData = S.data[S.top];
        S.top--;
        return topData;
    }
}

int getTop(sqStack S) // get the top data of the stack and return it the main
{
    if(empty(S))
    {
        return -1;
    }
    else
    {
        return S.data[S.top];
    }
}

int findLength(sqStack S) // Find the length of the stack and return it to the main
{
    return S.top + 1;
}

bool empty(sqStack S) // Find is the stack is empty or not
{
    int length = findLength(S);
    if(length == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}