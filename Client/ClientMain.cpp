
#include "Doctor.h"
int main(int argc, char* argv[])
{
	setlocale(LC_CTYPE, "rus");
	Doctor doc = Doctor();
	std::cout << "Добро пожаловать! Вам доступны команды:" << std::endl
		<< "-  get - принять пациента " << std::endl
		<< "-  print - информация о пациенте " << std::endl << std::endl;
	while (true) {
		std::string mes;
		std::cin >> mes;
		if (mes == "get") {
			doc.GetNextP();
			doc.PrintCurrentPat();
			std::cout << std::endl;
		}
		else if (mes == "print") {
			doc.PrintCurrentPat();
			std::cout << std::endl;
		}
		else std::cout << "Команда отсутствует" << std::endl << std::endl;
	}
}
