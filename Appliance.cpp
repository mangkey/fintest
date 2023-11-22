#include "Appliance.h"

int Totalpowerconsumption = 0;

/*--------------------------------------------------------------------------------
전원 상태 변경시 시작/종료/사용한 시간 데이터 입력
전원 OFF → ON 변경시 해당 제품에 연결된 전화번호에 메세지 전달
--------------------------------------------------------------------------------*/
void Appliance::setTime(int gettime) {
	if (TurnOnOff == 2 && gettime == 1) {
		start_time = time(nullptr);
		end_time = 0;
		sms.send_sms(ApplianceName, name);
	}
	else if (TurnOnOff == 1 && gettime == 2) {
		end_time = time(nullptr);
		total_time += difftime(end_time, start_time);
	}
}

// 프로그램 실행시 가전제품 기존 데이터 불러오기
void Appliance::load(ifstream& prodListFile) {
	prodListFile >> ApplianceName;
	prodListFile >> state1;
	prodListFile >> name;
	prodListFile >> powerConsumption;
}

/*--------------------------------------------------------------------------------
프로그램 종료시 등록된 가전제품 데이터 저장하기
프로그램 종료시 모든 가전제품 OFF로 변경되기에 추후 사용할 데이터만 저장
--------------------------------------------------------------------------------*/
void Appliance::save(ofstream& prodListFile) {
	prodListFile << ApplianceName << endl;
	prodListFile << state1 << endl;
	prodListFile << name << endl;
	prodListFile << powerConsumption << endl;
}

// 가전제품 타입별 상태 출력 override
void Aircon::show() {
	cout << "              [AirConditioner]" << endl;
	cout << "제품명        : " << name << endl;
	if (TurnOnOff == 1)
		cout << "전원          : OFF" << endl;
	else if (TurnOnOff == 2)
		cout << "전원          : ON" << endl;
	if (state1 == 1)
		cout << "제품 상태     : 송풍" << endl;
	else if (state1 == 2)
		cout << "제품 상태     : 냉방" << endl;
	else if (state1 == 3)
		cout << "제품 상태     : 난방" << endl;
	cout << "설정 온도     : " << state2 << endl;
	if (start_time == 0) cout << "Start Time    : 0" << endl;
	else if (start_time != 0) cout << "Start Time    : " << put_time(localtime(&start_time), "%Y-%m-%dT%H:%M:%S") << endl;
	if (end_time == 0) cout << "End Time      : 0" << endl;
	else if (end_time != 0) cout << "End Time      : " << put_time(localtime(&end_time), "%Y-%m-%dT%H:%M:%S") << endl;
	cout << "Total Time    : " << total_time << endl;
	cout << "총 전력소모량 : " << powerConsumption * total_time << " (시간당 : " << powerConsumption << ")" << endl;
}
void Ricecooker::show() {
	cout << "              [RiceCooker]" << endl;
	cout << "제품명        : " << name << endl;
	if (TurnOnOff == 1)
		cout << "전원          : OFF" << endl;
	else if (TurnOnOff == 2)
		cout << "전원          : ON" << endl;
	if (state1 == 1)
		cout << "제품 상태     : 무동작" << endl;
	else if (state1 == 2)
		cout << "제품 상태     : 보온" << endl;
	else if (state1 == 3)
		cout << "제품 상태     : 밥짓기" << endl;
	else if (state1 == 4)
		cout << "제품 상태     : 데우기" << endl;
	if (start_time == 0) cout << "Start Time    : 0" << endl;
	else if (start_time != 0) cout << "Start Time    : " << put_time(localtime(&start_time), "%Y-%m-%dT%H:%M:%S") << endl;
	if (end_time == 0) cout << "End Time      : 0" << endl;
	else if (end_time != 0) cout << "End Time      : " << put_time(localtime(&end_time), "%Y-%m-%dT%H:%M:%S") << endl;
	cout << "Total Time    : " << total_time << endl;
	cout << "총 전력소모량 : " << powerConsumption * total_time << " (시간당 : " << powerConsumption << ")" << endl;
}
void Washer::show() {
	cout << "              [Washer]" << endl;
	cout << "제품명        : " << name << endl;
	if (TurnOnOff == 1)
		cout << "전원          : OFF" << endl;
	else if (TurnOnOff == 2)
		cout << "전원          : ON" << endl;
	if (state1 == 1)
		cout << "제품 상태     : 무동작" << endl;
	else if (state1 == 2)
		cout << "제품 상태     : 일반빨래" << endl;
	else if (state1 == 3)
		cout << "제품 상태     : 삶은빨래" << endl;
	else if (state1 == 4)
		cout << "제품 상태     : 건조" << endl;
	if (start_time == 0) cout << "Start Time    : 0" << endl;
	else if (start_time != 0) cout << "Start Time    : " << put_time(localtime(&start_time), "%Y-%m-%dT%H:%M:%S") << endl;
	if (end_time == 0) cout << "End Time      : 0" << endl;
	else if (end_time != 0) cout << "End Time      : " << put_time(localtime(&end_time), "%Y-%m-%dT%H:%M:%S") << endl;
	cout << "Total Time    : " << total_time << endl;
	cout << "총 전력소모량 : " << powerConsumption * total_time << " (시간당 : " << powerConsumption << ")" << endl;
}
void Light::show() {
	cout << "              [Light]" << endl;
	cout << "제품명        : " << name << endl;
	if (TurnOnOff == 1)
		cout << "전원          : OFF" << endl;
	else if (TurnOnOff == 2)
		cout << "전원          : ON" << endl;
	if (state1 == 1)
		cout << "제품 상태     : 백색등" << endl;
	else if (state1 == 2)
		cout << "제품 상태     : 아이보리등" << endl;
	else if (state1 == 3)
		cout << "제품 상태     : 주황등" << endl;
	if (start_time == 0) cout << "Start Time    : 0" << endl;
	else if (start_time != 0) cout << "Start Time    : " << put_time(localtime(&start_time), "%Y-%m-%dT%H:%M:%S") << endl;
	if (end_time == 0) cout << "End Time      : 0" << endl;
	else if (end_time != 0) cout << "End Time      : " << put_time(localtime(&end_time), "%Y-%m-%dT%H:%M:%S") << endl;
	cout << "Total Time    : " << total_time << endl;
	cout << "총 전력소모량 : " << powerConsumption * total_time << " (시간당 : " << powerConsumption << ")" << endl;
}

