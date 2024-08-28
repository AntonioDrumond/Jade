#include "jadeLib.hpp"

bool comp(char* str1, char* str2){
	if(strlen(str1) != strlen(str2)) return false;
	int reps = strlen(str1);
	int i = 0;
	bool result = true;
	while(result && i<reps){
		if(str1[i] != str2[i]) result = false;
		i++;
	}
	return result;
}

void flag(){
	std::cout << "\nFLAG\n\n";
}

int main(int argc, char* argv[]){
	int myOut = 1,
		pubOut = 2;

	if(argc == 1){
		std::cout << "Modo de uso:\n";
		std::cout << "Para compilar e comparar: \"jade sourceCode myOutput pub.out\"\n";
		std::cout << "Para comparar apenas: \"jade myOutput pub.out\"\n";
		return 1;
	}
	if(argc < 3){
		std::cerr << "ERRO: Parametros insuficientes\n";
		return 1;
	}
	else if(argc > 4){
		std::cerr << "ERRO: Parametros demais\n";
		return 1;
	}

	//___Compilar o codigo fonte___
	else if(argc == 4){
		myOut++; pubOut++;
		std::cout << "compilando " << argv[1] << "...\n\n";
		
	}


	//___Abrir arquivos para leitura___
	
	std::ifstream my;
	my.open(argv[myOut]);
	
	std::ifstream pub;
	pub.open(argv[pubOut]);

	if(!my || !pub){
		std::cerr << "ERROR: Error opening files\n";
		return 1;
	}


	//___Comparar arquivos___

	Stack* pilha = new Stack();
	int linha = 1;
	bool reading1 = true;
	bool reading2 = true;
	bool linDif = false;
	bool pushed = false;

	while(reading1 || reading2){
		pushed = false;
		char* l1 = new char[1000];
		char* l2 = new char[1000];

		if(reading1)
			if(!my.getline(l1, 999, '\n')) reading1 = false;

		if(reading2)
			if(!pub.getline(l2, 999, '\n')) reading2 = false;

		if(reading1 && reading2 && !comp(l1, l2)){
			pushed = true;
			pilha->push(linha, l2, l1);
			//std::cout << linha << "\n" << l2 << "\n" << l1 << "\n\n";
		}

		if((reading1&&!reading2) || (!reading1&&reading2))
			linDif = true;

		linha++;
		if(!pushed){
			delete l1;
			delete l2;
		}
	}

	my.close();
	pub.close();

	//___Exibir resultado___
	pilha->print(linha);
	
	delete pilha;
	return 0;
}
