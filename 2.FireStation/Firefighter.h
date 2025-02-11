#pragma once

#include <string>
#include <iostream>
#include "Firetruck.h"

class Firefighter
{
public:
	Firefighter(const std::string& name)
		: name(name)
	{
	}

	virtual ~Firefighter() = default;

	// 불끄기(ExtinguishFire).
	virtual void ExtinguishFire()
	{
		std::cout << name << " 소방관이 불을 끄고 있음!\n";
		TrainHoseOnFire();
		TurnOnHose();
	}

	// 운전(Drive).
	void Drive(Firetruck* truckToDrive, const class Point& position)
	{
		// 운전자 확인.
		if (truckToDrive->GetDriver() != this)
		{
			return;
		}

		// 이동.
		truckToDrive->Drive(position);
	}

	// Getter/Setter.
	const std::string GetName() const { return name; }
	void SetName(const std::string& name)
	{
		this->name = name;
	}

	// 멤버 함수(메소드).
protected:

	// 호스 켜기(물).
	virtual void TurnOnHose()
	{
		std::cout << "불이 꺼지고 있습니다.\n";
	}

	// 호스 조준.
	virtual void TrainHoseOnFire()
	{
		std::cout << "호스를 불이 발생한 곳에 겨냥하고 있습니다.\n";
	}

private:
	std::string name;
};