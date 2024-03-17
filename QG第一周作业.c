#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode{
	int data;                                  //�ڵ��ŵ�����Ԫ�� 
	struct LNode *next;                             //ָ����һ���ڵ��ָ�� 
}LNode,LinkList;


//��ʼ��һ��������(��ͷ���) 
bool InitList(LinkList *L){
     L=(LNode*)malloc(sizeof(LNode));               //�����ͷָ��LһƬ�ռ���Ϊͷ�ڵ� 
	if (L==NULL){                                  //�ж�ͷָ���Ƿ�Ϊ�� 
		return false;
	}
    L->next = NULL;                              //ͷ�ڵ�֮����ʱû�нڵ�
	    return true; 
}

//�����µĽڵ�(���)
bool ListInsert(LinkList *L, int i, int e){
	if(i<1){                                        //�ж�iֵ�Ƿ�Ϸ� 
		return false;
	}
	int j;
	LNode *p;
	p=L;                                            //pһ��ʼָ��ͷ�ڵ�Ҳ���ǵ�0���ڵ� 
	j=0;                                            //��j����ʾp��ǰָ��Ľڵ� 
	while(p!=NULL && j<i-1){                        //Ѱ��Ҫ����Ľڵ�i��ǰһ���ڵ� 
		p=p->next;                                  //��pָ��ָ����һ���ڵ� 
		j++;
	}
	if (p==NULL){                                   //��Ҫ����Ľڵ㳬��������ķ�Χ��p 
		return false;                               //��ָ��գ���p==NULL 
	}
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s->data =e;
	s->next =p->next;
	p->next =s;
	
} 
//ɾ���ڵ�
bool  Nodedelete(LinkList *L, int i){
	if(i<1){                                       
		return false;
	}
	int j;
	LNode *p;
	p=L;                                            
	j=0;                                            
	while(p!=NULL && j<i-1){                        
		p=p->next;                                  
		j++;
	}	

	 
	if(p==NULL) {                                 //��Ҫɾ���ڵ��ǰ�ýڵ�Ϊ��ʱ 
		return false;
	}
	LNode *q=p->next;                             //��qָ��ɾ���Ľڵ� 
	                                    
	p->next=q->next;                              //��q��ָ��Ҫɾ���Ľڵ�Ͽ�
	free(q) ;
	return true;
} 

//��������
//��λ����
LNode *GetElem(LinkList *L, int i){
	if (i<0){
		return NULL;
	}
	LNode *p;
	int j=0;
	p=L;
	while(p!=NULL && j<=i){
		p=p->next;
		j++;
	}
	return p;
} 


 
 //β�巨����������ָ�룩 
bool List_Taillnsert(LinkList *L) {
	int x;
	LinkList *a=(LNode*)malloc(sizeof(LNode));                     //����ͷ�ڵ� 
	if (a==NULL){
		return false;
	}
	LNode *s, *r=a;                                    //����rΪ��βָ��
	scanf("%d",&x);                                    //����ڵ��ֵ  

	s=(LNode*)malloc(sizeof(LNode));
	s->data=x;
	r->next=s;
	r=s; 
    r->next=NULL;
    return L;
}
//������ĺ�ɾ
bool DeleteNextNode(LNode *p)
{
	if(p==NULL) return false;
	LNode*q = p->next;               //�ҵ�p�ĺ�̽ڵ�
	if(q==NULL) return false;       //qû�к��
	p->next=q->next;
	free(q);                        //�ͷſռ�
	return true;
}
    
//��ʾ����
void displayLinkedList(LinkList* L) {
    LNode* current = L;
    printf("L: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}    

//��������� 
void DestoryList(LinkList *L){
	while(L->next!=NULL){
		DeleteNextNode(&L); 
		free(L);
		L=NULL;
	}
}	

 
 
int main()
{
	LinkList L;                                     //����һ��ָ������ͷ�ڵ��ָ�� 
	InitList(&L);                                   //��ʼ�����������Ϊ�ձ� 
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
			InitList(&L);
			int i;
			for(i=1;i<=b1;i++) {
				printf("�������%d���ڵ������(������9999)",i);
				List_Taillnsert( &L);
			}
				break;
		case (2):
		    printf("�ڵڼ���λ��֮ǰ����ڵ�");
		    int cha;
		    scanf("%d",&cha); 
		    printf("�����������");
		    int newcha;
			scanf("%d",&newcha) ;
			ListInsert(&L, cha, newcha);
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
