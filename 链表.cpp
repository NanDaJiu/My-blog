#include<stdio.h>
#include<malloc.h>
# include <stdlib.h>
typedef struct Student{
	int num;//学生学号 
	int java;//学生Java成绩 
	struct Student* next;
}* Stu;

//1.创建链表 
Stu creatList(){//用返回头节点的方式 
    int n;
    Stu pHead=(Stu)malloc(sizeof(struct Student));//创建一个头指针指向头节点 
    pHead->next=NULL;//让头节点指针域为空 
    Stu pTail;//创建一个尾指针，用尾插法创建链表
	pTail=pHead;//尾指针也指向头节点 
	 
	if(pHead==NULL){//判断头指针指向的是否为空，如果为空程序结束 
		printf("内存为空，结束程序");
		exit(-1);
	}
	//创建链表 
	printf("请输入要创建的节点个数\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		Stu pNew=(Stu)malloc(sizeof(struct Student));//创建一个新节点
		printf("请输入第%d个学生的学号\n",i+1);
		scanf("%d",&pNew->num);
		printf("请为第%d个学生输入java成绩\n",i+1);
		scanf("%d",&pNew->java);
		pTail->next=pNew;//刚开始是让头节点指向第一个节点(后面让前一个节点指向下一个节点)
		pNew->next=NULL;//让尾节点指向为空，为什么要这样我也不懂
		pTail=pNew;//让尾指针指向最后一个节点 
		
	}
	return pHead;
	
}

//2.遍历链表
void traverse(Stu pHead){
	Stu p;
	p=pHead->next;//让指针P指向第一个节点 
	while(p!=NULL){//如果p指针不为空就可以遍历所有 
		printf("学号为%d的学生java成绩为%d分\n",p->num,p->java);
		p=p->next;
	}
	
}


//3.查找学号为某个数的学生的Java成绩
//void seekJava(Stu pHead,int IDnum){
//	int i=0;
//	Stu p;
//	p=pHead->next;//让指针指向第一个节点 
//	while(p!=NULL){
//		if(p->num==IDnum){
//			printf("学号为%d的学生java成绩为%d",p->num,p->java);
//			i=1;
//			break;
//		}
//		else{
//			p=p->next;
//		}
//	}
//	if(i==0){
//		printf("没有找到该学生\n");
//	}
//	
//} 


//4.将节点插入链表中，只用一个辅助指针就行 
//思路，当p指针指到i-1个节点时，插入新节点 ,要思考插入第一个和最后一个的情况 
//讲一下count,将count初始化为1，如果i=1就可以直接插入，如果i等于最后一个的节点数MAXi,p指针只要移动到i-1个节点就行 
void inset(Stu pHead,int i,int num,int java){
	int j=1;//判断插入成功没有，如果j=1,就表示插入成功，等于0就是表示插入失败 
	Stu p;//用p指向头节点，万一i=1时就可以 直接插到第一个 
	int count=1;//用来计数，P移动一次加一,用来给P指针指路
	p=pHead;//指向头节点 
	while(p!=NULL&&count<i){//先将指针移到i-1位上
		p=p->next;
		count++;
	}
	if(p==NULL){
		j=0;
	}
	else{
		Stu pNew=(Stu)malloc(sizeof(struct Student));//创建一个新节点
		pNew->java=java;
		pNew->num=num;
		pNew->next=p->next;//为什么这一行先执行呢，如果先将p-next插到pNew里的话，p->next就找不到了
		p->next=pNew; 
		printf("插入成功\n");
		j++;
		
	}
	if(j==0){
		printf("插入失败,请检查i是否正确\n");
	}

//失败的思路	 
//	while(p!=NULL&&count<i){//注意这里，防止越界 
//		if(count==i){
//			Stu pNew=(Stu)malloc(sizeof(struct Student));//创建一个新节点
//			pNew->java=java;
//			pNew->num=num;
//			pNew->next=p->next;//为什么这一行先执行呢，如果先将p-next插到pNew里的话，p->next就找不到了
//			p->next=pNew; 
//			printf("插入成功");
//			j++;
//			break;
//		}
//		else{
//			count++;
//			p=p->next;
//		}
//	}
//	if(j=0){
//		printf("插入失败,请检查i是否正确");
//	} 
	
}
//要删除学号为num的学生的节点 
void deleteNode(Stu pHead,int num){
	int i=0;
	Stu q,p;//创建两个指针q为前指针，p为后指针 
	q=pHead;//让前指针指向头节点，后指针指向第一个节点 
	p=q->next;
	while(p!=NULL){
		if(p->num==num){
			q->next=p->next;//让前指针指向要删除的节点的后一个节点 
			free(p);//把p节点清掉 
			p=q->next;//让p节点指向q指针指向的节点的下一个节点，保持一前一后 
			i++;
			break;
		}
		else{//如果找不到，指针后移 
			p=p->next;
			q=q->next;
		}
	}
	if(i==1){
	    printf("删除成功\n");
	}
	else{
		printf("删除失败，没有找到相关学号\n");
	}
	
	
} 
int main(){
	int IDnum;
	int java;
	int i;//表示要插入的节点，如果是i，表示插入的新节点排序号为i,原来的 i号变成i+1号节点 
	Stu pHead,pTail;
	pHead=creatList();
	
//	traverse(pHead);

//	printf("请输入要查找的学生的学号\n");
//	scanf("%d",&IDnum);
//	seekJava(pHead,i,IDnum,java);

//	printf("请问要将该节点排到第几位\n");
//	scanf("%d",&i);
//	printf("请输入该学生的学号\n");
//	scanf("%d",&IDnum);
//	printf("请输入该学生的Java成绩\n");
//	scanf("%d",&java);
//	inset(pHead,i,IDnum,java);
//	traverse(pHead);

    printf("请输入你要删除的学生的学号\n");
    scanf("%d",&IDnum);
    deleteNode(pHead,IDnum);
    traverse(pHead);

}
