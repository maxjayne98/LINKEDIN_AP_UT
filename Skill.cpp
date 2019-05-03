#include "Skill.hpp"


void Skill::endorse_skill(){
	endorsesCount++;
	set_sRate();
}

void Skill::set_sRate(){
	sRate = sqrt(endorsesCount + 1);
}

void Skill::print_skill(int nth_skill){
	cout << skillName << " - ";
	print_sRate();
}

void Skill::print_sRate(){
	int num1 = sRate*100;
	int num2 = sRate*10;
	if(num1 % 10 == 0){
		if(num2 % 10 ==0){
			int num = sRate;
			cout << num << endl;
		}
		else{
			float fnum = num1/10;
			cout << fnum << endl;
		}
	}
	else{
		float fnum = num2/100;
		cout << fnum << endl;
	}
}