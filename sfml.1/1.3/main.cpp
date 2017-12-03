#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 700}), "");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({500, 350});
    shape1.setRotation(0);
    shape1.setPosition({150, 340});
    shape1.setFillColor(sf::Color(0x4D, 0x33, 0x11));
    window.draw(shape1);

    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(0x76, 0x1F, 0x1F));
    trapeze.setPosition(400, 200);
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {-150, 0});
    trapeze.setPoint(1, {150, 0});
    trapeze.setPoint(2, {350, 150});
    trapeze.setPoint(3, {-350, 150});
    window.draw(trapeze);

    sf::RectangleShape shape2;
    shape1.setSize({100, 220});
    shape1.setRotation(0);
    shape1.setPosition({250, 470});
    shape1.setFillColor(sf::Color(0x21, 0x1F, 0x1F));
    window.draw(shape1);

    sf::RectangleShape shape3;
    shape3.setSize({50, 100});
    shape3.setRotation(0);
    shape3.setPosition({500, 190});
    shape3.setFillColor(sf::Color(0x21, 0x1F, 0x1F));
    window.draw(shape3);

    sf::RectangleShape shape4;
    shape4.setSize({60, 70});
    shape4.setRotation(90);
    shape4.setPosition({560, 130});
    shape4.setFillColor(sf::Color(0x21, 0x1F, 0x1F));
    window.draw(shape4);

    sf::CircleShape shape5(20);
    shape5.setPosition({510, 90});
    shape5.setFillColor(sf::Color(0xB5, 0xB5, 0xB5));
    window.draw(shape5);

    sf::CircleShape shape6(23);
    shape6.setPosition({525, 70});
    shape6.setFillColor(sf::Color(0xB5, 0xB5, 0xB5));
    window.draw(shape6);

    sf::CircleShape shape7(25);
    shape7.setPosition({540, 50});
    shape7.setFillColor(sf::Color(0xB5, 0xB5, 0xB5));
    window.draw(shape7);

    sf::CircleShape shape8(27);
    shape8.setPosition({560, 30});
    shape8.setFillColor(sf::Color(0xB5, 0xB5, 0xB5));
    window.draw(shape8);

    window.display();
    sf::sleep(sf::seconds(5));
}