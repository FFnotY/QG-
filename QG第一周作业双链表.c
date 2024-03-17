#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct DNode{
	int data;
	struct DNode *prior,*next;
}DNode,DLinkList;

//初始化双链表
bool InitDlinklist(DLinkList *L)
{
    L=(DNode*)malloc(sizeof(DNode));       //分配一个头节点
    if (L==NULL){
    	return false;
	}
    L->prior=NULL;                           
    L->next=NULL;
	return true;    
                            
    
} 

 //尾插法建立单链表（指针） 
bool List_Taillnsert(DLinkList *L) {
	int x;
	DLinkList *a=(DNode*)malloc(sizeof(DNode));                     //建立头节点 
	if (a==NULL){
		return false;
	}
	DNode *s, *r=a;                                    //定义r为表尾指针
	scanf("%d",&x);                                    //输入节点的值  

	s=(DNode*)malloc(sizeof(DNode));
	s->data=x;
	r->next=s;
	r=s; 
    r->next=NULL;
    return L;
}

//双链表的插入 
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

//双链表的查询（按位查询）
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

//删除节点
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

	 
	if(p==NULL) {                                 //当要删除节点的前置节点为空时 
		return false;
	}
	DNode *q=p->next;                             //让q指向被删除的节点 
	                                    
	p->next=q->next;                              //将q所指的要删除的节点断开
	free(q) ;
	return true;
} 

//显示链表
void displayLinkedList(DLinkList* L) {
    DNode* current = L;
    printf("L: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}    


//删除p节点的后继节点
bool DeleteNextDnode(DNode*p)
{
	if(p==NULL) return false;
	DNode*q = p->next;//找到p的后继节点
	if(q==NULL) return false;//q没有后继
	p->next=q->next;
	if(q->next!=NULL)//q节点不是最后一个节点
		q->next->prior=p;
	free(q);//释放空间
	return true;
}
//销毁一个双链表
void DestoryList(DLinkList *L)
{
    while(L->next!=NULL)
        DeleteNextDnode(L);
    free(L);
    L=NULL;
}

int main()
{
	DLinkList L;                                     //声明一个指向单链表头节点的指针 
	InitDlinklist(&L);                                   //初始化这个单链表为空表 
	int a;
	do{
	printf("************************\n");
	printf("[1]初始化一个列表\n");
	printf("[2]插入新的节点\n");
	printf("[3]查询链表\n");
	printf("[4]删除链表\n");
	printf("[5]输出链表\n");
	printf("[6]退出系统"); 
	printf("************************\n");
	printf("\n");
	printf("请输入对应的数字（1~6）\n");
	int  b1;
	scanf("%d",&a);
	switch (a) {
		case (1):
			printf("想创建几个节点\n");
			scanf("%d",&b1);
			InitDlinklist(&L);
			int i;
			for(i=1;i<=b1;i++) {
				printf("请输入第%d个节点的数据(不超过9999)",i);
				List_Taillnsert( &L);
			}
				break;
		case (2):
		    printf("在第几个位置之前插入节点");
		    int cha;
		    int *b;
		    scanf("%d",&cha); 
		    printf("插入的数据是");
		    int newcha;
		    int *c;
			scanf("%d",&newcha) ;
			InsertNextDnode(&b,&c);
			printf("插入成功\n");
			break;
		case (3):
		    printf("你要查询第几个数据(按位查找)");
		    int shan;
			scanf("%d",&shan);
			printf("第%d个数据是%d",shan,GetElem( &L, shan));	
			break;
		case (4):
		    printf("删除第几个节点");
			int cut,e1;
			int *num=&e1;
			scanf("%d",&cut);
			Nodedelete( &L, cut);
			printf("删除的数据是%d",e1);
			break;
		case (5):
			displayLinkedList( &L);
		    break;	
		case (6):
			DestoryList(&L);
		    printf("退出成功");  				
			}
	} while(a!=6);
		
	return 0;
 } 
