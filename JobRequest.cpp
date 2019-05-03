#include "JobRequest.hpp"


void JobRequest::apply_for_job(User* user){
	if(user -> can_apply(conditions)){
		applied.push_back(user);
	}
}

void JobRequest::hire_best_applicant(string startsAt, string endsAt){
	if(applied.size() >= 0){
		User* user = find_best_applicant();
		user -> hire_user(startsAt, companyName, title, endsAt);
	}
}

User* JobRequest::find_best_applicant(){
	User* best = applied[0];
	float best_rate = best -> calculate_rate(conditions);
	for(int i = 1 ; i < applied.size() ; i++){
		float rate = applied[i] -> calculate_rate(conditions);
		if(rate > best_rate){
			best = applied[i];
			best_rate = rate;
		}
	}
	return best;
}

void JobRequest::print_reqs(){
	cout << title << " - " << "needed skills: ";
	print_map(conditions);
}

void JobRequest::print_map(map<string, float> cons){
	for(map<string, float>::iterator it = cons.begin() ; it != cons.end() ; ++it){
		cout << it -> first << "(" << it -> second << "), ";
	}
}

int JobRequest::print_suggested_jobs(User* user, int count){
	if(user -> can_apply(conditions)){
		cout << count << ". " << title << " in " << companyName << " - needed skills: ";
		print_map(conditions);
		count++;
	}
	return count;
}

void JobRequest::print_suggested_users(string jobTitle, vector<User*> users){
	if(jobTitle == title){
		int count = 1;
		for(int i = 0 ; i < users.size() ; i++){
			if(users[i] -> can_apply(conditions)){
				cout << count << endl;
				users[i] -> print_profile();
				count++;
			}
		}
	}
}