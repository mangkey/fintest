#pragma once
#include "SMSManager.h"

SMSManager sms;

/*--------------------------------------------------------------------------------
Appliancename(key)�� �ִ� Ư�� ��ǰ ON ��
Appliancename�� ����� ��ȭ��ȣ(number)�� �޼��� ����
ex) �ó����(key)�� �Ｚ, ����(name) ��� ��ǰ�� ��ϵǾ��ְ�
�Ｚ(name) ��ǰ�� ON�Ǹ� �ó���⿡ ����� ��ȭ��ȣ(number)�� �޼��� ����
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
	cout << name << " (" << key << ") ON �޼��� ���� �Ϸ�" << endl;
	cout << "**********************************\n" << endl;
	cout << "�� Press Enter to continue... ";
	while (getchar() != '\n') {
		;
	}
}