#include <iostream>
using namespace std;

typedef struct Node {
    char data;
    struct Node* next;
} LNode, *LinkList;

void InitList_L(LinkList& L)
{
    L = (LNode*)malloc(sizeof(LNode));
    if (!L)
        exit(1);
    L->next = NULL;
}

int ListLength_L(LinkList L)
{
    LinkList p;
    int k = 0;
    p = L->next;
    while (p) {
        k++;
        p = p->next;
    }
    return k;
}

LNode* LocateElem_L(LinkList L, char e)
{
    LinkList p;
    p = L->next;
    while (p && p->data != e) {
        p = p->next;
    }
    return p;
}

bool ListInsert_L(LinkList& L, int i, char e)
{
    LinkList p, s;
    int j;
    p = L;
    j = 0;
    while (p->next && j < i - 1) {
        p = p->next;
        j++;
    }
    if (j != i - 1)
        return false;
    if ((s = (LNode*)malloc(sizeof(LNode))) == NULL)
        exit(1);
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListDelete_L(LinkList &L,int i,char &e)
{
    LinkList p,q;
    int j;
    p=L;
    j=0;
    while(p->next->next&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(j!=i-1)
        return false;
    q=p->next;
    p->next=q->next;
    e=q->data;
    free(q);
    return true;
}

bool GetElem_L(LinkList L,int i,char &e)
{
    LinkList p;
    int j;
    p=L;
    j=0;
    while(p->next&&j<i){
        p=p->next;
        j++;
    }
    if(j!=i)
        return false;
    e=p->data;
    return true;
}

void CreateList_L_Rear(LinkList &L,char a[],int n)
{
    LinkList p,q;
    int i;
    L=(LinkList)malloc(sizeof(LNode));
    q=L;
    for( i = 0; i < n; i++)
    {
        p=(LinkList)malloc(sizeof(LNode));
        p->data=a[i];
        q->next=p;
        q=p;
    }
    q->next=NULL;
}

void CreateList_L_Front(LinkList &L,char a[],int n)
{
    LinkList p;
    int i;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    for(i=n-1;i>=0;i--)
    {
        p=(LinkList)malloc(sizeof(LNode));
        p->data=a[i];
        p->next=L->next;
        L->next=p;
    }
}

void ListTraverse_L(LinkList L)
{
    LinkList p=L->next;
    while(p){
        cout<<" "<<p->data;
        p=p->next;
    }
    cout<<endl;
}

void DestroyList_L(LinkList &L)
{
    LinkList p,p1;
    p=L;
    while(p){
        p1=p;
        p=p->next;
        free(p1);
    }
    L=NULL;
}

int main()
{
    LinkList head;
    int i;
    char x,a[]={66,67,68,69,70};
    InitList_L(head);
    for( i = 1; i <= 5; i++)
    {
        if (!ListInsert_L(head,i,a[i-1])) {
            cout<<"Insert false"<<endl;
            return 0;
        }
    }
    cout<<"before delete";
    ListTraverse_L(head);
    if(!ListDelete_L(head,4,x))
    {
        cout<<"delete false"<<endl;
        return 0;
    }
    cout<<x<<" be deleted"<<endl;
    cout<<"after delete";
    ListTraverse_L(head);
    DestroyList_L(head);
    getchar();
    return 0;
}