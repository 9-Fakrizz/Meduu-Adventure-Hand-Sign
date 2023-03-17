#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<iomanip>

using namespace std;

class Equipment{
	int hpmax;
	int atk;
	int def;
	public:
		Equipment(int,int,int);
		vector<int> getStat();			
};

Equipment::Equipment(int hp_e, int atk_e, int def_e){
	hpmax = hp_e; atk = atk_e; def = def_e;
}

vector<int> Equipment::getStat(){
	vector<int> Stat;
	Stat.push_back(hpmax); Stat.push_back(atk); Stat.push_back(def);
	return Stat;
}

class Unit{
		string name;
		string type;		
		int hp;
		int hpmax;
		int atk;
		int def;
		int exp;
		bool guard_on;
		bool dodge_on; 
		Equipment *equipment; 
	public:			
		Unit(string,string); 
		void showStatus();
		void newTurn();
		int attack(Unit &);
		int ultimateAttack(Unit &); 
		int beAttacked(int);
		int heal();	
		int buff();
		int hyperbuff();
		int life_drain(Unit &);
		void guard();
		void dodge(); 
		bool isDead();
		void equip(Equipment *);  
};

Unit::Unit(string t,string n){ 
	type = t;
	name = n;
	if(type == "Hero"){
		hpmax = rand()%20+120;
		atk = rand()%5+14;
		def = rand()%3+9;
		exp = rand()%3+9;
	}else if(t == "Monster"){
		hpmax = rand()%20+250;
		atk = rand()%5+25;
		def = rand()%3+5;
	}
	hp = hpmax;	
	guard_on = false;
	dodge_on = false;
	equipment = NULL;
}

void Unit::showStatus(){
	if(type == "Hero"){
		cout << "---------------------------------------\n"; 
		cout << name << "\n"; 
		cout << "HP: " << hp << "/" << hpmax << "\tATK: "<< atk << "\tDEF: "<< def<<"\t\tEXP: "<<exp;		
		cout << "\n---------------------------------------\n";
	}	
	else if(type == "Monster"){
		cout << "\t\t\t\t---------------------------------------\n"; 
		cout << "\t\t\t\t" << name << "\n"; 
		cout << "\t\t\t\tHP: " << hp << "\t\tATK: "<< atk << "\t\tDEF: "<< def;
		cout << "\n\t\t\t\t---------------------------------------\n";
	}
}

void Unit::equip(Equipment *eq){
	if (equipment == NULL){
	   	equipment = eq;
		hpmax += equipment->getStat().at(0);
		atk += equipment->getStat().at(1);
		def += equipment->getStat().at(2);
    	}
	else{
		hpmax -= equipment->getStat().at(0);
		atk -= equipment->getStat().at(1);
		def -= equipment->getStat().at(2);
		equipment = eq;
		hpmax += equipment->getStat().at(0);
		atk += equipment->getStat().at(1);
		def += equipment->getStat().at(2);
	}
	if(hp > hpmax) hp = hpmax;
}

void Unit::newTurn(){
	guard_on = false; 
	dodge_on = false;
}

int Unit::beAttacked(int oppatk){
	int dmg;
	if(oppatk > def){
		dmg = oppatk-def;	
		if(guard_on) dmg = dmg/3;
		if(dodge_on) {
		    int temp = rand()%2;
		    if(temp == 0) dmg *= 2;
		    else {dmg = 0;}
		}
	}	
	hp -= dmg;
	if(hp <= 0){hp = 0;}
	
	return dmg;	
}

int Unit::attack(Unit &opp){
	exp = exp + 1;
	return opp.beAttacked(atk),exp;
	
	
}

int Unit::ultimateAttack(Unit &opp){
	return opp.beAttacked(atk*2);
}

int Unit::heal(){
	int h = rand()%21 + 10;
	if(hp + h > hpmax) h = hpmax - hp;
	hp = hp + h;
	return h;
}

int Unit::buff(){
	if(exp>=1){
	int buff = rand()%21 + 10;
	atk = atk + buff;
	exp -=1;
	return buff;
	}
	
}
int Unit::hyperbuff(){
	int Abuff = rand()%21 + 10;
	int Dbuff = rand()%21 + 10;
	atk = atk + (Abuff)*2;	
}

int Unit::life_drain(Unit &opp){
	if(exp>=5){
	int hh = rand()%21 + 10;
	if(hp + hh > hpmax) {hh = hpmax - hp;
	hp = hp + hh;
	exp -=5;}
	return opp.beAttacked(atk),hh;
	}
	
}

void Unit::guard(){
	guard_on = true;
}	

void Unit::dodge(){
    dodge_on = true;
}

bool Unit::isDead(){
	if(hp <= 0) return true;
	else return false;
}

