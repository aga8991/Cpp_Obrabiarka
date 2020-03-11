#pragma once
// Czas.h

class Czas
{
	int m_iGodziny;
	int m_iMinuty;
	int m_iSekundy;
public:
	Czas(int s=0, int m=0, int h=0);		//konstruktor
	int	podglad_h();
	int podglad_m();
	int	podglad_s();
	void zabezpieczenie();	// zabezbieczenie + przelicz mozna w jednym
	void przelicz();
	void wprowadz_czas(int s, int m, int h);
	int sprowadz_do_s_obecny();
	int sprowadz_do_s(Czas _czas);
	void ustaw_czas(int h = 0, int m = 0, int s = 0);
	void ustaw_czas(Czas _czas);
	void wyswietl_stan();
	Czas operator+(int s);
	Czas operator+(const Czas& _liczba);
	Czas& operator=(const Czas& _czas);
	bool operator==(const Czas& _liczba);
	bool operator<(const Czas& _liczba);
};
