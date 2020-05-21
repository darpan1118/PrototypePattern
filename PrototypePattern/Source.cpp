#include <iostream>
#include "Ship.h"

int main()
{
	ShipFactory *factory = new ShipFactory();
	int ans = -1;
	while (true)
	{
		IShipPrototype *currentShip;
		std::cout << "What kind of clone you wanna use to go home, sir?\n";
		std::cout << "1) Warship \t2) Cruise \t3)Simple Ferry \n";
		std::cin >> ans;

		if (ans == 1)
		{
			currentShip = factory->CreateCloneShip("Warship");
			currentShip->SetShipName("WarshipClone");
			currentShip->Print();
			std::cout << "\n\n";
		}
		else if (ans == 2)
		{
			currentShip = factory->CreateCloneShip("Cruise");
			currentShip->SetShipName("CruiseClone");
			currentShip->Print();
			std::cout << "\n\n";
		}
		else if (ans == 3)
		{
			currentShip = factory->CreateCloneShip("Ferry");
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