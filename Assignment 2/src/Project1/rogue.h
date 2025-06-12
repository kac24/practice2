#ifndef SENECA_ROGUE_H
#define SENECA_ROGUE_H
#include <iostream>
#include "charactertpl.h"

namespace seneca{
	template<typename T, typename FirstAbility_t, typename SecondAbility_t>
	class Rogue : public CharacterTpl<T> {
		int m_baseDefense{};
		int m_baseAttack{};
		FirstAbility_t m_firstAbility{};
		SecondAbility_t m_secondAbility{};
		seneca::Dagger m_weapon{};
	public:	
		Rogue(const char* name, int healthMax, int baseAttack, int baseDefense) : CharacterTpl<T>(name, healthMax), m_baseDefense { baseDefense }, m_baseAttack{ baseAttack } {};
		int getAttackAmnt() const override {
			
			return m_baseAttack + 2 * static_cast<double>(m_weapon);

		}
		
		int getDefenseAmnt() const override {
			return m_baseDefense;
		}

		Character* clone() const override {
			return new Rogue(*this);
		}

		void attack(Character* enemy) override{
			std::cout << this->getName() << " is attacking " << enemy->getName() << "." << std::endl;
			m_firstAbility.useAbility(this);
			m_secondAbility.useAbility(this);
			int damage = getAttackAmnt();
			m_firstAbility.transformDamageDealt(damage);
			m_secondAbility.transformDamageDealt(damage);

			std::cout << "Rouge deals " << damage << " melee samage!" << std::endl;

			enemy->takeDamage(damage);
		}

		void takeDamage(int dmg) override {
			std::cout << this->getName() << " is attacked for " << dmg << " damage." << std::endl;
			std::cout << "    Rogue has a defense of " << m_baseDefense << ". Reducing damage received." << std::endl;

			int damageTaken = dmg - m_baseDefense;
			if (damageTaken < 0) {
				damageTaken = 0;
			}

			m_firstAbility.transformDamageDealt(damageTaken);
			m_secondAbility.transformDamageDealt(damageTaken);

			CharacterTpl<T>::takeDamage(damageTaken);
		}
	};
}
#endif
