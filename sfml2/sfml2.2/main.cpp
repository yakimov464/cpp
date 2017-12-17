#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main()
{
    constexpr int pointCount = 720;
    sf::Clock clock;
    float amplitude = 60.f;
    float period = 2;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::Vector2f position = {400, 300};
    sf::RenderWindow window(
        sf::VideoMode({800, 600}), "sfml2.2",
        sf::Style::Default, settings);

    sf::ConvexShape ellipse;
    ellipse.setPosition(position);
    ellipse.setFillColor(sf::Color(0xFF, 0x09, 0x80));

    ellipse.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        const float ellipseRadius = 200 * sin(6 * angle);
        sf::Vector2f point = {
            ellipseRadius * std::sin(angle),
            ellipseRadius * std::cos(angle)};
        ellipse.setPoint(pointNo, point);
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        const float dt = clock.getElapsedTime().asSeconds();
        const float wavePhase = dt * float(2 * M_PI);
        const float y = amplitude * std::sin(wavePhase / period);
        const float x = amplitude * std::cos(wavePhase / period);
        const sf::Vector2f offset = {x, y};
        ellipse.setPosition(position + offset);

        window.clear();
        window.draw(ellipse);
        window.display();
    }
}