#include<iostream>
#include"ForwardList.h"




int main()
{
	class QGForwardList<int> qgforwardlist;
	std::cout << "已初始化链表！" << std::endl;
	/*qgforwardlist.ShowMenu();*/
	int choice;
	int temp = 0;
	/*cout << "请输入选项" << endl;
	cin >> choice;*/
	unsigned int index = 0;
	/*if (qgforwardlist.empty())
	{
		std::cout << "链表为空，无法进行操作" << endl;
	}*/
	while (true)
	{
		qgforwardlist.ShowMenu();
		std::cout << "请输入选项" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			qgforwardlist.~QGForwardList();
			std::cout << "链表已销毁！" << std::endl;
			break;
		case 1:
			qgforwardlist.creat();
			break;
		case 2:          //返回第一个元素的引用
		{
			if (qgforwardlist.empty())
			{
				std::cout << "不存在元素！" << std::endl;
			}
			else
			{
				qgforwardlist.front(temp);
				std::cout << "第一个元素为：" << qgforwardlist.front(temp) << std::endl;
			}
			break;
		}
		case 3:         //返回最后一个元素的引用
		{
			if (qgforwardlist.empty())
			{
				std::cout << "不存在元素！" << std::endl;
			}
			else
			{
				qgforwardlist.back(temp);
				std::cout << "最后一个元素为：" << qgforwardlist.back(temp) << std::endl;
			}
			break;
		}
		case 4:          //在链表中插入元素
		{
			int a;
			std::cout << "请输入要插入的位置" << std::endl;
			std::cin >> index;
			std::cout << "请输入要插入的内容：" << std::endl;
			std::cin >> a;
			if (qgforwardlist.empty())
			{
				std::cout << "链表为空，找不到该位置,默认在尾节点插入数据\n";
				qgforwardlist.push_back(a);
			}
			else if (index == 0)
			{
				qgforwardlist.push_front(a);
				std::cout << "插入成功！" << std::endl;
			}
			else if (index == -1) {
				qgforwardlist.push_back(a);
				std::cout << "插入成功！" << std::endl;
			}
			else if (index<1 || index >(qgforwardlist.size() + 1)) {
				std::cout << "输入位置有误或不存在，插入失败！" << std::endl;
			}
			else {
				qgforwardlist.insert(index, a);
				std::cout << "插入成功！" << std::endl;
			}
			break;
		}
		case 5:          //删除链表中的元素
		{
			if (qgforwardlist.empty())
			{
				std::cout << "链表为空，无法删除！" << std::endl;
			}
			else
			{
				std::cout << "请输入要删除的位置" << std::endl;
				std::cin >> index;
				if (index == 1)    //头删
				{
					qgforwardlist.pop_front();
					std::cout << "删除成功！" << std::endl;
				}
				else if (index == qgforwardlist.size() && qgforwardlist.size() != 1)     //尾删
				{
					qgforwardlist.pop_back();
					std::cout << "删除成功！" << std::endl;
				}
				else if (index < 1 || (index > qgforwardlist.size()))
				{
					std::cout << "没有该位置，删除失败！" << std::endl;
				}
				else          //删除
				{
					qgforwardlist.erase(index);
					std::cout << "删除成功！" << std::endl;
				}
			}
			break;
		}
		case 6:          //查找元素是否存在
		{
			int b;
			std::cout << "请输入元素：" << std::endl;
			std::cin >> b;
			qgforwardlist.contain(b);
			break;
		}
		case 7:          //链表中元素数量 
			std::cout << "元素数量为：" << qgforwardlist.size() << std::endl;
			break;
		case 8:          //遍历链表
		{
			if (qgforwardlist.empty())
			{
				std::cout << "链表为空!" << std::endl;
			}
			else
			{
				qgforwardlist.traverse(Print);
			}
			break;
		}
		case 9:          //清空链表
			std::cout << "是否确定清空？清空后将退出整个操作系统！" << std::endl << "1.确定  2.取消" << std::endl;
			int a;
			std::cin >> a;
			if (a == 1)
			{
				qgforwardlist.clear();
				std::cout << "链表已清空！" << std::endl;
			}
			else if (a == 2)
			{
				std::cout << "取消清空成功！" << std::endl;
			}
			else
			{
				std::cout << "输入有误！" << std::endl;
			}
			break;
		case 10:        //链表反转
		{
			int a;
			std::cout << "输入‘1’选择非递归反转" << std::endl;
			std::cout << "输入‘2’选择递归反转" << std::endl;
			std::cin >> a;
			std::cout << "反转前为：" << std::endl;
			qgforwardlist.traverse(Print);
			std::cout << "反转后为：" << std::endl;
			if (a == 1)
			{
				qgforwardlist.reverse1();
			}
			else if (a == 2)
			{
				qgforwardlist.reverse2(qgforwardlist.get_head());
				qgforwardlist.traverse(Print);
			}
			else
			{
				std::cout << "输入错误，无法进行反转" << std::endl;
			}
			break;
		}
		case 11:        //链表判环
		{
			bool ret = qgforwardlist.isLoop();
			if (ret == 1)
			{
				std::cout << "链表内有环！" << std::endl;
			}
			else
			{
				std::cout << "链表内无环！" << std::endl;
			}
			break;
		}
		case 12:        //链表偶节点反转 
		{

			if (qgforwardlist.empty())
			{
				std::cout << "不存在链表，无法进行偶节点反转！" << std::endl;
			}
			else if (qgforwardlist.size() == 1)
			{
				std::cout << "链表只有一个节点，无法进行偶节点反转！" << std::endl;
			}
			else
			{
				qgforwardlist.reverseEven();
				std::cout << "反转成功！" << std::endl;
			}
			break;
		}
		case 13:        //返回中间节点
			std::cout << "中间节点值为：" << qgforwardlist.middleElem() << std::endl;
			break;
		default:
			std::cout << "输入有误，请重新输入" << std::endl;
		}
		std::system("pause");
		std::system("cls");
	}
	return 0;
}