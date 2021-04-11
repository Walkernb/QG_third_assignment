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
    int i;                  //��¼ͷ�ڵ��λ��
    int j;                  //��¼β�ڵ��λ��
    int length;            //���г���
}  LQueue;
typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;
char datatype[30];

extern int IsEmptyLQueue( LQueue *Q);       //�ж϶��Ƿ�Ϊ��
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

LQueue *InitLQueue(LQueue *Q)          //��ʼ����
{
    Q->front=NULL;
    Q->rear=NULL;
    Q->i=Q->j=0;
    Q->length=0;
    return Q;
}

void DestoryLQueue(LQueue *Q)       //���ٶ�
{
    int i=IsEmptyLQueue(Q);
    if(i)    {printf("�նӣ�\n");return ;}
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
    printf("���ѱ����٣�\n");
}

Status GetHeadLQueue(LQueue *Q,LQueue *e)     //����ͷ�ڵ�
{
    int i=IsEmptyLQueue(Q);
    if(!i)
        {
            printf("ͷ�ڵ㣺");
            e=Q->front;
            LPrint(Q->front->data,Q->i);
            getchar();
            printf("\n����Ҫ�ٴΰ��� ȷ�ϼ� ��");
            getchar();
            return TRUE;
        }
    else        printf("��Ϊ�գ�\n");
    return FALSE;
}
int LengthLQueue(LQueue *Q)                 //���ضӵĳ���
{
    printf("�ӵĳ��ȣ�%d\n",Q->length);
    getchar();
    printf("����Ҫ�ٴΰ��� ȷ�ϼ� ��");
    getchar();
    return  Q->length;
}

Status DeLQueue(LQueue *Q)                //����
{
    int i=IsEmptyLQueue(Q);
    if(i)    {printf("�նӣ�\n");   return FALSE;}
    printf("�������ݣ�");
    LPrint(Q->front->data,Q->i);
    Q->i++;
    Q->front=Q->front->next;
    Q->length--;
    getchar();
    printf("����Ҫ�ٴΰ��� ȷ�ϼ� ��");
    getchar();
    return TRUE;
}
void ClearLQueue(LQueue *Q)             //��ն�
{
    int i=IsEmptyLQueue(Q);
    if(i)    {printf("�նӣ�\n");   return ;}
    Q->front=NULL;
    Q->rear=NULL;
    Q->length=0;
    Q->i=Q->j=0;
    printf("���ѱ���գ�\n");
}
Status TraverseLQueue(LQueue *Q)
{
    int i=IsEmptyLQueue(Q);
    if(i)    {printf("�նӣ�\n"); return FALSE;}
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
    printf("����Ҫ�ٴΰ��� ȷ�ϼ� ��");
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
            if(strlen(s)>1) printf("��������\n");
            else{
                    n=s[0]-'0';
                    if(n>9)     printf("��������\n");
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
                            default:printf("��������\n");
                        }
                    }
            }
    }
    getchar();
    getchar();
    return 0;
}
