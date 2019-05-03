#ifndef IMPLEMENTATION_H
#define IMPLEMENTATION_H

#include <vector>
#include "User.hpp"
#include "Company.hpp"
#include "Experience.hpp"

using namespace std;

#define NOT_FOUND -1

class Experience;

class Implementation{
  private:
  	vector <User*> users;
  	vector <Company*> companies;
  	vector <Experience*> experiences;
  public:
    Implementation(){}
  	void add_user(User* user);
  	bool exist_in_users(string emailAddress);
   	void add_company(Company* company);
   	bool exist_in_companies(string name);
  	void add_experience(Experience* experience);
  	int search_user_by_userId(string userId);
  	bool exist_in_experiences(string companyId, string title);
  	void add_job_request(JobRequest* jobreq);
  	int search_company_by_name(string companyName);
  	void assign_skill(Skill* skill);
  	void endorse_skill(string endorserUserId, string skilledUserId, string skillName);
  	void follow_(string followerId, string followingId);
  	void apply_for_job(string userId, string companyId, string jobTitle);
  	void hire_best_applicant(string companyId, string jobTitle, string startsAt, string endsAt);
  	void print_user_profile(string userId);
  	void print_company_profile(string companyName);
  	void print_suggested_jobs(string userId);
  	void print_suggested_users(string companyName, string jobTitle);
};

#endif
