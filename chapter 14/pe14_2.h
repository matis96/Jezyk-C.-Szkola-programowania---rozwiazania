//zad2.h
struct miesiac {
	char nazwa[20];
	char skrot[4];
	int dni;
	int numer;
};

struct miesiac miesiace[12]=
{
	{"styczen", "sty", 31, 1},
	{"luty", "lut", 28, 2},
	{"marzec", "mar", 31, 3},
	{"kwiecien", "kwi", 30, 4},
	{"maj", "maj", 31, 5},
	{"czerwiec", "cze", 30, 6},
	{"lipiec", "lip", 31, 7},
	{"sierpien", "sie", 31, 8},
	{"wrzesien", "wrz", 30, 9},
	{"pazdziernik", "paz", 31, 10},
	{"listopad", "lis", 30, 11},
	{"grudzien", "gru", 31, 12}
};
