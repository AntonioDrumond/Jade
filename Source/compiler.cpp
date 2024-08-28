#include "jadeLib.hpp"

int main(int argc, char* argv[]){
	if(argc!=2){
		std::cerr << "deu erro dog\n";
		return 1;
	}

	if(isCFile(argv[1])){
		char* comando = concat("gcc -o program ", argv[1]);
		system(comando);
	}
	
	return 0;
}
