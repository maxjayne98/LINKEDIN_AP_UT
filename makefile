all: a.out

interface.o: interface.cpp interface.hpp
	g++ -c interface.cpp
main.o: main.cpp
	g++ -c main.cpp
Company.o: Company.cpp Company.hpp
	g++ -c Company.cpp
User.o: User.cpp User.hpp
	g++ -c User.cpp
Experience.o: Experience.cpp Experience.hpp
	g++ -c Experience.cpp
Skill.o: Skill.cpp Skill.hpp
	g++ -c Skill.cpp
JobRequest.o: JobRequest.cpp JobRequest.hpp
	g++ -c JobRequest.cpp
Implementation.o: Implementation.cpp Implementation.hpp
	g++ -c Implementation.cpp
a.out: main.o Company.o Skill.o User.o Experience.o JobRequest.o interface.o Implementation.o
	g++ main.o Company.o Skill.o User.o Experience.o JobRequest.o interface.o Implementation.o
clean: 
	rm *.o
	rm a.out

