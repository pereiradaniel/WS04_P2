#pragma once
#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

namespace sdds
{
	class Saiyan
	{
			char* m_name{};
			int m_dob;			// Year the Saiyan was born.
			int m_power;		// Integer indicating the strength of the Saiyan (>= 0).
			bool m_super;		// indicates whether Saiyan can evolve
			int m_level;		// an integer indicating the level of a SS

		/*
		***Valid Name*** : a string that contains at least one character, but less than 32.
		***Valid Year of Birth***: an integer within the interval[0, 2020].
		***Valid Power***: an integer that is greater than 0.
		*/

	public:
		Saiyan();
		Saiyan(const char* name, int dob, int power);  // Custom constructor
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		bool isValid() const;
		void display() const;
		bool fight(Saiyan& other);
		~Saiyan();
	};
}

#endif