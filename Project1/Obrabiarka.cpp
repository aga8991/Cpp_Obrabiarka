// Obrabiarka.cpp
#include "Obrabiarka.h"
#include "Czas.h"
#include <iostream>


Obrabiarka::Obrabiarka(const Obrabiarka& _obrabiarka)
{
	ilosc = _obrabiarka.ilosc;
	lista_czasow = new Czas[ilosc];
	for (int i = 0; i < ilosc; i++)
	{
		lista_czasow[i] = _obrabiarka.lista_czasow[i];
	}
}

Obrabiarka::Obrabiarka(Czas _czas)
{
	ilosc += 1;
	Czas *ptr = nullptr;
	ptr = lista_czasow;
	lista_czasow = new Czas[ilosc];
	for (int i = 0; i < ilosc - 1; i++)
	{
		lista_czasow[i] = ptr[i];
	}
	lista_czasow[ilosc - 1] = _czas;
	delete[] ptr;
}

Obrabiarka::Obrabiarka()
{
	lista_czasow = nullptr;
	ilosc = 0;
}

Obrabiarka::~Obrabiarka()
{
	delete[] lista_czasow;
}

void Obrabiarka::dodaj_czas(Czas _czas)
{
	ilosc++;
	if (ilosc > 1)
	{
		Czas *ptr = nullptr;
		ptr = lista_czasow;
		lista_czasow = new Czas[ilosc];
		for (int i = 0; i < ilosc - 1; i++)
		{
			lista_czasow[i] = ptr[i];
		}
		lista_czasow[ilosc - 1] = _czas;
		delete[] ptr;
	}
	else
	{
		lista_czasow = new Czas[ilosc];
		lista_czasow[ilosc - 1] = _czas;
	}
}

void Obrabiarka::dodaj_czas(int s, int m, int h)
{
	Czas _czas(s+(m*60)+(h*3600));
	dodaj_czas(_czas);
}

Czas Obrabiarka::zsumuj_czasy()
{
	Czas suma;

	if (ilosc != 0)
	{
		for (int i = 0; i < ilosc; i++)
		{
			suma = suma + lista_czasow[i];
		}
	}
		return suma;
}

int Obrabiarka::odczyt_ilosci()
{
	return ilosc;
}

void Obrabiarka::wypisz_czas(int _ktory)
{
	lista_czasow[_ktory - 1].wyswietl_stan();
}

void Obrabiarka::wypisz_czasy()
{
	for(int i = 0; i < ilosc; i++)
	{
		lista_czasow[i].wyswietl_stan();
	}
}

Obrabiarka& Obrabiarka::operator=(const Obrabiarka& _obrabiarka)
{
	if (&_obrabiarka == this)
	{
		return *this;
	}
	delete[] lista_czasow;
	ilosc = _obrabiarka.ilosc;
	lista_czasow = new Czas[ilosc];
	for (int i = 0; i < ilosc; i++)
	{
		lista_czasow[i] = _obrabiarka.lista_czasow[i];
	}
	return *this;
}

void Obrabiarka::kopia_n_czasow(int _liczba_czasow, const Obrabiarka& _kopiowana)
{
	if (_liczba_czasow >= 1)
	{
		if ((_liczba_czasow > _kopiowana.ilosc))
		{
			_liczba_czasow = _kopiowana.ilosc;
		}
		delete[] lista_czasow;
		ilosc = _liczba_czasow;
		lista_czasow = new Czas[_liczba_czasow];
		for (int i = 0; i < _liczba_czasow; i++)
		{
			lista_czasow[i] = _kopiowana.lista_czasow[i];
		}
	}
}

Obrabiarka Obrabiarka::kopia_n_czasow(int _liczba_czasow)
{
	Obrabiarka temp_obr;

	if (_liczba_czasow >= 1)
	{
		if ((_liczba_czasow > ilosc))
		{
			_liczba_czasow = ilosc;
		}

		temp_obr.ilosc = _liczba_czasow;
		temp_obr.lista_czasow = new Czas[_liczba_czasow];
		for (int i = 0; i < _liczba_czasow; i++)
		{
			temp_obr.lista_czasow[i] = lista_czasow[i];
		}
	}
	return temp_obr;
}

Obrabiarka Obrabiarka::kopia_do_czasu(const Czas& _czas)
{
	Czas temp_czas;
	Obrabiarka temp_obr;
	int i = 0;

	while (temp_czas < _czas)
	{
		temp_czas.ustaw_czas(temp_czas + lista_czasow[i]);
		if (!(temp_czas < _czas || temp_czas == _czas)) break;
		else temp_obr.dodaj_czas(lista_czasow[i]);
		i++;
		if (i > ilosc) break;
	}

	return temp_obr;
}

Obrabiarka Obrabiarka::kopia_do_czasu(int s,int m, int h)
{
	Obrabiarka temp_obr;
	Czas _czas(s, m, h);
	temp_obr = kopia_do_czasu(_czas);
	return temp_obr;
}