// 가전제품 타입별 제품 제어 override
void Aircon::control(){
	while (1) {
		system("cls");
		int temp1, flag = 0;
		cout << "\n**********************************" << endl;
		cout << "1. 전원\n2. 제품 상태\n3. 설정 온도\n4. 종료\n";
		cout << "**********************************\n" << endl;
		cout << "▶ 변경할 옵션 선택 : ";
		input::intinput(temp1);
		switch (temp1)
		{
		case 1:
			while (1) {
				int temp2;
				cout << "\n**********************************" << endl;
				cout << "1. OFF\n2. ON\n3. 종료\n";
				cout << "**********************************\n" << endl;
				cout << "▶ 변경할 옵션 선택 : ";
				input::intinput(temp2);
				if (temp2 == 1 || temp2 == 2) {
					int time = getTurnOnOff();
					TurnOnOff = temp2;
					setTime(time);
				}
				else if (temp2 == 3) break;
			}
			break;
		case 2:
			while (1) {
				int temp2;
				cout << "\n**********************************" << endl;
				cout << "1. 송풍\n2. 냉방\n3. 난방\n4. 종료\n";
				cout << "**********************************\n" << endl;
				cout << "▶ 변경할 옵션 선택 : ";
				input::intinput(temp2);
				if (temp2 == 1 || temp2 == 2 || temp2 == 3) state1 = temp2;
				else if (temp2 == 4) break;
			}
			break;
		case 3:
			while (1) {
				int temp2;
				cout << "▶ 설정할 온도 입력 (18 ~ 30℃ / 종료 0) : ";
				input::intinput(temp2);
				if (temp2 >= 18 && temp2 <= 30) state2 = temp2;
				else if (temp2 == 0) break;
			}
			break;
		case 4:
			flag = 1;
			break;
		default:
			break;
		}
		if (flag == 1) break;
	}
}
void Ricecooker::control() {
	while (1) {
		system("cls");
		int temp1, flag = 0;
		cout << "\n**********************************" << endl;
		cout << "1. 전원\n2. 제품 상태\n3. 종료\n";
		cout << "**********************************\n" << endl;
		cout << "▶ 변경할 옵션 선택 : ";
		input::intinput(temp1);
		switch (temp1)
		{
		case 1:
			while (1) {
				int temp2;
				cout << "\n**********************************" << endl;
				cout << "1. OFF\n2. ON\n3. 종료\n";
				cout << "**********************************\n" << endl;
				cout << "▶ 변경할 옵션 선택 : ";
				input::intinput(temp2);
				if (temp2 == 1 || temp2 == 2) {
					int time = getTurnOnOff();
					TurnOnOff = temp2;
					setTime(time);
				}
				else if (temp2 == 3) break;
			}
			break;
		case 2:
			while (1) {
				int temp2;
				cout << "\n**********************************" << endl;
				cout << "1. 무동작\n2. 보온\n3. 밥짓기\n4. 데우기\n5. 종료\n";
				cout << "**********************************\n" << endl;;
				cout << "▶ 변경할 옵션 선택 : ";
				input::intinput(temp2);
				if (temp2 >= 1 && temp2 <= 4) state1 = temp2;
				else if (temp2 == 5) break;
			}
			break;
		case 3:
			flag = 1;
			break;
		default:
			break;
		}
		if (flag == 1) break;
	}
}
void Washer::control() {
	while (1) {
		system("cls");
		int temp1, flag = 0;
		cout << "\n**********************************" << endl;
		cout << "1. 전원\n2. 제품 상태\n3. 종료\n";
		cout << "**********************************\n" << endl;
		cout << "▶ 변경할 옵션 선택 : ";
		input::intinput(temp1);
		switch (temp1)
		{
		case 1:
			while (1) {
				int temp2;
				cout << "\n**********************************" << endl;
				cout << "1. OFF\n2. ON\n3. 종료\n";
				cout << "**********************************\n" << endl;
				cout << "▶ 변경할 옵션 선택 : ";
				input::intinput(temp2);
				if (temp2 == 1 || temp2 == 2) {
					int time = getTurnOnOff();
					TurnOnOff = temp2;
					setTime(time);
				}
				else if (temp2 == 3) break;
			}
			break;
		case 2:
			while (1) {
				int temp2;
				cout << "\n**********************************" << endl;
				cout << "1. 무동작\n2. 일반빨래\n3. 삶은빨래\n4. 건조\n5. 종료\n";
				cout << "**********************************\n" << endl;;
				cout << "▶ 변경할 옵션 선택 : ";
				input::intinput(temp2);
				if (temp2 >= 1 && temp2 <= 4) state1 = temp2;
				else if (temp2 == 5) break;
			}
			break;
		case 3:
			flag = 1;
			break;
		default:
			break;
		}
		if (flag == 1) break;
	}
}
void Light::control() {
	while (1) {
		system("cls");
		int temp1, flag = 0;
		cout << "\n**********************************" << endl;
		cout << "1. 전원\n2. 제품 상태\n3. 종료\n";
		cout << "**********************************\n" << endl;
		cout << "▶ 변경할 옵션 선택 : ";
		input::intinput(temp1);
		switch (temp1)
		{
		case 1:
			while (1) {
				int temp2;
				cout << "\n**********************************" << endl;
				cout << "1. OFF\n2. ON\n3. 종료\n";
				cout << "**********************************\n" << endl;
				cout << "▶ 변경할 옵션 선택 : ";
				input::intinput(temp2);
				if (temp2 == 1 || temp2 == 2) {
					int time = getTurnOnOff();
					TurnOnOff = temp2;
					setTime(time);
				}
				else if (temp2 == 3) break;
			}
			break;
		case 2:
			while (1) {
				int temp2;
				cout << "\n**********************************" << endl;
				cout << "1. 백색등\n2. 아이보리등\n3. 주황등\n4. 종료\n";
				cout << "**********************************\n" << endl;;
				cout << "▶ 변경할 옵션 선택 : ";
				input::intinput(temp2);
				if (temp2 >= 1 && temp2 <= 3) state1 = temp2;
				else if (temp2 == 4) break;
			}
			break;
		case 3:
			flag = 1;
			break;
		default:
			break;
		}
		if (flag == 1) break;
	}
}