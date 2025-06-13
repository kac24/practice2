// characterTpl.h
// 
// Name: King Fung Alec Chan
// Email: kfachan@myseneca.ca
// Student ID: 101733236
// Date: 2025-06-13
//
// I declare that this submission is the result of my own work and I only copied the code 
// that my professor provided to complete my assignments. This submitted piece of work 
// has not been shared with any other student or 3rd party content provider.
#ifndef SENECA_CHARACTERTPL_H
#define SENECA_CHARACTERTPL_H
#include <iostream>
#include "character.h"

namespace seneca {

	template <typename T>
	class CharacterTpl : public Character {
		int m_healthMax{};
		T m_health{};
	public:
		CharacterTpl(const char* srcName, int srcHealthMax) : Character(srcName) {
			m_healthMax = srcHealthMax;
			m_health = srcHealthMax;
		};

		void takeDamage(int dmg) override {
			int remainHealth = static_cast<int>(m_health) - dmg;

			if (remainHealth <= 0) {
				std::cout <<"    " << getName() << " has been defeated!" << std::endl;
				m_health = 0;
			}
			else {
				m_health = remainHealth;
				std::cout << "    " << getName() << " took " << dmg << " damage, " << m_health << " health remaining." << std::endl;
			}
			

		};


		int getHealth() const override { return static_cast<int>(m_health); };

		int getHealthMax() const override { return m_healthMax; };
		void setHealth(int health) override { m_health = health; };
		void setHealthMax(int health) override { m_healthMax = health, m_health = health; };

	};


}



#endif
