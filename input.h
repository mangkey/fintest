#pragma once
#include <iostream>
using namespace std;

// int�� �Է� ���� �ذ�
class input {
public:
	static void intinput(int& tmp) {
		cin >> tmp;
		if (cin.fail() || getchar() != '\n') {
			cin.clear();
			while (getchar() != '\n') {
				;
			}
			tmp = -1;
		}
	}
};
