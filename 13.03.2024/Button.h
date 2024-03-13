#pragma once
#include <SFML/Graphics.hpp>
class Button
{
	sf::RectangleShape shape;
	sf::Text text;
	sf::Font font;
public:
	Button(sf::Vector2f size, 
		sf::Color color, 
		sf::Vector2f position,
		std::string str);
	void draw(sf::RenderWindow& window);
};

