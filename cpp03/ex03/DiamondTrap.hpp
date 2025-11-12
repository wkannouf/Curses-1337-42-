#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string	name;
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &diamond);
		DiamondTrap &operator=(const DiamondTrap &diamond);
		void	attack(const std::string& target);
		void	whoAmI();
		~DiamondTrap();
};
#endif