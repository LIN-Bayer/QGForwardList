#pragma once
/**
 * ����:QG
 **/

#ifndef __QGFORWARD_LIST_H__
#define __QGFORWARD_LIST_H__

#include<iostream>

 /*
  * ��������
  */
template<typename T>
class QGForwardList {
public:
	struct Node {
		/* ��������ڵ�Ķ��� */
		T data; // ��ʾ������
		Node* next;  // ��ʾָ���򣬴洢��һ���ڵ��λ��
	};

protected:

	Node* head;
	Node* tail;
	int count;
public:



	//��ȡͷ���
	Node* get_head()
	{
		return head;
	}

	/*
	 * ��ʾ�˵�
	 */
	void ShowMenu();


	//�ж������Ƿ�Ϊ��
	bool empty();

	/*
	 * ��ʼ������
	 */
	QGForwardList();


	/*
	 * ��������
	 */
	void creat();


	/*
	 * ��������
	 */
	~QGForwardList();

	/*
	 * ���������е�һ��Ԫ�ص�����
	 */
	T& front(T& a);

	/*
	 * �������������һ��Ԫ�ص�����
	 */
	T& back(T& a);

	/*
	 * �������һ��Ԫ��ǰ���Ԫ��e
	 */
	bool push_front(T& e);

	/*
	 * ɾ�������һ��Ԫ��
	 */
	bool pop_front();

	/*
	 * ���������һ��Ԫ�غ����Ԫ��e
	 */
	bool push_back(T& e);

	/*
	 * ɾ���������һ��Ԫ��
	 */
	bool pop_back();

	/*
	 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	 */
	bool insert(unsigned int index, T& e);

	/*
	 * ɾ������λ��Ԫ��
	 */
	bool erase(unsigned int index);

	/*
	 * �������
	 */
	bool clear();

	/*
	 * ����Ԫ���Ƿ����
	 */
	bool contain(T& e);

	/*
	 * ����������Ԫ�ص�����
	 */
	unsigned int size();

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
	 */
	bool traverse(void (*visit)(T& e));

	/*
	 * ��ת����1234��ת����4321
	 */
	bool reverse1();//�ǵݹ�
	Node* reverse2(Node* node_ptr); //�ݹ�

	/*
	 * �����л�
	 */
	bool isLoop();

	/*
	 * ż�ڵ㷴ת��1234��ת����2143
	 */
	bool reverseEven();

	/*
	 * �����м�ڵ�
	 */
	T& middleElem();
};


//ForwardList.cpp



//�ж������Ƿ�Ϊ��
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






//��ʾ�˵�
template<typename T>
void QGForwardList<T>::ShowMenu() {
	std::cout << "********************************" << std::endl;
	std::cout << "*         0.��������           *" << std::endl;
	std::cout << "*         1.��������           *" << std::endl;
	std::cout << "*    2.���ص�һ��Ԫ�ص�����    *" << std::endl;
	std::cout << "*    3.���ص�һ��Ԫ�ص�����    *" << std::endl;
	std::cout << "*      4.�������в���Ԫ��      *" << std::endl;
	std::cout << "*      5.ɾ�������е�Ԫ��      *" << std::endl;
	std::cout << "*      6.����Ԫ���Ƿ����      *" << std::endl;
	std::cout << "*       7.������Ԫ������       *" << std::endl;
	std::cout << "*          8.��������          *" << std::endl;
	std::cout << "*          9.�������          *" << std::endl;
	std::cout << "*         10.����ת          *" << std::endl;
	std::cout << "*         11.�����л�          *" << std::endl;
	std::cout << "*      12.����ż�ڵ㷴ת       *" << std::endl;
	std::cout << "*       13.�����м�ڵ�        *" << std::endl;
	std::cout << "********************************" << std::endl;
}




//��ʼ������
template<typename T>
QGForwardList<T>::QGForwardList() {
	count = 0;//��ʼ��������
	head = nullptr;//��ͷ���Ϊ��
	Node* newnode = new Node;//�����ڴ�
	head = newnode;
	head->next = nullptr;
	tail = nullptr;
}


//��������
template<typename T>
void QGForwardList<T>::creat()
{
	Node* newnode = new Node;//�����ڴ�
	std::cout << "�밴��ʾ��������" << std::endl;
	std::cout << "�������һ������(��0)��" << std::endl;
	std::cin >> newnode->data;

	while (newnode->data != 0) {
		count++;
		if (count == 1) {
			head->next = newnode;//ͷ�ڵ���һ���½ڵ�
			newnode->next = nullptr;//ʹ��ָ��Ϊ��
			tail = newnode;//�����½ڵ�
		}
		else {
			newnode->next = nullptr;//�½ڵ�ָ��Ϊ��
			tail->next = newnode;//ԭ����β�ڵ�ָ���½ڵ�
			tail = newnode;
		}
		newnode = new Node;//�ٴθ��½ڵ�����µ��ڴ�ռ�
		std::cout << "�������" << count + 1 << "�����ݣ�(��ʾ�����롮0������ֹ����)" << std::endl;
		std::cin >> newnode->data;

		if (newnode->data == 0) {
			break;
		}
	}
}



