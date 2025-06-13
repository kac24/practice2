// team.cpp
// 
// Name: King Fung Alec Chan
// Email: kfachan@myseneca.ca
// Student ID: 101733236
// Date: 2025-06-13
//
// I declare that this submission is the result of my own work and I only copied the code 
// that my professor provided to complete my assignments. This submitted piece of work 
// has not been shared with any other student or 3rd party content provider.
#include "team.h"

namespace seneca {
	Team::Team() {};
	Team::Team(const char* name) {
		m_character = nullptr;
		m_name = name;
		m_size = 0;
	};
	Team::~Team() {
		for (int i = 0; i < m_size; i++) {
			delete m_character[i];
		}

		delete[] m_character;
	}


	Team::Team(const Team& src) {
		*this = src; 	
	}

	Team& Team::operator=(const Team& src) {
		if (this != &src) {
			m_name = src.m_name;

			for (int i = 0; i < m_size; ++i) {
				delete m_character[i];
			}
			delete[] m_character;

			m_size = src.m_size;
			m_character = new Character * [m_size];
			for (int i = 0; i < m_size; ++i) {
				m_character[i] = src.m_character[i]->clone();
			}
		}
		return *this;
	}

	Team::Team(Team&& src) noexcept {
		*this = std::move(src);
	}

	Team& Team::operator=(Team&& src) noexcept {
		if (this != &src) {
			for (int i = 0; i < m_size; ++i) {
				delete m_character[i];
			}
			delete[] m_character;

			m_name = std::move(src.m_name);
			m_character = src.m_character;
			m_size = src.m_size;

			src.m_character = nullptr;
			src.m_size = 0;
		}
		return *this;
	}

	void Team::addMember(const Character* c) {
		bool found = false;
		for (int i = 0; i < m_size; i++) {
			if (m_character[i]->getName() == c->getName()) {
				found = true;
			}
		}

		if (!found) {
			Character** temp = new Character*[m_size + 1];
			for (int i = 0; i < m_size; i++) {
				temp[i] = m_character[i];
			}
			temp[m_size] = c->clone();
			delete[] m_character;
			m_character = temp;
			m_size++;
		} 


	}

	void Team::removeMember(const std::string& c) {
		bool found = false;
		int position = 0;
		for (int i = 0; i < m_size; i++) {
			if (m_character[i]->getName() == c) {
				found = true;
				position = i;
			}
		}

		if (found) {
			delete m_character[position];

			for (int i = position; i < m_size - 1; i++) {
				m_character[i] = m_character[i + 1];
			}

			Character** temp = new Character*[m_size - 1];
			for (int i = 0; i < m_size - 1; i++) {
				temp[i] = m_character[i];
			}

			delete[] m_character;
			m_character = temp;
			m_size--;
		}
	}

	Character* Team::operator[](size_t idx) const {
		if (idx < static_cast<size_t>(m_size)) {
			return m_character[idx];
		}
		else {
			return nullptr;
		}
	}
	void Team::showMembers() const {
		std::cout << "[Team] " << m_name << std::endl;
		if (m_size == 0) {
			std::cout << "No team." << std::endl;
		} else  {
			for (int i = 0; i < m_size; i++) {
				std::cout << "    " << i + 1 << ": " << *m_character[i] << std::endl;
			}
		}
	}
}