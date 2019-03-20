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

## 二 Vector实现

> Vector常用操作

1. push_back 在数组的最后添加一个数据

2. pop_back 去掉数组的最后一个数据

3. at 得到编号位置的数据

4. begin 得到数组头的指针

5. end 得到数组的最后一个单元+1的指针

6. front 得到数组头的引用

7. back 得到数组的最后一个单元的引用

8. max_size 得到vector最大可以是多大

9. capacity 当前vector分配的大小

10. size 当前使用数据的大小

11. resize 改变当前使用数据的大小，如果它比当前使用的大，者填充默认值

12. reserve 改变当前vecotr所分配空间的大小

13. erase 删除指针指向的数据项

14. clear 清空当前的vector

15. rbegin 将vector反转后的开始指针返回(其实就是原来的end-1)

16. rend 将vector反转构的结束指针返回(其实就是原来的begin-1)

17. empty 判断vector是否为空

18. swap 与另一个vector交换数据

> 初始化

只需将顺序表长度置零

```cpp
void sqlist::init()
{
    len = 0;
}
```

> 清空 

```c
void sqlist::clear()
{
    v.clear();
    len = 0;
}
```

> 判断是否为空
```c
bool sqlist::is_empty()
{
    return (len == 0) ? true : false;
}

```

> 获取数据

```c
Seqlist_t sqlist::get_elem(int i)
{
    return v.at(i);
}
```

> 查找数据

```c
int sqlist::get_locate(Seqlist_t e)
{
    int i = 0;
    for (i = 0; i < len; i++)
        if (e.element == v.at(i).element)
            break;
    return (i != len) ? (i) : (-1);
}
```

> 在尾部添加数据

```c
void sqlist::add_back(Seqlist_t e)
{
    v.push_back(e);
    len++;
}
```

> 删除最后一个数据

```c
void sqlist::delete_back()
{
    v.pop_back();
    len--;
}
```

> 指定位置插入数据

```c
void sqlist::insert_elem(Seqlist_t e, int i)
{
    v.insert(v.begin() + i, e);
    len++;
}
```

>删除指定位置数据

```c
void sqlist::delete_elem(int i)
{
    v.erase(v.begin() + i);
    len--;
}
```

>遍历数据

```c
void sqlist::traverse()
{
    cout << "The element is ";
    for (int i = 0; i < len; i++)
        cout << v.at(i).element << ' ';
    cout << endl;
}
```