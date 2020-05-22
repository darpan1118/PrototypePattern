#include <iostream>
#include "Ship.h"

int main()
{
	std::map<std::string, IShipPrototype*> ships;

	ships["Warship"] = new WarShip("ManO'War", 32, 43, 17);
	ships["Cruise"] = new Cruise("Cruise", 27, 73, 10);
	ships["Ferry"] = new Ferry("RideBackHome", 12, 13, 13);


	int ans = -1;
	while (true)
	{
		IShipPrototype *currentShip;
		std::cout << "What kind of clone you wanna use to go home, sir?\n";
		std::cout << "1) Warship \t2) Cruise \t3)Simple Ferry \n";
		std::cin >> ans;

		if (ans == 1)
		{
			currentShip = ships["Warship"]->clone();
			currentShip->SetShipName("WarshipClone");
			currentShip->Print();
			std::cout << "\n\n";
		}
		else if (ans == 2)
		{
			currentShip = ships["Cruise"]->clone();
			currentShip->SetShipName("CruiseClone");
			currentShip->Print();
			std::cout << "\n\n";
		}
		else if (ans == 3)
		{
			currentShip = ships["Ferry"]->clone();
			currentShip->SetShipName("FerryClone");
			currentShip->Print();
			std::cout << "\n\n";
		}
		else break;

		delete currentShip;
	}

	getchar();
	return EXIT_SUCCESS;
}