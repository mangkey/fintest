#include "menu.h"

// �ֻ�� mainMenu ���� ���� mainMenu ���� �����Ͽ�
// title ��� �� ����� subMenu command �Լ� ����
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
			cout << "�� ���Ͻô� �޴��� �����ϼ��� : ";
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
			cout << v.size() + 1 << ". ����" << endl;
			cout << "**********************************\n" << endl;;
			cout << "�� ���Ͻô� �޴��� �����ϼ��� : ";
			input::intinput(tmp);
			if (tmp >= 1 && tmp <= v.size()) {
				v[tmp - 1]->command();
			}
			else if (tmp == v.size() + 1) break;
		}
	}
}