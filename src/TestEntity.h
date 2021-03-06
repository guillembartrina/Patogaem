#ifndef TESTENTITY_HPP
#define TESTENTITY_HPP

#include "SFML/System/Vector2.hpp"

#include "Engine/AnimatedSprite.hpp"

#include "Entity.h"


class TestEntity : public Entity, public _EntityRegistration<TestEntity, Entity, "TestEntity">
{
    public:

    using _EntityRegistration<TestEntity, Entity, "TestEntity">::snode;

    TestEntity(const sf::Vector2f& position);
    ~TestEntity();

    virtual void update(const sf::Time deltatime) override;

    //static const _EntityRegistryNode* _fixnode;
    
    private:

    enum Anim
    {
        NONE,
        BASE,
        BASE2
    };

    AnimatedSprite<Anim, Anim::NONE>* sprite;
    sf::Vector2f vel;
};

#endif