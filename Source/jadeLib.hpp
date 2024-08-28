#include <iostream>
#include <fstream>
#include <string.h>

class Cell{
	public:
	int index;
	char* expected;
	char* user;
	Cell* next;

	Cell(int ind, char* exp, char* usr){
		//expected = new char[1000];
		//user = new char[1000];
		//strcpy(expected, exp);
		//strcpy(user, usr);
		expected = exp;
		user = usr;
		exp = nullptr;
		usr = nullptr;
		index = ind;
		next = nullptr;
	}

	~Cell(){
		delete expected;
		delete user;
		if(next!=nullptr) delete next;
	}
};

class Stack{
	public:
	Cell* top;
	int qnt;

	Stack(int ind, char* exp, char* usr){
		top = new Cell(ind, exp, usr);
		qnt = 1;
	}

	Stack(){
		top = nullptr;
		qnt = 0;
	}

	~Stack(){
		if(top!=nullptr) delete top;
	}

	void push(int ind, char* exp, char* usr){
		Cell* tmp = new Cell(ind, exp, usr);
		tmp->next = top;
		top = tmp;
		qnt++;
	}

	void pop(){
		Cell* tmp = top;
		top = top->next;
		tmp->next = nullptr;
		delete tmp;
		qnt--;
	}

	void print(int totalLines){
		double pct = 100 * (totalLines-qnt) / totalLines ;
		//std::cout << "Resultado estimado: " << pct << "%\n";
		//std::cout << "Erros encontrados em " << qnt << " linhas de " << totalLines << "\n\n";
		if(top!=nullptr){
			std::cout << "Linha: x\nSaida esperada\nSaida do usuario\n\n";
			printRec(top);
		}
		std::cout << "Resultado estimado: " << pct << "%\n";
		std::cout << "Erros encontrados em " << qnt << " linhas de " << totalLines << "\n\n";
	}

	void printRec(Cell* current){
		if(current->next!=nullptr) printRec(current->next);
			std::cout << "Linha: " << current->index << "\n";
			std::cout << current->expected << "\n";
			std::cout << current->user << "\n";
			std::cout << "\n";
		}
};

bool isCFile(char* name){
	int leng = strlen(name);
	return (name[leng-1]=='c' && name[leng-2]=='.');
}

bool isJavaFile(char* name){
	int leng = strlen(name);
	return (name[leng-1]=='a' && name[leng-2]=='v' && name[leng-3]=='a' && name[leng-4]=='j' && name[leng-5]=='.');
}

char* removeExtension(const char* name){
	char* result = new char[strlen(name)-4];
	int reps = strlen(name)-5;
	for(int i=0; i<reps; i++){
		result[i] = name[i];
	}
	return result;
}

char* concat(const char* st1, const char* st2){
	char* result = new char[strlen(st1) + strlen(st2) + 1];
	strcpy(result, st1);
	strcat(result, st2);
	return result;
}
