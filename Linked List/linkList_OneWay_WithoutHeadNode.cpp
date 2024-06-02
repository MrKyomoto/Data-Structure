#include <iostream>
#include <stdlib.h>
using namespace std;
// 单向链表+不带头节点

typedef struct linkList
{
    int data;
    struct linkList *next;
}LNode;

LNode *iniLinkList(LNode *L);               // Initialize the link list and return the head pointer to the main
int findLength(LNode *L);                  // Find the length of the link list and return it to the main
LNode *findNodePointer(LNode *L, int n);    // Find the pointer of No.n node and return it to the main
bool InsertNode(LNode *L, int data, int n); // Insert the node containing the data in to the link list as the No.n node
bool insertFromHead(LNode *L, int data);    // 头插法
bool insertFromTail(LNode *L, int data);    // 尾插法
int delNode(LNode *L, int n);               // Delete the No.n note and return the data in No.n node to the main
int changeNode(LNode *L, int data, int n);  // Change the data of No.n node as the new data and return the pre-data to the main
bool delLinkList(LNode *L);                 // Delete the link list
bool outputLinkList(LNode *L);              // Output the link list

int main()
{
    return 0;
}

LNode *iniLinkList(LNode *L) // Initialize the link list and return the head pointer to the main
{
    L = NULL;
    return L;
}

int findLength(LNode *L)                 // Find the length of the link list and return it to the main
{
    int length = 0;
    LNode *head = L;
    if(head == NULL)
    {
        return length;
    }
    else
    {
        length = 1;
        while(head->next != NULL)
        {
            length++;
            head = head->next;
        }
        return length;
    }
}
LNode *findNodePointer(LNode *L, int n) // Find the pointer of No.n node and return it to the main
{
    int length = findLength(L);
    if( n < 1 || n > length )
    {
        return NULL;
    }
    else
    {
        LNode *p = L;
        for (int i = 0; i < n-1; i++)
        {
            p = p->next;
        }
        return p;
    }
}

bool InsertNode(LNode *L, int data, int n) // Insert the node containing the data in to the link list as the No.n node
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;

    int length = findLength(L);
    if(n < 1 || n > length + 1)
    {
        return false;
    }
    else if( n == 1)
    {
        p->next = L;
        L = p;
        return true;
    }
    else
    {
        LNode *p_1 = findNodePointer(L, n-1);
        p->next = p_1->next;
        p_1->next = p;
        return true;
    }
}

bool insertFromHead(LNode *L, int data)    // 头插法
{
    if(InsertNode(L,data,1) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool insertFromTail(LNode *L, int data)    // 尾插法
{
    int length = findLength(L);
    int n = length + 1;
    if(InsertNode(L, data, n) == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int delNode(LNode *L, int n)               // Delete the No.n note and return the data in No.n node to the main
{
    int length = findLength(L);
    if(length == 0)
    {
        return -1;
    }
    if( n < 1 || n > length)
    {
        return -1; // -1 is considered invalid in this case
    }
    else if(n == 1)
    {
        LNode *temp = L;
        L = L->next;
        int preData = temp->data;
        free(temp);
        return preData;
    }
    else
    {
        LNode *p_1 = findNodePointer(L, n - 1);
        LNode *p_2 = p_1->next;
        p_1->next = p_2->next;
        int preData = p_2->data;
        free(p_2);
        return preData;
    }
}

int changeNode(LNode *L, int data, int n)  // Change the data of No.n node as the new data and return the pre-data to the main
{
    int length = findLength(L);
    if ( n < 1 || n > length)
    {
        return -1;
    }
    else
    {
        LNode *p = findNodePointer(L, n);
        int preData = p->data;
        p->data = data;
        return preData;
    }
}

bool delLinkList(LNode *L)                 // Delete the link list
{
    while( delNode(L,1) != -1)
    {
        ;
    } 
    return true;
}

bool outputLinkList(LNode *L)              // Output the link list
{
    int length = findLength(L);
    LNode *p = L;
    for (int i = 0; i < length; i++)
    {
        cout << p->data << endl;
        p = p->next;
    }
    return true;
}