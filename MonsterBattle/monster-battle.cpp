//#include "pch.h"
// -----------------------------------------------------------------------
// monster-battle.cpp
// -----------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;

// -----------------------------------------------------------------------
// Global constants
const int LINE_WIDTH = 16;


// -----------------------------------------------------------------------
// Structs

struct Weapon {
	string name;
	int damageModifier;
};

struct Stats {
	// TODO (1): declare agility, toughness, and hitpoints
	int agility;
	int toughness;
	int hitpoints;
};

struct Monster {
	// TODO (2): declare name, stats, and weapon
	string name;
	Stats stats;
	Weapon weapon;
} ;

// TODO (3): declare Hero struct
struct Hero {
	string name;
	Stats stats;
	Weapon weapon;
};


// -----------------------------------------------------------------------
// Function prototypes

// print a newline, then LINE_WIDTH dashes, followed by the given title string
void printHeading(const string& title);

// Output agility, toughness, and hitpoints, NO newline
void displayStats(const Stats& s);

// Output Weapon name and damageModifier, NO newline
void displayWeapon(const Weapon& w);

// Output name, stats, and weapon (single line)
void displayMonster(const Monster& m);

// Display each monster in the vector (one per line)
void displayMonsters(const vector<Monster>& lair);

// Output name, stats, and weapon (single line)
void displayHero(const Hero& h);

// Roll a d6 numDice times (nd6)
int d6Roll(int numDice);

// Hero attacks a Monster
void attackMonster(const Hero& h, Monster& m);

// Monster attacks the Hero
void attackHero(const Monster& m, Hero& h);

// Hero attacks each Monster in the lair
void heroTurn(const Hero& h, vector<Monster>& lair);

// Each Monster in the lair attacks the Hero
void monstersTurn(const vector<Monster>& lair, Hero& h);

// Returns true if no Monster in the lair has hitpoints > 0
bool lairCleared(const vector<Monster>& lair);

// Begin an epic battle!  displayHero, displayMonsters
// loop as long as the hero is alive and the lair is not clear
void enterLair(Hero& h, vector<Monster>& lair);


// -----------------------------------------------------------------------
// Main Program

int main() {
	int battleSeed;
	cout << "Enter battle number (int): ";
	cin >> battleSeed;
	srand(battleSeed);

	// create some weapons
	Weapon teeth = {"teeth/claws", -3};
	Weapon axe = {"sharp axe", +1};
	Weapon club = {"spiked club", +2};
	Weapon dagger = {"steel dagger", +2};

	// create a lair of monsters
	vector<Monster> lair;
	lair.push_back({"Rat", Stats{4, 4, 2}, teeth});
	lair.push_back({"Goblin", Stats{3, 6, 9}, axe});
	lair.push_back({"Ogre", Stats{2, 8, 16}, club});

	// create the hero
	Hero hero = {"Darwin", Stats{4, 7, 20}, dagger};

	// enter the lair; only return when the game is over.
	enterLair(hero, lair);

	// Did the hero get out alive?
	printHeading("The battle is over!");

	cout << hero.name << " has "
		 << hero.stats.hitpoints << " hitpoints left!" << endl;

	if (lairCleared(lair)) {
		cout << "*** You Win! ***" << endl;
	} else {
		cout << "=== Game Over ===" << endl;
	}

	return 0;
}

// -----------------------------------------------------------------------
// Function implementations

// TODO (4): printHeading
// print a newline, then LINE_WIDTH dashes, followed by the given title string
void printHeading(const string& title) {
	cout << endl;
	cout << setfill('-') << setw(LINE_WIDTH) << "";
	cout << title << "";
	cout << endl;
}

// TODO (5): displayStats
// Output agility, toughness, and hitpoints, NO newline
void displayStats(const Stats& s) {
	cout << "[a:" << s.agility;
	cout << ", t:" << s.toughness;
	cout << ", hp:" << s.hitpoints;
	cout << "]";
	//cout << "[a:" << s.agility << ", t:" << s.toughness << ", hp:" << s.hitpoints  << "] ";
}

// TODO (6): displayWeapon
// Output Weapon name and damageModifier, NO newline
// If damageModifier >= 0 prepend a "+"
void displayWeapon(const Weapon& w) {
	cout << "<" << w.name << ", ";
	if (w.damageModifier >= 0)
		cout << '+';
	cout << w.damageModifier << ">";
}


// TODO (7): displayMonster
// Output name, stats, and weapon (single line)
void displayMonster(const Monster& m) {
	cout << m.name << " ";
	displayStats(m.stats);
	cout << " ";
	displayWeapon(m.weapon);
	cout << endl;
}

// TODO (8): displayMonsters
// Display each monster in the vector (one per line)
void displayMonsters(const vector<Monster>& lair) {
	for (size_t i = 0; i < lair.size(); i++) {
		cout << lair[i].name << " ";
		displayStats(lair[i].stats);
		cout << " ";
		displayWeapon(lair[i].weapon);
		cout << endl;
	}
}

// TODO (9): displayHero
// Output name, stats, and weapon (single line)
void displayHero(const Hero& h) {
	cout << h.name << " ";
	displayStats(h.stats);
	cout << " ";
	displayWeapon(h.weapon);
	cout << endl;
}

// TODO (10): d6Roll
// Roll a d6 numDice times (nd6)
int d6Roll(int numDice) {
	int dice = 0;
	for (int i = 0; i < numDice; i++)
	{
		dice += (rand() % 6) + 1;
	}
	return dice;
}

