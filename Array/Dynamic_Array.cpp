#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

typedef struct
{
    int* data;
    int maxsize;
    int length;
} Dynamic_Array;

bool IniArray(Dynamic_Array &A); //Initial the array
bool DelArray(Dynamic_Array &A); //Delete the array
int FindElm(Dynamic_Array A, int n); //Find the No.n elm and return it to the main
int FindNumerOfElm(Dynamic_Array A, int elm); //Find the number of the elm and return it to the main
bool InsertElm(Dynamic_Array &A, int elm, int n); //Insert the elm as the No.n elm in the array
int DelElmByNumber(Dynamic_Array &A, int n); //Delete the No.n elm and return the elm to the main
int DelElm(Dynamic_Array &A, int elm); //Delete all the pointed elm from the array and return how many elms you have deleted
int FindLength(Dynamic_Array A); //Find the current length of the array and return it to the main
bool OutputArray(Dynamic_Array A); //Output the array one by one

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    Dynamic_Array Array;
    Dynamic_Array &A = Array;
    IniArray(A);
    for (int i = 0; i < 4; i++)
    {
        int elm;
        int n;
        cin >> elm;
        cin >> n;
        InsertElm(A, elm, n);
    }
    int n;
    cout << "Find the No.n Elm" << endl;
    cin >> n;
    cout << "The No." << n << "Elm is:" << FindElm(Array, n) << endl;

    int elm;
    cout << "Input a elm you wanna find" << endl;
    cin >> elm;
    cout << "The number of the Elm " << elm << " is:" << FindNumerOfElm(Array, elm) << endl;

    cout << "Input the number of the elm you wanna delete" << endl;
    cin >> n;
    cout << endl;
    cout << "You delete the No." << n << "Elm : " << DelElmByNumber(A, n) << endl;

    cout << "Input the elm you wanna delete" << endl;
    cin >> elm;
    cout << endl;
    cout << "You have deleted " << DelElm(A, elm) << " " << elm << endl;

    cout << "The length of the array is " << FindLength(Array) << endl;

    OutputArray(Array);
    return 0;
}

bool IniArray(Dynamic_Array &A) //Initial the array
{
    A.data = (int *)malloc(sizeof(int));
    cout << "Please type the maxsize of the array:" << endl;
    cin >> A.maxsize;
    A.length = 0;

    return true;
}

bool DelArray(Dynamic_Array &A) //Delete the array
{
    free(A.data);
    return true;
}

int FindElm(Dynamic_Array A, int n) //Find the No.n elm and return it to the main
{
    if (A.length == 0)
    {
        cout << "The array is empty" << endl;
        return -1; // -1 is considered invalid in this case
    }
    if(1 <= n && n <= A.length)
    {
        return A.data[n - 1];
    }
    else
    {
        cout << "Invalid input" << endl;
        return -1;
    }
}

int FindNumerOfElm(Dynamic_Array A, int elm) //Find the first number of the elm and return it to the main
{
    if(A.length == 0)
    {
        cout << "The array is empty" << endl;
        return -1; // -1 is considered invalid in this case
    }
    for (int i = 0; i < A.length; i++)
    {
        if(elm == A.data[i])
        {
            return i + 1;
            break;
        }
    }
    cout << "The elm " << elm << "is not in the array" << endl;
    return -1;
}

bool InsertElm(Dynamic_Array &A, int elm, int n) //Insert the elm as the No.n elm in the array
{
    if(A.length == A.maxsize)
    {
        cout << "此数组已达最大容量限度，无法继续添加数据" << endl;
        return false;
    }

    /* if(A.length == 0 && n == 1 )//处理特殊情况
    {
        A.data = (int *)malloc(sizeof(int));
        A.data[0] = elm;
        A.length++;
    } */
    if(1 <= n && n <= A.length + 1 )//要插入到数组中间的情况,也可以插入到数组最后
    {
        int *temp = A.data;
        A.data = (int *)malloc(sizeof(int) * (A.length + 1));
        for (int i = 0; i < n - 1; i++)
        {
            A.data[i] = temp[i];
        }

        A.data[n - 1] = elm;

        for(int i = n - 1; i < A.length; i++)
        {
            A.data[i + 1] = temp[i];
        }
        A.length++;
    }
    else
    {
        cout << "您要插入的位置不在数组范围" << endl;
        return false;
    }
    
}

int DelElmByNumber(Dynamic_Array &A, int n) //Delete the No.n elm and return the elm to the main
{
    if( 1 <= n && n <= A.length)
    {
        if(A.length == 1)
        {
            
            int *temp = A.data;
            A.data = (int *)malloc(sizeof(int));
            int t = temp[0];
            free(temp);
            A.length--;
            return t;
        }
        else
        {
            int *temp = A.data;
            A.data = (int *)malloc(sizeof(int) * (A.length - 1));
            for (int i = 0; i < n - 1; i++)
            {
                A.data[i] = temp[i];
            }
            for (int i = n; i < A.length; i++)
            {
                A.data[i - 1] = temp[i];
            }
            int t = temp[n - 1];
            A.length--;
            return t;
        }
    }
    else
    {
        cout << "您要删除的位置不在数组范围内" << endl;
        return -1;
    }
}

int DelElm(Dynamic_Array &A, int elm) //Delete all the pointed elm from the array and return how many elms you have deleted
{
    int cout = 0;
    for (int i = 0; i < A.length; i++)
    {
        if(A.data[i] == elm)
        {
            DelElmByNumber(A, i + 1);
            cout++;
        }
    }
    return cout;
}

int FindLength(Dynamic_Array A) //Find the current length of the array and return it to the main
{
    return A.length;
}

bool OutputArray(Dynamic_Array A) //Output the array one by one
{
    for (int i = 0; i < A.length; i++)
    {
        cout << A.data[i] << endl;
    }
    return true;
}