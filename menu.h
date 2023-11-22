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
	// mainMenu, subMenu 클래스 포인터를 담을 1차원 벡터
	vector<shared_ptr<baseHomeIoT>> v;
public:
	mainMenu(const string& s) : baseHomeIoT(s) {}

	void add(shared_ptr<baseHomeIoT> c) { v.push_back(c); }

	// mainMenu로 할당한 클래스의 title 출력 및 title에 연결된(subMenu) 함수 동작
	void command() override;
		
};

class subMenu : public baseHomeIoT
{
	function<void()> handler;
public:
	subMenu(const string& s = "x", function<void()> h = nullptr) : baseHomeIoT(s), handler(h) {}

	// subMenu 클래스 할당시 입력한 함수 동작
	void command() override{
		if(handler != nullptr)
			handler();
	}
};
