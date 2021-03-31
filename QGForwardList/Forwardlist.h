#pragma once
/**
 * 作者:QG
 **/

#ifndef __QGFORWARD_LIST_H__
#define __QGFORWARD_LIST_H__

#include<iostream>

 /*
  * 单向链表
  */
template<typename T>
class QGForwardList {
public:
	struct Node {
		/* 用于链表节点的定义 */
		T data; // 表示数据域
		Node* next;  // 表示指针域，存储下一个节点的位置
	};

protected:

	Node* head;
	Node* tail;
	int count;
public:



	//获取头结点
	Node* get_head()
	{
		return head;
	}

	/*
	 * 显示菜单
	 */
	void ShowMenu();


	//判断链表是否为空
	bool empty();

	/*
	 * 初始化链表
	 */
	QGForwardList();


	/*
	 * 创建链表
	 */
	void creat();


	/*
	 * 销毁链表
	 */
	~QGForwardList();

	/*
	 * 返回链表中第一个元素的引用
	 */
	T& front(T& a);

	/*
	 * 返回链表中最后一个元素的引用
	 */
	T& back(T& a);

	/*
	 * 在链表第一个元素前添加元素e
	 */
	bool push_front(T& e);

	/*
	 * 删除链表第一个元素
	 */
	bool pop_front();

	/*
	 * 在链表最后一个元素后添加元素e
	 */
	bool push_back(T& e);

	/*
	 * 删除链表最后一个元素
	 */
	bool pop_back();

	/*
	 * 在链表的第index + 1个元素前插入元素e
	 */
	bool insert(unsigned int index, T& e);

	/*
	 * 删除任意位置元素
	 */
	bool erase(unsigned int index);

	/*
	 * 清空链表
	 */
	bool clear();

	/*
	 * 查找元素是否存在
	 */
	bool contain(T& e);

	/*
	 * 返回链表中元素的数量
	 */
	unsigned int size();

	/*
	 * 遍历链表, 对每个元素调用visit指向的函数
	 */
	bool traverse(void (*visit)(T& e));

	/*
	 * 反转链表，1234反转后变成4321
	 */
	bool reverse1();//非递归
	Node* reverse2(Node* node_ptr); //递归

	/*
	 * 链表判环
	 */
	bool isLoop();

	/*
	 * 偶节点反转，1234反转后变成2143
	 */
	bool reverseEven();

	/*
	 * 返回中间节点
	 */
	T& middleElem();
};


//ForwardList.cpp



