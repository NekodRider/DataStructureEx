#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <cstring>
#include "BinaryTree.h"

int main(void)
{
	BinaryTree T[10];
	Node NodeList[10][128];
	int op = 1, m, num = 0;
	ElemType t, n;
	status flag;
	char filename[30],	definition[10][128];
	while (op)
	{
		system("cls");
		printf("\n\n");
		printf("                 Menu for BinaryTree   \n");
		printf("-------------------------------------------------\n");
		printf("    	  1. InitBiTree      11. LeftChild\n");
		printf("    	  2. CreateBiTree    12. RightChild\n");
		printf("    	  3. DestroryBiTree  13. LeftSibling\n");
		printf("    	  4. ClearBiTree     14. RightSibling\n");
		printf("    	  5. BiTreeEmpty     15. InsertChild\n");
		printf("    	  6. BiTreeDepth     16. DeleteChild\n");
		printf("    	  7. Root            17. PreOrderTraverse\n");
		printf("    	  8. Value           18. InOrderTraverse\n");
		printf("    	  9. Assign          19. PostOrderTraverse\n");
		printf("    	  10.Parent         20. LevelOrderTraverse\n");
		printf("          21.SaveToFile      22. LoadFromFile\n");
		printf("    	  0. Exit\n");
		printf("          99. ChangePlot     Current Plot %d\n", num);
		printf("-------------------------------------------------\n");
		printf("    请选择你的操作[0~99]:");
		scanf("%d", &op);
		switch (op)
		{
		case 99:
			printf("当前栏位为 %d ,请输入你想切换的栏位号[0-9]：\n", num);
			scanf("%d", &num);
			printf("成功切换到栏位 %d !\n", num);
			getchar();
			getchar();
			break;
		case 1:
			if (InitBiTree(T[num]) == OK)
				printf("二叉树创建成功！\n");
			else
				printf("二叉树创建失败！\n");
			getchar();
			getchar();
			break;
		case 2:
			printf("请输入创建二叉树的definition:\n");
			scanf("%s",definition);
			flag = CreateBiTree(T[num],definition[num],NodeList[num]);
			if(flag == INFEASIBLE){
				printf("二叉树未建立！\n");
			}
			getchar();
			getchar();
			break;
		case 3:
			getchar();
			getchar();
			break;
		case 4:
			getchar();
			getchar();
			break;
		case 5:
			getchar();
			getchar();
			break;
		case 6:
			getchar();
			getchar();
			break;
		case 7:
			
			getchar();
			getchar();
			break;
		case 8:
			getchar();
			getchar();
			break;
		case 9:
			getchar();
			getchar();
			break;
		case 10:
			getchar();
			getchar();
			break;
		case 11:
			getchar();
			getchar();
			break;
		case 12:
			getchar();
			getchar();
			break;
		case 13:
			getchar();
			getchar();
			break;
		case 14:
			getchar();
			getchar();
			break;
		case 15:
			getchar();
			getchar();
			break;
		case 16:
			getchar();
			getchar();
			break;
		case 17:
			getchar();
			getchar();
			break;
		case 18:
			getchar();
			getchar();
			break;
		case 19:
			getchar();
			getchar();
			break;
		case 20:
			getchar();
			getchar();
			break;
		case 21:
			//if (!isList(L[num]))
			//	printf("顺序表不存在！\n");
			
				printf("请输入要存储的文件名：\n");
				scanf("%s", &filename);
				if (SaveToFile(T[num],definition[num], filename))
					printf("存储成功！\n");
				else
					printf("存储失败！\n");
			
			getchar();
			getchar();
			break;
		case 22:
			printf("请输入要读取的文件名：\n");
			scanf("%s", &filename);
			if (LoadFromFile(T[num], definition[num],filename)&&CreateBiTree(T[num],definition[num],NodeList[num]))
				printf("读取成功！\n");
			else
				printf("读取失败！\n");
			getchar();
			getchar();
			break;
		case 0:
			break;
		}
	}
	printf("欢迎下次再使用本系统！\n");
	return 0;
}



status SaveToFile(BinaryTree T,char* definition, char *filename)
{
	if (T.data==NULL)
	{
		printf("二叉树不存在！\n");
		return INFEASIBLE;
	}
	FILE *fp;
	if ((fp = fopen(filename, "w")) == NULL)
	{
		printf("保存数据出错！\n");
		return ERROR;
	}
	fwrite(definition, sizeof(char)*strlen(definition), 1, fp);
	fclose(fp);
	return OK;
}

status LoadFromFile(BinaryTree &T, char* definition,char *filename)
{
	if (T.data==NULL)
	{
		InitBiTree(T);
	}
	FILE *fp;
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("读取数据出错！\n");
		DestroyBiTree(T);
		return ERROR;
	}
	fread(definition, sizeof(char)*strlen(definition), 1, fp);
	fclose(fp);
	return OK;
}

status InitBiTree(BinaryTree &T){
	if(T.data!=NULL){
		return INFEASIBLE;
	}
	T = *(new BinaryTree);
	if(!(&T))
		exit(OVERFLOW);
	return OK;
}
status DestroyNode(Node e){
	if((*e).lchild)
		DestroyNode((*e).lchild);	
	if((*e).rchild)
		DestroyNode((*e).rchild);
	free(e);
}
status DestroyBiTree(BinaryTree &T){
	if(T.data==NULL){
		return INFEASIBLE;
	}
	if(T.lchild)
		DestroyNode(T.lchild);	
	if(T.rchild)
		DestroyNode(T.rchild);	
	free(&T);
	return OK;
}

status CreateBiTree(BinaryTree &T,char* definition,Node* NodeList){
	if(T.data!=NULL){
		return INFEASIBLE;
	}
	int pos = 0,layer_max = 1,p_pos=0;
	Node node = &T,p = &T,node_list[128];
	node_list[0]=&T;
	for(int i = 1;i<128;i++)
		node_list[i]=nullptr;
	while(definition[pos]!=EOF){
		if(definition[pos]!='#'){
			node = (Node)malloc(sizeof(BinaryTree));
			(*node).data = definition[pos];
			(*node).lchild = nullptr;
			(*node).rchild = nullptr;
		}
		pos++;
		node_list[pos]=node;
		if(pos==layer_max){
			node = (*(node_list[((layer_max+1)/2)-1])).lchild;
			p_pos = (layer_max+1)/2-1;
			p = node_list[p_pos];
			layer_max=2*layer_max-1;
		}
		else if((pos+1)%2==0){
			node = (*p).rchild;
		}
		else{
			p_pos=+2;
			p = node_list[p_pos];
			node = (*p).lchild;
		}
	}
	NodeList = node_list;
	return OK;
}

status ClearBiTree(BinaryTree &T){
	if(T.data==NULL){
		return INFEASIBLE;
	}
	else if(!DestroyBiTree(T)&&!InitBiTree(T)){
		return OK;
	}
	else
		return ERROR;
}

status BiTreeEmpty(BinaryTree T){
	if(T.data==NULL&&T.lchild==nullptr&&T.rchild==nullptr){
		return TRUE;
	}
	return FALSE;
}

int BiTreeDepth(BinaryTree T){

}

Node Root(BinaryTree T){
	return (&T);
}

ElemType Value(BinaryTree T,Node e){
	return (*e).data;
}

status Assign(BinaryTree T,Node &e, ElemType value){
	(*e).data = value;
	return OK;
}



// while((*p).lchild){
// 		q = p;
// 		ListLength++;
// 		NodeList[ListLength]=q;
// 		p = (*p).lchild;
// 	}
// 	(*p).data=definition[i];
// 	i++;