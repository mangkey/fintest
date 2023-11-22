#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Appliance.h"
#include <functional>
#include "function.h"

using namespace std::placeholders;
using namespace std;

class baseHomeIoT {
	string title;

public:
	baseHomeIoT(const string& s) : title(s) {}

	string getTitle() { return title; }

	virtual void command() = 0;

	virtual ~baseHomeIoT() {}
};

class mainMenu : public baseHomeIoT
{
	// mainMenu, subMenu Ŭ���� �����͸� ���� 1���� ����
	vector<shared_ptr<baseHomeIoT>> v;
public:
	mainMenu(const string& s) : baseHomeIoT(s) {}

	void add(shared_ptr<baseHomeIoT> c) { v.push_back(c); }

	// mainMenu�� �Ҵ��� Ŭ������ title ��� �� title�� �����(subMenu) �Լ� ����
	void command() override;
		
};

class subMenu : public baseHomeIoT
{
	function<void()> handler;
public:
	subMenu(const string& s = "x", function<void()> h = nullptr) : baseHomeIoT(s), handler(h) {}

	// subMenu Ŭ���� �Ҵ�� �Է��� �Լ� ����
	void command() override{
		if(handler != nullptr)
			handler();
	}
};
