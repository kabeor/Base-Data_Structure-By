#include <iostream>
using namespace std;

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef struct
{
    int* elem;
    int length;
    int listsize;
    int incrementsize;
} SqList;

void InitList_Sq(SqList& L, int maxsize = LIST_INIT_SIZE, int incresize = LISTINCREMENT)
{
    L.elem = (int*)malloc(maxsize * sizeof(int));
    if (!L.elem)
        exit(1);
    L.length = 0;
    L.listsize = maxsize;
    L.incrementsize = incresize;
}

int ListLength_Sq(SqList L)
{
    return L.length;
}

int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i] == e)
            return i;
    }
    return -1;
}

bool ListInsert_Sq(SqList& L, int i, int e)
{
    int j;
    if (i < 0 || i > L.length) {
        return false;
    }
    if (L.length > L.listsize) {
        L.elem = (int*)realloc(L.elem, (L.listsize + L.incrementsize) * sizeof(int));
        if (!L.elem)
            exit(1);
        L.listsize += L.incrementsize;
    }
    for (j = L.length; j > i; j--)
        L.elem[j] = L.elem[j - 1];
    L.elem[i] = e;
    L.length++;
    return true;
}

bool ListDetect_Sq(SqList& L, int i, int& e)
{
    int j;
    if (i < 0 || i >= L.length)
        return false;
    if (L.length <= 0)
        return false;
    e = L.elem[i];
    for (j = i + 1; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j];
    L.length--;
    return true;
}

bool GetElem_Sq(SqList L, int i, int& e)
{
    if (i < 0 || i > L.length)
        return false;
    if (L.length <= 0)
        return false;
    e = L.elem[i];
    return true;
}

void ListTraverse_Sq(SqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
        cout << L.elem[i] << " ";
    cout << endl;
}

void DestroyList_Sq(SqList& L)
{
    free(L.elem);
    L.listsize = 0;
    L.length = 0;
}

int main()
{
    system("chcp 65001");
    SqList mylist;
    int i;
    int x, y, a[] = { 65, 66, 67, 68, 69, 70, 71, 72, 73, 74 };
    InitList_Sq(mylist, 50, 10);
    for (i = 0; i < 10; i++) {
        if (!ListInsert_Sq(mylist, i, a[i])) {
            cout << "插入失败" << endl;
            return 0;
        }
    }
    cout << "删除前 ";
    ListTraverse_Sq(mylist);
    cout << "请输入要删除的元素" << endl;
    cin >> y;
    if (!ListDetect_Sq(mylist, y, x)) {
        cout << "删除失败" << endl;
        return 0;
    }
    cout << x << " 被删除" << endl;
    cout << "删除后 ";
    ListTraverse_Sq(mylist);
    DestroyList_Sq(mylist);
    getchar();
    getchar();
    return 0;
}