//
// Created by 张宝印 on 2022/10/30.
//

#include <iostream>

class LinkQueue {
private:
    typedef struct Data_Node {
        char data;
        struct Data_Node *next;
    } DataNode;//声明链队数据结点类型
    typedef struct {
        DataNode *front;
        DataNode *rear;
    } LinkQuNode;//声明链队类型
    LinkQuNode *L;
public:
    LinkQueue(); //初始化队列q
    ~LinkQueue(); //销毁队列q
    bool QueueEmpty(); //判断队列q是否为空
    void enQueue(char e); //进队
    char deQueue(); //出队
};

LinkQueue::LinkQueue() {
    L = (LinkQuNode *) malloc (sizeof (LinkQuNode));
    L->front = L->rear = nullptr;
}

LinkQueue::~LinkQueue() {
    DataNode *p = L->front, *r;//p指向队头数据结点
    if (p != nullptr)//释放数据结点占用的空间
    {
        r = p->next;
        while (r != nullptr) {
            free (p);
            p = r;
            r = p->next;
        }
    }
    free (p);
    free (L);
}

bool LinkQueue::QueueEmpty() {
    return (L->rear == nullptr);
}

void LinkQueue::enQueue(char e) {
    DataNode *p;
    p = (DataNode *) malloc (sizeof (DataNode));
    p->data = e;
    p->next = nullptr;
    if (L->rear == nullptr)//若链队为空，则新结点既是队首结点又是队尾结点
        L->front = L->rear = p;
    else {
        L->rear->next = p;//将p结点链到队尾，并将rear指向它
        L->rear = p;
    }
}

char LinkQueue::deQueue() {
    DataNode *t;
    if (L->rear == nullptr)//队列为空
        return false;
    t = L->front;//t指向第一个数据结点
    if (L->front == L->rear)//队列中只有一个结点
        L->front = L->rear = nullptr;
    else//队列中有多个结点
        L->front = L->front->next;
    return t->data;
}


int main() {
    class LinkQueue g;
    printf("链队的基本运算如下:\n");
    printf(" (1)构造函数初始化链队g\n");
    printf(" (2)依次进链队元素a,b,c\n");
    g.enQueue('a');
    g.enQueue('b');
    g.enQueue('c');
    printf(" (3)链队为%s\n", (g.QueueEmpty() ? "空" : "非空"));
    if (g.QueueEmpty())
        printf("\t提示:队空,不能出队\n");
    else
        printf(" (4)出队一个元素%c\n", g.deQueue());
    printf(" (5)依次进链队元素d,e,f\n");
    g.enQueue('d');
    g.enQueue('e');
    g.enQueue('f');
    printf(" (6)出链队序列:");
    while (!g.QueueEmpty())
        printf("%c ", g.deQueue());
    printf("\n");
    printf(" (7)构析函数释放链队\n");
    return 0;
}