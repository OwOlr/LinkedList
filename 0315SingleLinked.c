#include <stdio.h>
#include <malloc.h>

#define SAFE_FREE(p) do{free(p); (p) = NULL;}while (p);

//Single Linked List
//� � �
//� : �޸� �ȭ � �ذ�
//� : �ӵǾ� � �ʾ� �ӵ� �. � CPU� ũ� � �߱⿡ ũ� �Ű澲� �ʾҴ�.
//Over Head : �  �ϴ� �
//Node : � � �ּҰ�, � � � �־� �ü� �.
//�ȭ� ArrayList ,� � Single Linked List

// Structure �ü
// structure Padding - �޸� ȿ� � �Ѵ�.
// �ڷ� �Ƽ� �ϳ� �ڷ� �. -> � � �ڷ�.
struct SExample{
	
	// Structure Member Variables �ü � �
	
	char c;

	double d;	//� ũ�Ⱑ ū �ڷ� � �е� �ȴ�..
	int i;
};
void StructureExample() {
	struct SExample example = {1 ,10,100};	//�迭� �ϰ� ó� � �ڷ� �ּҸ� �.
	// . : � � �.
	//example.i = 10;
	//example.f = 3.14f;
	//printf("example Address; %p\n", &example);
	//printf("example.i: %d (%p)\n", example.i, &example.i);
	//printf("example.ii: %p\n", &example.ii);
	//printf("example.f: %f (%p)\n", example.f, &example.f);

	printf("SExample Size: %d byte\n", sizeof(struct SExample));
}


typedef struct _SNode {
	int data;
	struct _SNode* pNext;

}SNode;
//typedef struct SNode Node;	//struct SNode� Node� �θ� � �ִ�.

//�߿� const �߰�
void AddNode(SNode* _pHead, int _data);
void PrintAll (SNode* _pHead);
void RemoveAll(SNode* _pHead);
void InsertNode(SNode* _pHead, int _data, int _index );

//�
//1. � � ī�
int Count(SNode* _pHead);
void AddFront(SNode* _pHead, int _data);
void AddBack(SNode* _pHead, int _data);
//Ư� �ε� �ġ� �ִ� �带 �
SNode* GetNodeWithIndex(SNode* _pHead, int _index);
//Ư� �(�)� � �ִ� �(�ε�)� �
SNode* GetNodeWithData(SNode* _pHead, int _data);
//Ư� �ε� �ġ� �ִ� �带 �
void RemoveAt(SNode* _pHead, int index);
//SNode* GetNodeWithIndex(SNode* _pHead, int _index); �Լ� � �ش�ϴ� �带 �
void Remove(SNode* _pHead, SNode* _delNode);


void main() {
	SNode* pNode = (SNode*)malloc(sizeof(SNode));
	
	if (pNode != NULL) {

		pNode->data = 10;	//�Ҵ� � : " . "� ->� �.

		SAFE_FREE(pNode);
	}

	//1. Head� �س� � (� � � �)
		//	� : �޸� �.
	//2. AddNode�Լ� Head� � -> 2� �.
	SNode head = { 0 , NULL};
	PrintAll(&head);

	for (int i = 0; i < 5; i++)
	{
		AddNode(&head, i);

	}
	AddNode(&head, 100);
	PrintAll(&head);
	printf("-----------------\n");

	
	InsertNode(&head, 77, 14);
	PrintAll(&head);
	printf("-----------------\n");

	printf("<<� �տ� � �߰�!>>\n");
	AddFront(&head, 1021);
	PrintAll(&head);
	printf("-----------------\n");

	printf("<<� �ڿ� � �߰�!>>\n");
	AddBack(&head, 999);
	PrintAll(&head);
	printf("-----------------\n");

  GetNodeWithIndex(&head, 0);

	RemoveAll(&head);
	PrintAll(&head);


}

void AddNode(SNode* _pHead, int _data) {
	//�带 �ȸ�ϱ� � � � 
	//� : head � � �븮�ڰ� �ʿ�ϴ�.
	//STL : Interator (�ݺ�) 

	//1. Interator� �Ͽ� � � ã�
	SNode* pCurNode = _pHead;	//�

	while (pCurNode->pNext != NULL) {	//� ĭ �ּҰ� NULL� �ƴ� � �ݺ�
		pCurNode = pCurNode->pNext;	//�ĭ �̵�.
	}

	//while�ɾ �ݺ� � � � �忡 �Ѵ�.
	//2.� � ã� � � �带 �Ͽ� � �ش�.

	//2-1. �ο� � �
	SNode* pNewNode = (SNode*)malloc(sizeof(SNode));
	if (pNewNode != NULL) {
		
		pNewNode->data = _data;
		pNewNode->pNext = NULL;

		//2-2. � �忡 �ο� � �ּҸ� �ִ´�.
		pCurNode->pNext = pNewNode;
	}
	


}

