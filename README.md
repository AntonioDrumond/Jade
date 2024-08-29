# Jade
+ Verificador de exercicios semelhante ao Verde (sistema de verificação de exercícios da PUC Minas), capaz de checar exercicios feitos pelo aluno antes de fazer o upload
+ Ainda não testado no Windows

## Modo de uso:
#### Tutorial:
```sh
  jade
```
#### Dois parâmetros:
```sh
  jade <arquivo1> <arquivo2>
```
+ Os arquivos "arquivo1" e "arquivo2" serão comparados

#### Três parâmetros:
```sh
  jade <codigo> <arquivo1> <arquivo2>
```
+ O arquivo "codigo" sera compilado (Java ou C), e executado utilizando o arquivo "arquivo1" como entrada e gerando um arquivo de saída "my.out"
+ Os arquivos "my.out:" e "arquivo2" serão comparados

## Como compilar:
+ Para compilar localmente, um compilador de C++ é necessário. Segue o passo a passo com o GCC:
```sh
  g++ -o jade main.cpp
```
+ Todo o código fonte esta na pasta [Source/](https://github.com/AntonioDrumond/Jade/tree/main/Source) deste repositório

## Como instalar:
### Linux
+ Para adicionar o Jade ao PATH, basta adicionar as seguintes linhas ao arquivo ``~/.bashrc`` e substituir ``/opt/Jade`` pelo endereço do diretório do executável no seu sistema
```sh
  #adding Jade to PATH
  export PATH="/opt/Jade:$PATH"
```
