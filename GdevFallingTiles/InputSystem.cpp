#include "InputSystem.h"
#include <iostream>

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

// Advance the process, this makes the Started and Canceled phases work
void InputSystem::Advance()
{
	// someone explain to me how this for loop works
	for (auto const& x : inputs) {
		if (inputs[x.first] == InputPhase::Started) { inputs[x.first] = InputPhase::Held; }
		else if (inputs[x.first] == InputPhase::Canceled) { inputs[x.first] = InputPhase::Off; }

		//std::cout << "input " << x.first << " = " << x.second << std::endl;
	}
}

void InputSystem::ProcessEvent(sf::Event _event)
{
	if (_event.type == sf::Event::KeyPressed) {
		if (inputMap.find(_event.key.code) != inputMap.end()) {
			std::string nm = inputMap[_event.key.code];
			inputs[nm] = InputPhase::Started;
		}
	}
	else if (_event.type == sf::Event::KeyReleased) {
		if (inputMap.find(_event.key.code) != inputMap.end()) {
			std::string nm = inputMap[_event.key.code];
			inputs[nm] = InputPhase::Canceled;
		}
	}
}

InputPhase InputSystem::GetButtonPhase(std::string _key)
{
	return inputs[_key];
}

bool InputSystem::GetButton(std::string _key)
{
	return (inputs[_key] == InputPhase::Held);
}

bool InputSystem::GetButtonDown(std::string _key)
{
	return (inputs[_key] == InputPhase::Started);
}

bool InputSystem::GetButtonUp(std::string _key)
{
	return (inputs[_key] == InputPhase::Canceled);
}
