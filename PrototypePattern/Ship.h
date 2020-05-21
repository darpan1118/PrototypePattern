#pragma once
#include <string>
#include <map>

class IShipPrototype
{
public:
	virtual IShipPrototype* clone() = 0;

	IShipPrototype(const std::string sName, float w = 10, float h = 10, float s = 10) : shipName{ sName }, width{ w }, height{ h }, speed{ s } {};
	IShipPrototype(const IShipPrototype &that)
	{
		shipName = that.shipName;
		width = that.width;
		height = that.height;
		speed = that.speed;
	}

	void Print()
	{
		std::cout << "-----------------------\n";
		std::cout << "\tShip Info\t\n" <<
			"Name:\t\t" << shipName << "\n" <<
			"Width:\t\t" << width << "\n" <<
			"Height:\t\t" << height << "\n" <<
			"Speed:\t\t" << speed << std::endl;

	}
	void SetShipName(const std::string &newShipName)	{ shipName = newShipName; }
	void SetShipHeight(float NewHeight)			{ height = NewHeight; }
	void SetShipWidth(float NewWidth)			{ width = NewWidth; }
	void SetShipSpeed(float NewSpeed)			{ speed = NewSpeed; }


private:
	std::string shipName;
	float width = 0, height = 0, speed = 0;
};


class WarShip : public IShipPrototype
{

public:
	WarShip(const std::string& sName, float w, float h, float s) : IShipPrototype(sName, w, h, s) {}
	WarShip(const WarShip &ship) : IShipPrototype(ship) {}


	IShipPrototype* clone() override
	{
		return new WarShip(*this);
	}

};


class Cruise : public IShipPrototype
{
public: 
	Cruise(const std::string& sName, float w, float h, float s) : IShipPrototype(sName, w, h, s) {}
	Cruise(const WarShip &ship) : IShipPrototype(ship) {}


	IShipPrototype* clone() override
	{
		return new Cruise(*this);
	}
};

class Ferry : public IShipPrototype
{
public:
	Ferry(const std::string& sName, float w, float h, float s) : IShipPrototype(sName, w, h, s) {}
	Ferry(const WarShip &ship) : IShipPrototype(ship) {}


	IShipPrototype* clone() override
	{
		return new Ferry(*this);
	}
};



class ShipFactory
{
public:
	ShipFactory()
	{
		ships["Warship"] = new WarShip("ManO'War", 32, 43, 17);
		ships["Cruise"] = new Cruise("Cruise", 27, 73, 10);
		ships["Ferry"] = new Ferry("RideBackHome", 12, 13, 13);
	}

	IShipPrototype* CreateCloneShip(std::string idx)
	{
		return ships[idx]->clone();
	}

private:
	std::map<std::string, IShipPrototype*> ships;

};