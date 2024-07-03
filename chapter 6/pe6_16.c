//zad16.c
int main(void)
{
    float Kasia, Ewa;
    int lata=0;
    const int initial = 100;
    const float Ewa_rate = 10.0/100;
    const float Kasia_rate = 5.0/100;
    Kasia = Ewa = initial;
    while (Ewa>=Kasia)
    {

        Ewa += initial*Ewa_rate;
        Kasia += Kasia*Kasia_rate;
        lata++;
    }
    printf("%d\n", lata);
    printf("Ewa po %d latach ma %.2f oszczednosci\n", lata, Ewa);
    printf("Kasia po %d latach ma %.2f oszczednosci", lata, Kasia);
    return 0;
}
