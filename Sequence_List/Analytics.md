# (Sequence List)顺序表算法分析
## 一 Struct实现

> 动态存储分配
```cpp
#define LIST_INIT_SIZE 100  //初始化顺序表最大容量
#define LISTINCREMENT 10    //默认增加空间量

typedef struct
{
    char* elem;         //一维数组
    int length;         //线性表当前长度
    int listsize;       //当前数组容量
    int incrementsize;  //增加空间量
} SqList;
```

> 初始化

构造一个空的顺序表L

```cpp
void InitList_Sq(SqList& L, int maxsize = LIST_INIT_SIZE, int incresize = LISTINCREMENT)
{                                        //构建最大容量maxsize的顺序表L
    L.elem = (char*)malloc(maxsize * sizeof(char));  //申请内存
    if (!L.elem)
        exit(1);
    L.length = 0;
    L.listsize = maxsize;
    L.incrementsize = incresize;
}
```

> 求表长

返回当前顺序表L元素个数

```c
int ListLength_Sq(SqList L)
{
    return L.length;
}
```

> 查找元素

从第一个元素起，一次和待查找元素e相比较，找到则返回该元素在L中的位序，查找成功；否则返回-1，查找失败。

```c
int LocateElem(SqList L, char e)
{
    for (int i = 0; i < L.length; i++) {      //遍历
        if (L.elem[i] == e)
            return i;
    }
    return -1;
}
```

> 插入元素

假设顺序表中有length个元素，在第i(0<=i<=length)个元素前插入新元素e时，需要将第length-1至第i个位置(共length-i个)依次后移，然后插入e到第i个位置，length加1，返回true。

```c
bool ListInsert_Sq(SqList& L, int i, char e)
{
    int j;
    if (i < 0 || i > L.length) {
        return false;
    }
    if (L.length > L.listsize) {
        L.elem = (char*)realloc(L.elem, (L.listsize + L.incrementsize) * sizeof(char));
        if (!L.elem)
            exit(1);
        L.listsize += L.incrementsize;
    }
    for (j = L.length; j > i; j--)      //后移
        L.elem[j] = L.elem[j - 1];
    L.elem[i] = e;
    L.length++;
    return true;
}
```

> 删除元素

与插入相反，需要删除第i(0<=i<=length)个元素，将第i至第length-1个位置(共length-i个)依次前移，length减1，返回true。

```c
bool ListDetect_Sq(SqList& L, int i, char& e)
{
    int j;
    if (i < 0 || i > L.length)
        return false;
    if (L.length <= 0)
        return false;
    e = L.elem[i];
    for (int j = i + 1; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j];
    L.length--;
    return true;
}
```

> 取元素

直接返回元素，不需要移动

```c
bool GetElem_Sq(SqList L, int i, char& e)
{
    if (i < 0 || i > L.length)
        return false;
    if (L.length <= 0)
        return false;
    e = L.elem[i];
    return true;
}
```

> 遍历表

```c
void ListTraverse_Sq(SqList L)
{
    int i;
    for (i = 0; i < L.length; i++)
        cout << L.elem[i] << " ";
    cout << endl;
}
```

> 释放表

```c
void DestroyList_Sq(SqList& L)
{
    free(L.elem);
    L.listsize = 0;
    L.length = 0;
}
```