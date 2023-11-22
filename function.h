#pragma once
#include <iostream>
#include <vector>
#include "Appliance.h"
#include <memory>
using namespace std;

// �ֻ�� mainMenu�� ���� �޴� ����
void programStop(vector<vector<shared_ptr<Appliance>>>& prodList);

// ������ǰ ��� �޴� ����
void addAppliance(vector<vector<shared_ptr<Appliance>>>& prodList);

// ��ǰ ��ü ��� �޴� ����
void displayAppliance(vector<vector<shared_ptr<Appliance>>>& prodList);

// ������ǰ ����, ������ǰ ����/������ ��ǰ ���� �޴� ����
void controlAct(vector<vector<shared_ptr<Appliance>>>& prodList, int actionnum);

// ��ü ��ǰ ON/OFF �޴� ����
void integTurn(vector<vector<shared_ptr<Appliance>>>& prodList);

// ��ȭ��ȣ ��� �޴� ����
void registerPhone();
