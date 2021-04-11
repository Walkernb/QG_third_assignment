#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXQUEUE 10
extern char type;
extern char datatype[MAXQUEUE];
typedef struct Aqueue
{
    void *data[MAXQUEUE];      //数据域
    int front;
    int rear;
    size_t length;        //队列长度
} AQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;

Status EnAQueue(AQueue *Q, void *data)
{
    int i=IsFullAQueue(Q);
    if(!i)
    {
        if(Q->front==-1&&Q->rear==-1)
            Q->front=Q->rear=0;
        else    Q->rear=(Q->rear+1)%10;
        Q->data[Q->rear]=data;
        Q->length++;
        return TRUE;
    }
    return FALSE;
}

void    InsertQueue(AQueue *Q)
{
    int *i=(int *)malloc(sizeof(int));
    double *d=(double *)malloc(sizeof(double));
    void *data=malloc(50);
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
    if(n==1)    {data=i;    datatype[(Q->rear+1)%10]='i';n=EnAQueue(Q,data);if(n)   printf("入队成功！\n");}
    else    if(n==2)    {data=d;    datatype[(Q->rear+1)%10]='d';n=EnAQueue(Q,data);if(n)   printf("入队成功！\n");}
    else    if(n==3)    {datatype[(Q->rear+1)%10]='s';n=EnAQueue(Q,data);if(n)   printf("入队成功！\n");}
}
