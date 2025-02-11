#include "Firefighter.h"
#include "FireChief.h"
#include "TraineeFirefighter.h"

#include "FireStation.h"
#include "Administrator.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	// �޸� ���� Ȯ��.
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// �ҹ漭 ����.
	FireStation* fireStation = new FireStation();

	// ������ ����.
	Administrator* taejun = new Administrator("������", "����", "��");

	// �ҹ��� ����.
	Firetruck* truckOne = new Firetruck();
	Firefighter* ronnie = new Firefighter("�δ�");
	Firefighter* james = new Firefighter("���ӽ�");

	// ���� �ҹ�� ���� �� �׽�Ʈ.
	Firefighter* bill = new TraineeFirefighter("��");
	bill->ExtinguishFire();

	// �ҹ漭��.
	FireChief* harry = new FireChief("�ظ�", ronnie);
	truckOne->SetDriver(harry);
	harry->Drive(truckOne, Point(200, 300));

	// ���.
	fireStation->ClockIn(ronnie);
	fireStation->ClockIn(james);
	fireStation->ClockIn(bill);
	fireStation->ClockIn(harry);
	fireStation->ClockIn(taejun);

	// �̸� Ȯ��.
	fireStation->RollCall();

	// �Ҳ��� ����.
	//harry->TellFirefighterToExtinguishFire(ronnie);
	harry->ExtinguishFire();

	// �׽�Ʈ.
	//FirefighterBase* testFighter = new FirefighterBase("�׽�Ʈ");

	// ������.
	FirefighterBase* stillHarry = harry;
	stillHarry->ExtinguishFire();

	// ������ ����.
	truckOne->SetDriver(ronnie);

	// �ҹ��� �̵�.
	ronnie->Drive(truckOne, Point(10, 5));
	james->Drive(truckOne, Point(20, -3));

	// ������ ����.
	truckOne->SetDriver(james);

	// �ҹ��� �̵�.
	james->Drive(truckOne, Point(20, -3));

	// �޸� ����.
	delete truckOne;
	delete ronnie;
	delete james;
	delete bill;
	delete harry;

	delete fireStation;
	delete taejun;

	std::cin.get();
}