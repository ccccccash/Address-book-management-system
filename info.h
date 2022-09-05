#include<iostream>
using namespace std;
#define max 1000

void showMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
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
		cout << "通讯录已满无法继续添加" << endl;
		return;
	}
	else
	{
		cout << "请输入姓名：" << endl;
		string name ;
		cin >> name;
		p->arr[p->m_size].name = name;

		cout << "请输入性别：" << endl;
		int gender;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				string sex = gender == 1 ? "男" : "女";
				p->arr[p->m_size].gender = sex;
				break;
			}
			else
			{
				cout << "输入错误请重新输入" << endl;
			}
		}
		
		cout << "请输入年龄：" << endl;
		int age = p->arr[p->m_size].age;
		cin >> age;
		p->arr[p->m_size].age = age;

		cout << "请输入电话：" << endl;
		string phone = p->arr[p->m_size].phone;
		cin >> phone;
		p->arr[p->m_size].phone = phone;


		cout << "请输入地址：" << endl;
		string adress = p->arr[p->m_size].adress;
		cin >> adress;
		p->arr[p->m_size].adress = adress;

		p->m_size++;
		cout << "添加完毕" << endl;
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
		cout << "记录为空" << endl;
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
	cout << "请输入您要删除的联系人：" << endl;
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
		cout << "删除成功"<<endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}

void findPerson(adressBooks* p)
{
	cout << "请输入您要修改的联系人" << endl;
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
		cout << "查无此人" << endl;
	}
}

void editPerson(adressBooks* p)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(p, name);
	if (ret != -1)
	{
		cout << "请输入姓名：" << endl;
		string name;
		cin >> name;
		p->arr[ret].name = name;

		cout << "请输入性别：" << endl;
		int gender;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		while (true)
		{
			cin >> gender;
			if (gender == 1 || gender == 2)
			{
				string sex = gender == 1 ? "男" : "女";
				p->arr[ret].gender = sex;
				break;
			}
			else
			{
				cout << "输入错误请重新输入" << endl;
			}
		}

		cout << "请输入年龄：" << endl;
		int age = p->arr[p->m_size].age;
		cin >> age;
		p->arr[ret].age = age;

		cout << "请输入电话：" << endl;
		string phone = p->arr[p->m_size].phone;
		cin >> phone;
		p->arr[ret].phone = phone;


		cout << "请输入地址：" << endl;
		string adress = p->arr[p->m_size].adress;
		cin >> adress;
		p->arr[ret].adress = adress;
	}
	else
	{
		cout << "查无此人" << endl;
	}
}

void clearAll(adressBooks* p)
{
	p->m_size = 0;
	cout << "联系人已清空" << endl;
}
