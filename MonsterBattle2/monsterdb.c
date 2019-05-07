// -----------------------------------------------------------------------
// monsterdb.c
// -----------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// -----------------------------------------------------------------------
// Some defines
#define NAME_MAX 64
#define BUFFER_MAX 256

// User instructions
const char *info[] = {
  "Enter a command:",
  "",
  "  ?  - print this list of commands",
  "  r  - read monster database (binary file)",
  "  w  - write monster database (binary file)",
  "  d  - display monsters",
  "  n  - sort monsters by name (ascending)",
  "  h  - sort monsters by hitpoints (descending)",
  "  q  - quit",
};
const int N_INFO = 9;


// -----------------------------------------------------------------------
// Structs

typedef struct Weapon_struct {
    char name[NAME_MAX];
    int damageModifier;
} Weapon;

typedef struct Stats_struct {
    int agility;
    int toughness;
    int hitpoints;
} Stats;

typedef struct Monster_struct {
    char name[NAME_MAX];
    Stats stats;
    Weapon weapon;
} Monster;

typedef struct MonsterList_struct {
    int size;
    Monster *list;
} MonsterList;


// -----------------------------------------------------------------------
// Function prototypes

void printInfo();
void displayMonster(Monster *m);
void displayMonsters(MonsterList *monsters);
int swapNeededName(Monster *a, Monster *b);
int swapNeededHitPoints(Monster *a, Monster *b);
void sortMonsters(MonsterList *monsters, char sortType);
void readDb(MonsterList *monsters, char *fileName);
void writeDb(MonsterList *monsters, char *fileName);

// -----------------------------------------------------------------------
// Main Program

int main() {
    MonsterList monsters = {0, NULL};
    char fileName[BUFFER_MAX];
    char userIn[BUFFER_MAX];
    char cmd;

    printInfo();

    int done = 0;
    while (!done) {
        printf("\n> ");
        scanf("%s", userIn);
        cmd = userIn[0];

        switch (cmd) {
            // TODO (1): '?' command
            // TODO (2): 'r' command
            // TODO (3): 'w' command
            // TODO (4): 'd' command
            // TODO (5): 'n' command
            // TODO (6): 'h' command
            // TODO (7): 'q' command

            default:
                printf("Unknown command `%c`", cmd);
                break;
        }
    }
    return 0;
}

// -----------------------------------------------------------------------
// Function implementations

// TODO (8): void printInfo();
// TODO (9): void displayMonster(Monster *m);
// TODO (10): void displayMonsters(MonsterList *monsters);
// TODO (11): int swapNeededName(Monster *a, Monster *b);
// TODO (12): int swapNeededHitPoints(Monster *a, Monster *b);
// TODO (13): void sortMonsters(MonsterList *monsters, char sortType);
// TODO (14): void readDb(MonsterList *monsters, char *fileName);
// TODO (15): void writeDb(MonsterList *monsters, char *fileName);

// -----------------------------------------------------------------------
