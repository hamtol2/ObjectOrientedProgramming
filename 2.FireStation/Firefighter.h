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

	// �Ҳ���(ExtinguishFire).
	virtual void ExtinguishFire()
	{
		std::cout << name << " �ҹ���� ���� ���� ����!\n";
		TrainHoseOnFire();
		TurnOnHose();
	}

	// ����(Drive).
	void Drive(Firetruck* truckToDrive, const class Point& position)
	{
		// ������ Ȯ��.
		if (truckToDrive->GetDriver() != this)
		{
			return;
		}

		// �̵�.
		truckToDrive->Drive(position);
	}

	// Getter/Setter.
	const std::string GetName() const { return name; }
	void SetName(const std::string& name)
	{
		this->name = name;
	}

	// ��� �Լ�(�޼ҵ�).
protected:

	// ȣ�� �ѱ�(��).
	virtual void TurnOnHose()
	{
		std::cout << "���� ������ �ֽ��ϴ�.\n";
	}

	// ȣ�� ����.
	virtual void TrainHoseOnFire()
	{
		std::cout << "ȣ���� ���� �߻��� ���� �ܳ��ϰ� �ֽ��ϴ�.\n";
	}

private:
	std::string name;
};