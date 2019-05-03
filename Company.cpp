#include "Company.hpp"

void Company::add_job_request(JobRequest* jobReq){
	jobReqs.push_back(jobReq);
}

void Company::apply_for_job(User* user, string jobTitle){
	int nth_jobReq = search_jobReq_by_jobTitle(jobTitle);
	if(nth_jobReq != NOT_FOUND){
		jobReqs[nth_jobReq] -> apply_for_job(user);
	}
}

int Company::search_jobReq_by_jobTitle(string jobTitle){
	for(int i = 0 ; i < jobReqs.size() ; i++){
		string title = jobReqs[i] -> get_title();
		if(title == jobTitle)
			return i;
	}
	return NOT_FOUND;
}

void Company::hire_best_applicant(string jobTitle, string startsAt, string endsAt){
	int nth_jobReq = search_jobReq_by_jobTitle(jobTitle);
	if(nth_jobReq != NOT_FOUND){
		jobReqs[nth_jobReq] -> hire_best_applicant(startsAt, endsAt);
	}
}

void Company::print_company_profile(vector <User*> users){
	cout << "Name: " << name << endl;
	cout << "Address: " << address << endl;
	cout << "Description: " << description << endl;
	cout << "Jobs:" << endl;
	print_activated_jobs(name, users);
	cout << "Requests:" << endl;
	print_reqs();
}

void Company::print_activated_jobs(string companyName, vector <User*> users){
	int count = 1;
	for(int i = 0 ; i < users.size() ; i++){
		count = users[i] -> print_activated_jobs(companyName, count);
	}
}

void Company::print_reqs(){
	for(int i = 0 ; i < jobReqs.size() ; i++){
		cout << i << ". ";
		jobReqs[i] -> print_reqs();
	}
}

int Company::print_suggested_jobs(User* user, int count){
	for(int i = 0 ; i < jobReqs.size() ; i++){
		count = jobReqs[i] -> print_suggested_jobs(user, count);
	}
	return count;
}

void Company::print_suggested_users(string title, vector<User*> users){
	for(int i = 0 ; i < jobReqs.size() ; i++){
		jobReqs[i] -> print_suggested_users(title, users);
	}
}