#include <stdio.h>
#include <stdlib.h>
#define QueueMax 100

typedef struct Node
{
    int data;
    struct Node *LChild, *RChild;
}BiNode, *BiTree;

typedef struct
{
    BiTree data[QueueMax];
    int head;
    int rear;
    int len;
}Queue;

BiTree CreateTree();  //建立二叉树
Queue InitQueue();  //初始化队列
int IsEmptyQueue(Queue seq);  //队列判空
int IsFullQueue(Queue seq);   //队列判满
void PushQueue(Queue *seq, BiTree T);  //入队
void PopQueue(Queue *seq, BiTree *T);  //出队
void LayerOrder(BiTree T);  //层序遍历

int main()
{
    BiTree T;
    T = CreateTree();
    LayerOrder(T);
    return 0;
}

BiTree CreateTree()
{  //建立二叉树
    int c;
    c = getchar();
    BiTree T;
    if (c == -1) {
        return NULL;
    }
    T = (BiTree) malloc (sizeof(BiNode));
    T->data = c;
    T->LChild = CreateTree();
    T->RChild = CreateTree();
    return T;
}

Queue InitQueue()
{  //初始化队列
    Queue seq;
    for(int i = 0; i < QueueMax; i++) {
        seq.data[i] = NULL;
    }
    seq.head = 0;
    seq.rear = -1;
    seq.len = 0;
    return seq;
}

int IsEmptyQueue(Queue seq)
{  //队列判空
    if (seq.len == 0) {
        return 1;
    }
    return 0;
}

int IsFullQueue(Queue seq)
{  //队列判满
    if (seq.len == QueueMax) {
        return 1;
    }
    return 0;
}

void PushQueue(Queue *seq, BiTree T)
{  //入队
    if (IsFullQueue(*seq)) {
        printf("ErrorFull");
        return;
    }
    seq->rear = (seq->rear + 1) % QueueMax;
    seq->len++;
    seq->data[seq->rear] = T;
}

void PopQueue(Queue *seq, BiTree *T)
{  //出队
    if (IsEmptyQueue(*seq)) {
        printf("ErrorEmpty");
        return;
    }
    seq->head = (seq->head + 1) % QueueMax;
    *T = seq->data[seq->head];
    seq->len--;
}

void LayerOrder(BiTree T)
{  //层序遍历
    Queue seq;
    seq = InitQueue();
    BiTree tmp;
    tmp = T;
    PushQueue(&seq, tmp);
    while(!IsEmptyQueue(seq)) {
        printf("%d", tmp->data);
        if (tmp->LChild != NULL) {
            PushQueue(&seq, tmp->LChild);
        }
        if (tmp->RChild != NULL) {
            PushQueue(&seq, tmp->RChild);
        }
        PopQueue(&seq, &tmp);
    }
}

