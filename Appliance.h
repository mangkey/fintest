#pragma once
#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include "input.h"
#include "SMSManager.h"
#include <fstream>
using namespace std;

extern int Totalpowerconsumption;

class Appliance
{
protected:
	string ApplianceName;
	int TurnOnOff;
	int state1;
	string name;
	int powerConsumption;
	time_t start_time = 0;
	time_t end_time = 0;
	time_t total_time = 0;
public:
	Appliance(int t=1, int s1=1, const string& s="", int power=0, const string& name ="")
		: TurnOnOff(t), state1(s1), name(s), powerConsumption(power), ApplianceName(name) {}
	
	string getName() { return name; }

	int getTotalpower() { return powerConsumption * total_time; }

	int getTurnOnOff() { return TurnOnOff; }

	void setTurnOnOff(int tmp) { TurnOnOff = tmp; }

	// 전원 상태 변경시 시작/종료/사용한 시간 데이터 입력
	void setTime(int gettime);

	// 프로그램 실행시 가전제품 기존 데이터 불러오기
	virtual void load(ifstream& prodListFile);

	// 프로그램 종료시 등록된 가전제품 데이터 저장하기
	virtual void save(ofstream& prodListFile);

	// 가전제품 타입별 제품 제어
	virtual void control() = 0;
	
	// 가전제품 타입별 상태 출력
	virtual void show() = 0;

	virtual ~Appliance() {}
};

class Aircon : public Appliance
{
	int state2;
public:
	Aircon(int t = 1, int s1 = 1, const string& s = "", int power = 0, const string& name = "AirConditioner", int s2 = 25)
		: Appliance(t, s1, s, power, name), state2(s2) {}

	void save(ofstream& prodListFile) override {
		Appliance::save(prodListFile);
		prodListFile << state2 << endl;
	}

	void load(ifstream& prodListFile) override {
		Appliance::load(prodListFile);
		prodListFile >> state2;
	}

	void show() override;

	void control() override;
};

class Ricecooker : public Appliance
{
public:
	Ricecooker(int t = 1, int s1 = 1, const string& s = "", int power = 0, const string& name = "RiceCooker")
		: Appliance(t, s1, s, power, name) {}

	void show() override;

	void control() override;
};

class Washer : public Appliance
{
public:
	Washer(int t = 1, int s1 = 1, const string& s = "", int power = 0, const string& name="Washer")
		: Appliance(t, s1, s, power, name) {}
	
	void show() override;

	void control() override;
};

class Light : public Appliance
{
public:
	Light(int t = 1, int s1 = 1, const string& s = "", int power = 0, const string& name = "Light")
		: Appliance(t, s1, s, power, name) {}
	void show() override;

	void control() override;
};