//判断链表是否为空
template<typename T>
bool QGForwardList<T>::empty()
{
	if (head->next == nullptr && count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}






//显示菜单
template<typename T>
void QGForwardList<T>::ShowMenu() {
	std::cout << "********************************" << std::endl;
	std::cout << "*         0.销毁链表           *" << std::endl;
	std::cout << "*         1.创建链表           *" << std::endl;
	std::cout << "*    2.返回第一个元素的引用    *" << std::endl;
	std::cout << "*    3.返回第一个元素的引用    *" << std::endl;
	std::cout << "*      4.在链表中插入元素      *" << std::endl;
	std::cout << "*      5.删除链表中的元素      *" << std::endl;
	std::cout << "*      6.查找元素是否存在      *" << std::endl;
	std::cout << "*       7.链表中元素数量       *" << std::endl;
	std::cout << "*          8.遍历链表          *" << std::endl;
	std::cout << "*          9.清空链表          *" << std::endl;
	std::cout << "*         10.链表反转          *" << std::endl;
	std::cout << "*         11.链表判环          *" << std::endl;
	std::cout << "*      12.链表偶节点反转       *" << std::endl;
	std::cout << "*       13.返回中间节点        *" << std::endl;
	std::cout << "********************************" << std::endl;
}




//初始化链表
template<typename T>
QGForwardList<T>::QGForwardList() {
	count = 0;//初始化链表长度
	head = nullptr;//让头结点为空
	Node* newnode = new Node;//开辟内存
	head = newnode;
	head->next = nullptr;
	tail = nullptr;
}


//创建链表
template<typename T>
void QGForwardList<T>::creat()
{
	Node* newnode = new Node;//开辟内存
	std::cout << "请按提示创建链表：" << std::endl;
	std::cout << "请输入第一个数据(非0)：" << std::endl;
	std::cin >> newnode->data;

	while (newnode->data != 0) {
		count++;
		if (count == 1) {
			head->next = newnode;//头节点下一个新节点
			newnode->next = nullptr;//使得指向为空
			tail = newnode;//加入新节点
		}
		else {
			newnode->next = nullptr;//新节点指针为空
			tail->next = newnode;//原来的尾节点指向新节点
			tail = newnode;
		}
		newnode = new Node;//再次给新节点分配新的内存空间
		std::cout << "请输入第" << count + 1 << "个数据：(提示，输入‘0’可终止输入)" << std::endl;
		std::cin >> newnode->data;

		if (newnode->data == 0) {
			break;
		}
	}
}



//销毁链表
template<typename T>
QGForwardList<T>::~QGForwardList() {
	Node* p = nullptr;
	if (head->next != nullptr) {
		while (head) {
			p = head->next->next;
			delete(head->next);
			head->next = p;
		}
	}
	delete(p);
}






//返回链表第一个元素的引用
template<typename T>
T& QGForwardList<T>::front(T& a) {
	if (head->next == nullptr)
	{
		abort();
	}
	else {
		return head->next->data;

	}
	system("pause");
	system("cls");
}

//返回链表中最后一个元素的引用
template<typename T>
T& QGForwardList<T>::back(T& a) {
	if (head->next == nullptr)
	{
		abort();
	}
	else {
		return tail->data;

	}
	system("pause");
	system("cls");
}


//在链表第一个元素前添加元素e
template<typename T>
bool QGForwardList<T>::push_front(T& e) {
	Node* newnode = new Node;
	newnode->data = e;
	if (head == nullptr && tail == nullptr)
	{
		head = tail = newnode;
	}
	else
	{
		newnode->next = head;
		head = newnode;
	}
	count++;
	return true;
	system("pause");
	system("cls");
}

//删除链表第一个元素
template<typename T>
bool QGForwardList<T>::pop_front() {
	Node* p = nullptr;
	if (head->next == nullptr && tail == nullptr)
	{
		abort();
	}
	else
	{
		p = head->next;
		head->next = head->next->next;
		delete(p);
		count--;
		return true;
	}
	system("pause");
	system("cls");
}

//在链表最后一个元素后添加元素e
template<typename T>
bool QGForwardList<T>::push_back(T& e) {
	Node* p = new Node;
	p->data = e;
	p->next = nullptr;
	if (head->next == nullptr && tail == nullptr)
	{
		head->next = p;
		tail = p;
	}
	else
	{
		tail->next = p;
		tail = tail->next;
	}
	count++;
	return true;
}

//删除链表最后一个元素
template<typename T>
bool QGForwardList<T>::pop_back() {
	Node* p, * pre = head;
	p = tail;
	if (head->next == nullptr && tail == nullptr)
	{
		abort();
	}
	else
	{
		for (unsigned int i = 1; i < count - 1; i++)  //利用for循环让指针指在倒数第二个结点上
		{
			pre = pre->next;
		}
		pre->next = tail;
		tail = pre;
		pre = nullptr;
		delete(p);
		count--;
		return true;
	}
	system("pause");
	system("cls");
}

//在链表的第index + 1个元素前插入元素e
template<typename T>
bool QGForwardList<T>::insert(unsigned int index, T& e) {
	Node* p = head;
	Node* newnode = new Node; //开辟新结点内存
	newnode->data = e;   //把e赋值进数据域里
	for (unsigned int i = 1; i < index; i++)  //利用for循环让指针指在第index个结点上
	{
		p = p->next;
	}
	newnode->next = p->next;  //新结点的next指向第index+1个结点
	p->next = newnode;   //第index个结点的next指向新结点
	count++;    //链表节点增加
	delete(p);
	return true;
	system("pause");
	system("cls");
}

//删除任意位置元素
template<typename T>
bool QGForwardList<T>::erase(unsigned int index) {
	Node* p = head->next, * pre = p;
	if (head->next == nullptr && tail == nullptr)
	{
		abort();
	}
	else
	{
		for (unsigned int i = 1; i < index; i++) {
			pre = p;
			p = p->next;
		}
		pre->next = p->next;
		delete(p);
		count--;
		return true;
	}
	system("pause");
	system("cls");
}

//清空链表
template<typename T>
bool QGForwardList<T>::clear() {
	Node* p, * q;
	p = head->next->next;

	if (head->next != nullptr || count != 0)
	{
		//记录当前指针变量
		p = head->next;
		while (p->next)
		{
			//将头指针后移
			head->next = p->next;
			delete p;
			p = nullptr;
			//将新的头指针赋给临时变量
			p = head->next;
		}

		//删除最后一个节点  并将长度设置为0
		delete head;
		head = nullptr;
		count = 0;
		return true;
	}
}

//查找元素是否存在
template<typename T>
bool QGForwardList<T>::contain(T& e) {
	Node* p = head->next;

	for (int i = 1; i <= count; i++) {
		if (p->data == e) {
			std::cout << "存在该元素！" << std::endl;
			break;
		}
		else {
			if (i == count) {
				std::cout << "查不到该元素！" << std::endl;
				break;
			}
			p = p->next;
		}
	}
	return true;
	system("pause");
	system("cls");
}

//返回链表中元素的数量
template<typename T>
unsigned int QGForwardList<T>::size() {
	return count;
	system("pause");
	system("cls");
}



template<typename T>
void Print(T& e) {
	std::cout << e << " ";
}


//遍历链表, 对每个元素调用visit指向的函数
template<typename T>
bool QGForwardList<T>::traverse(void (*visit)(T& e)) {
	Node* p = head->next;
	if (p == nullptr)
	{
		abort();
	}
	else
	{
		while (p != nullptr) {
			(*visit)(p->data);
			p = p->next;
		}
		std::cout << std::endl;
		return true;
	}
}


//反转链表，1234反转后变成4321
//非递归
template<typename T>
bool QGForwardList<T>::reverse1() {
	Node* p1, * p2, * p3;
	p2 = head->next;  //将phead指向链表头
	p3 = p1 = nullptr;  //p1为头指针之前的节点
	while (p2 != nullptr) {
		p3 = p2->next;	//暂存下一个节点的指针
		p2->next = p1;	//反转
		p1 = p2;	//上一节点指针右移
		p2 = p3;	//当前节点指针右移
	}
	head->next = p1;	//反转后的链表头指针为最后一个非NULL节点的指针

	//打印
	Node* p = head->next;
	while (p->next != nullptr) {
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << p->data << std::endl;

	return true;

}


//递归
template<typename T>
typename QGForwardList<T>::Node* QGForwardList<T>::reverse2(typename QGForwardList<T>::Node* node_ptr) {
	if (node_ptr->next == nullptr) {
		head->next = node_ptr;	//最后一个节点会成为新的头节点
		return node_ptr;   //最后一个节点返回
	}

	Node* next_node = reverse2(node_ptr->next);
	next_node->next = node_ptr;
	node_ptr->next = nullptr;

	return node_ptr;
}


//链表判环
template<typename T>
bool QGForwardList<T>::isLoop() {
	Node* slow = head->next, * fast = head->next;//从头开始出发
	if (slow == nullptr)
	{
		return false;
	}
	if (slow->next != nullptr && fast->next->next == nullptr)
	{
		return false;
	}
	while (slow->next != nullptr && fast->next->next != nullptr) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			return true;
			break;
		}
		else {
			return false;
		}
	}
}


