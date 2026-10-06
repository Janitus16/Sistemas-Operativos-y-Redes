#include <iostream>
#include "2InputSystem/InputsConsts.h"
#include "Utils/ConsoleControl.h"
#include "2InputSystem/InputSystem.h"


void CuandoPresiono1() {
	CC::Lock();
	std::cout << "Pressed 1" << std::endl;
	CC::Unlock();
}

void keyName() {
	int key = CC::WaithForReadNextKey();
	std::cout << key;
}

int main()
{
	InputSystem* iS = new InputSystem();

	InputSystem::KeyBinding* kb1 = iS->AddListener(K_1, CuandoPresiono1);

	keyName();

	iS->StartListen();

	while (true) {

	}
}