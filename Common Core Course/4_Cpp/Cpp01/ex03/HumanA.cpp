#include "HumanA.hpp"


HumanA::HumanA(std::string initialName, Weapon& initialWeaponType) : name(initialName), weapon(initialWeaponType){}

HumanA::~HumanA()
{

}

void HumanA::attack() const
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}