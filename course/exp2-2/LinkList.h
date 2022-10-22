//
// Created by 张宝印 on 2022/10/22.
//

#include <iostream>
#include <cstdlib>
#include <cassert>


class LinkList{
private:
    typedef struct Node{
        char data;
        Node* next;
    }LinkNode;
    LinkNode *L;
public:
    explicit LinkList(const char src[] = nullptr, size_t len = 0);
    ~LinkList();
    bool is_ListEmpty();
    size_t listLength();
    void displayList();
    char getElem(size_t index);
    size_t locateElem(char elem);
    bool listInsert(size_t index, char elem);
    bool listDelete(char elem);
};
