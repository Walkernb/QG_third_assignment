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
    int i;                  //记录头节点的位置
    int j;                  //记录尾节点的位置
    int length;            //队列长度
}  LQueue;
typedef enum
{
    FALSE=0, TRUE=1
} Status;
extern char type;
extern char datatype[30];

Status EnLQueue(LQueue *Q, void *data)    //插入节点
{
    Node *p=(Node *)malloc(sizeof(Node));
    p->data=data;
    p->next=NULL;
    if(Q->length==0)    {Q->rear=Q->front=p;Q->length++; Q->i=1;}
    else
        {Q->rear->next=p;
        Q->rear=p;
        Q->length++;}
    Q->j++;
    return TRUE;
}

void Insert_Queue(LQueue *Q)
{
    void *data=malloc(50);
    double *d=(double *)malloc(sizeof(double));
    int     *i=(int *)malloc(sizeof(int));
    printf("1       输入整型数据\n");
    printf("2       输入小数数据\n");
    printf("3       输入字符数据\n");
    printf("请输入你的选择：");
    char s[20];
    int n;
    scanf("%s",s);
    if(strlen(s)>1) {printf("输入有误！\n"); return ;}
    n=s[0]-'0';
    printf("请输入数据：");
    switch(n)
    {
        case 1:scanf("%d",i);break;
        case 2:scanf("%lf",d);break;
        case 3:scanf("%s",data);break;
        default:printf("输入有误！\n");
    }
    if(n==1)    {data=i;    datatype[Q->j+1]='i';   n=EnLQueue(Q,data);if(n)   printf("入队成功！\n");}
    else    if(n==2)    {data=d;    datatype[Q->j+1]='d'; n=EnLQueue(Q,data); if(n)   printf("入队成功！\n");}
    else    if(n==3)    {datatype[Q->j+1]='s';n=EnLQueue(Q,data); if(n)   printf("入队成功！\n");}
}
