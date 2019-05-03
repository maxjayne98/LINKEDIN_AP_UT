#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include "Experience.hpp"
#include "Skill.hpp"
#include "Company.hpp"

using namespace std;

#define NOT_FOUND -1

class Experience;
class Skill;
class Company;

class User{
  private:
  	string firstName;
  	string lastName;
  	string emailAddress;
  	string biography;
  	vector <Experience*> experiences;
  	vector <Skill*> skills;
   	vector <string> followed;
  public:
  	User(string _firstName, string _lastName, string _emailAddress, string _biography){
  		firstName = _firstName;
  		lastName = _lastName;
  		emailAddress = _emailAddress;
  		biography = _biography;
  	}
  	string get_emailAddress(){return emailAddress;}
  	void add_experience(Experience* exp);
  	void assign_skill(Skill* skill);
  	void endorse_skill(string skillName);
  	void follow(string userId);
  	bool exist_in_followed(string userId);
  	bool can_apply(map<string, float> con);
  	int search_skill_by_name(string skillName);
  	bool afford_skill(string skillName, float skillRate);
  	float calculate_rate(map<string, float> con);
  	void hire_user(string startsAt, string companyId, string title, string endsAt);
  	void print_profile();
  	void print_experiences();
  	void print_skills();
  	int print_activated_jobs(string companyId, int cont);
  	void print_suggested_jobs(vector <Company*> comps);
};

#endif