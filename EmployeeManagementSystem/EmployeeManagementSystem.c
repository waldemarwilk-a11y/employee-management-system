#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

void DodajPracownika();
void EdytujPracownika();
void ListaPracownikow();
void UsunInformacje();
void Wyjscie_z_Aplikacji();

COORD c = { 0, 0 };
FILE* fp, * ft;
char wybor, another;

struct Pracownik
{
    char imie[20];
    char nazwisko[20];
    int wiek;
    long int telefon;
    float wynagrodzenie;
};

struct Pracownik e;
char Pracowniknazwisko[20];
int recsize;

void setxy(int x, int y)
{
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void login()
{
    char Login[] = "111";
    char Haslo[] = "111";
    char id[20], h[20];

    int n = 1, x, y, i;

    do
    {
        setxy(47, 3);
        printf("LOGOWANIE");

        setxy(45, 4);
        printf("Login:");
        scanf("%s", id);

        setxy(45, 5);
        printf("Haslo:");
        int j = 0;
        char znak;

        while ((znak = _getch()) != 13)
        {
            h[j++] = znak;
            printf("*");
        }
        h[j] = '\0';

        x = strcmp(id, Login);
        y = strcmp(h, Haslo);

        if (x == 0 && y == 0)
        {
            setxy(45, 9);
            printf("Zalogowano pomyslnie");
            break;
        }
        else
        {
            printf("\nZle haslo, sprobuj jeszcze raz");
            _getch();
            system("cls");
            n++;
        }

        if (n > 5)
        {
            setxy(35, 12);
            printf("Odmowa dostepu z powodu zbyt wielu prob logowania");
            _getch();
            exit(2);
        }

    } while (n <= 5);

    for (i = 1; i <= 3; i++)
    {
        printf(".");
        Sleep(1000);
    }
}

int main()
{
    recsize = sizeof(e);

    login();

    fp = fopen("EMP.DAT", "rb+");

    if (fp == NULL)
    {
        fp = fopen("EMP.DAT", "wb+");

        if (fp == NULL)
        {
            printf("Nie mozna otworzyc pliku");
            exit(1);
        }
    }

    while (1)
    {
        system("cls");

        setxy(30, 2);
        printf("============================================================");

        setxy(44, 3);
        printf("SYSTEM ZARZADZANIA PRACOWNIKAMI");

        setxy(30, 4);
        printf("============================================================");

        setxy(43, 6);
        printf("1. Dodaj informacje o pracowniku");

        setxy(43, 8);
        printf("2. Edytuj dane pracownika");

        setxy(43, 10);
        printf("3. Lista pracownikow");

        setxy(43, 12);
        printf("4. Usun informacje pracownika");

        setxy(43, 14);
        printf("5. Wyjdz");

        setxy(43, 16);
        printf("Twoj wybor: ");

        setxy(58, 16);
        wybor = _getche();

        switch (wybor)
        {
        case '1':
            DodajPracownika();
            break;

        case '2':
            EdytujPracownika();
            break;

        case '3':
            ListaPracownikow();
            break;

        case '4':
            UsunInformacje();
            break;

        case '5':
            Wyjscie_z_Aplikacji();
            break;

        default:
            system("cls");
            setxy(50, 10);
            printf("ZLY WYBOR!");
            _getch();
            break;
        }
    }

    return 0;
}

void DodajPracownika()
{
    system("cls");

    fseek(fp, 0, SEEK_END);

    another = 'y';

    while (another == 'y')
    {
        printf("\nPodaj imie pracownika: ");
        scanf("%s", e.imie);

        printf("Podaj nazwisko: ");
        scanf("%s", e.nazwisko);

        printf("Podaj wiek: ");
        scanf("%d", &e.wiek);

        printf("Podaj numer telefonu: ");
        scanf("%ld", &e.telefon);

        printf("Podaj wynagrodzenie: ");
        scanf("%f", &e.wynagrodzenie);

        fwrite(&e, recsize, 1, fp);
        printf("\nPracownik zostal dodany pomyslnie.\n");

        printf("\nAby dodac nastepnego pracownika wcisnij y: ");
        another = _getche();
    }
}

void EdytujPracownika()
{
    system("cls");

    char znaleziono;
    int opcja;

    another = 'y';

    while (another == 'y')
    {
        znaleziono = 0;

        printf("Podaj nazwisko pracownika do edycji: ");
        scanf("%s", Pracowniknazwisko);

        rewind(fp);

        while (fread(&e, recsize, 1, fp) == 1)
        {
            if (strcmp(e.nazwisko, Pracowniknazwisko) == 0)
            {
                znaleziono = 1;

                printf("\nZnaleziono pracownika:\n");
                printf("---------------------------------\n");
                printf("Imie: %s\n", e.imie);
                printf("Nazwisko: %s\n", e.nazwisko);
                printf("Wiek: %d\n", e.wiek);
                printf("Telefon: %ld\n", e.telefon);
                printf("Wynagrodzenie: %.2f\n", e.wynagrodzenie);
                printf("---------------------------------\n");

                printf("\nCo chcesz edytowac?\n");
                printf("1. Imie\n");
                printf("2. Nazwisko\n");
                printf("3. Wiek\n");
                printf("4. Telefon\n");
                printf("5. Wynagrodzenie\n");

                printf("\nWybor: ");
                scanf("%d", &opcja);

                switch (opcja)
                {
                case 1:
                    printf("Nowe imie: ");
                    scanf("%s", e.imie);
                    break;

                case 2:
                    printf("Nowe nazwisko: ");
                    scanf("%s", e.nazwisko);
                    break;

                case 3:
                    printf("Nowy wiek: ");
                    scanf("%d", &e.wiek);
                    break;

                case 4:
                    printf("Nowy telefon: ");
                    scanf("%ld", &e.telefon);
                    break;

                case 5:
                    printf("Nowe wynagrodzenie: ");
                    scanf("%f", &e.wynagrodzenie);
                    break;

                default:
                    printf("Niepoprawny wybor.\n");
                    break;
                }

                fseek(fp, -recsize, SEEK_CUR);
                fwrite(&e, recsize, 1, fp);

                printf("\nDane zostaly zaktualizowane.\n");
                break;
            }
        }

        if (!znaleziono)
        {
            printf("\nNie znaleziono pracownika o podanym nazwisku.\n");
        }

        printf("\nEdytuj kolejnego pracownika? (y/n): ");
        another = _getche();
    }
}

void ListaPracownikow()
{
    system("cls");

    printf("=====================================================================\n");
    printf("%-15s %-15s %-8s %-15s %-12s\n",
        "IMIE",
        "NAZWISKO",
        "WIEK",
        "TELEFON",
        "PENSJA");

    printf("=====================================================================\n");

    rewind(fp);

    while (fread(&e, recsize, 1, fp) == 1)
    {
        printf("%-15s %-15s %-8d %-15ld %-12.2f\n",
            e.imie,
            e.nazwisko,
            e.wiek,
            e.telefon,
            e.wynagrodzenie);
    }

    printf("\nNacisnij dowolny klawisz...");
    _getch();
}
void UsunInformacje()
{
    system("cls");

    another = 'y';

    while (another == 'y')
    {
        printf("\nPodaj nazwisko pracownika do usuniecia: ");
        scanf("%s", Pracowniknazwisko);

        ft = fopen("Tym.dat", "wb");

        rewind(fp);

        while (fread(&e, recsize, 1, fp) == 1)
        {
            if (strcmp(e.nazwisko, Pracowniknazwisko) != 0)
            {
                fwrite(&e, recsize, 1, ft);
            }
        }

        fclose(fp);
        fclose(ft);

        remove("EMP.DAT");
        rename("Tym.dat", "EMP.DAT");

        fp = fopen("EMP.DAT", "rb+");

        printf("\nPracownik zostal usuniety pomyslnie.");
        printf("\nCzy chcesz usunac kolejnego pracownika? (y/n): ");
        another = _getche();
    }
}

void Wyjscie_z_Aplikacji()
{
    system("cls");

    setxy(35, 12);
    printf("Dziekujemy za skorzystanie z programu!");

    Sleep(3000);

    fclose(fp);

    exit(0);
}