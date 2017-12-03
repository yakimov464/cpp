#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({40, 100});
    shape1.setRotation(-45);
    shape1.setPosition({50, 50});
    shape1.setFillColor(sf::Color(0x5F, 0x5F, 0x5F));
    window.draw(shape1);

    sf::RectangleShape shape2;
    shape2.setSize({40, 100});
    shape2.setRotation(45);
    shape2.setPosition({200, 23});
    shape2.setFillColor(sf::Color(0x5F, 0x5F, 0x5F));
    window.draw(shape2);

    sf::RectangleShape shape3;
    shape3.setSize({50, 100});
    shape3.setRotation(0);
    shape3.setPosition({115, 100});
    shape3.setFillColor(sf::Color(0x5F, 0x5F, 0x5F));
    window.draw(shape3);

    sf::RectangleShape shape4;
    shape4.setSize({40, 100});
    shape4.setRotation(-45);
    shape4.setPosition({250, 50});
    shape4.setFillColor(sf::Color(0x5F, 0x5F, 0x5F));
    window.draw(shape4);

    sf::RectangleShape shape5;
    shape5.setSize({40, 100});
    shape5.setRotation(45);
    shape5.setPosition({400, 23});
    shape5.setFillColor(sf::Color(0x5F, 0x5F, 0x5F));
    window.draw(shape5);

    sf::RectangleShape shape6;
    shape6.setSize({50, 100});
    shape6.setRotation(0);
    shape6.setPosition({315, 100});
    shape6.setFillColor(sf::Color(0x5F, 0x5F, 0x5F));
    window.draw(shape6);

    sf::RectangleShape shape7;
    shape7.setSize({30, 75});
    shape7.setRotation(90);
    shape7.setPosition({550, 25});
    shape7.setFillColor(sf::Color(0x5F, 0x5F, 0x5F));
    window.draw(shape7);

    sf::RectangleShape shape8;
    shape8.setSize({30, 50});
    shape8.setRotation(0);
    shape8.setPosition({475, 55});
    shape8.setFillColor(sf::Color(0x5F, 0x5F, 0x5F));
    window.draw(shape8);

    sf::RectangleShape shape9;
    shape9.setSize({30, 75});
    shape9.setRotation(90);
    shape9.setPosition({550, 105});
    shape9.setFillColor(sf::Color(0x5F, 0x5F, 0x5F));
    window.draw(shape9);

    sf::RectangleShape shape10;
    shape10.setSize({30, 50});
    shape10.setRotation(0);
    shape10.setPosition({520, 135});
    shape10.setFillColor(sf::Color(0x5F, 0x5F, 0x5F));
    window.draw(shape10);

    sf::RectangleShape shape11;
    shape11.setSize({30, 75});
    shape11.setRotation(90);
    shape11.setPosition({550, 185});
    shape11.setFillColor(sf::Color(0x5F, 0x5F, 0x5F));
    window.draw(shape11);

    window.display();
    sf::sleep(sf::seconds(5));
}