#ifndef COMPANY_H
#define COMPANY_H

#include <vector>
#include <string>
#include <iostream>
#include "JobRequest.hpp"
#include "User.hpp"

using namespace std;

class JobRequest; 

#define NOT_FOUND -1

class User;

class Company{
  private:
  	string name;
  	string address;
  	string description;
  	vector <JobRequest*> jobReqs;
  public:
  	Company(string _name, string _address, string _description){
  		name = _name;
  		address = _address;
  		description = _description;
  	}
  	string get_company_name(){return name;}
  	void add_job_request(JobRequest* jobReq);
  	void apply_for_job(User* user, string jobTitle);
  	int search_jobReq_by_jobTitle(string jobTitle);
  	void hire_best_applicant(string jobTitle, string startsAt, string endsAt);
  	void print_company_profile(vector <User*> users);
  	void print_activated_jobs(string companyName, vector <User*> users);
  	void print_reqs();
  	int print_suggested_jobs(User* user, int count);
  	void print_suggested_users(string title, vector<User*> users);
};

#endif