//��������
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






//���������һ��Ԫ�ص�����
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

//�������������һ��Ԫ�ص�����
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


//�������һ��Ԫ��ǰ���Ԫ��e
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

//ɾ�������һ��Ԫ��
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

//���������һ��Ԫ�غ����Ԫ��e
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

//ɾ���������һ��Ԫ��
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
		for (unsigned int i = 1; i < count - 1; i++)  //����forѭ����ָ��ָ�ڵ����ڶ��������
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

//������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
template<typename T>
bool QGForwardList<T>::insert(unsigned int index, T& e) {
	Node* p = head;
	Node* newnode = new Node; //�����½���ڴ�
	newnode->data = e;   //��e��ֵ����������
	for (unsigned int i = 1; i < index; i++)  //����forѭ����ָ��ָ�ڵ�index�������
	{
		p = p->next;
	}
	newnode->next = p->next;  //�½���nextָ���index+1�����
	p->next = newnode;   //��index������nextָ���½��
	count++;    //����ڵ�����
	delete(p);
	return true;
	system("pause");
	system("cls");
}

//ɾ������λ��Ԫ��
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

//�������
template<typename T>
bool QGForwardList<T>::clear() {
	Node* p, * q;
	p = head->next->next;

	if (head->next != nullptr || count != 0)
	{
		//��¼��ǰָ�����
		p = head->next;
		while (p->next)
		{
			//��ͷָ�����
			head->next = p->next;
			delete p;
			p = nullptr;
			//���µ�ͷָ�븳����ʱ����
			p = head->next;
		}

		//ɾ�����һ���ڵ�  ������������Ϊ0
		delete head;
		head = nullptr;
		count = 0;
		return true;
	}
}

//����Ԫ���Ƿ����
template<typename T>
bool QGForwardList<T>::contain(T& e) {
	Node* p = head->next;

	for (int i = 1; i <= count; i++) {
		if (p->data == e) {
			std::cout << "���ڸ�Ԫ�أ�" << std::endl;
			break;
		}
		else {
			if (i == count) {
				std::cout << "�鲻����Ԫ�أ�" << std::endl;
				break;
			}
			p = p->next;
		}
	}
	return true;
	system("pause");
	system("cls");
}

//����������Ԫ�ص�����
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


//��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
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


//��ת����1234��ת����4321
//�ǵݹ�
template<typename T>
bool QGForwardList<T>::reverse1() {
	Node* p1, * p2, * p3;
	p2 = head->next;  //��pheadָ������ͷ
	p3 = p1 = nullptr;  //p1Ϊͷָ��֮ǰ�Ľڵ�
	while (p2 != nullptr) {
		p3 = p2->next;	//�ݴ���һ���ڵ��ָ��
		p2->next = p1;	//��ת
		p1 = p2;	//��һ�ڵ�ָ������
		p2 = p3;	//��ǰ�ڵ�ָ������
	}
	head->next = p1;	//��ת�������ͷָ��Ϊ���һ����NULL�ڵ��ָ��

	//��ӡ
	Node* p = head->next;
	while (p->next != nullptr) {
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << p->data << std::endl;

	return true;

}


//�ݹ�
template<typename T>
typename QGForwardList<T>::Node* QGForwardList<T>::reverse2(typename QGForwardList<T>::Node* node_ptr) {
	if (node_ptr->next == nullptr) {
		head->next = node_ptr;	//���һ���ڵ���Ϊ�µ�ͷ�ڵ�
		return node_ptr;   //���һ���ڵ㷵��
	}

	Node* next_node = reverse2(node_ptr->next);
	next_node->next = node_ptr;
	node_ptr->next = nullptr;

	return node_ptr;
}


//�����л�
template<typename T>
bool QGForwardList<T>::isLoop() {
	Node* slow = head->next, * fast = head->next;//��ͷ��ʼ����
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


//ż�ڵ㷴ת��1234��ת����2143
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
			if (p3->next != nullptr && p3->next->next != nullptr) //������ǰѭ��
			{
				p1->next = p3->next;
				p1 = p3;
				p2 = p1->next;
				p3 = p3->next->next;
				break;
			}
			else if (p3->next == nullptr)           //����β����������Ԫ�ظ���Ϊ������ֱ�Ӱ����һ��Ԫ�����ӵ�ĩβ
			{
				p3->next = p3;
				break;
			}
			else if (p3->next != 0 && p3->next->next == nullptr)      //����β����������Ԫ�ظ���Ϊż�����������һ�������������ý�����NULL
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




//�����м�ڵ�
template<typename T>
T& QGForwardList<T>::middleElem() {
	Node* slow = head->next, * fast = head->next;//��ͷ��ʼ����

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
