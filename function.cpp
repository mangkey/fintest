#include "function.h"

// �ֻ�� mainMenu�� ���� ���ý� ����
void programStop(vector<vector<shared_ptr<Appliance>>>& prodList) {
	for (int i = 0; i < prodList.size(); i++) {
		for (int j = prodList[i].size() - 1; j >= 0; j--) {
			if (prodList[i][j]->getTurnOnOff() == 2)
			{
				prodList[i][j]->setTurnOnOff(1);
				prodList[i][j]->setTime(2);
			}
			Totalpowerconsumption += prodList[i][j]->getTotalpower();
			//prodList[i].erase(prodList[i].begin() + j);
		}
	}
	cout << "\n**********************************" << endl;
	cout << "������ǰ �� ���¼Ҹ� : " << Totalpowerconsumption << endl;
	cout << "**********************************\n" << endl;
	cout << "�� Ȩ�ɾ� �ý��� ���� (Press Enter) ";
	while (getchar() != '\n') {
		;
	}
}

// ������ǰ ��� �޴� ����
void addAppliance(vector<vector<shared_ptr<Appliance>>>& prodList) {
	while (1) {
		system("cls");
		cout << "\n**********************************" << endl;
		cout << "1. �ó���� (AirConditioner)\n2. ���     (RiceCooker)\n3. ��Ź��   (Washer)\n4. ����     (Light)\n5. ����\n";
		cout << "**********************************\n" << endl;
		cout << "�� ��ǰ Ÿ�� ���� : ";
		int typenum, flag, powernum;
		input::intinput(typenum);
		string prodname;
		if (typenum >= 1 && typenum <= 4) {
			cout << "\n�� ��ǰ�� �Է� (���� : 0) : ";
			do {
				flag = 0;
				cin >> prodname;
				if (getchar() != '\n') {
					cout << "�� [�Է¿���] ���Է� : ";
					flag = 1;
					while (getchar() != '\n') {
						;
					}
				}
				for (int i = 0; i < prodList[typenum - 1].size(); i++) {
					if (prodname == prodList[typenum - 1][i]->getName()) {
						cout << "�� [�ִ� ��ǰ��] ���Է� : ";
						flag = 1;
						break;
					}
				}
			} while (flag == 1);
			if (prodname == "0") continue;
			else {
				// Ÿ�Ժ� vector �ױ�
				cout << "\n�� �ð��� ���¼Ҹ� �Է� (���� : 0) : ";
				while (1) {
					input::intinput(powernum);
					if (powernum < 0 || powernum>10000) {
						cout << "�� [�Է¿���] ���Է� : ";
					}
					else break;
				}
				if (powernum == 0) continue;
				switch (typenum)
				{
				case 1:
					prodList[0].push_back(make_shared<Aircon>(1, 1, prodname, powernum));
					break;
				case 2:
					prodList[1].push_back(make_shared<Ricecooker>(1, 1, prodname, powernum));
					break;
				case 3:
					prodList[2].push_back(make_shared<Washer>(1, 1, prodname, powernum));
					break;
				case 4:
					prodList[3].push_back(make_shared<Light>(1, 1, prodname, powernum));
					break;
				}
			}
		}
		else if (typenum == 5) break;
	}
}

