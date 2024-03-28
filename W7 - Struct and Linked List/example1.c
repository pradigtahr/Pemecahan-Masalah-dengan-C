#include <stdio.h>
#include <string.h>

struct Person
{
    char name[50];
    int atk;
    int def;
    int mana;
} hero;

int main(void){
    // declare variable
    struct Person villain;

    // assign value to name of hero
    strcpy(hero.name, "Spiderman");


    // Assign values to other hero variables
    hero.atk = 10;
    hero.def = 11;
    hero.mana = 20;

    // Print struct variables
    printf("%s\n", hero.name);
    printf("Attack\t: %d\n", hero.atk);
    printf("Defense\t: %d\n", hero.def);
    printf("Mana\t: %d\n", hero.mana);

    return 0;
}
