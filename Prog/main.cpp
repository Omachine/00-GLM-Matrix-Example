/* 
Diretiva que d� a instru��o ao pr�-processador para incluir o c�digo do header
"iostream".Este header declara as opera��es b�sicas de input e output. 
*/
#include <iostream>
/*
Diretiva que inclui o c�digo para especifica��o das defini��es regionais.
Torna poss�vel a utiliza��o dos carateres especiais, tais como: '�', '�', entre outros.
*/
#include <locale>

using namespace std;
// In�cio da defini��o da fun��o principal, isto �, da fun��o "main()".
int main()
{
	// Configura as defini��es regionais
	locale::global(std::locale("pt-PT"));

	// Esta instru��o compreende tr�s partes:
	// std::cout - STandarD Character OUTput
	// << - Operador que indica que o que se segue, ser� enviado para o output
	// "Hello, World!" - String que ser� enviada para o output
	// std::endl - Quebra de linha
	 
	// Acesso n�o-qualificado
	cout << "Ol� Mundo!" << endl << "Em C++\n";
	// Vers�o com acesso qualificado a 'cout' e 'endl'
	std::cout << "Ol� Mundo!" << std::endl<< "Em C++\n";

	// Termina o programa
	return 0;	
}