void PrintAll(SNode* _pHead) {

	//�ϱ� � Interator(� �) �
	SNode* pCurNode = _pHead->pNext;
	if (pCurNode == NULL)
	{
		printf("List is Empty!\n");
		return;
	}

	//while (pCurNode->pNext != NULL) {}
		//�Ͱ� � � � � �Ѵ�.

	/*do
	{
		printf("%d - ", pCurNode->data);
		pCurNode = pCurNode->pNext;
		++index;
	} while (pCurNode != NULL);*/
	while (pCurNode != NULL) {
		printf("%d - ", pCurNode->data);
		pCurNode = pCurNode->pNext;

	}
	printf("( idx : %d )\n", Count(_pHead));

}

//� �غ�
void RemoveAll(SNode* _pHead) {
	if (_pHead == NULL || _pHead->pNext == NULL) return;

	//1. � �ּҿ� �ְ� �Ѵ�.
	SNode* pCurNode = _pHead->pNext;
	SNode* pDelNode = _pHead->pNext;

	do{
	//2. � � � � � � �带 �ռ� �Ѵ�.
	pCurNode = pDelNode->pNext;
	printf("pDelNode data : %d\n", pDelNode->data);
	SAFE_FREE(pDelNode);
	pDelNode = pCurNode;
	} while (pCurNode != NULL);
	
	//� pHead � �带 �Ű� �ִ�.

	_pHead->pNext = NULL;
}

void InsertNode(SNode* _pHead, int _data, int _index) {
	if (_pHead == NULL) return;		//� �
	if (_index < 0) _index *= -1;	//� � index� � � � �.


	//1-1. Interator�
	//1-2. Head � �带 index = 0 � �ġ.
	SNode* pCurNode = _pHead;
	int curIdx = -1;

	//2. Index ī�
	while (pCurNode != NULL) {
		
		if (_index  == 0||curIdx + 1 == _index) break;

		pCurNode = pCurNode->pNext;
		++curIdx;
	}

	if (pCurNode == NULL)
	{
		AddNode(_pHead, _data);
		return;
	}

	//� �
	//� �带 � �带 � � � � � �ּҸ� �.
	SNode* pCurNextNode = pCurNode->pNext;

	//�ο� � � �ο� �带 �
	SNode* pNewNode = (SNode*)malloc(sizeof(SNode));
	pNewNode->data = _data;

	//� � � �ּҿ� �ο� � �ּҸ� �ִ´�.
	pCurNode->pNext = pNewNode;
	//�ο� � � �ּҿ� � � �ּҸ� �ִ´�.
	pNewNode->pNext = pCurNextNode;

	printf("index [ %d ] : %d\n",_index,_data);


}

int Count(SNode* _pHead) {
	SNode* curNode = _pHead->pNext;
	int index = 0;

	while (curNode != NULL)
	{
		curNode = curNode->pNext;
		++index;
	}
	return index;
}

void AddFront(SNode* _pHead, int _data) {
	
	//1.�ο� �带 �
	SNode* pNewNode = (SNode*)malloc(sizeof(SNode));

	//2.�ο� �忡 � � � �ּҸ� �ֱ�.
	pNewNode = _pHead->pNext;
	//3.�ο� �尡 � � � �쿡 �.
	if (pNewNode != NULL) {
		//3-1. �ο� �忡 �޾ƿ� � � �.
		pNewNode->data = _data;
		//3-2. � � �ּҸ� � � � �ּҸ� �.
		_pHead->pNext = pNewNode;
	}
}

void AddBack(SNode* _pHead, int _data) {

	//1. �ͷ� �
	SNode* curNode = _pHead;

	//� � � �尡 NULL� � �.
	while (curNode->pNext != NULL)
	{
		curNode = curNode->pNext;
	}

	//2. �ο� � � � �
	SNode* pNewNode = (SNode*)malloc(sizeof(SNode));

	if (pNewNode!=NULL)
	{
		//�ο� �忡 �, �ּҸ� �
		pNewNode->data = _data;
		pNewNode->pNext = NULL;
		//� � � �ּҿ� �ο� � �ּ� �ֱ�
		curNode->pNext = pNewNode;
	}
}

SNode* GetNodeWithIndex(SNode* _pHead, int _index) {

  int curIndex = 0;
  SNode* curNode = _pHead->pNext;
  while(_index != curIndex){
    curNode=curNode->pNext;
    ++curIndex;
    
  }
  printf("data : %d , curIndex : %d \n",curNode->data,curIndex);
  return curNode;
  
}
