//
// Created by 张宝印 on 2022/11/1.
//

#include <iostream>

const int maxsize = 100;

typedef struct Tree_Node {
    char data;
    struct Tree_Node *lchild;
    struct Tree_Node *rchild;
} Tnode;



void CreateTree(Tnode *&b,char *str) {
    Tnode *St[maxsize], *p;
    int top = -1, k, j = 0;
    char ch;
    b = nullptr;
    ch = str[j];
    while(ch!='\0') {
        switch(ch) {
            case'(':
                top++;
                St[top]=p;
                k=1;
                break;
            case')':
                top--;
                break;
            case',':
                k=2;
                break;
            default:
                p=(Tnode*) malloc(sizeof(Tnode));
                p->data=ch;
                p->lchild=p->rchild=nullptr;
                if ( b==nullptr)
                    b=p;
                else {
                    switch(k) {
                        case 1:
                            St[top]->lchild=p;
                            break;
                        case 2:
                            St[top]->rchild=p;
                            break;
                        default:
                            break;
                    }
                }
        }
        j++;
        ch=str[j];
    }
}

int BTHeigt(Tnode *b) {
    int lchildh, rchildh;
    if (b==nullptr)
        return(0);
    else {
        lchildh=BTHeigt(b->lchild);
        rchildh=BTHeigt(b->rchild);
        return(lchildh>rchildh)?(lchildh+1):(rchildh+1);
    }
}

int Nodes(Tnode *b){
    int num1, num2;
    if (b == nullptr)
        return 0;
    else if (b->lchild==nullptr and b->rchild==nullptr)
        return 1;
    else {
        num1 = Nodes(b->lchild);
        num2 = Nodes(b->rchild);
        return num1+num2+1;
    }
}

int leafNodes(Tnode *b){
    int num1, num2;
    if (b == nullptr)
        return 0;
    else if (b->lchild==nullptr and b->rchild==nullptr)
        return 1;
    else {
        num1 = leafNodes(b->lchild);
        num2 = leafNodes(b->rchild);
        return num1+num2;
    }
}

void PreOrder(Tnode *b) {
    if (b != nullptr) {
        printf("%c ", b->data);
        PreOrder(b->lchild);
        PreOrder(b->rchild);
    }
}

void InOrder(Tnode *b) {
    if (b != nullptr) {
        InOrder(b->lchild);
        printf("%c ", b->data);
        InOrder(b->rchild);
    }
}

void PostOrder(Tnode *b) {
    if (b != nullptr) {
        PostOrder(b->lchild);
        PostOrder(b->rchild);
        printf("%c ", b->data);
    }
}

void TravLevel(Tnode *b) {
    Tnode *Qu[maxsize];
    int front = 0, rear = 0;
    if(b!=nullptr)
        printf("%c ",b->data);
    rear++;
    Qu[rear] = b;
    while(rear!=front) {
        front=(front+1)%maxsize;
        b=Qu[front];
        if(b->lchild != nullptr) {
            printf("%c ", b->lchild->data);
            rear=(rear+1)%maxsize;
            Qu[rear] = b->lchild;
        }
        if(b->rchild != nullptr) {
            printf("%c ", b->rchild->data);
            rear = (rear+1)%maxsize;
            Qu[rear] = b->rchild;
        }
    }
    printf("\n");
}


//A(B(D,E(H(G,K(L,M(,N)),))),C(F,G(,I)))

int main() {
    using namespace std;
    Tnode* b;
    char src[] = "A(B(D,E(H(G,K(L,M(,N)),))),C(F,G(,I)))";
    CreateTree(b, src);
    cout << "PreOrder:  ";  PreOrder(b);   cout << endl;
    cout << "InOrder:   ";  InOrder(b);    cout << endl;
    cout << "PostOrder: ";  PostOrder(b);  cout << endl;
    cout << "TravLevel: ";  TravLevel(b);  cout << endl;

    cout << "Height: " << BTHeigt(b) << endl;
    cout << "Nodes: " << Nodes(b) << endl;
    cout << "leafNodes: " << leafNodes(b) << endl;
}











