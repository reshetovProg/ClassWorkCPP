#include "Calculator.h"



Calculator::Calculator() :
	window(sf::VideoMode(398, 598), "i-calculator"),
	gray(200, 200, 200, 255),
	white(20,20,20,255),
	orange(198,114,57,255)	
{
	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			sf::Color setColor = (i == 1 || j == 3) ? orange : gray;
			keybord.push_back(
				Button(sf::Vector2f(98, 98),
					setColor,
					sf::Vector2f(j * 100, i * 100),
					keyboardText[i-1][j])
			);
		}
	}
	font.loadFromFile("arialbd.ttf");
	text.setFont(font);
	text.setCharacterSize(70);
	text.setString(fieldText);
	text.setFillColor(sf::Color::White);
	text.setPosition(sf::Vector2f(350, 5));

	//button(sf::Vector2f(98,98), gray, sf::Vector2f(200,200))

}

void Calculator::run(){
	while (window.isOpen())
	{
		processEvent();
		update();
		render();
	}

}

void Calculator::update()
{
	for (auto& key : keybord) {
		key.update();
	}
	text.setString(fieldText);
	text.setPosition(sf::Vector2f(
		365 - fieldText.size() * 38,
		text.getPosition().y
	));
}

void Calculator::processEvent()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) ||
			event.type == sf::Event::MouseButtonReleased)
		{
			std::cout << "mouse is pressed"<<std::endl;
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			for (auto& key : keybord) {
				if ((mousePos.x >= key.getPosition().x) &&
					(mousePos.x <= (key.getPosition().x + key.getSize().x)) &&
					(mousePos.y >= key.getPosition().y) &&
					(mousePos.y <= (key.getPosition().y + key.getSize().y))) {
					key.changeActive();

					if (event.type == sf::Event::MouseButtonReleased) {
						if (key.getText()[0] >= '0' && key.getText()[0] <= '9' ||
							key.getText()[0] == '.') {
							if (fieldText == "0" && key.getText() != ".") fieldText = "";
							if (key.getText() == "." &&
								fieldText.find(".") <= fieldText.size()) {
								break;
							}
							fieldText += key.getText();
						}
						else {
							
							
							if (key.getText()[0] == '=') {
								if (operation != "") {
									std::cout << operation;
									
								}
								else {
									std::cout << "empty" << std::endl;
								}
							}
							else {
								operation = key.getText();
								fieldText = "0";
							}

							
						}
						
					}
					
						
				}
			}

		}
		
	}
}

void Calculator::render()
{
	window.clear();
	for (auto el : keybord) {
		el.draw(window);
	}

	window.draw(text);
	window.display();
}
