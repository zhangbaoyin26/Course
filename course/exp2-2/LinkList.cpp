//
// Created by 张宝印 on 2022/10/22.
//

#include "LinkList.h"

LinkList::LinkList(const char src[], size_t len) {
    LinkNode *ptr;
    try {
        L = (LinkNode *) malloc(sizeof(LinkNode));
        ptr = L;
    }
    catch (std::bad_alloc &e) {
        std::cout << e.what() << std::endl;
    }
    if (src != nullptr) {
        ptr->data = src[0];
        for (size_t i = 1; i < len; ++i) {
            try {
                auto *NEXT = (LinkNode *) malloc(sizeof(LinkNode));
                ptr->next = NEXT;
                ptr = NEXT;
                NEXT->data = src[i];
                NEXT->next = nullptr;
            }
            catch (std::bad_alloc &e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
    else
        ptr->next = nullptr;
}

LinkList::~LinkList() {
    LinkNode *left, *right;
    left = L, right = L->next;
    while (right != nullptr){
        free(left);
        left = right;
        right = right->next;
    }
    free(left);
}

bool LinkList::is_ListEmpty() {
    return (L->next == nullptr);
}

size_t LinkList::listLength() {
    size_t len = 0;
    LinkNode *ptr = L;
    while (ptr != nullptr) {
        ++len;
        ptr = ptr->next;
    }
    return len;
}

void LinkList::displayList() {
    LinkNode *ptr = L;
    while (ptr != nullptr){
        std::cout << ptr->data << ' ';
        ptr = ptr->next;
    }
}

char LinkList::getElem(size_t index) {
    size_t i = 0;
    LinkNode *ptr = L;
    while ((ptr != nullptr) and (index != i++))
        ptr = ptr->next;
    if (index > i) {
        assert("索引值超过链表长度");
        return -1;
    }
    return ptr->data;
}

size_t LinkList::locateElem(char elem) {
    size_t index = 0;
    LinkNode *ptr = L;
    while (ptr != nullptr) {
        if (ptr->data == elem)
            return index;
        ++index;
        ptr = ptr->next;
    }
    return -1;
}

bool LinkList::listInsert(size_t index, char elem) {
    size_t i = 0;
    LinkNode *ptr = L;
    while ((ptr->next != nullptr) and (index != i++))
        ptr = ptr->next;
    if (index > i) {
        assert("索引值超过链表长度");
        return false;
    }
    else
    {
        LinkNode *newNode;
        try{
            newNode = (LinkNode*) malloc(sizeof(LinkNode));
        }
        catch (std::bad_alloc &e){
            std::cout << e.what() << std::endl;
        }
        newNode->data = elem;
        newNode->next = ptr->next;
        ptr->next = newNode;
        return true;
    }
}

bool LinkList::listDelete(char elem) {
    LinkNode *left, *right;
    left = L, right = left;
    while (right != nullptr){
        if (right->data == elem){
            right = left->next;
            break;
        }

    }
    if (left == nullptr)   //没找到
        return false;
    else {
        left->next = right->next;
        free(right);
        return true;
    }
}
