#pragma once
#include <iostream>
#include <vector>
#include "Appliance.h"
#include <memory>
using namespace std;

// 최상단 mainMenu의 종료 메뉴 동작
void programStop(vector<vector<shared_ptr<Appliance>>>& prodList);

// 가전제품 등록 메뉴 동작
void addAppliance(vector<vector<shared_ptr<Appliance>>>& prodList);

// 제품 전체 출력 메뉴 동작
void displayAppliance(vector<vector<shared_ptr<Appliance>>>& prodList);

// 가전제품 삭제, 가전제품 상태/제어의 제품 선텍 메뉴 동작
void controlAct(vector<vector<shared_ptr<Appliance>>>& prodList, int actionnum);

// 전체 제품 ON/OFF 메뉴 동작
void integTurn(vector<vector<shared_ptr<Appliance>>>& prodList);

// 전화번호 등록 메뉴 동작
void registerPhone();
