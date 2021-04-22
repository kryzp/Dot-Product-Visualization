#include <SFML/Graphics.hpp>
#include <iostream>
#include "vec2.h"

constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;

constexpr int BASE_WIDTH = 500;
constexpr int BASE_HEIGHT = 8;

namespace
{
    sf::Color g_vector_a_col(235, 24, 82);
    sf::Color g_vector_b_col(86, 241, 114);
    sf::Color g_base_col(67, 66, 83);
    sf::Color g_cast_col(139, 138, 162);
    sf::Color g_shadow_col(30, 28, 42);
}

void draw_base_line(sf::RenderTarget& target);
void draw_shadow_line(sf::RenderTarget& target, float length);
void draw_vector(sf::RenderTarget& target, const math::Vec2F& vector, const sf::Color& color, float x_offset = 0, float y_offset = 0);

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Dot Product Visualization");

    math::Vec2F vector_trace;
    math::Vec2F vector_shadow;

    math::Vec2F vector_b(300, 0);
    math::Vec2F vector_a(300, 300);

    while (window.isOpen())
    {
        // handle events
        {
            sf::Event e;
            while (window.pollEvent(e))
            {
                if (e.type == sf::Event::Closed)
                    window.close();
            }
        }

        window.clear(sf::Color(41, 40, 53));
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                vector_a = math::Vec2F(
                    sf::Mouse::getPosition(window).x - (WINDOW_WIDTH / 2),
                    -sf::Mouse::getPosition(window).y + (WINDOW_HEIGHT / 2)
                );
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
            {
                vector_b = math::Vec2F(
                    sf::Mouse::getPosition(window).x - (WINDOW_WIDTH / 2),
                    -sf::Mouse::getPosition(window).y + (WINDOW_HEIGHT / 2)
                );
            }

            float shadow_length = math::Vec2F::dot(vector_a, vector_b) / vector_b.length();

            vector_shadow = vector_b.normal() * shadow_length;
            vector_trace = vector_shadow - vector_a;

            float angle = vector_b.angle();

            draw_base_line(window);
            draw_vector(window, vector_shadow, g_shadow_col);
            draw_vector(window, vector_b, g_shadow_col, calc::sin(angle) * 20, calc::cos(angle) * 20);
            draw_vector(window, vector_trace, g_shadow_col, vector_a.x, -vector_a.y);
            draw_vector(window, vector_a, g_vector_a_col);
            draw_vector(window, vector_b, g_vector_b_col);
        }
        window.display();
    }

    return 0;
}

void draw_base_line(sf::RenderTarget& target)
{
    sf::CircleShape circle_1;
    circle_1.setFillColor(g_base_col);
    circle_1.setPosition(sf::Vector2f((WINDOW_WIDTH/2) - (BASE_WIDTH/2) - (BASE_HEIGHT/2), (WINDOW_HEIGHT/2) - (BASE_HEIGHT/2)));
    circle_1.setRadius(BASE_HEIGHT / 2);
    target.draw(circle_1);

    sf::CircleShape circle_2;
    circle_2.setFillColor(g_base_col);
    circle_2.setPosition(sf::Vector2f((WINDOW_WIDTH/2) + (BASE_WIDTH/2) - (BASE_HEIGHT/2), (WINDOW_HEIGHT/2) - (BASE_HEIGHT/2)));
    circle_2.setRadius(BASE_HEIGHT / 2);
    target.draw(circle_2);

    sf::RectangleShape base_line;
    base_line.setFillColor(g_base_col);
    base_line.setPosition(sf::Vector2f((WINDOW_WIDTH/2) - (BASE_WIDTH/2), (WINDOW_HEIGHT/2) - (BASE_HEIGHT/2)));
    base_line.setSize(sf::Vector2f(BASE_WIDTH, BASE_HEIGHT));
    target.draw(base_line);
}

void draw_vector(sf::RenderTarget& target, const math::Vec2F& vector, const sf::Color& color, float x_offset, float y_offset)
{
    float angle = vector.angle();

    float x = calc::sin(angle) * (BASE_HEIGHT / 2);
    float y = calc::cos(angle) * (BASE_HEIGHT / 2);

    sf::CircleShape circle_1;
    circle_1.setFillColor(color);
    circle_1.setPosition(sf::Vector2f(x_offset + (WINDOW_WIDTH/2) - (BASE_HEIGHT/2), y_offset + (WINDOW_HEIGHT/2) - (BASE_HEIGHT/2)));
    circle_1.setRadius(BASE_HEIGHT / 2);
    target.draw(circle_1);

    sf::CircleShape circle_2;
    circle_2.setFillColor(color);
    circle_2.setPosition(sf::Vector2f(vector.x + x_offset + (WINDOW_WIDTH/2) - (BASE_HEIGHT/2), -vector.y + y_offset + (WINDOW_HEIGHT/2) - (BASE_HEIGHT/2)));
    circle_2.setRadius(BASE_HEIGHT / 2);
    target.draw(circle_2);

    sf::RectangleShape shape;
    shape.setFillColor(color);
    shape.setPosition(sf::Vector2f(
        (WINDOW_WIDTH / 2) - x + x_offset,
        (WINDOW_HEIGHT / 2) - y + y_offset
    ));
    shape.setSize(sf::Vector2f(vector.length(), BASE_HEIGHT));
    shape.setRotation(-angle * calc::RAD2DEG);
    target.draw(shape);
}
