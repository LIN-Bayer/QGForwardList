#include<iostream>
#include"ForwardList.h"




int main()
{
	class QGForwardList<int> qgforwardlist;
	std::cout << "�ѳ�ʼ������" << std::endl;
	/*qgforwardlist.ShowMenu();*/
	int choice;
	int temp = 0;
	/*cout << "������ѡ��" << endl;
	cin >> choice;*/
	unsigned int index = 0;
	/*if (qgforwardlist.empty())
	{
		std::cout << "����Ϊ�գ��޷����в���" << endl;
	}*/
	while (true)
	{
		qgforwardlist.ShowMenu();
		std::cout << "������ѡ��" << std::endl;
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			qgforwardlist.~QGForwardList();
			std::cout << "���������٣�" << std::endl;
			break;
		case 1:
			qgforwardlist.creat();
			break;
		case 2:          //���ص�һ��Ԫ�ص�����
		{
			if (qgforwardlist.empty())
			{
				std::cout << "������Ԫ�أ�" << std::endl;
			}
			else
			{
				qgforwardlist.front(temp);
				std::cout << "��һ��Ԫ��Ϊ��" << qgforwardlist.front(temp) << std::endl;
			}
			break;
		}
		case 3:         //�������һ��Ԫ�ص�����
		{
			if (qgforwardlist.empty())
			{
				std::cout << "������Ԫ�أ�" << std::endl;
			}
			else
			{
				qgforwardlist.back(temp);
				std::cout << "���һ��Ԫ��Ϊ��" << qgforwardlist.back(temp) << std::endl;
			}
			break;
		}
		case 4:          //�������в���Ԫ��
		{
			int a;
			std::cout << "������Ҫ�����λ��" << std::endl;
			std::cin >> index;
			std::cout << "������Ҫ��������ݣ�" << std::endl;
			std::cin >> a;
			if (qgforwardlist.empty())
			{
				std::cout << "����Ϊ�գ��Ҳ�����λ��,Ĭ����β�ڵ��������\n";
				qgforwardlist.push_back(a);
			}
			else if (index == 0)
			{
				qgforwardlist.push_front(a);
				std::cout << "����ɹ���" << std::endl;
			}
			else if (index == -1) {
				qgforwardlist.push_back(a);
				std::cout << "����ɹ���" << std::endl;
			}
			else if (index<1 || index >(qgforwardlist.size() + 1)) {
				std::cout << "����λ������򲻴��ڣ�����ʧ�ܣ�" << std::endl;
			}
			else {
				qgforwardlist.insert(index, a);
				std::cout << "����ɹ���" << std::endl;
			}
			break;
		}
		case 5:          //ɾ�������е�Ԫ��
		{
			if (qgforwardlist.empty())
			{
				std::cout << "����Ϊ�գ��޷�ɾ����" << std::endl;
			}
			else
			{
				std::cout << "������Ҫɾ����λ��" << std::endl;
				std::cin >> index;
				if (index == 1)    //ͷɾ
				{
					qgforwardlist.pop_front();
					std::cout << "ɾ���ɹ���" << std::endl;
				}
				else if (index == qgforwardlist.size() && qgforwardlist.size() != 1)     //βɾ
				{
					qgforwardlist.pop_back();
					std::cout << "ɾ���ɹ���" << std::endl;
				}
				else if (index < 1 || (index > qgforwardlist.size()))
				{
					std::cout << "û�и�λ�ã�ɾ��ʧ�ܣ�" << std::endl;
				}
				else          //ɾ��
				{
					qgforwardlist.erase(index);
					std::cout << "ɾ���ɹ���" << std::endl;
				}
			}
			break;
		}
		case 6:          //����Ԫ���Ƿ����
		{
			int b;
			std::cout << "������Ԫ�أ�" << std::endl;
			std::cin >> b;
			qgforwardlist.contain(b);
			break;
		}
		case 7:          //������Ԫ������ 
			std::cout << "Ԫ������Ϊ��" << qgforwardlist.size() << std::endl;
			break;
		case 8:          //��������
		{
			if (qgforwardlist.empty())
			{
				std::cout << "����Ϊ��!" << std::endl;
			}
			else
			{
				qgforwardlist.traverse(Print);
			}
			break;
		}
		case 9:          //�������
			std::cout << "�Ƿ�ȷ����գ���պ��˳���������ϵͳ��" << std::endl << "1.ȷ��  2.ȡ��" << std::endl;
			int a;
			std::cin >> a;
			if (a == 1)
			{
				qgforwardlist.clear();
				std::cout << "��������գ�" << std::endl;
			}
			else if (a == 2)
			{
				std::cout << "ȡ����ճɹ���" << std::endl;
			}
			else
			{
				std::cout << "��������" << std::endl;
			}
			break;
		case 10:        //����ת
		{
			int a;
			std::cout << "���롮1��ѡ��ǵݹ鷴ת" << std::endl;
			std::cout << "���롮2��ѡ��ݹ鷴ת" << std::endl;
			std::cin >> a;
			std::cout << "��תǰΪ��" << std::endl;
			qgforwardlist.traverse(Print);
			std::cout << "��ת��Ϊ��" << std::endl;
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
				std::cout << "��������޷����з�ת" << std::endl;
			}
			break;
		}
		case 11:        //�����л�
		{
			bool ret = qgforwardlist.isLoop();
			if (ret == 1)
			{
				std::cout << "�������л���" << std::endl;
			}
			else
			{
				std::cout << "�������޻���" << std::endl;
			}
			break;
		}
		case 12:        //����ż�ڵ㷴ת 
		{

			if (qgforwardlist.empty())
			{
				std::cout << "�����������޷�����ż�ڵ㷴ת��" << std::endl;
			}
			else if (qgforwardlist.size() == 1)
			{
				std::cout << "����ֻ��һ���ڵ㣬�޷�����ż�ڵ㷴ת��" << std::endl;
			}
			else
			{
				qgforwardlist.reverseEven();
				std::cout << "��ת�ɹ���" << std::endl;
			}
			break;
		}
		case 13:        //�����м�ڵ�
			std::cout << "�м�ڵ�ֵΪ��" << qgforwardlist.middleElem() << std::endl;
			break;
		default:
			std::cout << "������������������" << std::endl;
		}
		std::system("pause");
		std::system("cls");
	}
	return 0;
}