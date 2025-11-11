#include "DiamondTrap.hpp"

int main()
{
	
	DiamondTrap d("lola");
	
	d.attack("Oliver");
	d.takeDamage(7);
	d.beRepaired(5);
	d.whoAmI();
}