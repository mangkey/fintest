#include "Appliance.h"

int Totalpowerconsumption = 0;

/*--------------------------------------------------------------------------------
���� ���� ����� ����/����/����� �ð� ������ �Է�
���� OFF �� ON ����� �ش� ��ǰ�� ����� ��ȭ��ȣ�� �޼��� ����
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

// ���α׷� ����� ������ǰ ���� ������ �ҷ�����
void Appliance::load(ifstream& prodListFile) {
	prodListFile >> ApplianceName;
	prodListFile >> state1;
	prodListFile >> name;
	prodListFile >> powerConsumption;
}

/*--------------------------------------------------------------------------------
���α׷� ����� ��ϵ� ������ǰ ������ �����ϱ�
���α׷� ����� ��� ������ǰ OFF�� ����Ǳ⿡ ���� ����� �����͸� ����
--------------------------------------------------------------------------------*/
void Appliance::save(ofstream& prodListFile) {
	prodListFile << ApplianceName << endl;
	prodListFile << state1 << endl;
	prodListFile << name << endl;
	prodListFile << powerConsumption << endl;
}

// ������ǰ Ÿ�Ժ� ���� ��� override
void Aircon::show() {
	cout << "              [AirConditioner]" << endl;
	cout << "��ǰ��        : " << name << endl;
	if (TurnOnOff == 1)
		cout << "����          : OFF" << endl;
	else if (TurnOnOff == 2)
		cout << "����          : ON" << endl;
	if (state1 == 1)
		cout << "��ǰ ����     : ��ǳ" << endl;
	else if (state1 == 2)
		cout << "��ǰ ����     : �ù�" << endl;
	else if (state1 == 3)
		cout << "��ǰ ����     : ����" << endl;
	cout << "���� �µ�     : " << state2 << endl;
	if (start_time == 0) cout << "Start Time    : 0" << endl;
	else if (start_time != 0) cout << "Start Time    : " << put_time(localtime(&start_time), "%Y-%m-%dT%H:%M:%S") << endl;
	if (end_time == 0) cout << "End Time      : 0" << endl;
	else if (end_time != 0) cout << "End Time      : " << put_time(localtime(&end_time), "%Y-%m-%dT%H:%M:%S") << endl;
	cout << "Total Time    : " << total_time << endl;
	cout << "�� ���¼Ҹ� : " << powerConsumption * total_time << " (�ð��� : " << powerConsumption << ")" << endl;
}
void Ricecooker::show() {
	cout << "              [RiceCooker]" << endl;
	cout << "��ǰ��        : " << name << endl;
	if (TurnOnOff == 1)
		cout << "����          : OFF" << endl;
	else if (TurnOnOff == 2)
		cout << "����          : ON" << endl;
	if (state1 == 1)
		cout << "��ǰ ����     : ������" << endl;
	else if (state1 == 2)
		cout << "��ǰ ����     : ����" << endl;
	else if (state1 == 3)
		cout << "��ǰ ����     : ������" << endl;
	else if (state1 == 4)
		cout << "��ǰ ����     : �����" << endl;
	if (start_time == 0) cout << "Start Time    : 0" << endl;
	else if (start_time != 0) cout << "Start Time    : " << put_time(localtime(&start_time), "%Y-%m-%dT%H:%M:%S") << endl;
	if (end_time == 0) cout << "End Time      : 0" << endl;
	else if (end_time != 0) cout << "End Time      : " << put_time(localtime(&end_time), "%Y-%m-%dT%H:%M:%S") << endl;
	cout << "Total Time    : " << total_time << endl;
	cout << "�� ���¼Ҹ� : " << powerConsumption * total_time << " (�ð��� : " << powerConsumption << ")" << endl;
}
void Washer::show() {
	cout << "              [Washer]" << endl;
	cout << "��ǰ��        : " << name << endl;
	if (TurnOnOff == 1)
		cout << "����          : OFF" << endl;
	else if (TurnOnOff == 2)
		cout << "����          : ON" << endl;
	if (state1 == 1)
		cout << "��ǰ ����     : ������" << endl;
	else if (state1 == 2)
		cout << "��ǰ ����     : �Ϲݻ���" << endl;
	else if (state1 == 3)
		cout << "��ǰ ����     : ��������" << endl;
	else if (state1 == 4)
		cout << "��ǰ ����     : ����" << endl;
	if (start_time == 0) cout << "Start Time    : 0" << endl;
	else if (start_time != 0) cout << "Start Time    : " << put_time(localtime(&start_time), "%Y-%m-%dT%H:%M:%S") << endl;
	if (end_time == 0) cout << "End Time      : 0" << endl;
	else if (end_time != 0) cout << "End Time      : " << put_time(localtime(&end_time), "%Y-%m-%dT%H:%M:%S") << endl;
	cout << "Total Time    : " << total_time << endl;
	cout << "�� ���¼Ҹ� : " << powerConsumption * total_time << " (�ð��� : " << powerConsumption << ")" << endl;
}
void Light::show() {
	cout << "              [Light]" << endl;
	cout << "��ǰ��        : " << name << endl;
	if (TurnOnOff == 1)
		cout << "����          : OFF" << endl;
	else if (TurnOnOff == 2)
		cout << "����          : ON" << endl;
	if (state1 == 1)
		cout << "��ǰ ����     : �����" << endl;
	else if (state1 == 2)
		cout << "��ǰ ����     : ���̺�����" << endl;
	else if (state1 == 3)
		cout << "��ǰ ����     : ��Ȳ��" << endl;
	if (start_time == 0) cout << "Start Time    : 0" << endl;
	else if (start_time != 0) cout << "Start Time    : " << put_time(localtime(&start_time), "%Y-%m-%dT%H:%M:%S") << endl;
	if (end_time == 0) cout << "End Time      : 0" << endl;
	else if (end_time != 0) cout << "End Time      : " << put_time(localtime(&end_time), "%Y-%m-%dT%H:%M:%S") << endl;
	cout << "Total Time    : " << total_time << endl;
	cout << "�� ���¼Ҹ� : " << powerConsumption * total_time << " (�ð��� : " << powerConsumption << ")" << endl;
}

