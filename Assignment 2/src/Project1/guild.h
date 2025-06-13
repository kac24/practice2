// guild.h
// 
// Name: King Fung Alec Chan
// Email: kfachan@myseneca.ca
// Student ID: 101733236
// Date: 2025-06-13
//
// I declare that this submission is the result of my own work and I only copied the code 
// that my professor provided to complete my assignments. This submitted piece of work 
// has not been shared with any other student or 3rd party content provider.
#ifndef SENECA_GUILD_H
#define SENECA_GUILD_H
#include <string>
#include "character.h"

namespace seneca {
	class Guild {
		Character** m_character{};
		std::string m_name{};
		size_t m_size{};
	public:
		Guild();
		Guild(const char* name);
		Guild(const Guild& src);
		Guild& operator=(const Guild& src);
		~Guild();
		Guild(const Guild&& src) noexcept;
		Guild& operator=(const Guild&& src) noexcept;
		void addMember(Character* c);
		void removeMember(const std::string& c);
		Character* operator[](size_t idx) const;
		void showMembers() const;
	};





}

#endif