//偶节点反转，1234反转后变成2143
template<typename T>
bool QGForwardList<T>::reverseEven() {
	Node* p1, * p2, * p3/*, * p4,* p5*/;

	if (head->next == nullptr || count == 1) {
		abort();
	}

	else if (count == 2) {
		p1 = head->next;
		p2 = head->next->next;
		p1->next = nullptr;
		p2->next = p1;
		return true;
	}
	else if (count == 3)
	{
		p1 = head->next;
		p2 = head->next->next;
		p3 = head->next->next->next;
		p1->next = p3;
		p2->next = p1;
		return true;
	}
	else {
		Node* p1 = head->next;
		Node* p2 = head->next->next;
		Node* p3 = p2->next;
		head->next = head->next->next;
		while (true) {
			p2->next = p1;
			if (p3->next != nullptr && p3->next->next != nullptr) //正常往前循环
			{
				p1->next = p3->next;
				p1 = p3;
				p2 = p1->next;
				p3 = p3->next->next;
				break;
			}
			else if (p3->next == nullptr)           //到达尾部，且链表元素个数为奇数，直接把最后一个元素连接到末尾
			{
				p3->next = p3;
				break;
			}
			else if (p3->next != 0 && p3->next->next == nullptr)      //到达尾部，且链表元素个数为偶数，进行最后一步互换，并设置结束符NULL
			{
				p1->next = p3->next;
				p3->next->next = p3;
				p3->next = nullptr;
				break;
			}
		}
		return true;
	}
}




//返回中间节点
template<typename T>
T& QGForwardList<T>::middleElem() {
	Node* slow = head->next, * fast = head->next;//从头开始出发

	while (fast != nullptr && fast->next != nullptr) {
		fast = fast->next;
		if (fast != nullptr && fast->next != nullptr) {
			fast = fast->next;
			slow = slow->next;
		}
		else {
			break;
		}
	}
	return slow->data;

}




#endif
