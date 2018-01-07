#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

void init(sf::ConvexShape &shape)
{
    shape.setPointCount(3);
    shape.setPoint(0, {40, 0});
    shape.setPoint(1, {-20, -20});
    shape.setPoint(2, {-20, 20});
    shape.setPosition({400, 300});
    shape.setFillColor(sf::Color(0xFF, 0x80, 0x00));
}
float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x), float(event.y)};
}
void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &shape, float &dt)
{
    const sf::Vector2f delta = mousePosition - shape.getPosition();
    float maxSpeed = 15;
    float angle = atan2(delta.y, delta.x);
    if (angle < 0)
    {
        angle = angle + 2 * M_PI;
    }
    angle = toDegrees(angle);
    const float maxRotation = maxSpeed * dt;
    const float rotation = std::abs((angle - shape.getRotation()));
    if (angle < shape.getRotation())
    {
        if ((angle + 180) < shape.getRotation())
        {
            shape.setRotation(shape.getRotation() + std::min(maxRotation, rotation));
        }
        else
        {
            shape.setRotation(shape.getRotation() - std::min(maxRotation, rotation));
        }
    }
    else
    {
        if ((angle - 180) > shape.getRotation())
        {
            shape.setRotation(shape.getRotation() - std::min(maxRotation, rotation));
        }
        else
        {
            shape.setRotation(shape.getRotation() + std::min(maxRotation, rotation));
        }
    }
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &shape)
{
    window.clear();
    window.draw(shape);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "sfml3.1", sf::Style::Default, settings);

    sf::ConvexShape shape;
    sf::Vector2f mousePosition;
    sf::Clock clock;

    init(shape);
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        pollEvents(window, mousePosition);
        update(mousePosition, shape, dt);
        redrawFrame(window, shape);
    }
}