#include <iostream>

int main()
{
	system("cls");

	std::cout
		<< "**********************************" << std::endl
		<< "*                                *" << std::endl
		<< "*       Contador de Letras       *" << std::endl
		<< "*                                *" << std::endl
		<< "**********************************" << std::endl;

	std::cout << "" << std::endl;
	std::cout << "Digite uma palavra: ";

	std::string palavra;
	std::cin >> palavra;

	std::cout << "" << std::endl;

	std::cout << "Digite uma letra: ";

	char letra;
	std::cin >> letra;

	int contadorDeLetras = 0;

	std::cout << "" << std::endl;

	for (int i = 0; i < palavra.size(); i++)
	{
		if (std::tolower(letra) == std::tolower(palavra[i]))
		{
			contadorDeLetras++;

			std::cout << "  " << palavra[i] << " <- " << contadorDeLetras << " | " << "posicao: " << "[" << i << "]" << std::endl;
		}
		else
		{
			std::cout << "  " << palavra[i] << std::endl;
		}
	}

	if (contadorDeLetras > 0)
	{
		std::cout
			<< "" << std::endl
			<< "A letra '" << letra << "' aparece " << contadorDeLetras << " vez(es)." << std::endl;
	}
	else
	{
		std::cout
			<< "" << std::endl
			<< "A letra '" << letra << "' nao aparece nenhuma vez na palavra '" << palavra << "' :/" << std::endl;
	}

	std::cout
		<< "" << std::endl
		<< "Deseja reiniciar o programa?" << std::endl
		<< "" << std::endl
		<< "Sim -> 1" << std::endl
		<< "Nao -> 2" << std::endl
		<< "" << std::endl
		<< "Opcao: ";

	int opcaoReiniciar;
	std::cin >> opcaoReiniciar;

	switch (opcaoReiniciar)
	{
	case 1:
		main();
		break;

	case 2:
		std::cout
			<< "" << std::endl
			<< "Encerrando o programa." << std::endl;

		break;

	default:
		std::cout
			<< "" << std::endl
			<< "Opcao nao encontrada." << std::endl
			<< "Encerrando o programa." << std::endl;

		break;
	}
}