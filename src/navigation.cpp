#include "navigation.h"

void menu()
{
	if (authStatChk())
	{
		menuAuth();
		return;
	}
	system("cls");
	cout << "����� ���������� � ���������� ���!\n��� ��������� � �������� ��������� ���������� ����� ��� ������������������. " << endl;
	cout << "�������� ��������:\n 1 - ����������� ������������ \n 2 - ����������� \n 3 - ������ ������������� \n 4 - ����� �� ���������" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
	{
		incorrect();
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		menuRegUser();
		break;
	}
	case 2:
	{
		menuLogin();
		break;
	}
	case 3:
	{
		menuUserList();
		break;
	}
	case 4:
	{
		exit();
		break;
	}
	default:
		break;
	}
}

void menuRegUser()
{
	string name, login, pwd;
	system("cls");
	cout << "������� ��� ������������:" << endl;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, name);
	cout << "������� ����� ������������:" << endl;
	getline(cin, login);
	while (!regLoginChk(login))
	{
		getline(cin, login);
	}
	cout << "������� �������� ������:" << endl;
	getline(cin, pwd);
	while (!regPwdChk(pwd))
	{
		getline(cin, pwd);
	}
	Users->addUsers(name, login, pwd);
	cout << "������������ " << name << " ������� ���������������. \n 1 - ������� ���� 2 - �����������" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		incorrect();
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		if (auth && userId == 0)
		{
			menuAuth();
			break;
		}
		else
		{
			menu();
			break;
		}
		break;
	}
	case 2:
	{
		menuLogin();
		break;
	}
	default:
		break;
	}
}

void menuLogin()
{
	string name, login, pwd;
	system("cls");
	cout << "���� ��� ������������������ �������������" << endl;
	cout << "������� �����:" << endl;
	inputCleaner();
	getline(cin, login);
	if (Users->loginCheck(login))
	{
		cout << "������� ������:" << endl;
		getline(cin, pwd);
		while (!authPwdChk(login, pwd))
		{
			cout << "�������� ������, ���������:" << endl;
			getline(cin, pwd);
		}
		if (authPwdChk(login, pwd))
		{
			auth = true;
			userId = Users->getUserId(login);
			menuAuth();
		}
	}
	else
	{
		cout << "�������� ��� ������������" << endl;
		cout << "1 - ��������� � ������� ����, 2 - ����� �� ���������, 3 - ���������" << endl;
		cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3)
		{
			incorrect();
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			menu();
			break;
		}
		case 2:
		{
			exit();
			break;
		}
		case 3:
		{
			menuLogin();
			break;
		}
		default:
			break;
		}
	}
}

void menuUserList()
{
	system("cls");
	Users->showUsers();
	cout << "1 - ��������� � ������� ����, 2 - ����� �� ���������";
	if (authStatChk())
		cout << " 3 - �������� ���������";
	cout << endl;

	cin >> choice;
	if (authStatChk())
	{
		while (choice != 1 && choice != 2 && choice != 3)
		{
			incorrect();
			cin >> choice;
		}
	}
	else
	{
		while (choice != 1 && choice != 2)
		{
			incorrect();
			cin >> choice;
		}
	}
	switch (choice)
	{
	case 1:
	{
		if (authStatChk())
		{
			menuAuth();
		}
		else
		{
			menu();
		}
		break;
	}
	case 2:
	{
		exit();
		break;
	}
	case 3:
	{
		menuPrivateSendMsg();
		break;
	}
	default:
		break;
	}
}

void menuUserMgmt()
{
	if (!authAdminStatChk())
	{
		menuAuth();
		return;
	}
	system("cls");
	cout << "���������� ��������������. \n";
	Users->showUsers();
	cout << "\n �������� ��������: \n 1 - �������� ������������ \n 2 - ������� ������������ \n 3 - ������� ������ ������������ \n 4 - ������� ����" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
	{
		incorrect();
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		menuRegUser();
		break;
	}
	case 2:
	{
		menuDelUser();
		break;
	}
	case 3:
	{
		menuUsrMgmtSetPwd();
		break;
	}
	case 4:
	{
		menuAuth();
		break;
	}
	default:
		break;
	}
}

void chkUsersAv()
{
	if (Users->getUserCount() <= 1)
	{
		cout << "��� ��������� ��� ���������� �������������. ����������? \n 1 - �� 2 - ���" << endl;
		cin >> choice;
		while (choice != 1 && choice != 2)
		{
			incorrect();
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			menuUserMgmt();
			break;
		}
		case 2:
		{
			menuAuth();
			break;
		}
		default:
			break;
		}
	}
}

