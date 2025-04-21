#include <iostream>

class IDevice
{
public:	
	virtual void switchOn()=0;
	virtual void switchOff()=0;
	virtual ~IDevice()=default;
};



class LED: public IDevice
{
public:
	void switchOn() override
	{
		std::cout<<"LED On\n";
	}

	void switchOff() override
	{
		std::cout<<"LED OFF\n";
	}
};



class Bulb: public IDevice
{
public:
	void switchOn() override
	{
		std::cout<<"Bulb On\n";
	}

	void switchOff() override
	{
		std::cout<<"Bulb OFF\n";
	}
};


class Switch
{
public:
	IDevice &m_device;

	Switch(IDevice &device):m_device(device)
	{
		//
	}
	void operate()
	{
		m_device.switchOn();
	}

};


int main()
{
	auto bulb=Bulb();
	auto led=LED();
	IDevice &bulbObj=bulb;
	IDevice &ledObj=led;

	Switch switchObj{bulbObj};
	switchObj.operate();

	return 0;
}
