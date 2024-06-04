#include <stdlib.h>
#include <iostream>
using namespace std;
// 双向链表不带头节点
typedef struct linkList
{
    int data;
    struct linkList *next;
    struct linkList *pre;
} LNode;

LNode *iniLinkList(LNode *L);               // Initialize the link list;
bool delLinkList(LNode *L);                 // Delete the link list;
bool insertNode(LNode *L, int data, int n); // Insert the data as the No.n data;
int delNode(LNode *L, int n);               // Delete the No.n node and return the data in that node to the main;
LNode *findNodePointer(LNode *L, int n);    // Find the pointer of the No.n node and return it to the main;
int findLength(LNode *L);                   // Find the length of the link list;
bool outputLinkList(LNode *L);              // Output the link list;
bool empty(LNode *L);                       // Find if the link list is empty or not;

int main()
{
    return 0;
}

LNode *iniLinkList(LNode *L) // Initialize the link list;
{
    L = NULL;
    return L;
}

bool delLinkList(LNode *L) // Delete the link list;
{
    if (empty(L))
    {
        return false;
    }
    else
    {
        int length = findLength(L);
        for (int i = 0; i < length; i++)
        {
            delNode(L, 1);
        }
        if (empty(L))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool insertNode(LNode *L, int data, int n) // Insert the data as the No.n data;
{
    int length = findLength(L);

    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;

    if (length == 0)
    {
        if (n == 1)
        {
            L = p;
            L->next = L;
            L->pre = L;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (1 <= n && n <= length)
        {
            LNode *p_1 = findNodePointer(L, n);
            p->pre = p_1->pre;
            p_1->pre->next = p;
            p->next = p_1;
            p_1->pre = p;
            return true;
        }
        if (n == length + 1)
        {
            LNode *p_2 = findNodePointer(L, n - 1);
            p->next = p_2->next;
            p_2->next->pre = p;
            p->pre = p_2;
            p_2->next = p;
            return true;
        }
        else
        {
            return false;
        }
    }
}

int delNode(LNode *L, int n) // Delete the No.n node and return the data in that node to the main;
{
    int length = findLength(L);
    if (n < 1 || n > length)
    {
        return -1; // -1 is considered invalid in this case
    }
    else if (n == 1)
    {
        LNode *temp = L;
        L = L->next;
        L->pre = temp->pre;
        temp->pre->next = L;
        int delData = temp->data;
        free(temp);
        return delData;
    }
    else
    {
        LNode *p = findNodePointer(L, n);
        p->pre->next = p->next;
        p->next->pre = p->pre;
        int delData = p->data;
        free(p);
        return delData;
    }
}

LNode *findNodePointer(LNode *L, int n) // Find the pointer of the No.n node and return it to the main;
{
    LNode *p = L;
    for (int i = 0; i < n - 1; i++)
    {
        p = p->next;
    }
    return p;
}

int findLength(LNode *L) // Find the length of the link list;
{
    LNode *head = L;
    LNode *p = L;
    int cout = 0;
    if (head == NULL)
    {
        return cout;
    }
    else
    {
        cout = 1;
        while (p->next != head)
        {
            cout++;
            p = p->next;
        }
        return cout;
    }
}

bool outputLinkList(LNode *L) // Output the link list;
{
    LNode *p = L;
    if (p == NULL)
    {
        return false;
    }
    else
    {
        int length = findLength(L);
        for (int i = 0; i < length; i++)
        {
            cout << p->data << endl;
            p = p->next;
        }
        return true;
    }
}

bool empty(LNode *L) // Find if the link list is empty or not;
{
    if (L == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}