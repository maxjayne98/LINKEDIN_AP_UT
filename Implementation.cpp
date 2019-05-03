#include "Implementation.hpp"


void Implementation::add_user(User* user){
	if(!exist_in_users(user -> get_emailAddress()))
		users.push_back(user);
}

bool Implementation::exist_in_users(string emailAddress){
	for(int i = 0 ; i < users.size() ; i++){
		string userEmailAddress = users[i] -> get_emailAddress();
		if(emailAddress == userEmailAddress)
			return true;
	}
	return false;
}

void Implementation::add_company(Company* company){
	if(!exist_in_companies(company -> get_company_name()))
		companies.push_back(company);
}

bool Implementation::exist_in_companies(string name){
	for(int i = 0 ; i < companies.size() ; i++){
		string companyName = companies[i] -> get_company_name();
		if(companyName == name)
			return true;
	}
	return false;
}

void Implementation::add_experience(Experience* experience){
	int nth_user = search_user_by_userId(experience -> get_userId());
	if(nth_user != NOT_FOUND && !exist_in_experiences(experience -> get_companyId(), experience -> get_title())){
		users[nth_user] -> add_experience(experience);
		experiences.push_back(experience);
	}
}

int Implementation::search_user_by_userId(string userId){
	for(int i = 0 ; i < users.size() ; i++){
		if(userId == users[i] -> get_emailAddress())
			return i;
	}
	return NOT_FOUND;
}

bool Implementation::exist_in_experiences(string companyId, string title){
	for(int i = 0 ; i < experiences.size() ; i++){
		if(experiences[i] -> get_companyId() == companyId && experiences[i] -> get_title() == title)
			return true;
	}
	return false;
}

void Implementation::add_job_request(JobRequest* jobreq){
	int nth_comp = search_company_by_name(jobreq -> get_company_name());
	if(nth_comp != NOT_FOUND){
		companies[nth_comp] -> add_job_request(jobreq);
	}
}

int Implementation::search_company_by_name(string companyName){
	for(int i = 0 ; i < companies.size() ; i++){
		string name = companies[i] -> get_company_name();
		if(name == companyName)
			return i;
	}
	return NOT_FOUND;
}

void Implementation::assign_skill(Skill* skill){
	int nth_user = search_user_by_userId(skill -> get_userId());
	if(nth_user != NOT_FOUND){
		users[nth_user] -> assign_skill(skill);
	}
}

void Implementation::endorse_skill(string endorserUserId, string skilledUserId, string skillName){
	int nth_user = search_user_by_userId(skilledUserId);
	if(nth_user != NOT_FOUND){
		users[nth_user] -> endorse_skill(skillName);
	}
}

void Implementation::follow_(string followerId, string followingId){
	int nth_user1 = search_user_by_userId(followingId);
	int nth_user2 = search_user_by_userId(followerId);
	if(nth_user1 != NOT_FOUND && nth_user2 != NOT_FOUND){
		users[nth_user1] -> follow(followerId);
		users[nth_user2] -> follow(followingId);
	}
}

void Implementation::apply_for_job(string userId, string companyId, string jobTitle){
	int nth_user = search_user_by_userId(userId);
	int nth_comp = search_company_by_name(companyId);
	if(nth_user != NOT_FOUND && nth_comp != NOT_FOUND){
		companies[nth_comp] -> apply_for_job(users[nth_user], jobTitle);
	}
}

void Implementation::hire_best_applicant(string companyId, string jobTitle, string startsAt, string endsAt){
	int nth_comp = search_company_by_name(companyId);
	if(nth_comp != NOT_FOUND){
		companies[nth_comp] -> hire_best_applicant(jobTitle, startsAt, endsAt);
	}
}

void Implementation::print_user_profile(string userId){
	int nth_user = search_user_by_userId(userId);
	if(nth_user != NOT_FOUND){
		users[nth_user] -> print_profile();
	}
}

void Implementation::print_company_profile(string companyName){
	int nth_comp = search_company_by_name(companyName);
	if(nth_comp != NOT_FOUND){
		companies[nth_comp] -> print_company_profile(users);
	}
}

void Implementation::print_suggested_jobs(string userId){
	int nth_user = search_user_by_userId(userId);
	if(nth_user != NOT_FOUND){
		users[nth_user] -> print_suggested_jobs(companies);
	}
}

void Implementation::print_suggested_users(string companyName, string jobTitle){
	int nth_comp = search_company_by_name(companyName);
	if(nth_comp != NOT_FOUND){
		companies[nth_comp] -> print_suggested_users(jobTitle, users);
	}
}