#include "Fileio.h"

/*--------------------------------------------------------------------------------
 Fileio Ŭ���� ������
 ���α׷� ���� �� ���� ������ ������ �ҷ�����
 �ҷ��� ������ : ������ǰ ������, ��ȭ��ȣ ���, ������ǰ �� ���¼Ҹ�
 --------------------------------------------------------------------------------*/
Fileio::Fileio() {
    
    // ������ǰ ������, ������ǰ �� ���¼Ҹ� ��������
    ifstream prodListFile("prodList.txt");
    if (prodListFile.is_open()) {
        int tmp, i = 0;
        prodListFile >> Totalpowerconsumption;
        while (i < prodList.size()) {
            prodListFile >> tmp;
            for (int j = 0; j < tmp; j++) {
                switch (i + 1)
                {
                case 1:
                    prodList[0].push_back(make_shared<Aircon>());
                    break;
                case 2:
                    prodList[1].push_back(make_shared<Ricecooker>());
                    break;
                case 3:
                    prodList[2].push_back(make_shared<Washer>());
                    break;
                case 4:
                    prodList[3].push_back(make_shared<Light>());
                    break;
                }
                prodList[i][j]->load(prodListFile);
            }
            i++;
        }
        prodListFile.close();
    }

    // ��ȭ��ȣ ��� �ҷ�����
    ifstream phoneFile("phone.txt");
    if (phoneFile.is_open()) {
        int tmp;
        string strkey, strnumber;
        phoneFile >> strkey;
        while (strkey != "end") {
            phoneFile >> tmp;
            for (int i = 0; i < tmp; i++) {
                phoneFile >> strnumber;
                sms.add_sms_number(strkey, strnumber);
            }
            phoneFile >> strkey;
        }
        phoneFile.close();
    }
}

/*--------------------------------------------------------------------------------
 Fileio Ŭ���� �Ҹ���
 ���α׷� ���� �� ��ϵ� �����͸� ���Ͽ� ���� �� ���� ������ �����Ͽ� ����
 ������ ������ : ������ǰ ������ (������ǰ Ÿ��, ��ǰ ����, ��ǰ �̸�, ���¼Ҹ�),
                 ��ȭ��ȣ ���, ������ǰ �� ���¼Ҹ�
--------------------------------------------------------------------------------*/
Fileio::~Fileio() {

    // ����� �����ִ� ������ǰ ������ ����
    ofstream prodListFile("prodList.txt");
    if (prodListFile.is_open()) {
        prodListFile << Totalpowerconsumption << endl;
        for (const auto& typeList : prodList) {
            prodListFile << typeList.size() << endl;
            for (const auto& appliance : typeList) {
                appliance->save(prodListFile);
            }
        }
        prodListFile.close();
    }
    else {
        while (1) {
            cout << "File Save Error" << endl;
            cin.get();
        }
    }

    // ��ϵ� ��ȭ��ȣ ������ ����
    ofstream phoneFile("phone.txt");
    if (phoneFile.is_open()) {
        for (const auto& entry : sms.getmap()) {
            phoneFile << entry.first << endl;
            phoneFile << entry.second.size() << endl;
            for (const auto& phoneNumber : entry.second) {
                phoneFile << phoneNumber << endl;
            }
        }
        phoneFile << "end" << endl;
        phoneFile.close();
    }
    else {
        while (1) {
            cout << "File Save Error" << endl;
            cin.get();
        }
    }
}