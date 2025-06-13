// team.h
// 
// Name: King Fung Alec Chan
// Email: kfachan@myseneca.ca
// Student ID: 101733236
// Date: 2025-06-13
//
// I declare that this submission is the result of my own work and I only copied the code 
// that my professor provided to complete my assignments. This submitted piece of work 
// has not been shared with any other student or 3rd party content provider.
#ifndef SENECA_TEAM_H
#define SENECA_TEAM_H
#include <string>
#include <iostream>
#include "character.h"

namespace seneca {
	class Team {
		Character** m_character{};
		std::string m_name{};
		int m_size{};
	public:
		Team();
		Team(const char* name);
		Team(const Team& src);
		Team& operator=(const Team& src);
		~Team();
		Team(Team&& src) noexcept;
		Team& operator=(Team&& src) noexcept;
		void addMember(const Character* c);
		void removeMember(const std::string& c);
		Character* operator[](size_t idx) const;
		void showMembers() const;
	};
}
#endif
