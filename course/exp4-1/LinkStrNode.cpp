//
// Created by �ű�ӡ on 2022/10/29.
//

#include<cstdio>
#include<malloc.h>

typedef struct snode {
    char data;
    struct snode *next;
} LinkStrNode; //���������������
void StrAssign (LinkStrNode *&s, const char cstr[]) //���ַ�������cstr������s
{
    LinkStrNode *r, *p;
    s = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    r = s; //rʼ��ָ��β���
    for (int i = 0; cstr[i] != '\0'; i++) {
        p = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        p->data = cstr[i];
        r->next = p;
        r = p;
    }
    r->next = nullptr;
}

void DestroyStr (LinkStrNode *&s)
{
    LinkStrNode *pre = s, *p = s->next;
    while (p != nullptr)
    {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

void StrCopy (LinkStrNode *&s, LinkStrNode *t)
{
    LinkStrNode *p = t->next, *q, *r;
    {
        s = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        r = s;
        while (p != nullptr)
            q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = nullptr;
}

bool StrEqual (LinkStrNode *s, LinkStrNode *t) //�жϴ��Ƿ����
{
    LinkStrNode *p = s->next, *q = t->next;
    while (p != nullptr && q != nullptr && p->data == q->data) {
        p = p->next;
        q = q->next;
    }
    if (p == nullptr && q == nullptr)
        return true;
    else
        return false;
}

int StrLength (LinkStrNode *s) //�󴮳�
{
    int i = 0;
    LinkStrNode *p = s->next;
    while (p != nullptr) {
        i++;
        p = p->next;
    }
    return i;
}

LinkStrNode *Concat (LinkStrNode *s, LinkStrNode *t)//���Ӵ�
{
    LinkStrNode *str, *p = s->next, *q, *r;
    str = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    r = str;
    while (p != nullptr)
    {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    p = t->next;
    while (p != nullptr)
    {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = nullptr;
    return str;
}

LinkStrNode *SubStr (LinkStrNode *s, int i, int j) //���Ӵ�
{
    int k;
    LinkStrNode *str, *p = s->next, *q, *r;

    str = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    str->next = nullptr;
    r = str;
    if (i <= 0 || i > StrLength(s) || j < 0 || i + j - 1 > StrLength(s))
        return str;
    for (k = 0; k < i - 1; k++)
        p = p->next;
    for (k = 1; k <= j; k++)
    {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = nullptr;
    return str;
}

LinkStrNode *InsStr (LinkStrNode *s, int i, LinkStrNode *t)
{
    LinkStrNode *str, *p = s->next, *p1 = t->next, *q, *r;
    str = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    str->next = nullptr;
    r = str;
    if (i <= 0 || i > StrLength(s) + 1)
        return str;
    for (int k = 1; k < i; k++)
    {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    while (p1 != nullptr)
    {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p1->data;
        r->next = q;
        r = q;
        p1 = p1->next;
    }
    while (p != nullptr)
    {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = nullptr;
    return str;
}

LinkStrNode *DelStr (LinkStrNode *s, int i, int j)//ɾ���Ӵ�
{
    LinkStrNode *str, *p = s->next, *q, *r;
    str = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    str->next = nullptr;

    r = str;
    if (i <= 0 || i > StrLength(s) || j < 0 || i + j - 1 > StrLength(s))
        return str;
    for (int k = 0; k < i - 1; k++)
    {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    for (int k = 0; k < j; k++)
        p = p->next;
    while (p != nullptr)
    {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = nullptr;
    return str;
}

LinkStrNode *RepStr (LinkStrNode *s, int i, int j, LinkStrNode *t) //�滻�Ӵ�
{
    LinkStrNode *str, *p = s->next, *p1 = t->next, *q, *r;
    str = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    str->next = nullptr;
    r = str;
    if (i <= 0 || i > StrLength(s) || j < 0 || i + j - 1 > StrLength(s))
        return str;
    for (int k = 0; k < i - 1; k++)
    {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        q->next = nullptr;
        r->next = q;
        r = q;
        p = p->next;
    }
    for (int k = 0; k < j; k++)
        p = p->next;
    while (p1 != nullptr)
    {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p1->data;
        q->next = nullptr;
        r->next = q;
        r = q;
        p1 = p1->next;
    }
    while (p != nullptr)
    {
        q = (LinkStrNode *) malloc(sizeof(LinkStrNode));
        q->data = p->data;
        q->next = nullptr;
        r->next = q;
        r = q;
        p = p->next;
    }
    r->next = nullptr;
    return str;

}

void DispStr (LinkStrNode *s) //�����
{
    LinkStrNode *p = s->next;
    while (p != nullptr) {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
}


int main() {
    LinkStrNode *s, *s1, *s2, *s3, *s4;
    printf("�����Ļ�����������:\n");
    printf(" (1)������s�ʹ�s1\n");
    StrAssign(s, "abcdefghijklmn");
    StrAssign(s1, "123");
    printf(" (2)�����s:");
    DispStr(s);
    printf(" (3)��s�ĳ���:%d\n", StrLength(s));
    printf(" (4)�ڴ�s�ĵ�9���ַ�λ�ò��봮s1��������s2\n");
    s2 = InsStr(s, 9, s1);
    printf(" (5)�����s2:");
    DispStr(s2);
    printf(" (6)ɾ����s��2���ַ���ʼ��5���ַ���������s2\n");
    s2 = DelStr(s, 2, 5);
    printf(" (7)�����s2:");
    DispStr(s2);
    printf(" (8)����s��2���ַ���ʼ��5���ַ��滻�ɴ�s1��������s2, \n");
    s2 = RepStr(s, 2, 5, s1);
    printf(" (9)�����s2: ");
    DispStr(s2);
    printf(" (10)��ȡ��s�ĵ�2���ַ���ʼ��10���ַ���������s3\n");
    s3 = SubStr(s, 2, 10);
    printf(" (11)�����s3:");
    DispStr(s3);
    printf(" (12)����s1�ʹ�s2����������������s4\n");
    s4 = Concat(s1, s2);
    printf(" (13)�����s4:");
    DispStr(s4);
    DestroyStr(s);
    DestroyStr(s1);
    DestroyStr(s2);
    DestroyStr(s3);
    DestroyStr(s4);
}

