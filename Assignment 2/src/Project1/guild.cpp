#include "guild.h"
namespace seneca {
	Guild::Guild() {};

	Guild::Guild(const char* name) {
		m_name = name;
		m_character = nullptr;
		m_size = 0;
	};
	Guild::Guild(const Guild& src) {
		*this = src;
	};

	Guild& Guild::operator=(const Guild& src ){
		if (this != &src) {
			delete[] m_character;

			m_name = src.m_name;
			m_size = src.m_size;
			m_character = new Character * [m_size];
			for (size_t i = 0; i < m_size; ++i) {
				m_character[i] = src.m_character[i]; 
			}
		}
		return *this;
	}

	Guild::~Guild() {

		delete [] m_character;
	};

	Guild::Guild(const Guild&& src) noexcept{
		*this = std::move(src);
	};

	Guild& Guild::operator=(const Guild&& src) noexcept{
		if (this != &src) {
			delete[] m_character;
			m_name = src.m_name;
			m_size = src.m_size;
			m_character = new Character * [m_size];
			for (size_t i = 0; i < m_size; ++i) {
				m_character[i] = src.m_character[i];
			}

		}
		return *this;
	}

	void Guild::addMember (Character* c) {
		bool found = false;
		for (size_t i = 0; i < m_size; i++) {
			if (m_character[i]->getName() == c->getName()) {
				found = true;
			}
		}

		if (!found) {
			c->setHealthMax(c->getHealthMax() + 300); 

			Character** temp = new Character * [m_size + 1];
			for (size_t i = 0; i < m_size; ++i) {
				temp[i] = m_character[i];
			}

			temp[m_size] = c; 
			m_size++;

			delete[] m_character;
			m_character = temp;
		}


	}

	void Guild::removeMember(const std::string& c) {
		bool found = false;
		int position = 0;
		for (size_t i = 0; i < m_size; i++) {
			if (m_character[i]->getName() == c) {
				found = true;
				position = i;
			}
		}

		if (found) {
			m_character[position]->setHealthMax(m_character[position]->getHealthMax() - 300); 

			for (int i = position; i < m_size - 1; i++) {
				m_character[i] = m_character[i + 1];
			}

			Character** temp = new Character * [m_size - 1];
			for (size_t i = 0; i < m_size - 1; ++i) {
				temp[i] = m_character[i];
			}

			delete[] m_character;
			m_character =temp;
			m_size--;
		}
	}



	Character* Guild::operator[](size_t idx) const {
		if (idx <= m_size) {
			return m_character[idx];
		}
		else {
			return nullptr;
		}
		
	}

	void Guild::showMembers() const {
		std::cout << "[Guild] " << m_name << std::endl;
		if (m_size == 0) {
			std::cout << "No guild." << std::endl;
		}
		else if (m_size > 0) {
			for (size_t i = 0; i < m_size; i++) {
				std::cout << "    " << i + 1 << ": " << *m_character[i] << std::endl;
			}
		}
	}
}