#pragma once
#include <iostream>
using namespace std;

// int형 입력 오류 해결
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
