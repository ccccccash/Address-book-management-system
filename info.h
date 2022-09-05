#include<iostream>
using namespace std;
#define max 1000

void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

struct person
{
	string name;
	string gender;
	int age =0;
	string phone;
	string adress;

};

struct adressBooks
{ 
	struct person* arr = NULL ;
	int m_size=0;
};

void addperson(adressBooks *p)
{
	if (p->m_size == max)
	{
		cout << "ͨѶ¼�����޷��������" << endl;
		return;
	}
	else
	{
		cout << "������������" << endl;
		string name ;
		cin >> name;
		p->arr[p->m_size].name = name;

		cout << "�������Ա�" << endl;
		int gender;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				string sex = gender == 1 ? "��" : "Ů";
				p->arr[p->m_size].gender = sex;
				break;
			}
			else
			{
				cout << "�����������������" << endl;
			}
		}
		
		cout << "���������䣺" << endl;
		int age = p->arr[p->m_size].age;
		cin >> age;
		p->arr[p->m_size].age = age;

		cout << "������绰��" << endl;
		string phone = p->arr[p->m_size].phone;
		cin >> phone;
		p->arr[p->m_size].phone = phone;


		cout << "�������ַ��" << endl;
		string adress = p->arr[p->m_size].adress;
		cin >> adress;
		p->arr[p->m_size].adress = adress;

		p->m_size++;
		cout << "������" << endl;
		system("pause");
		system("cls");
	}
}

void showlist(adressBooks *p)
{
	if (p->m_size != 0)
	{
		for (int i = 0; i < p->m_size; i++)
		{
			cout << p->arr[i].name << "\t"
				<< p->arr[i].gender << "\t"
				<< p->arr[i].age << "\t"
				<< p->arr[i].phone << "\t"
				<< p->arr[i].adress<<endl;
		}
	}
	else
	{
		cout << "��¼Ϊ��" << endl;
	}
	system("pause");
	system("cls");
}

int isExist(adressBooks* p,string name)
{
	for (int i = 0; i <= p->m_size; i++)
	{
		if (p->arr[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(adressBooks * p)
{
	cout << "��������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	int ret = isExist(p, name);
	if (ret != -1)
	{
		for (int i = ret; i < p->m_size; i++)
		{
			p->arr[i] = p->arr[i + 1];
		}
		p->m_size--;
		cout << "ɾ���ɹ�"<<endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
}

void findPerson(adressBooks* p)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(p, name);
	if (ret != -1)
	{
		cout << p->arr[ret].name << "\t"
			<< p->arr[ret].gender << "\t"
			<< p->arr[ret].age << "\t"
			<< p->arr[ret].phone << "\t"
			<< p->arr[ret].adress << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
}

void editPerson(adressBooks* p)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(p, name);
	if (ret != -1)
	{
		cout << "������������" << endl;
		string name;
		cin >> name;
		p->arr[ret].name = name;

		cout << "�������Ա�" << endl;
		int gender;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				string sex = gender == 1 ? "��" : "Ů";
				p->arr[ret].gender = sex;
				break;
			}
			else
			{
				cout << "�����������������" << endl;
			}
		}

		cout << "���������䣺" << endl;
		int age = p->arr[p->m_size].age;
		cin >> age;
		p->arr[ret].age = age;

		cout << "������绰��" << endl;
		string phone = p->arr[p->m_size].phone;
		cin >> phone;
		p->arr[ret].phone = phone;


		cout << "�������ַ��" << endl;
		string adress = p->arr[p->m_size].adress;
		cin >> adress;
		p->arr[ret].adress = adress;
	}
	else
	{
		cout << "���޴���" << endl;
	}
}

void clearAll(adressBooks* p)
{
	p->m_size = 0;
	cout << "��ϵ�������" << endl;
}