// TODO (11): attackMonster
// Hero attacks a Monster
//   (See rules in project description)
void attackMonster(const Hero& h, Monster& m) {
	int roll = d6Roll(1);
	cout << h.name << " attacks " << m.name << " with " << h.weapon.name << "..." << endl;
	cout << "  Hit? " << roll << " >= " << m.stats.agility << " (agility) ";
	if (roll >= m.stats.agility) {
		cout << ": yes" << endl;
		cout << h.name << " hits " << m.name << "..." << endl;
		roll = d6Roll(2);
		cout << "  Inflict? " << roll << " > " << m.stats.toughness << " (toughness) ";
		if (roll > m.stats.toughness) {
			cout << ": yes" << endl;
			roll = d6Roll(2);
			int d = h.weapon.damageModifier + roll;
			d = (d < 0) ? 0 : d;
			cout << h.name << " inflicts " << d << " points of damage..." << endl;
			m.stats.hitpoints = m.stats.hitpoints - d;
			if (m.stats.hitpoints <= 0) {
				cout << m.name << " is slain!" << endl;
			}
			else
				cout << m.name << " is wounded." << endl;
		}
		else {
			cout << ": no" << endl;
			cout << m.name << "'s toughness prevents damage.";
		}
	}
	else {
		cout << ": no" << endl;
		cout << h.name << " misses." << endl;
	}
}

// TODO (12): attackHero
// Monster attacks the Hero
//   (Same rules as above)
void attackHero(const Monster& m, Hero& h) {
	int roll = d6Roll(1);
	//cout << endl
	cout << m.name << " attacks " << h.name << " with " << m.weapon.name << "..." << endl;
	cout << "  Hit? " << roll << " >= " << h.stats.agility << " (agility)";
	if (roll >= h.stats.agility) {
		cout << " : yes" << endl;
		cout << m.name << " hits " << h.name << "..." << endl;
		roll = d6Roll(2);
		cout << "  Inflict? " << roll << " > " << h.stats.toughness << " (toughness)";
		if (roll > h.stats.toughness) {
			cout << " : yes" << endl;
			roll = d6Roll(2);
			int d = m.weapon.damageModifier + roll;
			d = (d < 0) ? 0 : d;
			cout << m.name << " inflicts " << d << " points of damage..." << endl;
			h.stats.hitpoints = h.stats.hitpoints - d;
			if (h.stats.hitpoints <= 0) {
				cout << h.name << " is slain!" << endl;
			}
			else
				cout << h.name << " is wounded." << endl;
		}
		else {
			cout << " : no" << endl;
			cout << h.name << "'s toughness prevents damage.";
		}
	}
	else {
		cout << ": no" << endl;
		cout << m.name << " misses." << endl;
	}
}
// TODO (13): heroTurn
// Hero attacks each Monster in the lair
//  - print the heading "The hero strikes..."
//  - display the hero
//  - loop through the vector:
//      - for each monster with remaining hitpoints, print a blank line,
//        then call attackMonster().
void heroTurn(const Hero& h, vector<Monster>& lair) {
	printHeading("The hero strikes...");
	displayHero(h);
	for (size_t i = 0; i < lair.size(); i++) {
		if (lair.at(i).stats.hitpoints >= 0){
			cout << endl;
			attackMonster(h, lair[i]);
		}else{continue;}

	}}

// TODO (14): monstersTurn
// Each Monster in the lair attacks the Hero
//  - print the heading "The monsters attack..."
//  - loop through the vector:
//      - for each monster with remaining hitpoints, print a blank line,
//        then call displayMonster(), followed by attackHero(). If the
//        hero's hitpoints drop to zero (or less), break out of the loop.
void monstersTurn(const vector<Monster>& lair, Hero& h) {
	printHeading("The monsters attack...");
	cout<<endl;
	for (size_t i = 0; i < lair.size(); i++) {
		if (lair[i].stats.hitpoints > 0) {
			displayMonster(lair[i]);
			attackHero(lair[i], h);
		}
		if (h.stats.hitpoints <= 0)
			break;
	}
	return;
}

// TODO (15): lairCleared
// Returns true if no Monster in the lair has hitpoints > 0
bool lairCleared(const vector<Monster>& lair) {
	size_t count = 0;
	for (size_t i = 0; i < lair.size(); i++) {
		if (lair.at(i).stats.hitpoints > 0)
			continue;
		else
			count++;
	}
	if (count == lair.size())
		return true;
	return false;
}

// TODO (16): enterLair
// Begin an epic battle!
//  - print the heading "Our Hero", and call displayHero()
//  - print the heading "The Monster Lair", and call displayMonsters()
//  - print the heading "The hero enters the lair..."
//  - loop as long as the hero is alive and the lair is not clear:
//      - call heroTurn()
//      - if the lair is not cleared, call monstersTurn()
void enterLair(Hero& h, vector<Monster>& lair) {
	printHeading("Our Hero");
	displayHero(h);
	printHeading("The Monster Lair");
	displayMonsters(lair);
	printHeading("The hero enters the lair...");
	while ((h.stats.hitpoints > 0) && !(lairCleared(lair))) {
		heroTurn(h, lair);
		if (!(lairCleared(lair)))
			if(h.stats.hitpoints > 0){
				monstersTurn(lair, h);
			}
	}
	return;
}