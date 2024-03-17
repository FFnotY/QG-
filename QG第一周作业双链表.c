#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct DNode{
	int data;
	struct DNode *prior,*next;
}DNode,DLinkList;

//��ʼ��˫����
bool InitDlinklist(DLinkList *L)
{
    L=(DNode*)malloc(sizeof(DNode));       //����һ��ͷ�ڵ�
    if (L==NULL){
    	return false;
	}
    L->prior=NULL;                           
    L->next=NULL;
	return true;    
                            
    
} 

 //β�巨����������ָ�룩 
bool List_Taillnsert(DLinkList *L) {
	int x;
	DLinkList *a=(DNode*)malloc(sizeof(DNode));                     //����ͷ�ڵ� 
	if (a==NULL){
		return false;
	}
	DNode *s, *r=a;                                    //����rΪ��βָ��
	scanf("%d",&x);                                    //����ڵ��ֵ  

	s=(DNode*)malloc(sizeof(DNode));
	s->data=x;
	r->next=s;
	r=s; 
    r->next=NULL;
    return L;
}

//˫����Ĳ��� 
bool InsertNextDnode(DNode*p,DNode*s)
{
	if(p==NULL||s==NULL)
		return false;
		s->next=p->next;
		if(p->next!=NULL)
			p->next->prior=s;
		s->prior = p;
		p->next = s;
		return true;
}

//˫����Ĳ�ѯ����λ��ѯ��
DNode *GetElem(DLinkList *L, int i){
	if (i<0){
		return NULL;
	}
	DNode *p;
	int j=0;
	p=L;
	while(p!=NULL && j<=i){
		p=p->next;
		j++;
	}
	return p;
} 

//ɾ���ڵ�
bool  Nodedelete(DLinkList *L, int i){
	if(i<1){                                       
		return false;
	}
	int j;
	DNode *p;
	p=L;                                            
	j=0;                                            
	while(p!=NULL && j<i-1){                        
		p=p->next;                                  
		j++;
	}	

	 
	if(p==NULL) {                                 //��Ҫɾ���ڵ��ǰ�ýڵ�Ϊ��ʱ 
		return false;
	}
	DNode *q=p->next;                             //��qָ��ɾ���Ľڵ� 
	                                    
	p->next=q->next;                              //��q��ָ��Ҫɾ���Ľڵ�Ͽ�
	free(q) ;
	return true;
} 

//��ʾ����
void displayLinkedList(DLinkList* L) {
    DNode* current = L;
    printf("L: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}    


//ɾ��p�ڵ�ĺ�̽ڵ�
bool DeleteNextDnode(DNode*p)
{
	if(p==NULL) return false;
	DNode*q = p->next;//�ҵ�p�ĺ�̽ڵ�
	if(q==NULL) return false;//qû�к��
	p->next=q->next;
	if(q->next!=NULL)//q�ڵ㲻�����һ���ڵ�
		q->next->prior=p;
	free(q);//�ͷſռ�
	return true;
}
//����һ��˫����
void DestoryList(DLinkList *L)
{
    while(L->next!=NULL)
        DeleteNextDnode(L);
    free(L);
    L=NULL;
}

int main()
{
	DLinkList L;                                     //����һ��ָ������ͷ�ڵ��ָ�� 
	InitDlinklist(&L);                                   //��ʼ�����������Ϊ�ձ� 
	int a;
	do{
	printf("************************\n");
	printf("[1]��ʼ��һ���б�\n");
	printf("[2]�����µĽڵ�\n");
	printf("[3]��ѯ����\n");
	printf("[4]ɾ������\n");
	printf("[5]�������\n");
	printf("[6]�˳�ϵͳ"); 
	printf("************************\n");
	printf("\n");
	printf("�������Ӧ�����֣�1~6��\n");
	int  b1;
	scanf("%d",&a);
	switch (a) {
		case (1):
			printf("�봴�������ڵ�\n");
			scanf("%d",&b1);
			InitDlinklist(&L);
			int i;
			for(i=1;i<=b1;i++) {
				printf("�������%d���ڵ������(������9999)",i);
				List_Taillnsert( &L);
			}
				break;
		case (2):
		    printf("�ڵڼ���λ��֮ǰ����ڵ�");
		    int cha;
		    int *b;
		    scanf("%d",&cha); 
		    printf("�����������");
		    int newcha;
		    int *c;
			scanf("%d",&newcha) ;
			InsertNextDnode(&b,&c);
			printf("����ɹ�\n");
			break;
		case (3):
		    printf("��Ҫ��ѯ�ڼ�������(��λ����)");
		    int shan;
			scanf("%d",&shan);
			printf("��%d��������%d",shan,GetElem( &L, shan));	
			break;
		case (4):
		    printf("ɾ���ڼ����ڵ�");
			int cut,e1;
			int *num=&e1;
			scanf("%d",&cut);
			Nodedelete( &L, cut);
			printf("ɾ����������%d",e1);
			break;
		case (5):
			displayLinkedList( &L);
		    break;	
		case (6):
			DestoryList(&L);
		    printf("�˳��ɹ�");  				
			}
	} while(a!=6);
		
	return 0;
 } 
