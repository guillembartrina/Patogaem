
#include "PhysicEntity.h"

#include "Level.h"

PhysicEntity::PhysicEntity(const sf::Vector2f& position, const sf::Vector2f& size, sf::Drawable* drawable)
: Entity(position, size, drawable)
{}

PhysicEntity::~PhysicEntity() {}

void PhysicEntity::update(const sf::Time deltatime) {}

void PhysicEntity::levelize(Level* level, int layer)
{
    Entity::levelize(level, layer);
    body = nullptr;
}

void PhysicEntity::unlevelize()
{
    body = nullptr;
}
