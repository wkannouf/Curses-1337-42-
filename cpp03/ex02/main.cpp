#include "FragTrap.hpp"

int main()
{
	ClapTrap a("Leo");
	FragTrap b("Andro");

	a.attack("Andro");
	b.attack("Leo");
	a.takeDamage(4);
	b.takeDamage(2);
	a.beRepaired(3);
	b.beRepaired(1);
	b. highFivesGuys();
}