//
// Created by 张宝印 on 2022/10/25.
//

#include <iostream>


class LinkStack{
private:
    typedef struct linknode{
        char data;
        linknode *next;
    }LinkStNode;
    LinkStNode *L;
public:
    LinkStack();
    ~LinkStack();
    bool isStackEmpty();
    void push(char elem);
    char pop();
    char getTop();
};


LinkStack::LinkStack() {
    try {
        L = (LinkStNode *) malloc(sizeof(LinkStNode));
    }
    catch (std::bad_alloc &e){
        std::cout << "alloc_err" << std::endl;
    }
    L->next = nullptr;
}

LinkStack::~LinkStack(){
    LinkStNode *left = L, *right = L->next;
    while(right != nullptr){
        free(left);
        left = right;
        right = right->next;
    }
    free(right);
}

bool LinkStack::isStackEmpty(){
    return (L->next == nullptr);
}

void LinkStack::push(char elem){
    LinkStNode *ptr = L;
    try {
        ptr = (LinkStNode *) malloc(sizeof(LinkStNode));
    }
    catch (std::bad_alloc &e){
        std::cout << "alloc_err" << std::endl;
    }
    ptr->data = elem;
    ptr->next = L;
    L = ptr;
}

char LinkStack::pop(){
    LinkStNode *ptr = L;
    char ret;
    try {
        ptr = (LinkStNode *) malloc(sizeof(LinkStNode));
    }
    catch (std::bad_alloc &e){
        std::cout << "alloc_err" << std::endl;
    }
    if (L->next == nullptr){
        ret = -1;
    }
    else{
        ptr = L;
        ret = ptr->data;
        L = ptr->next;
        free(ptr);
    }
    return ret;
}

char LinkStack::getTop(){
    char ret;
    if (L->next == nullptr){
        ret = -1;
    }
    else {
        ret = L->next->data;
    }
    return ret;
}



// 3927  exp3-2
int main (){
    using namespace std;
    cout << "(1)LinkStack() -> s" << endl;
    class LinkStack s;
    cout << "(2)isStackEmpty?: " << s.isStackEmpty() << endl;
    cout << "(3)push: " << endl;
    char src = 'a';
    for (int i = 0; i < 5; ++i)
        s.push(src+i);
    cout << "(4)isStackEmpty?: " << s.isStackEmpty() << endl;
    cout << "(5)pop: ";
    while (!s.isStackEmpty())
        cout << s.pop() << ' ';
    cout << endl;
    cout << "(6)isStackEmpty?: " << s.isStackEmpty() << endl;
    cout << "(7)~LinkStack()" << endl;
    s.pop();
}
