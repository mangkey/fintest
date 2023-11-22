#include "menu.h"

// 최상단 mainMenu 인지 하위 mainMenu 인지 구별하여
// title 출력 및 연결된 subMenu command 함수 동작
void mainMenu::command() {
	while (1) {
		system("cls");
		if (getTitle() == "root") {
			int tmp = 0;
			cout << "\n**********************************" << endl;
			for (int i = 0; i < v.size(); i++) {
				cout << i + 1 << ". " << v[i]->getTitle() << endl;
			}
			cout << "**********************************\n" << endl;;
			cout << "▶ 원하시는 메뉴를 선택하세요 : ";
			input::intinput(tmp);
			if (tmp >= 1 && tmp <= v.size()) {
				v[tmp - 1]->command();
				if (tmp == v.size()) break;
			}
		}
		else {
			int tmp = 0;
			cout << "\n**********************************" << endl;
			for (int i = 0; i < v.size(); i++) {
				cout << i + 1 << ". " << v[i]->getTitle() << endl;
			}
			cout << v.size() + 1 << ". 종료" << endl;
			cout << "**********************************\n" << endl;;
			cout << "▶ 원하시는 메뉴를 선택하세요 : ";
			input::intinput(tmp);
			if (tmp >= 1 && tmp <= v.size()) {
				v[tmp - 1]->command();
			}
			else if (tmp == v.size() + 1) break;
		}
	}
}