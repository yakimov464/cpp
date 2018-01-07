#include <SFML/Graphics.hpp>
#include <algorithm>
#include <cmath>
#include <iostream>

void init(sf::ConvexShape &shape)
{
    shape.setPointCount(7);
    shape.setPoint(0, {0, 40});
    shape.setPoint(1, {40, 0});
    shape.setPoint(2, {0, -40});
    shape.setPoint(3, {0, -20});
    shape.setPoint(4, {-40, -20});
    shape.setPoint(5, {-40, 20});
    shape.setPoint(6, {0, 20});
    shape.setFillColor(sf::Color(255, 255, 0));
    shape.setOutlineColor(sf::Color(0, 0, 0));
    shape.setOutlineThickness(2);
    shape.setPosition({400, 300});
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
    float maxSpeed = 90;
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

    const float speed = 20 * dt;
    float x = delta.x / sqrt(delta.x * delta.x + delta.y * delta.y);
    float y = delta.y / sqrt(delta.x * delta.x + delta.y * delta.y);
    const sf::Vector2f direction = {x, y};
    shape.setPosition(shape.getPosition() + direction * speed);
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &shape)
{
    window.clear(sf::Color(255, 255, 255));
    window.draw(shape);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "1.2", sf::Style::Default, settings);
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