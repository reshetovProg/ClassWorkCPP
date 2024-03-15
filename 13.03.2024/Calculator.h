#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
class Calculator
{
	sf::RenderWindow window;
	sf::Color gray;
	sf::Color white;
	sf::Color orange;
	std::vector<Button> keybord;
	std::string keyboardText[5][4]{ {"C","CE","X^","sqrt"},
								{"7","8","9","+"},
								{"4","5","6","-"},
								{"1","2","3","*"},
								{".","0","=","/"} };
	std::string fieldText="0";
	std::string operation = "";
	sf::Text text;
	sf::Font font;
public:
	Calculator();
	void run();
private:
	void update();
	void processEvent();
	void render();
};

