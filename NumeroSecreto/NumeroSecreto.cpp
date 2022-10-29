#include <iostream>
#include <thread>
#include <chrono>

int main()
{
	system("cls");

	srand((unsigned)time(NULL));

	const int NUMERO_SECRETO = 1 + rand() % 100;

	std::cout
		<< "*********************************" << std::endl
		<< "*                               *" << std::endl
		<< "*      Numero Secreto v1.0      *" << std::endl
		<< "*                               *" << std::endl
		<< "*********************************" << std::endl;

	std::cout
		<< "" << std::endl
		<< "Deseja adicionar configuracacao de tentativas?" << std::endl
		<< "" << std::endl
		<< "Sim -> 1" << std::endl
		<< "Nao -> 2" << std::endl
		<< "" << std::endl
		<< "Opcao: ";

	int opcaoAtivarConfiguracao;
	std::cin >> opcaoAtivarConfiguracao;

	bool ativarTentativas = false;
	int quantidadeTentativas;

	switch (opcaoAtivarConfiguracao)
	{
	case 1:
		ativarTentativas = true;
		std::cout
			<< "" << std::endl
			<< "*************************************************" << std::endl
			<< "*                                               *" << std::endl
			<< "* Configuracao de tentativas limitadas ativada! *" << std::endl
			<< "*                                               *" << std::endl
			<< "*************************************************" << std::endl
			<< "" << std::endl
			<< "Quantas tentativas serao permitidas? ";

		std::cin >> quantidadeTentativas;

		std::cout
			<< "" << std::endl
			<< "Configuracao salva com sucesso para essa rodada, serao permitidas " << quantidadeTentativas << " tentativas!" << std::endl
			<< "" << std::endl;

		system("pause");
		system("cls");
		break;

	case 2:
		std::cout
			<< "" << std::endl
			<< "****************************************************" << std::endl
			<< "*                                                  *" << std::endl
			<< "* Configuracao de tentativas limitadas desativada! *" << std::endl
			<< "*                                                  *" << std::endl
			<< "****************************************************" << std::endl
			<< "" << std::endl;

		system("pause");
		system("cls");
		break;

	default:
		std::cout
			<< "Opcao nao encontrada." << std::endl
			<< "Configuracao de tentativas sera desabilitada por padrao." << std::endl;

		system("pause");
		system("cls");
		break;
	}

	std::cout
		<< "" << std::endl
		<< "*********************" << std::endl
		<< "*                   *" << std::endl
		<< "* Iniciando o jogo! *" << std::endl
		<< "*                   *" << std::endl
		<< "*********************" << std::endl
		<< "" << std::endl;

	int input;
	std::cout << "Digite um numero: ";
	std::cin >> input;

	int contadorTentativas = 0;

	while (input != NUMERO_SECRETO)
	{
		contadorTentativas++;

		if (ativarTentativas == true)
			if (contadorTentativas == quantidadeTentativas)
				break;

		std::cout
			<< "" << std::endl
			<< "Numero incorreto." << std::endl
			<< "" << std::endl;

		if (input > NUMERO_SECRETO)
			std::cout << "Dica: O numero secreto eh menor." << std::endl;
		else
			std::cout << "Dica: O numero secreto eh maior" << std::endl;

		std::cout
			<< "" << std::endl
			<< "Digite outro numero: ";

		std::cin >> input;
	}

	system("cls");

	if (ativarTentativas == true && contadorTentativas == quantidadeTentativas)
	{
		std::cout
			<< "" << std::endl
			<< "********************************" << std::endl
			<< "                                " << std::endl
			<< " Limite de tentativas excedido! " << std::endl
			<< "" << std::endl
			<< " Tentativas permitidas: " << quantidadeTentativas << std::endl
			<< "" << std::endl
			<< " O numero correto era: " << NUMERO_SECRETO << std::endl
			<< "" << std::endl
			<< "********************************" << std::endl
			<< "" << std::endl;
	}
	else
	{
		std::cout
			<< "" << std::endl
			<< "********************************" << std::endl
			<< "" << std::endl
			<< " Parabens!                      " << std::endl
			<< "" << std::endl
			<< " O numero correto era: " << NUMERO_SECRETO << std::endl
			<< "" << std::endl
			<< " Voce acertou com " << contadorTentativas << " tentativas" << std::endl
			<< "" << std::endl
			<< "********************************" << std::endl
			<< "" << std::endl;
	}

	std::cout
		<< "Deseja jogar novamente (reiniciar)?" << std::endl
		<< "" << std::endl
		<< "Sim -> 1" << std::endl
		<< "Nao -> 2" << std::endl
		<< "" << std::endl
		<< "Opcao: ";

	int opcaoReiniciarJogo;
	std::cin >> opcaoReiniciarJogo;

	switch (opcaoReiniciarJogo)
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

	return 0;
}