#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// Callback 동작
class SMSManager
{
	using PHONENUMBER = string;
	map<string, vector<PHONENUMBER>> m;
public:
	// 등록된 map 확인용
	const map<string, vector<PHONENUMBER>>& getmap() const { return m; }
	
	// key : Appliancename 저장
	// number : 메세지 전달할 전화번호 저장
	void add_sms_number(const string& key, const PHONENUMBER& number)
	{
		m[key].push_back(number);
	}

	// key : Appliancename (가전제품 타입 이름)
	// name : 가전제품 등록시 입력한 고유 이름
	void send_sms(const string& key, const string& name);
	
};

extern SMSManager sms;
