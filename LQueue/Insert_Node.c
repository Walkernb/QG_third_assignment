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
extern char type;
extern char datatype[30];

Status EnLQueue(LQueue *Q, void *data)    //����ڵ�
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
    printf("1       ������������\n");
    printf("2       ����С������\n");
    printf("3       �����ַ�����\n");
    printf("���������ѡ��");
    char s[20];
    int n;
    scanf("%s",s);
    if(strlen(s)>1) {printf("��������\n"); return ;}
    n=s[0]-'0';
    printf("���������ݣ�");
    switch(n)
    {
        case 1:scanf("%d",i);break;
        case 2:scanf("%lf",d);break;
        case 3:scanf("%s",data);break;
        default:printf("��������\n");
    }
    if(n==1)    {data=i;    datatype[Q->j+1]='i';   n=EnLQueue(Q,data);if(n)   printf("��ӳɹ���\n");}
    else    if(n==2)    {data=d;    datatype[Q->j+1]='d'; n=EnLQueue(Q,data); if(n)   printf("��ӳɹ���\n");}
    else    if(n==3)    {datatype[Q->j+1]='s';n=EnLQueue(Q,data); if(n)   printf("��ӳɹ���\n");}
}
