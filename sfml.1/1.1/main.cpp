#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({110, 270}), "svetofor");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({80, 250});
    shape1.setRotation(0);
    shape1.setPosition({15, 10});
    shape1.setFillColor(sf::Color(0x5F, 0x5F, 0x5F));
    window.draw(shape1);

    sf::CircleShape shape2(35);
    shape2.setPosition({20, 25});
    shape2.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape2);

    sf::CircleShape shape3(35);
    shape3.setPosition({20, 100});
    shape3.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
    window.draw(shape3);

    sf::CircleShape shape4(35);
    shape4.setPosition({20, 175});
    shape4.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape4);

    window.display();

    sf::sleep(sf::seconds(5));
}