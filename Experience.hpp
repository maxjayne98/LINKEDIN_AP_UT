#ifndef EXPERIENCE_H
#define EXPERIENCE_H

#include <string>
#include <iostream>

using namespace std;

class Experience{
  private:
  	string userId;
  	string companyId;
  	string title;
  	string startsAt;
  	string endsAt;
  public:
  	Experience(string _userId, string _companyId, string _title, string _startsAt, string _endsAt){
  		userId = _userId;
  		companyId = _companyId;
  		title = _title;
  		startsAt = _startsAt;
  		endsAt = _endsAt;
  	}
  	string get_userId(){return userId;}
  	string get_companyId(){return companyId;}
  	string get_title(){return title;}
  	void print_experience(int nth_exp);
  	int print_activated_jobs(string companyName, int count, string firstName, string lastName);
};

#endif