#pragma once
// Obrabiarka.h
#include "Czas.h"

class Obrabiarka
{
private:
	Czas *lista_czasow;
	int ilosc;
public:
	Obrabiarka(const Obrabiarka& _obrabiarka);		//konstruktory
	Obrabiarka(Czas _czas);
	Obrabiarka(); 
	~Obrabiarka();									//destruktor
	void dodaj_czas(Czas _czas);
	void dodaj_czas(int s = 0, int m = 0, int h = 0);
	int	odczyt_ilosci();
	Czas zsumuj_czasy();
	void wypisz_czas(int _ktory);
	void wypisz_czasy();
	void kopia_n_czasow(int _ilu, const Obrabiarka& _kopiowana);   // nie wg instrukcji
	Obrabiarka kopia_n_czasow(int _ilu);
	Obrabiarka kopia_do_czasu(const Czas& _czas);
	Obrabiarka kopia_do_czasu(int s = 0, int m = 0, int h =0);
	Obrabiarka& operator=(const Obrabiarka& _obrabiarka);
};
