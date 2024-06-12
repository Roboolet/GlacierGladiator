#include "InputSystem.h"

void InputSystem::Initialize(InputMapping _inputMappings[], int _length)
{
	for (int i = 0; i < _length; i++) {
		InputMapping m = _inputMappings[i];

		// insert a new name -> inputphase mapping
		// will not create duplicate entries (good)
		inputs.insert(std::pair<std::string, InputPhase>(m.name, InputPhase::Off));

		// insert a new event -> name mapping
		inputMap.insert(std::pair<sf::Keyboard::Key, std::string>(m.key, m.name));
	}
}

void InputSystem::Advance()
{
}

void InputSystem::ProcessEvent(sf::Event)
{
}

InputPhase InputSystem::GetButtonPhase(std::string _key)
{
	return InputPhase();
}

bool InputSystem::GetButton(std::string _key)
{
	return false;
}

bool InputSystem::GetButtonDown(std::string _key)
{
	return false;
}

bool InputSystem::GetButtonUp(std::string _key)
{
	return false;
}