// ������ǰ Ÿ�Ժ� ��ǰ ���� override
void Aircon::control(){
	while (1) {
		system("cls");
		int temp1, flag = 0;
		cout << "\n**********************************" << endl;
		cout << "1. ����\n2. ��ǰ ����\n3. ���� �µ�\n4. ����\n";
		cout << "**********************************\n" << endl;
		cout << "�� ������ �ɼ� ���� : ";
		input::intinput(temp1);
		switch (temp1)
		{
		case 1:
			while (1) {
				int temp2;
				cout << "\n**********************************" << endl;
				cout << "1. OFF\n2. ON\n3. ����\n";
				cout << "**********************************\n" << endl;
				cout << "�� ������ �ɼ� ���� : ";
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
				cout << "1. ��ǳ\n2. �ù�\n3. ����\n4. ����\n";
				cout << "**********************************\n" << endl;
				cout << "�� ������ �ɼ� ���� : ";
				input::intinput(temp2);
				if (temp2 == 1 || temp2 == 2 || temp2 == 3) state1 = temp2;
				else if (temp2 == 4) break;
			}
			break;
		case 3:
			while (1) {
				int temp2;
				cout << "�� ������ �µ� �Է� (18 ~ 30�� / ���� 0) : ";
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
		cout << "1. ����\n2. ��ǰ ����\n3. ����\n";
		cout << "**********************************\n" << endl;
		cout << "�� ������ �ɼ� ���� : ";
		input::intinput(temp1);
		switch (temp1)
		{
		case 1:
			while (1) {
				int temp2;
				cout << "\n**********************************" << endl;
				cout << "1. OFF\n2. ON\n3. ����\n";
				cout << "**********************************\n" << endl;
				cout << "�� ������ �ɼ� ���� : ";
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
				cout << "1. ������\n2. ����\n3. ������\n4. �����\n5. ����\n";
				cout << "**********************************\n" << endl;;
				cout << "�� ������ �ɼ� ���� : ";
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
		cout << "1. ����\n2. ��ǰ ����\n3. ����\n";
		cout << "**********************************\n" << endl;
		cout << "�� ������ �ɼ� ���� : ";
		input::intinput(temp1);
		switch (temp1)
		{
		case 1:
			while (1) {
				int temp2;
				cout << "\n**********************************" << endl;
				cout << "1. OFF\n2. ON\n3. ����\n";
				cout << "**********************************\n" << endl;
				cout << "�� ������ �ɼ� ���� : ";
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
				cout << "1. ������\n2. �Ϲݻ���\n3. ��������\n4. ����\n5. ����\n";
				cout << "**********************************\n" << endl;;
				cout << "�� ������ �ɼ� ���� : ";
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
		cout << "1. ����\n2. ��ǰ ����\n3. ����\n";
		cout << "**********************************\n" << endl;
		cout << "�� ������ �ɼ� ���� : ";
		input::intinput(temp1);
		switch (temp1)
		{
		case 1:
			while (1) {
				int temp2;
				cout << "\n**********************************" << endl;
				cout << "1. OFF\n2. ON\n3. ����\n";
				cout << "**********************************\n" << endl;
				cout << "�� ������ �ɼ� ���� : ";
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
				cout << "1. �����\n2. ���̺�����\n3. ��Ȳ��\n4. ����\n";
				cout << "**********************************\n" << endl;;
				cout << "�� ������ �ɼ� ���� : ";
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