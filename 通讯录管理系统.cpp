#include "info.h"

int main()
{
	adressBooks t;
	t.m_size = 0;
	int select = 0;
	while (true)
	{
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&t);
			break;
		case 2:
			showlist(&t);
			break;
		case 3:
			deletePerson(&t);
			break;
		case 4:
			findPerson(&t);
			break;
		case 5:
			editPerson(&t);
			break;
		case 6:
			clearAll(&t);
			break;
		case 0:
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		}
	}
	system("pause");
	return 0;
}