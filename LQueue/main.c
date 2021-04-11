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
char type;
char datatype[30];

extern int IsEmptyLQueue( LQueue *Q);       //判断队是否为空
extern void Judge_Empty(LQueue *Q);
extern LQueue *Insert_Queue(LQueue *Q);
extern void Inter_Face();

void LPrint(void *q,int i)
{
    switch(datatype[i])
    {
        case    'i':printf("%d",*(int *)q);break;
        case    'd':printf("%lf",*(double *)q);break;
        case    's':printf("%s",(char *)q);break;
    }
}

LQueue *InitLQueue(LQueue *Q)          //初始化队
{
    Q->front=NULL;
    Q->rear=NULL;
    Q->i=Q->j=0;
    Q->length=0;
    return Q;
}

void DestoryLQueue(LQueue *Q)       //销毁队
{
    int i=IsEmptyLQueue(Q);
    if(i)    {printf("空队！\n");return ;}
    Node *p=Q->front;
    Q->front=Q->front->next;
    if(Q->front==NULL) free(p);
    while(Q->front!=NULL)
    {
        free(p);
        p=Q->front;
        Q->front=Q->front->next;
    }
    Q->rear=Q->front;
    Q->length=0;
    Q->i=Q->j=0;
    printf("队已被销毁！\n");
}

Status GetHeadLQueue(LQueue *Q,LQueue *e)     //返回头节点
{
    int i=IsEmptyLQueue(Q);
    if(!i)
        {
            printf("头节点：");
            e=Q->front;
            LPrint(Q->front->data,Q->i);
            getchar();
            printf("\n（需要再次按下 确认键 ）");
            getchar();
            return TRUE;
        }
    else        printf("队为空！\n");
    return FALSE;
}
int LengthLQueue(LQueue *Q)                 //返回队的长度
{
    printf("队的长度：%d\n",Q->length);
    getchar();
    printf("（需要再次按下 确认键 ）");
    getchar();
    return  Q->length;
}

Status DeLQueue(LQueue *Q)                //出队
{
    int i=IsEmptyLQueue(Q);
    if(i)    {printf("空队！\n");   return FALSE;}
    printf("出队数据：");
    LPrint(Q->front->data,Q->i);
    Q->i++;
    Q->front=Q->front->next;
    Q->length--;
    getchar();
    printf("（需要再次按下 确认键 ）");
    getchar();
    return TRUE;
}
void ClearLQueue(LQueue *Q)             //清空队
{
    int i=IsEmptyLQueue(Q);
    if(i)    {printf("空队！\n");   return ;}
    Q->front=NULL;
    Q->rear=NULL;
    Q->length=0;
    Q->i=Q->j=0;
    printf("队已被清空！\n");
}
Status TraverseLQueue(LQueue *Q)
{
    int i=IsEmptyLQueue(Q);
    if(i)    {printf("空队！\n"); return FALSE;}
    Node *p=Q->front;
    i=Q->i;
    LPrint(p->data,i);
    i++;
    p=p->next;
    while(p!=NULL)
    {
        printf("->");
        LPrint(p->data,i);
        i++;
        p=p->next;
    }
    printf("\n");
    getchar();
    printf("（需要再次按下 确认键 ）");
    getchar();
    return TRUE;
}


int main()
{
    LQueue *Q=(LQueue *)malloc(sizeof(LQueue));
    Q=InitLQueue(Q);
    int n,p=1;
    char s[30];
    while(p){
            Inter_Face();
            LQueue *e;
            scanf("%s",s);
            if(strlen(s)>1) printf("输入有误！\n");
            else{
                    n=s[0]-'0';
                    if(n>9)     printf("输入有误！\n");
                    else
                    {
                         switch(n)
                        {
                            case 1:DestoryLQueue(Q);break;
                            case 2:Judge_Empty(Q);break;
                            case 3:GetHeadLQueue(Q,e);break;
                            case 4:LengthLQueue(Q);break;
                            case 5:Insert_Queue(Q);break;
                            case 6:DeLQueue(Q);break;
                            case 7:ClearLQueue(Q);break;
                            case 8:TraverseLQueue(Q);break;
                            case 0:p=0;break;
                            default:printf("输入有误！\n");
                        }
                    }
            }
    }
    getchar();
    getchar();
    return 0;
}
