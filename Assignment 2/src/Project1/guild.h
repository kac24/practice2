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
