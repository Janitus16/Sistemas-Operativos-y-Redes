#include "InputSystem.h"

InputSystem::KeyBinding::KeyBinding(int key, OnKeyPress onKeyPress)
{

}

InputSystem::KeyBinding::~KeyBinding()
{

}

InputSystem::InputSystem()
{

}

InputSystem::~InputSystem()
{
	for (std::pair<int, KeyBindingList> pair : _keyBindingMap) {
		KeyBindingList bindingList = pair.second;
		for (KeyBinding* binding : bindingList) {
			delete binding;
		}

		bindingList.clear();
	}
	_keyBindingMap.clear();
}

InputSystem::KeyBinding* InputSystem::AddListener(int key, KeyBinding::OnKeyPress onKeyPress) {
	_classMutex.lock();

	if (_keyBindingMap.find(key) == _keyBindingMap.end()) {
		_keyBindingMap[key] = KeyBindingList();
	}

	KeyBinding* keyBinding = new KeyBinding(key, onKeyPress);
	_keyBindingMap[key].push_back(keyBinding);

	_classMutex.unlock();

	return keyBinding;
}