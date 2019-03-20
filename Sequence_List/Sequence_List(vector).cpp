#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef struct elem {
    int element;
} Seqlist_t;

class sqlist {
public:
    vector<Seqlist_t> v;
    int len;
    void init();
    void clear();
    bool is_empty();
    int length();
    Seqlist_t get_elem(int i);
    int get_locate(Seqlist_t e);
    Seqlist_t get_last(int i);
    Seqlist_t get_next(int i);
    void add_back(Seqlist_t e);
    void delete_back();

    void insert_elem(Seqlist_t e, int i);
    void delete_elem(int i);
    void traverse();
};

int main()
{
    sqlist L;
    Seqlist_t zero, one, two, three, four;

    zero.element = 0;
    one.element = 1;
    two.element = 2;
    three.element = 3;
    four.element = 4;

    L.init();
    L.add_back(zero);
    L.add_back(one);
    L.add_back(two);
    L.add_back(three);
    L.add_back(four);

    cout << "Init elem" << endl;
    L.traverse();
    cout << "Delect the last one" << endl;
    L.delete_back();
    L.traverse();
    cout << "Delect the third elem" << endl;
    L.delete_elem(2);
    L.traverse();
    cout << "insert the fifth elem before the first one" << endl;
    L.insert_elem(four, 0);
    L.traverse();

    getchar();
    getchar();
    return 0;
}

void sqlist::init()
{
    len = 0;
}

void sqlist::clear()
{
    v.clear();
    len = 0;
}

bool sqlist::is_empty()
{
    return (len == 0) ? true : false;
}

int sqlist::length()
{
    return len;
}

Seqlist_t sqlist::get_elem(int i)
{
    return v.at(i);
}

int sqlist::get_locate(Seqlist_t e)
{
    int i = 0;
    for (i = 0; i < len; i++)
        if (e.element == v.at(i).element)
            break;
    return (i != len) ? (i) : (-1);
}

Seqlist_t sqlist::get_last(int i)
{
    return v.at(i - 1);
}

Seqlist_t sqlist::get_next(int i)
{
    return v.at(i + 1);
}

void sqlist::add_back(Seqlist_t e)
{
    v.push_back(e);
    len++;
}

void sqlist::delete_back()
{
    v.pop_back();
    len--;
}

void sqlist::insert_elem(Seqlist_t e, int i)
{
    v.insert(v.begin() + i, e);
    len++;
}

void sqlist::delete_elem(int i)
{
    v.erase(v.begin() + i);
    len--;
}

void sqlist::traverse()
{
    cout << "The element is ";
    for (int i = 0; i < len; i++)
        cout << v.at(i).element << ' ';
    cout << endl;
}
