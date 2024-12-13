all: data_generator.x linear_search.x program_tester.x linear_search.class

C_FLAGS = -std=c++11

data_generator.x: data_generator.cc
	g++ -o data_generator.x data_generator.cc $(C_FLAGS)

linear_search.x: linear_search.cc
	g++ -o linear_search.x linear_search.cc $(C_FLAGS)

program_tester.x: program_tester.cc
	g++ -o program_tester.x program_tester.cc $(C_FLAGS)

clean:
	rm *.x *.class