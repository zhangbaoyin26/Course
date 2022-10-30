//
// Created by �ű�ӡ on 2022/10/30.
//

#include <iostream>

class LinkQueue {
private:
    typedef struct Data_Node {
        char data;
        struct Data_Node *next;
    } DataNode;//�����������ݽ������
    typedef struct {
        DataNode *front;
        DataNode *rear;
    } LinkQuNode;//������������
    LinkQuNode *L;
public:
    LinkQueue(); //��ʼ������q
    ~LinkQueue(); //���ٶ���q
    bool QueueEmpty(); //�ж϶���q�Ƿ�Ϊ��
    void enQueue(char e); //����
    char deQueue(); //����
};

LinkQueue::LinkQueue() {
    L = (LinkQuNode *) malloc (sizeof (LinkQuNode));
    L->front = L->rear = nullptr;
}

LinkQueue::~LinkQueue() {
    DataNode *p = L->front, *r;//pָ���ͷ���ݽ��
    if (p != nullptr)//�ͷ����ݽ��ռ�õĿռ�
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
    if (L->rear == nullptr)//������Ϊ�գ����½����Ƕ��׽�����Ƕ�β���
        L->front = L->rear = p;
    else {
        L->rear->next = p;//��p���������β������rearָ����
        L->rear = p;
    }
}

char LinkQueue::deQueue() {
    DataNode *t;
    if (L->rear == nullptr)//����Ϊ��
        return false;
    t = L->front;//tָ���һ�����ݽ��
    if (L->front == L->rear)//������ֻ��һ�����
        L->front = L->rear = nullptr;
    else//�������ж�����
        L->front = L->front->next;
    return t->data;
}


int main() {
    class LinkQueue g;
    printf("���ӵĻ�����������:\n");
    printf(" (1)���캯����ʼ������g\n");
    printf(" (2)���ν�����Ԫ��a,b,c\n");
    g.enQueue('a');
    g.enQueue('b');
    g.enQueue('c');
    printf(" (3)����Ϊ%s\n", (g.QueueEmpty() ? "��" : "�ǿ�"));
    if (g.QueueEmpty())
        printf("\t��ʾ:�ӿ�,���ܳ���\n");
    else
        printf(" (4)����һ��Ԫ��%c\n", g.deQueue());
    printf(" (5)���ν�����Ԫ��d,e,f\n");
    g.enQueue('d');
    g.enQueue('e');
    g.enQueue('f');
    printf(" (6)����������:");
    while (!g.QueueEmpty())
        printf("%c ", g.deQueue());
    printf("\n");
    printf(" (7)���������ͷ�����\n");
    return 0;
}