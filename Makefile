all: data_generator

data_generator.x: data_generator.cc
	g++ -o data_generator.x data_generator.cc

clean:
	rm *.o *.x