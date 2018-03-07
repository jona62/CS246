all: Bank

bank.o:
	g++ -c bank.cc

Bank: bank.o
	g++ -o Bank bank.cpp

clean:
	rm -f Bank bank.o	
