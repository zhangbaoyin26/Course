//
// Created by �ű�ӡ on 2022/11/20.
//


#include <stdio.h>
#include <malloc.h>

#define MaxSize 100

typedef int KeyType;
typedef char InfoType;
typedef struct node {
    KeyType key;
    InfoType data;
    struct node *lchild, *rchild;
} BSTNode;


void DispBST(BSTNode *bt) {
    if (bt != NULL) {
        printf("%d", bt->key);
        if (bt->lchild != NULL || bt->rchild != NULL) {
            printf("(");
            DispBST(bt->lchild);
            if (bt->rchild != NULL)
                printf(",");
            DispBST(bt->rchild);
            printf(")");
        }
    }
}

bool InsertBST(BSTNode *&bt, KeyType k) {
    if (bt == NULL) {

        bt = (BSTNode *) malloc(sizeof(BSTNode));
        bt->key = k;
        bt->lchild = bt->rchild = NULL;
        return true;
    } else if (k == bt->key)
        return false;
    else if (k < bt->key)
        return InsertBST(bt->lchild, k);
    else
        return InsertBST(bt->rchild, k);
}

BSTNode *CreateBST(int A[], int n) {
    BSTNode *bt = NULL;
    int i = 0;
    while (i < n)
        if (InsertBST(bt, A[i]) == 1) {
            printf("   ��%d��,����%d:", i + 1, A[i]);
            DispBST(bt);
            printf("\n");
            i++;
        }
    return bt;
}

void Deletel(BSTNode *p, BSTNode *&r) {
    BSTNode *q;
    if (r->rchild != NULL)
        Deletel(p, r->rchild);

    else {
        p->key = r->key;
        p->data = r->data;
        q = r;
        r = r->lchild;
        free(q);
    }
}

void Delete(BSTNode *&p) {
    BSTNode *q;
    if (p->rchild == NULL) {
        q = p;
        p = p->lchild;
        free(q);
    } else if (p->lchild == NULL) {
        q = p;
        p = p->rchild;
        free(q);
    } else Deletel(p, p->lchild);
}

bool DeleteBST(BSTNode *&bt, KeyType k) {
    if (bt == NULL) return false;
    else {
        if (k < bt->key)
            return DeleteBST(bt->lchild, k);
        return DeleteBST(bt->rchild, k);
        {
            Delete(bt);
            return true;
        }
    }
}

void SearchBST1(BSTNode *bt, KeyType k, KeyType path[], int i) {
    int j;
    if (bt == NULL)
        return;
    else if (k == bt->key) {
        path[i + 1] = bt->key;
        for (j = 0; j <= i + 1; j++)
            printf("% 3d", path[j]);
        printf("\n");
    } else {
        path[i + 1] = bt->key;
        if (k < bt->key)
            SearchBST1(bt->lchild, k, path, i + 1);
        else
            SearchBST1(bt->rchild, k, path, i + 1);

    }
}

int SearchBST2(BSTNode *bt, KeyType k) {
    if (bt == NULL)
        return 0;
    else if (k == bt->key) {
        printf("%3d", bt->key);
        return 1;
    } else if (k < bt->key)
        SearchBST2(bt->lchild, k);
    else
        SearchBST2(bt->rchild, k);
    printf("%3d", bt->key);
}

int predt = -32767;

bool JudgeBST(BSTNode *bt) {
    bool b1, b2;
    if (bt == NULL)
        return true;
    else {
        b1 = JudgeBST(bt->lchild);
        if (b1 == false || predt >= bt->key)
            return false;
        predt = bt->key;
        b2 = JudgeBST(bt->rchild);
        return b2;
    }
}

void DestroyBST(BSTNode *bt) {
    if (bt != NULL) {
        DestroyBST(bt->lchild);
        DestroyBST(bt->rchild);
        free(bt);
    }
}


int main() {
    BSTNode *bt;
    int path[MaxSize];
    KeyType k = 6;
    int a[] = {4, 9, 0, 1, 8, 6, 3, 5, 2, 7}, n = 10;
    printf("(1)����һ��BST��:");
    printf("\n");
    bt = CreateBST(a, n);
    printf("(2)BST:");
    DispBST(bt);
    printf("\n");
    printf("(3)bt%s\n", (JudgeBST(bt) ? "��һ�� BST" : "����һ�� BST"));
    printf("(4)����%d�ؼ���(�ݹ�,˳��):", k);
    SearchBST1(bt, k, path, -1);
    printf("(5)����%d�ؼ���(�ǵݹ�,����):", k);
    SearchBST2(bt, k);
    printf("\n(6)ɾ������:\n");
    printf("   ԭBST:");
    DispBST(bt);
    printf("\n");
    printf("   ɾ�����4:");
    DeleteBST(bt, 4);
    DispBST(bt);
    printf("\n");
    printf("   ɾ�����5:");
    DeleteBST(bt, 5);
    DispBST(bt);
    printf("\n");
    printf("(7)���� BST\n");
    DestroyBST(bt);
    return 0;
}
