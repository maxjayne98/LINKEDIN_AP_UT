#ifndef SKILL_H
#define SKILL_H

using namespace std;

#include <string>
#include <cmath>
#include <iostream>

class Skill{
  private:
  	string userId;
  	string skillName;
  	int endorsesCount;
  	float sRate;
  public:
  	Skill(string _userId, string _skillName){
  		userId = _userId;
  		skillName = _skillName;
  	}
  	string get_skillName(){return skillName;}
  	int get_endorseCount(){return endorsesCount;}
  	string get_userId(){return userId;}
  	void endorse_skill();
  	void set_sRate();
  	void print_skill(int nth_skill);
  	void print_sRate();
};

#endif