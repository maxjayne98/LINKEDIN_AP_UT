#include "User.hpp"


void User::add_experience(Experience* exp){
	experiences.push_back(exp);
}

void User::assign_skill(Skill* skill){
	skills.push_back(skill);
}

void User::endorse_skill(string skillName){
	int nth_skill = search_skill_by_name(skillName);
	if(nth_skill != NOT_FOUND){
		skills[nth_skill] -> endorse_skill();
	}
}

void User::follow(string userId){
	if(!exist_in_followed(userId)){
		followed.push_back(userId);
	}
}

bool User::exist_in_followed(string userId){
	for(int i = 0 ; i < followed.size() ; i++){
		if(followed[i] == userId)
			return true;
	}
	return false;
}

bool User::can_apply(map<string, float> con){
	for(map<string, float>::iterator it = con.begin() ; it != con.end() ; ++it){
		if(!afford_skill(it -> first, it -> second))
			return false;
	}
	return true;
}

int User::search_skill_by_name(string skillName){
	for(int i = 0 ; i < skills.size() ; i++){
		string name = skills[i] -> get_skillName();
		if(name == skillName)
			return i;
	}
	return NOT_FOUND;
}

bool User::afford_skill(string skillName, float skillRate){
	int nth_skill = search_skill_by_name(skillName);
	if(nth_skill == NOT_FOUND)
		return false;
	return true;
}

float User::calculate_rate(map<string, float> con){
	float rate = 0;
	for(map<string, float>::iterator it = con.begin() ; it != con.end() ; ++it){
		int nth_skill = search_skill_by_name(it -> first);
		rate += skills[nth_skill] -> get_endorseCount();
	}
	return sqrt(rate + 1);
}

void User::hire_user(string startsAt, string companyId, string title, string endsAt){
	Experience* exp = new Experience(emailAddress, companyId, title, startsAt, endsAt);
	experiences.push_back(exp);
}

void User::print_profile(){
	cout << "Name: " << firstName << " " << lastName << endl;
	cout << "Email: " << emailAddress << endl;
	cout << "Biography: " << biography << endl;
	cout << "Network: " << followed.size() << " connections" << endl;
	cout << "Experiences:" << endl;
	print_experiences();
	cout << "Skills:" << endl;
	print_skills();
}

void User::print_experiences(){
	for(int i = 0 ; i < experiences.size() ; i++){
		experiences[i] -> print_experience(i);
	}
}

void User::print_skills(){
	for(int i = 0 ; i < skills.size() ; i++){
		skills[i] -> print_skill(i);
	}
}

int User::print_activated_jobs(string companyId, int count){
	for(int i = 0 ; i < experiences.size() ; i++){
		count = experiences[i] -> print_activated_jobs(companyId, count, firstName, lastName);
	}
	return count;
}

void User::print_suggested_jobs(vector <Company*> comps){
	int count = 1;
	for(int i = 0 ; i < comps.size() ; i++){
		count = comps[i] -> print_suggested_jobs(this, count);
	}
}