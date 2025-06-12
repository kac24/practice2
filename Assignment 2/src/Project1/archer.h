#include <iostream>
#include "weapons.h"
#include "characterTpl.h"
#ifndef SENECA_ARCHER_H
#define SENECA_ARCHER_H

namespace seneca{

	template<typename Weapon_t>
	class Archer : public CharacterTpl<seneca::SuperHealth> {
		int m_baseDefense{};
		int m_baseAttack{};
		Weapon_t m_weapon{};
	public:
		Archer(const char* name, int healthMax, int baseAttack, int baseDefense, Weapon_t weapon)
			: CharacterTpl<seneca::SuperHealth>{ name, healthMax },
			 m_baseDefense{ baseDefense }, m_baseAttack{ baseAttack }, m_weapon{ weapon } {}


		int getAttackAmnt() const override {
			return 1.3 * m_baseAttack;
		}

		int getDefenseAmnt() const override {
			return 1.2 * m_baseDefense;
		}

		Character* clone() const override {
			return new Archer(*this);
		}

		void attack(Character* enemy) override{
			
			std::cout << getName() << " is attacking " << enemy->getName() << "." << std::endl;
			
			int damage = getAttackAmnt();
			std::cout << "Archer " << damage << " ranged damage!" << std::endl;
			enemy->takeDamage(damage);
		
		}

		void takeDamage(int dmg){

			std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
			std::cout << "    Archer has a defense of " << getDefenseAmnt() << ". Reducing damage received." << std::endl;
			int realdmg = dmg - getDefenseAmnt();

			if (realdmg < 0 ){
				realdmg = 0;
			}

			CharacterTpl<seneca::SuperHealth>::takeDamage(realdmg);
		}

		

	};

}
#endif
