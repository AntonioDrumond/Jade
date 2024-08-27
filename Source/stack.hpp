class Cell{
	public:
	int index;
	char* expected;
	char* user;
	Cell* next;

	Cell(int ind, char* exp, char* usr){
		expected = new char[1000];
		user = new char[1000];
		strcpy(exp, expected);
		strcpy(usr, user);
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
		double pct = 100*(qnt/totalLines);
		std::cout << "Resultado estimado: " << pct << "%\n\n";
		printRec(top);
	}

	void printRec(Cell* current){
		if(current->next!=nullptr) printRec(current->next);
		std::cout << current->index << " - " << current->expected << " | " << current->user << "\n\n";
	}
};
