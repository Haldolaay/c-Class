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
    //fileName = "monsterdb.c";
    int done = 0;
    while (!done) {
        printf("\n> ");
        scanf("%s", userIn);
        cmd = userIn[0];

        switch (cmd) {

            // TODO (1): '?' command
            case '?': printInfo(); break;
                // TODO (2): 'r' command
            case 'r':
                printf("DB file name (to read): ");
                scanf("%s", fileName);
                displayMonsters(&monsters); break;
                // TODO (3): 'w' command
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

// TODO (8): void printInfo();
void printInfo(){
    for(int i = 0; i<N_INFO; i++){
        printf("%s\n",info[i]);
    }
}//DONE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


void displayMonster(Monster *m){
    printf("%10s [a:%d, t:%d, hp:%2d] <%-15s mod:%2d>\n",m->name, m->stats.agility,m->stats.toughness,m->stats.hitpoints, m->weapon.name,m->weapon.damageModifier);
}
void displayMonsters(MonsterList *monsters){
    if (monsters->list == NULL) {
        printf("(no monsters loaded)\n");
    }else {
        for (int i=0; i<monsters->size;i++){
            displayMonster(&monsters->list[i]);
        }

    }
}
// }
// TODO (11): int swapNeededName(Monster *a, Monster *b);
int swapNeededName(Monster *a, Monster *b){
    int result = strcmp(a->name,b->name);
    return result > 0;

}
// TODO (12): int swapNeededHitPoints(Monster *a, Monster *b);
int swapNeededHitPoints(Monster *a, Monster *b){
    int result = b->stats.hitpoints - a->stats.hitpoints;
    return result >0?1:0;

}

// TODO (13): void sortMonsters(MonsterList *monsters, char sortType);

void sortMonsters(MonsterList *monsters, char sortType){
    Monster temp;
    if (sortType == 'n'){
        for ( int i = 1; i < monsters->size; ++i) {
            int j = i;

            while (j > 0 && (swapNeededName(&monsters->list[j - 1], &monsters->list[j]) > 0)) {


                temp = monsters->list[j];
                monsters->list[j] = monsters ->list [j-1];
                monsters ->list [j-1] = temp;
            }
        }
    }else if (sortType == 'h'){
        for ( int i = 1; i < monsters->size; ++i) {
            int j = i;

            // while (j > 0 && monsters->list[j].stats.hitpoints < monsters->list[j-1].stats.hitpoints) {
            while (j > 0 &&(swapNeededHitPoints(&monsters->list[j-1],& monsters->list[j]))>0) {

                temp = monsters->list[j];
                monsters->list[j] = monsters ->list [j-1];
                monsters ->list [j-1] = temp;
            }
        }
    }
    displayMonsters(monsters);
}
// TODO (14): void readDb(MonsterList *monsters, char *fileName);
void readDb(MonsterList *monsters, char *fileName){
    FILE* rFile= fopen(fileName, "rb");
    if( rFile == NULL ) {
        printf("Error read a file %s\n", fileName);

    }else{
        printf("DB file name (to read): ");
        int numItems =fread(&monsters->size, sizeof(int), 1, rFile);
        printf("%d items read from '%s' (size header)\n", numItems, fileName);
        if (monsters->size == 0){
            printf("Failed to open 'no-such-file.bin' for read");
        }else{
            if (monsters->list != NULL){free(monsters->list);}
            monsters->list = (Monster *)malloc(monsters->size * sizeof(  Monster));
            if (monsters->list ==NULL){
                printf("failed to allocate memory!");
                exit(1);
            }else{
                printf("%d items read from 'rabble1.bin' (monster array)",monsters->size);
            }

            printf("%d items read from 'rabble1.bin' (size header)\n",monsters->size);
            printf("Allocating heap for %d Monsters...\n",monsters->size);

        }
        fread(monsters->list,sizeof(Monster),monsters->size,rFile);
    }
}
// TODO (15): void writeDb(MonsterList *monsters, char *fileName);
void writeDb(MonsterList *monsters, char *fileName){
    if (monsters->list == NULL) {
        printf("(no monsters loaded)\n");

    }else{
        FILE* wFile= fopen(fileName, "wb");
        if( wFile == NULL ) {
            printf("Failed to open 'no-such-file.bin' for read");
            exit(1);
        }
        printf("DB file name (to write):%s", fileName);
        printf("source address: %p", &monsters->size);
        fwrite(&monsters->size, sizeof(int),1,wFile);
        printf("1 items written to '%s' (size header)\n", fileName);
        fwrite(&monsters->size,sizeof(Monster),monsters->size,wFile);
        printf("%d items written to '%s' (monster array)\n", monsters->size, fileName);

        fclose(wFile);
    }
}
// -----------------------------------------------------------------------
