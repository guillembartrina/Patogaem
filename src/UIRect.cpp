
#include "UIRect.h"

#include <iostream>

#include "SFML/Graphics/RectangleShape.hpp"

UIRect::UIRect(UIRectStyle style, EUIAlign align, EUIFit fit, const sf::Vector2f& position, const sf::Vector2f& size)
: UIComponent(align, fit, position, size, new sf::RectangleShape(size))
{
    sf::RectangleShape* rect =  static_cast<sf::RectangleShape*>(getDrawable());
    if(style.texture)
    {
        rect->setTexture(style.texture, true);
        if(style.textureRect.has_value())
        {
            rect->setTextureRect(style.textureRect.value());
        }
    }
    rect->setFillColor(style.fillColor);
    rect->setOutlineThickness(style.outlineThickness);
    rect->setOutlineColor(style.outlineColor);
}

UIRect::~UIRect() {}
