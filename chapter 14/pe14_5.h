//zad5.h
#define DL 20
#define MAX 10
struct daneos
{
    char imie[DL];
    char nazwisko[DL];
};
struct student
{
    struct daneos person;
    float oceny[10];
    float srednia;
};
