#include "Experience.hpp"

void Experience::print_experience(int nth_exp){
	cout << nth_exp << ". " << startsAt << " - " << endsAt;
	cout << title << " at " << companyId << endl;
}

int Experience::print_activated_jobs(string companyName, int count, string firstName, string lastName){
	if(companyName == companyName){
		cout << count << ". " << startsAt << " - " << endsAt << " ";
		cout << title << " by " << firstName << " " << lastName << endl;
		count++;
	}
	return count;
}