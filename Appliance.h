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

	// ���� ���� ����� ����/����/����� �ð� ������ �Է�
	void setTime(int gettime);

	// ���α׷� ����� ������ǰ ���� ������ �ҷ�����
	virtual void load(ifstream& prodListFile);

	// ���α׷� ����� ��ϵ� ������ǰ ������ �����ϱ�
	virtual void save(ofstream& prodListFile);

	// ������ǰ Ÿ�Ժ� ��ǰ ����
	virtual void control() = 0;
	
	// ������ǰ Ÿ�Ժ� ���� ���
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