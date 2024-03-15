#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Button
{
	sf::RectangleShape shape;
	sf::Text text;
	sf::Font font;
	bool active=false;
	sf::Color btnColor;
public:
	Button(sf::Vector2f size, 
		sf::Color color, 
		sf::Vector2f position,
		std::string str);
	void draw(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
	void changeActive();
	void update();
};

