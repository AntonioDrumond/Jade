#include <iostream>
#include <fstream>
#include <string.h>
#include "stack.hpp"

bool comp(char* str1, char* str2){
	if(strlen(str1) != strlen(str2)) return false;
	int reps = strlen(str1);
	int i = 0;
	bool result = true;
	while(result && i<reps){
		if(str1[i] != str2[i]) result = false;
	}
	return result;
}

void flag(){
	std::cout << "\nFLAG\n\n";
}

int main(int argc, char* argv[]){
	if(argc < 3){
		std::cerr << "ERROR: Not enough parameters\n";
		return 1;
	}
	else if(argc > 3){
		std::cerr << "ERROR: Too many paramenters\n";
		return 1;
	}

	std::ifstream my;
	my.open(argv[1]);
	
	std::ifstream pub;
	pub.open(argv[2]);

	if(!my || !pub){
		std::cerr << "ERROR: Error opening files\n";
		return 1;
	}


	Stack* pilha = new Stack();
	int linha = 1;
	bool reading1 = true;
	bool reading2 = true;
	bool linDif = false;

	while(reading1 || reading2){
		char* l1 = new char[1000];
		char* l2 = new char[1000];

		if(reading1)
			if(!my.getline(l1, 999, '\n')) reading1 = false;

		if(reading2)
			if(!pub.getline(l2, 999, '\n')) reading2 = false;

		if(reading1 && reading2 && !comp(l1, l2))
			pilha->push(linha, l2, l1);

		if((reading1&&!reading2) || (!reading1&&reading2))
			linDif = true;

		linha++;
		delete l1;
		delete l2;
	}
	flag();

	my.close();
	pub.close();

	if(pilha->qnt == 0)
		std::cout << "Resultado estimado: 100%\n";

	else
		pilha->print(linha);
	
	delete pilha;
	return 0;
}
