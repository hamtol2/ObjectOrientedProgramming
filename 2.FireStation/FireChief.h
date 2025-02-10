#pragma once

#include "Firefighter.h"

class FireChief : public Firefighter
{
public:
	FireChief(const std::string& name, Firefighter* numberOne = nullptr)
		: Firefighter(name), numberOne(numberOne)
	{
	}

	// �Ҳ��� ���� �Լ�.
	void TellFirefighterToExtinguishFire(Firefighter* colleague)
	{
		colleague->ExtinguishFire();
	}

	// ������.
	virtual void ExtinguishFire() override
	{
		if (numberOne == nullptr)
		{
			return;
		}

		TellFirefighterToExtinguishFire(numberOne);
	}

	const Firefighter* GetNumberOne() const { return numberOne; }
	void SetNumberOne(Firefighter* numberOne) { this->numberOne = numberOne; }

private:
	Firefighter* numberOne = nullptr;
};