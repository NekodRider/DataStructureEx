// ⑴初始化二叉树：函数名称是InitBiTree(T)；初始条件是二叉树T不存在；操作结果是构造空二叉树T。
// ⑵销毁二叉树：树函数名称是DestroyBiTree(T)；初始条件是二叉树T已存在；操作结果是销毁二叉树T。
// ⑶创建二叉树：函数名称是CreateBiTree(T,definition)；初始条件是definition 给出二叉树T的定义；操作结果是按definition构造二叉树T。
// ⑷清空二叉树：函数名称是ClearBiTree (T)；初始条件是二叉树T存在；	操作结果是将二叉树T清空。
// ⑸判定空二叉树：函数名称是BiTreeEmpty(T)；初始条件是二叉树T存在；操作结果是若T为空二叉树则返回TRUE，否则返回FALSE。
// ⑹求二叉树深度：函数名称是BiTreeDepth(T)；初始条件是二叉树T存在；操作结果是返回T的深度。
// ⑺获得根结点：函数名称是Root(T)；初始条件是二叉树T已存在；操作结果是返回T的根。
// ⑻获得结点：函数名称是Value(T,e)；初始条件是二叉树T已存在，e是T中的某个结点；操作结果是返回e的值。
// ⑼结点赋值：函数名称是Assign(T,&e,value)；初始条件是二叉树T已存在，e是T中的某个结点；操作结果是结点e赋值为value。
// ⑽获得双亲结点：函数名称是Parent(T,e) ；初始条件是二叉树T已存在，e是T中的某个结点；操作结果是若e是T的非根结点，则返回它的双亲结点指针，否则返回NULL。
// ⑾获得左孩子结点：函数名称是LeftChild(T,e)；初始条件是二叉树T存在，e是T中某个节点；操作结果是返回e的左孩子结点指针。若e无左孩子，则返回NULL。
// ⑿获得右孩子结点：函数名称是RightChild(T,e)；初始条件是二叉树T已存在，e是T中某个结点；操作结果是返回e的右孩子结点指针。若e无右孩子，则返回NULL。
// ⒀获得左兄弟结点：函数名称是LeftSibling(T,e)；初始条件是二叉树T存在，e是T中某个结点；操作结果是返回e的左兄弟结点指针。若e是T的左孩子或者无左兄弟，则返回NULL。
// ⒁获得右兄弟结点：函数名称是RightSibling(T,e)；初始条件是二叉树T已存在，e是T中某个结点；操作结果是返回e的右兄弟结点指针。若e是T的右孩子或者无有兄弟，则返回NULL。
// ⒂插入子树：函数名称是InsertChild(T,p,LR,c)；初始条件是二叉树T存在，p指向T中的某个结点，LR为0或1，,非空二叉树c与T不相交且右子树为空；操作结果是根据LR为0或者1，插入c为T中p所指结点的左或右子树，p	所指结点的原有左子树或右子树则为c的右子树。
// ⒃删除子树：函数名称是DeleteChild(T.p.LR)；初始条件是二叉树T存在，p指向T中的某个结点，LR为0或1。	操作结果是根据LR为0或者1，删除c为T中p所指结点的左或右子树。
// ⒄前序遍历：函数名称是PreOrderTraverse(T,Visit())；初始条件是二叉树T存在，Visit是对结点操作的应用函数；操作结果：先序遍历t，对每个结点调用函数Visit一次且一次，一旦调用失败，则操作失败。
// ⒅中序遍历：函数名称是InOrderTraverse(T,Visit))；初始条件是二叉树T存在，Visit是对结点操作的应用函数；操作结果是中序遍历t，对每个结点调用函数Visit一次且一次，一旦调用失败，则操作失败。
// ⒆后序遍历：函数名称是PostOrderTraverse(T,Visit))；初始条件是二叉树T存在，Visit是对结点操作的应用函数；操作结果是后序遍历t，对每个结点调用函数Visit一次且一次，一旦调用失败，则操作失败。
// ⒇按层遍历：函数名称是LevelOrderTraverse(T,Visit))；初始条件是二叉树T存在，Visit是对结点操作的应用函数；操作结果是层序遍历t，对每个结点调用函数Visit一次且一次，一旦调用失败，则操作失败。

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;
typedef int ElemType;


typedef struct BinaryTree{
	ElemType data=NULL;
	struct BinaryTree* lchild;
	struct BinaryTree* rchild;
}BinaryTree;

typedef struct BinaryTree* Node;


//20个ADT操作
status InitBiTree(BinaryTree &T);
status CreateBiTree(BinaryTree &T,char* definition,Node* NodeList);
status DestroyBiTree(BinaryTree &T);
status ClearBiTree(BinaryTree &T);
status BiTreeEmpty(BinaryTree T);
int BiTreeDepth(BinaryTree T);
Node Root(BinaryTree T);
ElemType Value(BinaryTree T,Node e);
status Assign(BinaryTree T, Node &e, ElemType value);
Node Parent(BinaryTree T, Node &e);
Node LeftChild(BinaryTree T,Node e);
Node RightChild(BinaryTree T,Node e);
Node LeftSibling(BinaryTree T,Node e);
Node RightSibling(BinaryTree T,Node e);
status InsertChild(BinaryTree &T,Node p,int LR,ElemType c);
status DeleteChild(BinaryTree &T,Node p,int LR);
status PreOrderTraverse(BinaryTree T,status (*visit)(ElemType &a));
status InOrderTraverse(BinaryTree T,status (*visit)(ElemType &a));
status PostOrderTraverse(BinaryTree T,status (*visit)(ElemType &a));
status LevelOrderTraverse(BinaryTree T,status (*visit)(ElemType &a));

//演示系统函数
Node LocateNode(BinaryTree T,int index);
status BiTreeDisplay(BinaryTree T);
status ElemDisplay(ElemType &a);
status ElemPlus(ElemType &a);

//文件读写
status SaveToFile(BinaryTree T, char* definition,char *filename);
status LoadFromFile(BinaryTree &T,char* definition ,char *filename);