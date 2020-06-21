#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <iostream>
#include "Saiyan.h"

using namespace std;

namespace sdds
{
	Saiyan::Saiyan() {
		// default state
		m_name = nullptr;	// Dynamic allocation:  set to nullptr!
		m_dob = 0;
		m_power = -1;
		m_super = false;
		m_level = 0;
	};
	
	Saiyan::Saiyan(const char* name, int dob, int power) {
		set(name, dob, power);
	};

	Saiyan::~Saiyan() {
		if (m_name != nullptr)
		{
			delete[] m_name;	// Deallocate memory of member.
			m_name = nullptr;
		}
	};

	void Saiyan::set(const char* name, int dob, int power, int level, bool super) {
		if (name == nullptr || strlen(name) == 0 || dob > 2020 || power < 0)
		{
			*this = Saiyan();	// Calls constructor that creates default.
		}
		else
		{
			// Deallocate previosly allocated memory for m_name to avoid memory leak:
			if (m_name != nullptr && strlen(name) == 0)
			{
				delete[] m_name;
				m_name = nullptr;
			}
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
			m_level = level;
		}
	};
	
	bool Saiyan::isValid() const {
		// validate Saiyan
		bool valid_state = m_name != nullptr && strlen(m_name) > 0 && m_dob < 2020 && m_power > 0;
		return valid_state;
	};

	void Saiyan::display() const {
		if (isValid())
		{
			cout << m_name << endl;
			
			cout.setf(ios::right);
			cout.width(10);
			cout << "DOB: " << m_dob << endl;
			cout.width(10);
			cout << "Power: " << m_power << endl;
			cout.width(10);
			if (m_super == true) {
				cout << "Super: " << "yes" << endl;
				cout.width(10);
				cout << "Level: " << m_level;
			}
			else
			{
				cout << "Super: " << "no";
			}
			cout.unsetf(ios::left);
		}
		else
		{
			cout << "Invalid Saiyan!";
		}
		cout << endl;
	};

	bool Saiyan::fight(Saiyan& other) {

		if (m_super == true)
		{
			m_power += m_power * (.1 * m_level);
		}
		if (other.m_super == true)
		{
			other.m_power += other.m_power * (.1 * other.m_level);
		}

		bool value = m_power > other.m_power;
		return value;
	};
}
