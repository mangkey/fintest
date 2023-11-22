#pragma once
#include "SMSManager.h"

SMSManager sms;

/*--------------------------------------------------------------------------------
Appliancename(key)에 있는 특정 제품 ON 시
Appliancename에 연결된 전화번호(number)로 메세지 전달
ex) 냉난방기(key)에 삼성, 엘지(name) 라는 제품이 등록되어있고
삼성(name) 제품이 ON되면 냉난방기에 연결된 전화번호(number)로 메세지 전달
--------------------------------------------------------------------------------*/
void SMSManager::send_sms(const string& key, const string& name)
{
	auto& v = m[key];
	int i = 0;
	cout << "\n**********************************" << endl;
	for (const PHONENUMBER& number : v)
	{
		cout << "0" << number.substr(0, 2) << "-" << number.substr(2, 4) << "-" << number.substr(6, 4) << endl;
	}
	cout << name << " (" << key << ") ON 메세지 전달 완료" << endl;
	cout << "**********************************\n" << endl;
	cout << "▷ Press Enter to continue... ";
	while (getchar() != '\n') {
		;
	}
}