#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode{
	int data;                                  //节点存放的数据元素 
	struct LNode *next;                             //指向下一个节点的指针 
}LNode,LinkList;


//初始化一个单链表(带头结点) 
bool InitList(LinkList *L){
     L=(LNode*)malloc(sizeof(LNode));               //分配给头指针L一片空间作为头节点 
	if (L==NULL){                                  //判断头指针是否为空 
		return false;
	}
    L->next = NULL;                              //头节点之后暂时没有节点
	    return true; 
}

//插入新的节点(后插)
bool ListInsert(LinkList *L, int i, int e){
	if(i<1){                                        //判断i值是否合法 
		return false;
	}
	int j;
	LNode *p;
	p=L;                                            //p一开始指向头节点也就是第0个节点 
	j=0;                                            //用j来表示p当前指向的节点 
	while(p!=NULL && j<i-1){                        //寻找要插入的节点i的前一个节点 
		p=p->next;                                  //让p指针指向下一个节点 
		j++;
	}
	if (p==NULL){                                   //当要插入的节点超过了链表的范围，p 
		return false;                               //会指向空，即p==NULL 
	}
	LNode *s=(LNode*)malloc(sizeof(LNode));
	s->data =e;
	s->next =p->next;
	p->next =s;
	
} 
//删除节点
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

	 
	if(p==NULL) {                                 //当要删除节点的前置节点为空时 
		return false;
	}
	LNode *q=p->next;                             //让q指向被删除的节点 
	                                    
	p->next=q->next;                              //将q所指的要删除的节点断开
	free(q) ;
	return true;
} 

//查找链表
//按位查找
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


 
 //尾插法建立单链表（指针） 
bool List_Taillnsert(LinkList *L) {
	int x;
	LinkList *a=(LNode*)malloc(sizeof(LNode));                     //建立头节点 
	if (a==NULL){
		return false;
	}
	LNode *s, *r=a;                                    //定义r为表尾指针
	scanf("%d",&x);                                    //输入节点的值  

	s=(LNode*)malloc(sizeof(LNode));
	s->data=x;
	r->next=s;
	r=s; 
    r->next=NULL;
    return L;
}
//单链表的后删
bool DeleteNextNode(LNode *p)
{
	if(p==NULL) return false;
	LNode*q = p->next;               //找到p的后继节点
	if(q==NULL) return false;       //q没有后继
	p->next=q->next;
	free(q);                        //释放空间
	return true;
}
    
//显示链表
void displayLinkedList(LinkList* L) {
    LNode* current = L;
    printf("L: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}    

//链表的销毁 
void DestoryList(LinkList *L){
	while(L->next!=NULL){
		DeleteNextNode(&L); 
		free(L);
		L=NULL;
	}
}	

 
 
int main()
{
	LinkList L;                                     //声明一个指向单链表头节点的指针 
	InitList(&L);                                   //初始化这个单链表为空表 
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
			InitList(&L);
			int i;
			for(i=1;i<=b1;i++) {
				printf("请输入第%d个节点的数据(不超过9999)",i);
				List_Taillnsert( &L);
			}
				break;
		case (2):
		    printf("在第几个位置之前插入节点");
		    int cha;
		    scanf("%d",&cha); 
		    printf("插入的数据是");
		    int newcha;
			scanf("%d",&newcha) ;
			ListInsert(&L, cha, newcha);
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
