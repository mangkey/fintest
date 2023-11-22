#include "Fileio.h"

/*--------------------------------------------------------------------------------
 Fileio 클래스 생성자
 프로그램 실행 시 기존 데이터 있으면 불러오기
 불러올 데이터 : 가전제품 데이터, 전화번호 목록, 가전제품 총 전력소모량
 --------------------------------------------------------------------------------*/
Fileio::Fileio() {
    
    // 가전제품 데이터, 가전제품 총 전력소모량 가져오기
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

    // 전화번호 목록 불러오기
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
 Fileio 클래스 소멸자
 프로그램 종료 시 등록된 데이터를 파일에 저장 및 파일 없으면 생성하여 저장
 저장할 데이터 : 가전제품 데이터 (가전제품 타입, 제품 상태, 제품 이름, 전력소모량),
                 전화번호 목록, 가전제품 총 전력소모량
--------------------------------------------------------------------------------*/
Fileio::~Fileio() {

    // 종료시 남아있는 가전제품 데이터 저장
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

    // 등록된 전화번호 데이터 저장
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