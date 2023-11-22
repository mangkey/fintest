#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// Callback ����
class SMSManager
{
	using PHONENUMBER = string;
	map<string, vector<PHONENUMBER>> m;
public:
	// ��ϵ� map Ȯ�ο�
	const map<string, vector<PHONENUMBER>>& getmap() const { return m; }
	
	// key : Appliancename ����
	// number : �޼��� ������ ��ȭ��ȣ ����
	void add_sms_number(const string& key, const PHONENUMBER& number)
	{
		m[key].push_back(number);
	}

	// key : Appliancename (������ǰ Ÿ�� �̸�)
	// name : ������ǰ ��Ͻ� �Է��� ���� �̸�
	void send_sms(const string& key, const string& name);
	
};

extern SMSManager sms;
