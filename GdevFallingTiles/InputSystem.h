#pragma once
#include <SFML/Graphics.hpp>

enum InputPhase {
	Off, Started, Held, Canceled
};

struct InputMapping {
	sf::Keyboard::Key key;
	std::string name;

	InputMapping(sf::Keyboard::Key _k, std::string _n) : key(_k), name(_n){}
	std::pair<sf::Keyboard::Key, std::string> GetPair() {
		return std::pair<sf::Keyboard::Key, std::string>(key, name);
	}
};

class InputSystem {
public:
	// singleton pattern, based off of this implementation:
	// https://stackoverflow.com/a/1008289
	static InputSystem& GetInstance() {
		static InputSystem instance;
		return instance;
	}
	// delete keyword makes these default methods inaccessible
	InputSystem(InputSystem const&) = delete;
	void operator=(InputSystem const&) = delete;

	void Initialize(InputMapping _inputMappings[], int _length);
	void Advance();
	void ProcessEvent(sf::Event);

	// input register
	std::map<std::string, InputPhase> inputs;
	std::map<sf::Keyboard::Key, std::string> inputMap;

	InputPhase GetButtonPhase(std::string _key);
	bool GetButton(std::string _key);
	bool GetButtonDown(std::string _key);
	bool GetButtonUp(std::string _key);

private:
	// this seems to be the same as doing InputSystem() {}
	InputSystem() = default;

};