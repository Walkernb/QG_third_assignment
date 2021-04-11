#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXQUEUE 10
char type;
char datatype[MAXQUEUE];
typedef struct Aqueue
{
    void *data[MAXQUEUE];      //������
    int front;
    int rear;
    size_t length;        //���г���
} AQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
Status IsFullAQueue(const AQueue *Q)    //�ж϶��Ƿ���
{
    if(Q->length==MAXQUEUE) {printf("������\n");return TRUE;}
    return FALSE;
}
Status IsEmptyAQueue(const AQueue *Q)       //�ж϶��Ƿ�Ϊ��
{
    if(Q->length==0)    {printf("�ӿգ�\n");   return TRUE;}
    return FALSE;
}
void InitAQueue(AQueue *Q)  //��ʼ����
{
    Q->front=-1;
    Q->rear=-1;
    Q->length=0;
}
void DestoryAQueue(AQueue *Q)   //���ٶ�
{
    int n=IsEmptyAQueue(Q);
    if(!n)
    {
        for(int i=0;i<10;i++)  { Q->data[i]=NULL;}
        Q->front=Q->rear=-1;
        Q->length=0;
        printf("���ѱ����٣�\n");
    }
}

Status GetHeadAQueue(AQueue *Q, void *e)
{
    int i=IsEmptyAQueue(Q);
    if(!i)
    {
        e=Q->data[Q->front];
        printf("ͷ�ڵ㣺");
        APrint(Q->data[Q->front],Q->front);
        printf("\n����Ҫ���� ȷ�ϼ���\n");
        getchar(); getchar();
        return TRUE;
    }
    return FALSE;
}
int LengthAQueue(AQueue *Q)
{
    printf("�ӵĳ���Ϊ��%d\n",Q->length);
    printf("����Ҫ���� ȷ�ϼ���\n");
        getchar(); getchar();
    return Q->length;
}

Status DeAQueue(AQueue *Q)
{
    int i=IsEmptyAQueue(Q);
    if(!i)
    {
        printf("�������ݣ�");
        APrint(Q->data[Q->front],Q->front);
        Q->front++;
        Q->length--;
        printf("\n����Ҫ���� ȷ�ϼ���\n");
        getchar(); getchar();
        return TRUE;
    }
    return FALSE;
}
void ClearAQueue(AQueue *Q)
{
    int i=IsEmptyAQueue(Q);
    if(!i)
    {
        Q->front=Q->length=-1;
        Q->length=0;
        printf("��ճɹ���\n");
    }
}
void APrint(void *q,int i)
{
    switch(datatype[i])
    {
        case 'i':printf("%d",*(int *)q);break;
        case 'd':printf("%lf",*(double *)q);break;
        case 's':printf("%s",(char *)q);break;
    }
}
Status TraverseAQueue(const AQueue *Q)
{
    int k=IsEmptyAQueue(Q);
    if(!k)
    {
        int i=Q->front;
        int j=Q->rear;
        APrint(Q->data[i],i);
        for(i++;i!=((j+1)%10);i++,i%=10)
        {
            printf("->");
            APrint(Q->data[i],i);
        }
        printf("\n����Ҫ���� ȷ�ϼ���\n");
        getchar(); getchar();
    }
    return FALSE;
}
extern void    InsertQueue(AQueue *Q);  //���
extern  void InterFace();
int main()
{
    void *e;
    AQueue *Q=(AQueue *)malloc(sizeof(AQueue));
    InitAQueue(Q);
    char s[20];
    int n,p=1;
    while(p)
    {
        InterFace();
        scanf("%s",s);
        if(strlen(s)>1) printf("��������\n");
        else
        {
            n=s[0]-'0';
            switch(n)
            {
                case    1:DestoryAQueue(Q);break;
                case    2:GetHeadAQueue(Q,e);break;
                case    3:LengthAQueue(Q);break;
                case    4:InsertQueue(Q);break;
                case    5:DeAQueue(Q);break;
                case    6:TraverseAQueue(Q);break;
                case    7:ClearAQueue(Q);break;
                case    0:p=0;break;
                default:printf("��������\n");
            }
        }
    }
    return 0;
}
