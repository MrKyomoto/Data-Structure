#include <iostream>
#include <stdlib.h>
using namespace std;
//单向链表+头节点

typedef struct linkList
{
    int data;//数据域
    struct linkList *next;//指针域
} LNode;

LNode* iniLinkList(LNode *L);//Initiate a link list and return the head point to the main
int FindLength(LNode *L);//Find the length of the link list
bool delLinkList(LNode *L);//Delete the link list
LNode *findNodePointer(LNode *L, int n);//Find the No.n Node and return the pointer to the main
bool insertNode(LNode *L, int data, int n);//Insert an node as the No.n node into the link list
int findNode(LNode *L, int data);//Find if the pointed data is in the link list, and if yes, return the number of the node to the main
int delNode(LNode *L, int data);//Delete the pointed data and return how many "data" you have just deleted
int delNodeByNumber(LNode *L, int n);//Delete the No.n node from the link list and return the data you have deleted
int changeData(LNode *L, int data, int n);//Change the No.n data to the new data and return the pre-data to the main
bool outputLinklist(LNode *L);//Output all the data in the link list one by one

int main()
{
    LNode *L = NULL;
    L = iniLinkList(L);
    for (int i = 0; i < 4; i++)
    {
        int data, n;
        cout << "Input the data you wanna put except '-1' in to the link list:" << endl;
        cin >> data;
        cout << "Input the number you wanna put the data to the link list" << endl;
        cin >> n;
        if (insertNode(L, data, n) == false)
        {
            cout << "Invalid number you had inputted" << endl;
        }
    }
    int data, n;

    cout << "The current length of the link list is " << FindLength(L) << endl;

    cout << "Input the data you wanna find in the link list:" << endl;
    cin >> data;
    cout << "The data " << data << "is in the No." << findNode(L, data) << " node" << endl;

    cout << "Input the data you wanna delete from the link list:" << endl;
    cin >> data;
    cout << "You have deleted " << delNode(L, data) << " node(s) containing the data " << data << endl;

    cout << "Input the number of the node you wanna delete:" << endl;
    cin >> n;
    cout << "The No." << n << " node containing the data " << delNodeByNumber(L, n) << " has be deleted successfully" << endl;

    cout << "Input the data you wanna refill in the link list:" << endl;
    cin >> data;
    cout << "Input the number of the node you wanna put the new data to:" << endl;
    cin >> n;
    cout << "You have changed the data from " << changeData(L, data, n) << " to " << data << " in the No." << n << " node" << endl;

    cout << "The current length of the link list is: " << FindLength(L) << endl;

    cout << "Output the link list" << endl;
    outputLinklist(L);
    return 0;
}

LNode* iniLinkList(LNode *L)//Initiate a link list and return the head point to the main
{
    L = (LNode *)malloc(sizeof(LNode));
    if(L == NULL)
    {
        return NULL;
    }
    L->data = 0; //头节点中存放整个链表的长度,以便达到内存的最大化利用
    L->next = NULL;

    return L;
}

int FindLength(LNode *L)//Find the length of the link list
{
    return L->data;
}

bool delLinkList(LNode *L)//Delete the link list
{
    int length = FindLength(L);
    LNode *head = L;
    for (int i = 1; i <= length; i++)
    {
        delNodeByNumber(L, 1);//重复删链表的第一个元素直到链表为空
    }
    if(head->data == 0 && head->next == NULL)
    {
        free(head);
    }
    return true;
}

LNode *findNodePointer(LNode *L, int n)//Find the No.n Node and return the pointer to the main
{
    LNode *p = L;
    for (int i = 0; i < n; i++)
    {
        p = p->next;
    }
    return p;
}

bool insertNode(LNode *L, int data, int n)//Insert an node as the No.n node into the link list
{
    int length = FindLength(L);
    if(n < 1 || n > length + 1)
    {
        return false;
    }
    else 
    {
        LNode *p_1, *p_2, *p;
        p_1 = findNodePointer(L, n - 1);
        p_2 = p_1->next;
        p = (LNode *)malloc(sizeof(LNode));
        p->data = data;
        p->next = p_2;
        p_1->next = p;

        L->data++;
        return true;
    }
}

int findNode(LNode *L, int data)//Find if the pointed data is in the link list, and if yes, return the number of the node to the main
{
    int length = FindLength(L);
    LNode *p = L->next;
    for (int i = 1; i <= length; i++)
    {
        if(p->data == data)
        {
            return i;
        }
        p = p->next;
    }
    return -1;
}

int delNode(LNode *L, int data)//Delete the pointed data and return how many "data" you have just deleted
{
    int cout = 0;
    int length = FindLength(L);
    LNode *p = L->next;
    for (int i = 1; i <= length; i++)
    {
        if(p->data == data)
        {
            delNodeByNumber(L, i);
            cout++;
        }
        p = p->next;
    }
    return cout;
}

int delNodeByNumber(LNode *L, int n)//Delete the No.n node from the link list and return the data you have deleted
{
    int dataDeleted;
    int length = FindLength(L);
    if(1 <= n && n < length)
    {
        LNode *p_1 = findNodePointer(L, n);
        LNode *p_2 = p_1->next;
        dataDeleted = p_1->data;
        p_1->data = p_2->data;
        p_1->next = p_2->next;
        free(p_2);
        L->data--;
        return dataDeleted;
    }
    else if( n == length)//处理特殊情况,当要删除的节点是最后一个节点的时候
    {
        LNode *p_1 = findNodePointer(L, n - 1);
        LNode *p_2 = p_1->next;
        p_1->next = p_2->next;
        dataDeleted = p_2->data;
        free(p_2);
        L->data--;
        return dataDeleted;
    }
    else
    {
        return -1;//-1 is considered invalid in this case
    }
}

int changeData(LNode *L, int data, int n)//Change the No.n data to the new data and return the pre-data to the main
{
    int length = FindLength(L);
    int dataPre;
    if( n < 1 || n > length)
    {
        return -1;//-1 is considered invalid in this case
    }
    else
    {
        LNode *p = findNodePointer(L, n);
        dataPre = p->data;
        p->data = data;
        return dataPre;
    }
}

bool outputLinklist(LNode *L)//Output all the data in the link list one by one
{
    int length = FindLength(L);
    LNode *p = L->next;
    for (int i = 0; i < length; i++)
    {
        cout << p->data << endl;
        p = p->next;
    }
    return true;
}