#include<stdio.h>
#include<malloc.h>
# include <stdlib.h>
typedef struct Student{
	int num;//ѧ��ѧ�� 
	int java;//ѧ��Java�ɼ� 
	struct Student* next;
}* Stu;

//1.�������� 
Stu creatList(){//�÷���ͷ�ڵ�ķ�ʽ 
    int n;
    Stu pHead=(Stu)malloc(sizeof(struct Student));//����һ��ͷָ��ָ��ͷ�ڵ� 
    pHead->next=NULL;//��ͷ�ڵ�ָ����Ϊ�� 
    Stu pTail;//����һ��βָ�룬��β�巨��������
	pTail=pHead;//βָ��Ҳָ��ͷ�ڵ� 
	 
	if(pHead==NULL){//�ж�ͷָ��ָ����Ƿ�Ϊ�գ����Ϊ�ճ������ 
		printf("�ڴ�Ϊ�գ���������");
		exit(-1);
	}
	//�������� 
	printf("������Ҫ�����Ľڵ����\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		Stu pNew=(Stu)malloc(sizeof(struct Student));//����һ���½ڵ�
		printf("�������%d��ѧ����ѧ��\n",i+1);
		scanf("%d",&pNew->num);
		printf("��Ϊ��%d��ѧ������java�ɼ�\n",i+1);
		scanf("%d",&pNew->java);
		pTail->next=pNew;//�տ�ʼ����ͷ�ڵ�ָ���һ���ڵ�(������ǰһ���ڵ�ָ����һ���ڵ�)
		pNew->next=NULL;//��β�ڵ�ָ��Ϊ�գ�ΪʲôҪ������Ҳ����
		pTail=pNew;//��βָ��ָ�����һ���ڵ� 
		
	}
	return pHead;
	
}

//2.��������
void traverse(Stu pHead){
	Stu p;
	p=pHead->next;//��ָ��Pָ���һ���ڵ� 
	while(p!=NULL){//���pָ�벻Ϊ�վͿ��Ա������� 
		printf("ѧ��Ϊ%d��ѧ��java�ɼ�Ϊ%d��\n",p->num,p->java);
		p=p->next;
	}
	
}


//3.����ѧ��Ϊĳ������ѧ����Java�ɼ�
//void seekJava(Stu pHead,int IDnum){
//	int i=0;
//	Stu p;
//	p=pHead->next;//��ָ��ָ���һ���ڵ� 
//	while(p!=NULL){
//		if(p->num==IDnum){
//			printf("ѧ��Ϊ%d��ѧ��java�ɼ�Ϊ%d",p->num,p->java);
//			i=1;
//			break;
//		}
//		else{
//			p=p->next;
//		}
//	}
//	if(i==0){
//		printf("û���ҵ���ѧ��\n");
//	}
//	
//} 


//4.���ڵ���������У�ֻ��һ������ָ����� 
//˼·����pָ��ָ��i-1���ڵ�ʱ�������½ڵ� ,Ҫ˼�������һ�������һ������� 
//��һ��count,��count��ʼ��Ϊ1�����i=1�Ϳ���ֱ�Ӳ��룬���i�������һ���Ľڵ���MAXi,pָ��ֻҪ�ƶ���i-1���ڵ���� 
void inset(Stu pHead,int i,int num,int java){
	int j=1;//�жϲ���ɹ�û�У����j=1,�ͱ�ʾ����ɹ�������0���Ǳ�ʾ����ʧ�� 
	Stu p;//��pָ��ͷ�ڵ㣬��һi=1ʱ�Ϳ��� ֱ�Ӳ嵽��һ�� 
	int count=1;//����������P�ƶ�һ�μ�һ,������Pָ��ָ·
	p=pHead;//ָ��ͷ�ڵ� 
	while(p!=NULL&&count<i){//�Ƚ�ָ���Ƶ�i-1λ��
		p=p->next;
		count++;
	}
	if(p==NULL){
		j=0;
	}
	else{
		Stu pNew=(Stu)malloc(sizeof(struct Student));//����һ���½ڵ�
		pNew->java=java;
		pNew->num=num;
		pNew->next=p->next;//Ϊʲô��һ����ִ���أ�����Ƚ�p-next�嵽pNew��Ļ���p->next���Ҳ�����
		p->next=pNew; 
		printf("����ɹ�\n");
		j++;
		
	}
	if(j==0){
		printf("����ʧ��,����i�Ƿ���ȷ\n");
	}

//ʧ�ܵ�˼·	 
//	while(p!=NULL&&count<i){//ע�������ֹԽ�� 
//		if(count==i){
//			Stu pNew=(Stu)malloc(sizeof(struct Student));//����һ���½ڵ�
//			pNew->java=java;
//			pNew->num=num;
//			pNew->next=p->next;//Ϊʲô��һ����ִ���أ�����Ƚ�p-next�嵽pNew��Ļ���p->next���Ҳ�����
//			p->next=pNew; 
//			printf("����ɹ�");
//			j++;
//			break;
//		}
//		else{
//			count++;
//			p=p->next;
//		}
//	}
//	if(j=0){
//		printf("����ʧ��,����i�Ƿ���ȷ");
//	} 
	
}
//Ҫɾ��ѧ��Ϊnum��ѧ���Ľڵ� 
void deleteNode(Stu pHead,int num){
	int i=0;
	Stu q,p;//��������ָ��qΪǰָ�룬pΪ��ָ�� 
	q=pHead;//��ǰָ��ָ��ͷ�ڵ㣬��ָ��ָ���һ���ڵ� 
	p=q->next;
	while(p!=NULL){
		if(p->num==num){
			q->next=p->next;//��ǰָ��ָ��Ҫɾ���Ľڵ�ĺ�һ���ڵ� 
			free(p);//��p�ڵ���� 
			p=q->next;//��p�ڵ�ָ��qָ��ָ��Ľڵ����һ���ڵ㣬����һǰһ�� 
			i++;
			break;
		}
		else{//����Ҳ�����ָ����� 
			p=p->next;
			q=q->next;
		}
	}
	if(i==1){
	    printf("ɾ���ɹ�\n");
	}
	else{
		printf("ɾ��ʧ�ܣ�û���ҵ����ѧ��\n");
	}
	
	
} 
int main(){
	int IDnum;
	int java;
	int i;//��ʾҪ����Ľڵ㣬�����i����ʾ������½ڵ������Ϊi,ԭ���� i�ű��i+1�Žڵ� 
	Stu pHead,pTail;
	pHead=creatList();
	
//	traverse(pHead);

//	printf("������Ҫ���ҵ�ѧ����ѧ��\n");
//	scanf("%d",&IDnum);
//	seekJava(pHead,i,IDnum,java);

//	printf("����Ҫ���ýڵ��ŵ��ڼ�λ\n");
//	scanf("%d",&i);
//	printf("�������ѧ����ѧ��\n");
//	scanf("%d",&IDnum);
//	printf("�������ѧ����Java�ɼ�\n");
//	scanf("%d",&java);
//	inset(pHead,i,IDnum,java);
//	traverse(pHead);

    printf("��������Ҫɾ����ѧ����ѧ��\n");
    scanf("%d",&IDnum);
    deleteNode(pHead,IDnum);
    traverse(pHead);

}
