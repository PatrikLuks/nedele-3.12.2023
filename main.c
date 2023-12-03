#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define POCET_PRVKU 8


int generujNahodneBinarniCislo() {   // Funkce pro generování náhodného čísla mezi 0 a 1
    return rand() % 2;  // Funkce vrací náhodné číslo 0 nebo 1
}

void naplnPoleBinarnimiCisly(int binarniPole[], int delkaPole) { // Funkce pro naplnění pole binárními čísly
    for (int i = 0; i < delkaPole; i++) {    // Cyklus, ve kterém se doplňuje do délky pole zadáno uživatelem
        binarniPole[i] = generujNahodneBinarniCislo();   // Každá pozice pole se naplní náhodným binárním číslem
    }
}

int prevedNaDesitkoveCislo(int binarniPole[], int delkaPole) { // funkce prevadici binarni cislo do desitkoveho
    int desitkoveCislo = 0; //promena ne nastavi na nulu
    for (int i = 0; i < delkaPole; i++) {   //cyklus, ve kterem se dopocitava do delky pole
        desitkoveCislo = desitkoveCislo * 2 + binarniPole[i];   //vypocet binarniho cisla do desitkoveho
    }
    return desitkoveCislo;  //funkce vraci promenou s hodnotou desitkoveho cisla
}

int main() {
    int repete; //promena slouzici k opakovani vypisu binarniho cisla podle volby uzivatele

    printf("Kolikrát se má vygenerovat číslo? ");
    scanf("%d", &repete);   //scan uzivatelskeho vstupu

    srand(time(NULL)); // Kód pro generování náhodných čísel

        int delkaPole;  // Vytvoří se proměnná délky pole

        printf("Zadejte velikost pole (8, 16 nebo 32 prvků): ");
        scanf("%d", &delkaPole); // Do proměnné délky pole se vloží zadané číslo

        for (int k = 0; k < repete; k++) {
            int binarniPole[delkaPole]; // Vytvoří se pole o délce zadné uživatelem

            naplnPoleBinarnimiCisly(binarniPole, delkaPole); // Vyvolání funkce pro naplnění pole binárními čísly

            printf("Binární číslo: "); // Výpis binárního čísla z pole
            for (int i = 0; i < delkaPole; i++) {   //cyklus, ktery dopocitava index delky pole, a tim vypise binarni cisla
                printf("%d", binarniPole[i]);   //vypisuje binarni cisla z pole. cyklus for zajistuje vypis cisel na vsech pozicich
            }

            int desitkoveCislo = prevedNaDesitkoveCislo(binarniPole, delkaPole);    //do promene desitkoveCislo se nahraje hodnota ziskana pomoci pole a jeho delky
            printf(" = Desítkové číslo: %d\n", desitkoveCislo); //vypise se cislo prevedene do desitkove soustavy

    }

    return 0;

}