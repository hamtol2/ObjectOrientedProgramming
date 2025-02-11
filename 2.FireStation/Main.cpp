#include "Firefighter.h"
#include "FireChief.h"
#include "TraineeFirefighter.h"

int main()
{
	// 소방차 생성.
	Firetruck* truckOne = new Firetruck();
	Firefighter* ronnie = new Firefighter("로니");
	Firefighter* james = new Firefighter("제임스");

	// 수습 소방관 생성 및 테스트.
	Firefighter* bill = new TraineeFirefighter("빌");
	bill->ExtinguishFire();

	// 소방서장.
	FireChief* harry = new FireChief("해리", ronnie);
	truckOne->SetDriver(harry);
	harry->Drive(truckOne, Point(200, 300));

	// 불끄기 위임.
	//harry->TellFirefighterToExtinguishFire(ronnie);
	harry->ExtinguishFire();

	// 다형성.
	Firefighter* stillHarry = harry;
	stillHarry->ExtinguishFire();

	// 운전자 설정.
	truckOne->SetDriver(ronnie);

	// 소방차 이동.
	ronnie->Drive(truckOne, Point(10, 5));
	james->Drive(truckOne, Point(20, -3));

	// 운전자 설정.
	truckOne->SetDriver(james);

	// 소방차 이동.
	james->Drive(truckOne, Point(20, -3));

	std::cin.get();
}