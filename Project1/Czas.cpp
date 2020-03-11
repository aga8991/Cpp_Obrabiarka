// Czas.cpp
#include "Czas.h"
#include <iostream>

// Pomocnicze:

void Czas::przelicz()			//przelicza odpowiednio ilosc sekund, minut i godzin
{
	int x = m_iSekundy / 60;
	m_iMinuty += x;
	m_iSekundy -= x * 60;
	x = m_iMinuty / 60;
	m_iGodziny += x;
	m_iMinuty -= x * 60;
}

void Czas::zabezpieczenie()		//zabezpiecza przed wprowadzeniem ujemnych wartosci
{
	if (m_iSekundy	< 0)	m_iSekundy = 0;
	if (m_iMinuty	< 0)	m_iMinuty = 0;
	if (m_iGodziny	< 0)	m_iGodziny = 0;
}

void Czas::wprowadz_czas(int s, int m, int h)
{
	m_iSekundy = s;
	m_iMinuty = m;
	m_iGodziny = h;
	zabezpieczenie();
	przelicz();
}

int Czas::sprowadz_do_s_obecny()		//sprowadzanie czasu do sekund
{
	int wynik = (m_iGodziny * 3600) + (m_iMinuty * 60) + (m_iSekundy);
	return wynik;
}

int Czas::sprowadz_do_s(Czas _wartosc)		//sprowadzanie czasu innego obiektu niz this tej klasy do sekund
{
	int wynik = (_wartosc.m_iGodziny * 3600) + (_wartosc.m_iMinuty * 60) + (_wartosc.m_iSekundy);
	return wynik;
}

// Niezbedne:

Czas::Czas(int s, int m, int h)
{
	wprowadz_czas(s, m, h);
}

int Czas::podglad_h()
{
	return m_iGodziny;
}

int Czas::podglad_m()
{
	return m_iMinuty;
}

int Czas::podglad_s()
{
	return m_iSekundy;
}

void Czas::ustaw_czas(int s, int m, int h)
{
	wprowadz_czas(s, m, h);
}

void Czas::ustaw_czas(Czas _czas)
{
	wprowadz_czas(_czas.m_iSekundy, _czas.m_iMinuty, _czas.m_iGodziny);
}

void Czas::wyswietl_stan()
{
	std::cout << m_iGodziny << " godz\t" << m_iMinuty << " min\t" << m_iSekundy << " s\t" << std::endl;
}

Czas Czas::operator+(int s)
{
	Czas temp_czas;
	temp_czas.m_iSekundy = m_iSekundy + s;
	temp_czas.m_iMinuty = m_iMinuty;
	temp_czas.m_iGodziny = m_iGodziny;
	temp_czas.zabezpieczenie();
	temp_czas.przelicz();
	return temp_czas;
}

Czas Czas::operator+(const Czas& wartosc)
{
	Czas temp_czas;
	return temp_czas + sprowadz_do_s(wartosc);
}

Czas& Czas::operator=(const Czas& _czas)
{
	wprowadz_czas(_czas.m_iSekundy, _czas.m_iMinuty, _czas.m_iGodziny);
	return *this;
}

bool Czas::operator==(const Czas& wartosc) 
{
	if ((sprowadz_do_s_obecny()) == (sprowadz_do_s(wartosc)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Czas::operator<(const Czas& wartosc)
{
	if ((sprowadz_do_s_obecny()) < (sprowadz_do_s(wartosc)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
