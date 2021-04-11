#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    void *data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
}  Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    int i;                  //记录尾节点的位置
    int length;            //队列长度
}  LQueue;
typedef enum
{
    FALSE=0, TRUE=1
} Status;

Status IsEmptyLQueue( LQueue *Q)       //判断队是否为空
{
   if(Q->length==0) return TRUE;
   else             return FALSE;
}

void Judge_Empty(LQueue *Q)
{
    int i=IsEmptyLQueue(Q);
    if(i)    printf("空队！\n");
    else        printf("不是空队！\n");
}
