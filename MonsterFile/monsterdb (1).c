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
            // TODO (1): '?' - print this list of commands
            case  '?' :
                printInfo();
                break;
                // TODO (2): 'r' - read monster database (binary file
            case  'r' :
                printf("DB file name (to read): ");
                scanf("%s", fileName);
                readDb(&monsters, fileName);
                break;
                // TODO (3): 'w' - write monster database (binary file)
            case  'w' :
                writeDb(&monsters, fileName);
                break;
                // TODO (4): 'd' - display monsters
            case  'd' :
                displayMonsters(&monsters);
                break;
                // TODO (5): 'n' - sort monsters by name (ascending)
            case  'n' :
                sortMonsters(&monsters, 'n');
                break;
                // TODO (6): 'h' - sort monsters by hitpoints (descending)
            case  'h' :
                sortMonsters(&monsters, 'h');
                break;
            case  'q' : // 'q'  - quit
                done = 1;
                break;
            default:
                printf("Unknown command `%c`", cmd);
                break;
        }
    }
    return 0;
}

// -----------------------------------------------------------------------
// Function implementations

void printInfo() {
    for (int i = 0; i < N_INFO ; ++i) {
        printf("%s\n", info[i]);
    }
}
void displayMonster(Monster *m) {
    const char * format = "%10s [a:%d, t:%d, hp:%2d] <%-15s mod:%2d>\n";
    printf(format, m->name,
                   m->stats.agility,
                   m->stats.toughness,
                   m->stats.hitpoints,
                   m->weapon.name,
                   m->weapon.damageModifier);
}
void displayMonsters(MonsterList *mMonsters) {
    if (mMonsters->list == NULL) {
        printf("(no monsters loaded)\n");
    } else {
        for (int i=0; i<mMonsters->size;i++)         {
            displayMonster(&mMonsters->list[i]);
        }
    }
}
int swapNeededName(Monster *a, Monster *b) {
    int ret = strcmp(a->name,b->name);
    return ret > 0;
}
int swapNeededHitPoints(Monster *a, Monster *b) {
    int ret = (b->stats.hitpoints) - (a->stats.hitpoints);
    if (ret > 0)
        return 1;
    else
        return 0;
}
void sortMonsters(MonsterList *mMonsters, char sortType) {
    if (mMonsters->list == NULL) {
        printf("(no monsters loaded)\n");
        return;
    }

    for(int i = 1; i < mMonsters->size; i++){
        if (sortType == 'n') {
            for (int j = i; j > 0 && (swapNeededName(&mMonsters->list[j - 1], &mMonsters->list[j]) > 0); j--) {
                Monster tmp = mMonsters->list[j - 1];
                mMonsters->list[j - 1] = mMonsters->list[j];
                mMonsters->list[j] = tmp;
            }
        } else {
            for (int j = i; j > 0 && (swapNeededHitPoints(&mMonsters->list[j - 1], &mMonsters->list[j]) > 0); j--) {
                Monster tmp = mMonsters->list[j - 1];
                mMonsters->list[j - 1] = mMonsters->list[j];
                mMonsters->list[j] = tmp;

            }
        }
    }
    displayMonsters(mMonsters);
}
void readDb(MonsterList *mMonsters, char *fName) {
    FILE *fp;
    fp=fopen(fName,"rb");
    if(fp==NULL)
    {
        printf("Error read a file %s\n", fName);
        return ;
    }

    int nItems = fread(&mMonsters->size, sizeof(int),1, fp);
    printf("%d items read from '%s' (size header)\n", nItems, fName);

    if (mMonsters->list != NULL) { free(mMonsters->list); }

    mMonsters->list = (Monster *) malloc(sizeof(Monster) * mMonsters->size);
    if (mMonsters->list == NULL)
    {
        printf("Allocating heap for %d Monsters...failed to allocate memory!\n", mMonsters->size);
        return ;
    }
    printf("Allocating heap for %d Monsters...memory allocated\n", mMonsters->size);

    nItems = fread(mMonsters->list, sizeof(Monster),mMonsters->size, fp);
    printf("%d items read from '%s' (monster array)\n", nItems, fName);

    fclose(fp);
}
void writeDb(MonsterList *mMonsters, char *fName) {
    if (mMonsters->list == NULL) {
        printf("(no monsters loaded)\n");
        return;
    }

    printf("DB file name (to write): %s\n", fName);

    FILE *fp;
    fp=fopen(fName,"wb");
    if(fp==NULL)
    {
        printf("Error to open a file %s\n", fName);
        return ;
    }

    fwrite(&mMonsters->size, sizeof(int),1, fp);
    printf("1 items written to '%s' (size header)\n", fName);

    fwrite(mMonsters->list, sizeof(Monster),mMonsters->size, fp);
    printf("%d items written to '%s' (monster array)\n", mMonsters->size, fName);

    fclose(fp);
}
// -----------------------------------------------------------------------