
#include "SceneTest.h"

#include "SFML/Graphics/RectangleShape.hpp"

#include "TestEntity.h"
#include "UIBox.h"
#include "UIBorder.h"
#include "UIRect.h"

SceneTest::SceneTest() : IScene() {}

SceneTest::~SceneTest() {}

void SceneTest::init(Window::View* window)
{
    Entity* entity = new TestEntity(sf::Vector2f(100, 100));
    entity->levelize(&level);

    UIRect* rect = new UIRect(UIRectStyle::defaultStyle(), EUIAlign::TOPLEFT, EUIFit::ADJUST, sf::Vector2f(100, 100), sf::Vector2f(1, 1));
    UIBox* box = new UIBox(sf::Vector2f(100, 100), sf::Vector2f(400, 400), new UIBorder(UIBorderStyle{sf::Color::White, 5.f}, rect));
    box->levelize(&level);
}

void SceneTest::handleEvents(const sf::Event& event)
{
    switch(event.type)
    {
        case sf::Event::KeyPressed:
        {
            switch(event.key.code)
            {
                case sf::Keyboard::Escape:
                {
                    closeScene();
                }
                    break;
                default:
                    break;
            }
        }
            break;
        default:
            break;
    }
}

void SceneTest::update(const sf::Time& deltatime)
{
    level.update(deltatime);
}

void SceneTest::draw(Renderer renderer) const
{
    level.draw(renderer);
}
