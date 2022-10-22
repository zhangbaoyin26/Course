//
// Created by 张宝印 on 2022/10/22.
//

#include "LinkList.h"

int main(){
    char arr[] = {'a', 'b', 'c', 'd', 'e'};
    //(1) (2)
    class LinkList L(arr, sizeof(arr)/sizeof(char));
    //(3)
    std::cout << "After insert: ";
    L.displayList();
    std::cout << std::endl;
    //(4)
    std::cout << "Length: " << L.listLength() << std::endl;
    //(5)
    std::cout << "Is_empty?: " << L.is_ListEmpty() << std::endl;
    //(6)
    std::cout << "Value[3-1]: " << L.getElem(3) << std::endl;
    //(7)
    std::cout << "Index(a): " << (int)L.locateElem('a') << std::endl;
    //(8)
    L.listInsert(4-1, 'f');
    //(9)
    std::cout << "After insert [4-1]: ";
    L.displayList();
    std::cout << std::endl;
    //(10)
    L.listDelete(L.getElem(3-1));
    //(11)
    std::cout << "After delete [3-1]: ";
    L.displayList();
    std::cout << std::endl;
    //(12)
    std::cout << "~LinkList()";
}