void menuDelUser()
{
	if (!authAdminStatChk())
	{
		menuAuth();
		return;
	}
	if (Users->getUserCount() > 1)
	{
		cout << "������� ������ \"�������������\" ������� ������. ��� �������� ������������ ������� ��� ID : " << endl;
		cin >> choice;
		while (choice <= 0 || choice >= Users->getUserCount())
		{
			incorrect();
			cin >> choice;
		}
		cout << "�� ������� ��� ������ ������� " << Users->getUserName(choice) << "? \n 1 - ��, 2 - ���" << endl;
		int temp;
		cin >> temp;
		while (temp != 1 && temp != 2)
		{
			incorrect();
			cin >> temp;
		}
		switch (temp)
		{
		case 1:
		{
			string curUser = Users->getUserName(userId);
			Users->delUser(choice);
			if (choice < userId)
			{
				userId = Users->getUserId(curUser);
			}
			menuUserMgmt();
			break;
		}
		case 2:
		{
			menuUserMgmt();
			break;
		}
		default:
			break;
		}
	}
	else
	{
		chkUsersAv();
	}
}

void menuUsrMgmtSetPwd()
{
	if (Users->getUserCount() > 1)
	{
		cout << "�������� ������ ������� ������ \"�������������\" ������. ��� ��������� ������ ������������ ������� ��� ID : " << endl;
		cin >> choice;
		while (choice <= 0 || choice >= Users->getUserCount())
		{
			incorrect();
			cin >> choice;
		}
		menuChgPwd(choice);
	}
	else
	{
		chkUsersAv();
	}
}

void menuChgPwd(int choice = userId)
{
	string pwd;
	cout << "������� ����� ������:" << endl;
	inputCleaner();
	getline(cin, pwd);
	while (!regPwdChk(pwd))
	{
		getline(cin, pwd);
	}
	Users->chgPwd(choice, pwd);
	cout << "������ ������������ " << Users->getUserName(choice) << " ������� �������. ������� 1 ����� ����������, 2 ����� ����� �� ���������" << endl;
	cin >> choice;
	while (choice != 1 && choice != 2)
	{
		incorrect();
		cin >> choice;
	}
	switch (choice)
	{
		case 1:
		{
			if(userId == 0)
				menuUserMgmt();
			if (userId > 0)
				menuAuth();
			break;
		}
		case 2:
		{
			exit();
			break;
		}
		default:
			break;
	}
}

void menuAuth()
{
	if (!authStatChk)
	{
		menu();
		return;
	}
	system("cls");
	cout << Users->getUserName(userId) << " ����� ���������� � ���������� ���!" << endl;
	cout << "�������� ��������:\n 1 - ����� �� ��������� \n 2 - ����� �� ������� ������ \n 3 - ����� ��� \n 4 - ������ ���������" << endl;
	if (userId == 0)
	{
		cout << " 5 - ���������� ��������������" << endl;
	}
	else if (userId > 0)
	{
		cout << " 5 - �������� ������" << endl;
	}
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
	{
		incorrect();
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
	{
		exit();
		break;
	}
	case 2:
	{
		logOut();
		menu();
		break;
	}
	case 3:
	{
		menuMainChat();
		break;
	}
	case 4:
	{
		menuUserList();
		break;
	}
	case 5:
	{
		if (userId == 0)
		{
			menuUserMgmt();
			break;
		}
		else if (userId > 0)
		{
			menuChgPwd();
			break;
		}
	}
	default:
		break;
	}
}

void menuPrivateSendMsg()
{
	if (!authStatChk())
	{
		menu();
		return;
	}
	int temp;
	cout << "������� ID ������������:" << endl;
	cin >> temp;
	while (cin.fail() || temp < 0 || temp >= Users->getUserCount())
	{
		incorrect();
		cin >> temp;
	}
	while (choice == 3)
	{
		system("cls");
		mainChat->showPersonal(Users->getUserName(userId), Users->getUserName(temp));
		cout << "1 - ��������� � ������� ����, 2 - ����� �� ��������� 3 - �������� ��������� 4 - ��������� � ������ �������������" << endl;
		cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
		{
			incorrect();
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			menuAuth();
			break;
		}
		case 2:
		{
			exit();
			break;
		}
		case 3:
		{
			cout << "������� ���������:" << endl;
			string msgText;
			inputCleaner();
			getline(cin, msgText);
			mainChat->sendMsg(Users->getUserName(temp), Users->getUserName(userId), msgText);
			break;
		}
		case 4:
		{
			menuUserList();
			break;
		}
		default:
			break;
		}
	}
}

void menuMainChat()
{
	if (!authStatChk())
	{
		menu();
		return;
	}
	while (choice == 3)
	{
		system("cls");
		mainChat->showMain();
		cout << "1 - ��������� � ������� ����, 2 - ����� �� ��������� 3 - ��������� ���������" << endl;
		cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3)
		{
			incorrect();
			cin >> choice;
		}
		switch (choice)
		{
		case 1:
		{
			menuAuth();
			break;
		}
		case 2:
		{
			exit();
			break;
		}
		case 3:
		{
			cout << "������� ���������:" << endl;
			string msgText;
			inputCleaner();
			getline(cin, msgText);
			mainChat->sendMsg("ALL", Users->getUserName(userId), msgText);
			break;
		}
		default:
			break;
		}
	}
}