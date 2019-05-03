#ifndef JOBREQUEST_H
#define JOBREQUEST_H

#include <map>
#include <iostream>
#include "User.hpp"
using namespace std;

class User;

class JobRequest{
  private:
  	string companyName;
  	string title;
  	map <string, float> conditions;
  	vector <User*> applied;
  public:
  	JobRequest(string _companyName, string _title, map <string, float> _conditions){
  		companyName = _companyName;
  		title = _title;
  		conditions = _conditions;
  	}
  	string get_title(){return title;}
  	string get_company_name(){return companyName;}
  	void apply_for_job(User* user);
  	void hire_best_applicant(string startsAt, string endsAt);
  	User* find_best_applicant();
  	void print_reqs();
  	void print_map(map<string, float> cons);
  	int print_suggested_jobs(User* user, int count);
  	void print_suggested_users(string jobTitle, vector<User*> users);
};

#endif