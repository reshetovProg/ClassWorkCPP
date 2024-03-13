#include "Button.h"

Button::Button(	sf::Vector2f size, 
				sf::Color color, 
				sf::Vector2f position,
				std::string str)

{

	shape.setSize(size);
	shape.setFillColor(color);
	shape.setPosition(position);	
	text.setString(str);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(position.x + 20, position.y + 20));

}

void Button::draw(sf::RenderWindow& window)
{
	font.loadFromFile("arialbd.ttf");
	text.setFont(font);
	window.draw(shape);
	window.draw(text);
}
