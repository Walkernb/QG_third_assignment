#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    void *data;                   //������ָ��
    struct node *next;            //ָ��ǰ������һ���
}  Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
    int i;                  //��¼β�ڵ��λ��
    int length;            //���г���
}  LQueue;
typedef enum
{
    FALSE=0, TRUE=1
} Status;

Status IsEmptyLQueue( LQueue *Q)       //�ж϶��Ƿ�Ϊ��
{
   if(Q->length==0) return TRUE;
   else             return FALSE;
}

void Judge_Empty(LQueue *Q)
{
    int i=IsEmptyLQueue(Q);
    if(i)    printf("�նӣ�\n");
    else        printf("���ǿնӣ�\n");
}
