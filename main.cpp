#include "menu.h"
#include "function.h"
#include "SMSManager.h"
#include "Fileio.h"

vector<vector<shared_ptr<Appliance>>> prodList(4);

int main() {
	
	Fileio FileManager;

	shared_ptr<mainMenu> root = make_shared<mainMenu>("root");

	shared_ptr<mainMenu> main1 = make_shared<mainMenu>("가전제품 상태");
	shared_ptr<mainMenu> main2 = make_shared<mainMenu>("가전제품 제어");
	root->add(main1);
	root->add(main2);
	root->add(make_shared<subMenu>("가전제품 등록", bind(&addAppliance, ref(prodList))));
	root->add(make_shared<subMenu>("가전제품 삭제", bind(&controlAct, ref(prodList), 3)));
	root->add(make_shared<subMenu>("전화번호 등록", bind(&registerPhone)));
	root->add(make_shared<subMenu>("종료", bind(&programStop, ref(prodList))));

	main1->add(make_shared<subMenu>("제품 전체 출력", bind(&displayAppliance, ref(prodList))));
	main1->add(make_shared<subMenu>("제품 선택", bind(&controlAct, ref(prodList), 1)));

	main2->add(make_shared<subMenu>("제품 전체 ON/OFF", bind(&integTurn, ref(prodList))));
	main2->add(make_shared<subMenu>("제품 선택", bind(&controlAct, ref(prodList), 2)));

	root->command();

	return 0;
}