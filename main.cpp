#include "menu.h"
#include "function.h"
#include "SMSManager.h"
#include "Fileio.h"

vector<vector<shared_ptr<Appliance>>> prodList(4);

int main() {
	
	Fileio FileManager;

	shared_ptr<mainMenu> root = make_shared<mainMenu>("root");

	shared_ptr<mainMenu> main1 = make_shared<mainMenu>("������ǰ ����");
	shared_ptr<mainMenu> main2 = make_shared<mainMenu>("������ǰ ����");
	root->add(main1);
	root->add(main2);
	root->add(make_shared<subMenu>("������ǰ ���", bind(&addAppliance, ref(prodList))));
	root->add(make_shared<subMenu>("������ǰ ����", bind(&controlAct, ref(prodList), 3)));
	root->add(make_shared<subMenu>("��ȭ��ȣ ���", bind(&registerPhone)));
	root->add(make_shared<subMenu>("����", bind(&programStop, ref(prodList))));

	main1->add(make_shared<subMenu>("��ǰ ��ü ���", bind(&displayAppliance, ref(prodList))));
	main1->add(make_shared<subMenu>("��ǰ ����", bind(&controlAct, ref(prodList), 1)));

	main2->add(make_shared<subMenu>("��ǰ ��ü ON/OFF", bind(&integTurn, ref(prodList))));
	main2->add(make_shared<subMenu>("��ǰ ����", bind(&controlAct, ref(prodList), 2)));

	root->command();

	return 0;
}