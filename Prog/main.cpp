/* 
Diretiva que dá a instrução ao pré-processador para incluir o código do header
"iostream".Este header declara as operações básicas de input e output. 
*/
#include <iostream>
/*
Diretiva que inclui o código para especificação das definições regionais.
Torna possível a utilização dos carateres especiais, tais como: 'ç', 'â', entre outros.
*/
#include <locale>

using namespace std;
// Início da definição da função principal, isto é, da função "main()".
int main()
{
	// Configura as definições regionais
	locale::global(std::locale("pt-PT"));

	// Esta instrução compreende três partes:
	// std::cout - STandarD Character OUTput
	// << - Operador que indica que o que se segue, será enviado para o output
	// "Hello, World!" - String que será enviada para o output
	// std::endl - Quebra de linha
	 
	// Acesso não-qualificado
	cout << "Olá Mundo!" << endl << "Em C++\n";
	// Versão com acesso qualificado a 'cout' e 'endl'
	std::cout << "Olá Mundo!" << std::endl<< "Em C++\n";

	// Termina o programa
	return 0;	
}
