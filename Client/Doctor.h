#pragma once
#include <string>
#include "ClientController.h"


class Doctor {
private:
	std::string pp="Нет текущего клиента";
public:
	void PrintCurrentPat() {
		std::cout <<pp << std::endl;
	};
	void GetNextP() {
		ClientController cl = ClientController();
		pp = cl.ResiveData();
	}

};

