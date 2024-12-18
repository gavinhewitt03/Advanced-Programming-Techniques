truefalsequestion.o : truefalsequestion.h truefalsequestion.cc question.h
	g++ -Wall -std=c++17 -I . -c truefalsequestion.cc

shortanswerquestion.o : shortanswerquestion.h shortanswerquestion.cc question.h
	g++ -Wall -std=c++17 -I . -c shortanswerquestion.cc

multiplechoicequestion.o : multiplechoicequestion.h multiplechoicequestion.cc question.h
	g++ -Wall -std=c++17 -I . -c multiplechoicequestion.cc

checkp6 : checkp6.cc
	g++ -Wall -std=c++17 checkp6.cc -o checkp6

checkstudentanswers : checkstudentanswers.cc multiplechoicequestion.o truefalsequestion.o shortanswerquestion.o checkp6
	g++ -Wall -std=c++17 -I . checkstudentanswers.cc multiplechoicequestion.o truefalsequestion.o shortanswerquestion.o -o checkstudentanswers
	./checkstudentanswers samplekey.txt samplestudent.txt > studentoutput.txt
	./checkp6

clean :
	rm *.o studentoutput.txt checkstudentanswers
