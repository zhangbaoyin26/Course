//
// Created by 张宝印 on 2022/10/29.
//

#include<cstdio>
#include<malloc.h>

typedef struct snode {
    char data;
    struct snode *next;
} LinkStrNode; //声明链串结点类型
void StrAssign (LinkStrNode *&s, const char cstr[]) //将字符串常量cstr赋给串s
{
    LinkStrNode *r, *p;
    s = (LinkStrNode *) malloc(sizeof(LinkStrNode));
    r = s; //r始终指向尾结点
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

bool StrEqual (LinkStrNode *s, LinkStrNode *t) //判断串是否相等
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

int StrLength (LinkStrNode *s) //求串长
{
    int i = 0;
    LinkStrNode *p = s->next;
    while (p != nullptr) {
        i++;
        p = p->next;
    }
    return i;
}

LinkStrNode *Concat (LinkStrNode *s, LinkStrNode *t)//连接串
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

LinkStrNode *SubStr (LinkStrNode *s, int i, int j) //求子串
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

LinkStrNode *DelStr (LinkStrNode *s, int i, int j)//删除子串
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

LinkStrNode *RepStr (LinkStrNode *s, int i, int j, LinkStrNode *t) //替换子串
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

void DispStr (LinkStrNode *s) //输出串
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
    printf("链串的基本运算如下:\n");
    printf(" (1)建立串s和串s1\n");
    StrAssign(s, "abcdefghijklmn");
    StrAssign(s1, "123");
    printf(" (2)输出串s:");
    DispStr(s);
    printf(" (3)串s的长度:%d\n", StrLength(s));
    printf(" (4)在串s的第9个字符位置插入串s1而产生串s2\n");
    s2 = InsStr(s, 9, s1);
    printf(" (5)输出串s2:");
    DispStr(s2);
    printf(" (6)删除串s第2个字符开始的5个字符而产生串s2\n");
    s2 = DelStr(s, 2, 5);
    printf(" (7)输出串s2:");
    DispStr(s2);
    printf(" (8)将串s第2个字符开始的5个字符替换成串s1而产生串s2, \n");
    s2 = RepStr(s, 2, 5, s1);
    printf(" (9)输出串s2: ");
    DispStr(s2);
    printf(" (10)提取串s的第2个字符开始的10个字符而产生串s3\n");
    s3 = SubStr(s, 2, 10);
    printf(" (11)输出串s3:");
    DispStr(s3);
    printf(" (12)将串s1和串s2连接起来而产生串s4\n");
    s4 = Concat(s1, s2);
    printf(" (13)输出串s4:");
    DispStr(s4);
    DestroyStr(s);
    DestroyStr(s1);
    DestroyStr(s2);
    DestroyStr(s3);
    DestroyStr(s4);
}

