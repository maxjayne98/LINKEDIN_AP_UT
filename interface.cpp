#include "interface.hpp"


void Interface::addUser(std::string firstName, std::string lastName, std::string emailAddress, std::string biography){
    User* user = new User(firstName, lastName, emailAddress, biography);
    add_user(user);
}

void Interface::addCompany(std::string name, std::string address, std::string description){
    Company* company = new Company(name, address, description);
    add_company(company);
}

void Interface::addExperience(std::string userId, std::string companyId, std::string title, std::string startAt , std::string endsAt){
    Experience* experience = new Experience(userId, companyId, title, startAt, endsAt);
    add_experience(experience);
}

void Interface::addJobRequest(std::string companyName, std::string title, std::map<std::string, float> conditions){
    JobRequest* jobreq = new JobRequest(companyName, title, conditions);
    add_job_request(jobreq);
}

void Interface::assignSkill(std::string userId, std::string skillName){
    Skill* skill = new Skill(userId, skillName);
    assign_skill(skill);
}

void Interface::endorseSkill(std::string endorserUserId, std::string skilledUserId, std::string skillName){
    endorse_skill(endorserUserId, skilledUserId, skillName);
}

void Interface::follow(std::string followerId, std::string followingId){
    follow_(followerId, followingId);
}

void Interface::applyForJob(std::string userId, std::string companyId, std::string jobTitle){
    apply_for_job(userId, companyId, jobTitle);
}

void Interface::hireBestApplicant(std::string companyId, std::string jobTitle, std::string startsAt){
	std::string endsAt = NOW;
    hire_best_applicant(companyId, jobTitle, startsAt, endsAt);
}

void Interface::printUserProfile(std::string userId){
    print_user_profile(userId);
}

void Interface::printSuggestedJobs(std::string userId){
    print_suggested_jobs(userId);
}

void Interface::printCompanyProfile(std::string companyName){
    print_company_profile(companyName);
}

void Interface::printSuggestedUsers(std::string companyName, std::string jobTitle){
    print_suggested_users(companyName, jobTitle);
}