#include "function.h"

// 최상단 mainMenu의 종료 선택시 동작
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
	cout << "가전제품 총 전력소모량 : " << Totalpowerconsumption << endl;
	cout << "**********************************\n" << endl;
	cout << "▷ 홈케어 시스템 종료 (Press Enter) ";
	while (getchar() != '\n') {
		;
	}
}

// 가전제품 등록 메뉴 동작
void addAppliance(vector<vector<shared_ptr<Appliance>>>& prodList) {
	while (1) {
		system("cls");
		cout << "\n**********************************" << endl;
		cout << "1. 냉난방기 (AirConditioner)\n2. 밥솥     (RiceCooker)\n3. 세탁기   (Washer)\n4. 전등     (Light)\n5. 종료\n";
		cout << "**********************************\n" << endl;
		cout << "▶ 제품 타입 선택 : ";
		int typenum, flag, powernum;
		input::intinput(typenum);
		string prodname;
		if (typenum >= 1 && typenum <= 4) {
			cout << "\n▶ 제품명 입력 (종료 : 0) : ";
			do {
				flag = 0;
				cin >> prodname;
				if (getchar() != '\n') {
					cout << "▷ [입력오류] 재입력 : ";
					flag = 1;
					while (getchar() != '\n') {
						;
					}
				}
				for (int i = 0; i < prodList[typenum - 1].size(); i++) {
					if (prodname == prodList[typenum - 1][i]->getName()) {
						cout << "▷ [있는 제품명] 재입력 : ";
						flag = 1;
						break;
					}
				}
			} while (flag == 1);
			if (prodname == "0") continue;
			else {
				// 타입별 vector 쌓기
				cout << "\n▶ 시간당 전력소모량 입력 (종료 : 0) : ";
				while (1) {
					input::intinput(powernum);
					if (powernum < 0 || powernum>10000) {
						cout << "▷ [입력오류] 재입력 : ";
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

// 제품 전체 출력 메뉴 동작
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
			cout << "▷ Press Enter to continue... ";
		}
		else {
			cout << "▷ 등록된 제품이 없습니다. (Press Enter)";
		}
		while (getchar() != '\n') {
			;
		}
		break;
	}
}

// 가전제품 삭제, 가전제품 상태/제어의 제품 선텍 메뉴 동작
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
			cout << "▷ 등록된 제품이 없습니다. (Press Enter)";
			while (getchar() != '\n') {
				;
			}
			break;
		}
		system("cls");
		cout << "\n**********************************" << endl;
		cout << "1. 냉난방기 (AirConditioner)\n2. 밥솥 (RiceCooker)\n3. 세탁기 (Washer)\n4. 전등 (Light)\n5. 종료\n";
		cout << "**********************************\n" << endl;
		cout << "▶ 제품 타입 선택 : ";
		int typenum, namenum;
		input::intinput(typenum);
		if (typenum >= 1 && typenum <= 4) {
			if (prodList[typenum - 1].size() <= 0) {
				cout << "▷ 등록된 제품이 없습니다. (Press Enter)";
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
					cout << prodList[typenum - 1].size() + 1 << ". 종료" << endl;
					cout << "**********************************\n" << endl;
					cout << "▶ 제품명 선택 : ";
					input::intinput(namenum);
					if (namenum == prodList[typenum - 1].size() + 1) break;
					else if (namenum > 0 && namenum <= prodList[typenum - 1].size()) {
						// 동작 구분
						switch (actionnum)
						{
						case 1:
							cout << "\n**********************************" << endl;
							prodList[typenum - 1][namenum - 1]->show();
							cout << "**********************************\n" << endl;
							cout << "▷ Press Enter to continue... ";
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

// 전체 제품 ON/OFF 메뉴 동작
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
			cout << "▷ 등록된 제품이 없습니다. (Press Enter)";
			while (getchar() != '\n') {
				;
			}
			break;
		}
		system("cls");
		int tmp;
		cout << "\n**********************************" << endl;
		cout << "1. 전체 OFF \n2. 전체 ON\n3. 종료\n";
		cout << "**********************************\n" << endl;
		cout << "▶ 옵션 선택 : ";
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

// 전화번호 등록 메뉴 동작
void registerPhone() {
	while (1) {
		system("cls");
		cout << "\n**********************************" << endl;
		cout << "1. 냉난방기 (AirConditioner)\n2. 밥솥 (RiceCooker)\n3. 세탁기 (Washer)\n4. 전등 (Light)\n5. 종료\n";
		cout << "**********************************\n" << endl;
		cout << "▶ 제품 타입 선택 : ";
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
			cout << "▶ 전화번호 10 자리 입력 (+82) XX-XXXX-XXXX : ";
			while (1) {
				input::intinput(phonenum);
				if (phonenum >= 1000000000 && phonenum <= 2000000000) break;
				else cout << "▷ [입력오류] 재입력 : ";
			}
			sms.add_sms_number(Appliancename, to_string(phonenum));
		}
		else if (typenum == 5) break;
	}
}