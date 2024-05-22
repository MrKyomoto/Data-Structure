#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAXSIZE 10
#define NUMBER 1
#define ELM 2

typedef struct
{
    int data[MAXSIZE];
    int length;
} Static_Array;

void InitArray(Static_Array &A);
void DelArray(Static_Array &A);
bool InsertElm(Static_Array &A, int elm, int n);           // Insert an element to the place n
int DelElm(Static_Array &A, int type, int elm_or_number);  // Delete the element and return it to the main
int FindElm(Static_Array A, int type, int elm_or_number); // Find the Elm and return it to the main
int FindLength(Static_Array A);                           // Find the length of the Array and return it to the main
bool OutputArray(Static_Array A);

int main()
{
    Static_Array Array;
    Static_Array &A = Array;
    InitArray(A);
    for (int i = 0; i < 4; i++)
    {
        int elm;
        int n;
        cin >> elm;
        cin >> n;
        InsertElm(A, elm, n);
    }
    int type;
    int elm_or_number;
    cin >> type;
    cin >> elm_or_number;
    DelElm(A, type, elm_or_number);

    cin >> type >> elm_or_number;
    cout << "The elm u will find is:" << FindElm(Array, type, elm_or_number) << endl;

    cout << "The length of the Array is:" << FindLength(Array) << endl;

    OutputArray(Array);
}

void InitArray(Static_Array &A)
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        A.data[i] = -1; // -1 is considered invalid in this case
    }
    A.length = 0;

    return;
}

bool InsertElm(Static_Array &A, int elm, int n) // Insert an element to the place n
{
    if (A.length == MAXSIZE)
    {
        cout << "The Array is full!" << endl;
        return false;
    }

    if (1 <= n && n <= A.length + 1)
    {
        for (int i = A.length; i > n - 1; i--)
        {
            A.data[i] = A.data[i - 1];
        }
        A.data[n - 1] = elm;
        A.length++;
        return true;
    }
    else
    {
        cout << "Invalid Input" << endl;
        return false;
    }
}

void DelArray(Static_Array &A)
{
    for (int i = 0; i < A.length; i++)
    {
        A.data[i] = -1;
    }
    A.length = 0;

    return;
}

int DelElm(Static_Array &A, int type, int elm_or_number) // Delete the element and return it to the main
{
    int number, elm;
    switch (type)
    {
    case NUMBER:
        number = elm_or_number;
        if (1 <= number && number <= A.length)
        {
            int temp = A.data[number - 1];
            for (int i = number - 1; i < A.length - 1; i++)
            {
                A.data[i] = A.data[i + 1];
            }
            A.length--;
            return temp;
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
        break;
    case ELM:
        elm = elm_or_number;
        for (int i = 0; i < A.length; i++)
        {
            if (A.data[i] == elm)
            {
                for (int j = i; j < A.length; j++)
                {
                    A.data[j] = A.data[j + 1];
                }
                A.length--;
            }
        }
        return elm;
        break;

    default:
        cout << "Invalid type input, please choose NUMBER or ELM" << endl;
        return -2;
        break;
    }
}

int FindElm(Static_Array A, int type, int elm_or_number) // Find the Elm and return it to the main
{
    int number, elm;
    switch (type)
    {
    case NUMBER:
        number = elm_or_number;
        if( 1<= number && number <= A.length)
        {
            return A.data[number - 1];
        }
        else
        {
            cout << "Invalid input number" << endl;
            return -2;
        }
        break;
    case ELM:
        elm = elm_or_number;
        for (int i = 0; i < A.length; i++)
        {
            if(A.data[i] == elm)
            {
                return elm;
                break;
            }
        }
        cout << "Invalid input elm" << endl;
        return -2;
        break;
    default:
        cout << "Invalid input, please choose NUMBER or ELM" << endl;
        return -2;
        break;
    }
    

}

int FindLength(Static_Array A)                           // Find the length of the Array and return it to the main
{
    return A.length;
}

bool OutputArray(Static_Array A)
{
    for (int i = 0; i < A.length; i++)
    {
        cout << A.data[i] << endl;
    }
    return true;
}