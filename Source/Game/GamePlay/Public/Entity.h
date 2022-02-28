#pragma once

#include "TransformComponent.h"

namespace Lumen::Game
{
    // Objects make up the world, entity can attach to another entity and is made up with components
    class Entity : public BaseObject
    {
    public:
        Entity();

        virtual void BeginPlay() {};
        virtual void Tick() {};

        inline std::string GetName() const noexcept { return mName; }
        inline void SetName(std::string_view name) noexcept { mName = name; }

    protected:
        [[serialize(true)]]
        std::string mName;
        [[serialize(true)]]
        std::vector<Entity> mChildEntities;

        [[serialize(true)]]
        TransformComponent transform;

        RTTR_REGISTRATION_FRIEND
        RTTR_ENABLE(BaseObject)
    };
}