// ��ǰ ��ü ��� �޴� ����
void displayAppliance(vector<vector<shared_ptr<Appliance>>>& prodList) {
	while (1) {
		int flag = 0;
		for (int i = 0; i < prodList.size(); i++) {
			if (prodList[i].size() > 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			for (int i = 0; i < prodList.size(); i++) {
				for (int j = 0; j < prodList[i].size(); j++) {
					cout << "\n**********************************" << endl;
					prodList[i][j]->show();
					cout << "**********************************\n" << endl;
				}
			}
			cout << "�� Press Enter to continue... ";
		}
		else {
			cout << "�� ��ϵ� ��ǰ�� �����ϴ�. (Press Enter)";
		}
		while (getchar() != '\n') {
			;
		}
		break;
	}
}

// ������ǰ ����, ������ǰ ����/������ ��ǰ ���� �޴� ����
void controlAct(vector<vector<shared_ptr<Appliance>>>& prodList, int actionnum) {
	while (1) {
		int flag = 0;
		for (int i = 0; i < prodList.size(); i++) {
			if (prodList[i].size() > 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "�� ��ϵ� ��ǰ�� �����ϴ�. (Press Enter)";
			while (getchar() != '\n') {
				;
			}
			break;
		}
		system("cls");
		cout << "\n**********************************" << endl;
		cout << "1. �ó���� (AirConditioner)\n2. ��� (RiceCooker)\n3. ��Ź�� (Washer)\n4. ���� (Light)\n5. ����\n";
		cout << "**********************************\n" << endl;
		cout << "�� ��ǰ Ÿ�� ���� : ";
		int typenum, namenum;
		input::intinput(typenum);
		if (typenum >= 1 && typenum <= 4) {
			if (prodList[typenum - 1].size() <= 0) {
				cout << "�� ��ϵ� ��ǰ�� �����ϴ�. (Press Enter)";
				while (getchar() != '\n') {
					;
				}
				continue;
			}
			else {
				while (1) {
					cout << "\n**********************************" << endl;
					for (int i = 0; i < prodList[typenum - 1].size(); i++) {
						cout << i + 1 << ". " << prodList[typenum - 1][i]->getName() << endl;
					}
					cout << prodList[typenum - 1].size() + 1 << ". ����" << endl;
					cout << "**********************************\n" << endl;
					cout << "�� ��ǰ�� ���� : ";
					input::intinput(namenum);
					if (namenum == prodList[typenum - 1].size() + 1) break;
					else if (namenum > 0 && namenum <= prodList[typenum - 1].size()) {
						// ���� ����
						switch (actionnum)
						{
						case 1:
							cout << "\n**********************************" << endl;
							prodList[typenum - 1][namenum - 1]->show();
							cout << "**********************************\n" << endl;
							cout << "�� Press Enter to continue... ";
							while (getchar() != '\n') {
								;
							}
							break;
						case 2:
							prodList[typenum - 1][namenum - 1]->control();
							break;
						case 3:
							if (prodList[typenum - 1][namenum - 1]->getTurnOnOff() == 2)
							{
								prodList[typenum - 1][namenum - 1]->setTurnOnOff(1);
								prodList[typenum - 1][namenum - 1]->setTime(2);
							}
							Totalpowerconsumption += prodList[typenum - 1][namenum - 1]->getTotalpower();
							prodList[typenum - 1].erase(prodList[typenum - 1].begin() + namenum - 1);
							break;
						default:
							break;
						}
					}

				}
			}
		}
		else if (typenum == 5) break;
	}
}

// ��ü ��ǰ ON/OFF �޴� ����
void integTurn(vector<vector<shared_ptr<Appliance>>>& prodList) {
	while (1) {
		int flag = 0;
		for (int i = 0; i < prodList.size(); i++) {
			if (prodList[i].size() > 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << "�� ��ϵ� ��ǰ�� �����ϴ�. (Press Enter)";
			while (getchar() != '\n') {
				;
			}
			break;
		}
		system("cls");
		int tmp;
		cout << "\n**********************************" << endl;
		cout << "1. ��ü OFF \n2. ��ü ON\n3. ����\n";
		cout << "**********************************\n" << endl;
		cout << "�� �ɼ� ���� : ";
		input::intinput(tmp);
		if (tmp == 1 || tmp == 2) {
			for (int i = 0; i < prodList.size(); i++) {
				for (int j = 0; j < prodList[i].size(); j++) {
					int time = prodList[i][j]->getTurnOnOff();
					prodList[i][j]->setTurnOnOff(tmp);
					prodList[i][j]->setTime(time);
				}
			}
			break;
		}
		else if (tmp == 3) break;
	}
}

// ��ȭ��ȣ ��� �޴� ����
void registerPhone() {
	while (1) {
		system("cls");
		cout << "\n**********************************" << endl;
		cout << "1. �ó���� (AirConditioner)\n2. ��� (RiceCooker)\n3. ��Ź�� (Washer)\n4. ���� (Light)\n5. ����\n";
		cout << "**********************************\n" << endl;
		cout << "�� ��ǰ Ÿ�� ���� : ";
		int typenum, phonenum;
		input::intinput(typenum);
		string Appliancename;
		if (typenum >= 1 && typenum <= 4) {
			switch (typenum)
			{
			case 1:
				Appliancename = "AirConditioner";
				break;
			case 2:
				Appliancename = "RiceCooker";
				break;
			case 3:
				Appliancename = "Washer";
				break;
			case 4:
				Appliancename = "Light";
				break;
			}
			cout << "�� ��ȭ��ȣ 10 �ڸ� �Է� (+82) XX-XXXX-XXXX : ";
			while (1) {
				input::intinput(phonenum);
				if (phonenum >= 1000000000 && phonenum <= 2000000000) break;
				else cout << "�� [�Է¿���] ���Է� : ";
			}
			sms.add_sms_number(Appliancename, to_string(phonenum));
		}
		else if (typenum == 5) break;
	}
}