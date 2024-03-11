#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "test sfml");
    int soccetSize = 50;
    std::vector<sf::RectangleShape> field;
    for (int i = 0; i <= window.getSize().y - soccetSize; i += soccetSize) {
        for (int j = 0; j <= window.getSize().x - soccetSize; j += soccetSize) {
            sf::RectangleShape soccet;
            soccet.setOutlineThickness(1);
            soccet.setOutlineColor(sf::Color::Black);
            soccet.setSize(sf::Vector2f(soccetSize, soccetSize));
            soccet.setPosition(sf::Vector2f(j, i));
            field.push_back(soccet);
        }
    }
    sf::CircleShape circle(soccetSize / 2);
    circle.setFillColor(sf::Color::Black);
    int countSoccetsWidth = window.getSize().x /soccetSize - 1;
    int countSoccetsHeight = window.getSize().y / soccetSize - 1;
    sf::Vector2f positionCircle(countSoccetsWidth / 2, countSoccetsHeight / 2);
    circle.setPosition(sf::Vector2f(positionCircle.x * soccetSize,
        positionCircle.y * soccetSize));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                if (positionCircle.x>0) positionCircle.x--;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                if (positionCircle.x < countSoccetsWidth) positionCircle.x++;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                if (positionCircle.y > 0) positionCircle.y--;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                if (positionCircle.y < countSoccetsHeight) positionCircle.y++;

            circle.setPosition(positionCircle.x* soccetSize,
                positionCircle.y * soccetSize);
        }



        window.clear(sf::Color::White);
        for (auto el : field) {
            window.draw(el);
        }
        window.draw(circle);
        window.display();
    }

    return 0;
}

