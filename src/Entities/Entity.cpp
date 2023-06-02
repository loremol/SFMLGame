#include "Entity.h"
#include "../mgr.h"

namespace game {
    Entity::Entity() : movement(*this), animation(*this) {}

    void Entity::update(const float &dt) {
        movement.update(dt);
        animation.updateSprite();
    }

    void Entity::render() {
        mgr::window.draw(sprite);
    }

    void Entity::flipSpriteLeft() {
        if (direction_r) {
            sprite.setTextureRect(sf::IntRect(static_cast<int>(sprite.getLocalBounds().width), 0,
                                              static_cast<int>(-sprite.getLocalBounds().width),
                                              static_cast<int>(sprite.getLocalBounds().height)));

            direction_r = false;
            direction_l = true;
        }
    }

    void Entity::flipSpriteRight() {
        if (direction_l) {
            sprite.setTextureRect(sf::IntRect(0, 0, static_cast<int>(sprite.getLocalBounds().width),
                                              static_cast<int>(sprite.getLocalBounds().height)));

            direction_r = true;
            direction_l = false;
        }
    }

    Entity::Movement::Movement(Entity &entity) : entity(entity) {
        switch (entity.entityID) {
            case 1:
                maxVelocity = 250.f;
                acceleration = 15.f;
                deceleration = 7.5f;
                break;
        }
    }

    void Entity::Movement::update(const float &dt) {
        decelerate();
        entity.mapPosition += velocity * dt;
        entity.sprite.move(velocity * dt);
        mgr::view.move(velocity * dt);
    }

    void Entity::Movement::decelerate() {// Deceleration
        if (velocity.x > 0.f) {
            // Checking if going over maxVelocity
            if (velocity.x > maxVelocity) {
                velocity.x = maxVelocity;
            }

            velocity.x -= deceleration;
            // Stopping the friction before it becomes acceleration
            if (velocity.x < 0.f) {
                velocity.x = 0.f;
            }
        } else if (velocity.x < 0.f) {
            // Checking if going over maxVelocity
            if (velocity.x < -maxVelocity)
                velocity.x = -maxVelocity;

            velocity.x += deceleration;
            // Stopping the friction before it becomes acceleration
            if (velocity.x > 0.f) {
                velocity.x = 0.f;
            }
        }

        if (velocity.y > 0.f) {
            // Checking if going over maxVelocity
            if (velocity.y > maxVelocity) {
                velocity.y = maxVelocity;
            }

            velocity.y -= deceleration;
            // Stopping the friction before it becomes acceleration
            if (velocity.y < 0.f) {
                velocity.y = 0.f;
            }
        } else if (velocity.y < 0.f) {
            // Checking if going over maxVelocity
            if (velocity.y < -maxVelocity)
                velocity.y = -maxVelocity;

            velocity.y += deceleration;
            // Stopping the friction before it becomes acceleration
            if (velocity.y > 0.f) {
                velocity.y = 0.f;
            }
        }
    }

    void Entity::Movement::calcVelocity(const float &dir_x, const float &dir_y) {
        velocity.x += acceleration * dir_x;
        velocity.y += acceleration * dir_y;
    }


    void Entity::Animation::updateSprite() {
        entity.isMoving = checkIfMoving();

        if (clock.getElapsedTime().asSeconds() >= 0.2) {
            // Moving animation
            if (entity.isMoving || movingFrameIterator != movingFrames.begin()) {
                entity.sprite.setTexture(*movingFrameIterator);

                movingFrameIterator = (movingFrameIterator + 1);
                if (movingFrameIterator == movingFrames.end()) {
                    movingFrameIterator = movingFrames.begin();
                }

                idleFrameIterator = idleFrames.begin();
                clock.restart();
            }
                // Idle animation
            else if (!entity.isMoving && clock.getElapsedTime().asSeconds() >= 0.4) {
                entity.sprite.setTexture(*idleFrameIterator);
                idleFrameIterator = (idleFrameIterator + 1);
                if (idleFrameIterator == idleFrames.end()) {
                    idleFrameIterator = idleFrames.begin();
                }

                movingFrameIterator = movingFrames.begin();
                clock.restart();
            }
        }
    }

    bool Entity::Animation::checkIfMoving() const {
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) ||
            (entity.movement.getVelocity().x != 0))
            return true;
        else if (entity.movement.getVelocity().x == 0 && entity.movement.getVelocity().y == 0)
            return false;
        return false;
    }

    void Entity::Animation::loadFrames() {
        for (const auto &fn: idleFramesFilenames) {
            sf::Texture texture;
            texture.loadFromFile(fn);
            idleFrames.push_back(texture);
        }
        for (const auto &fn: movingFramesFilenames) {
            sf::Texture texture;
            texture.loadFromFile(fn);
            movingFrames.push_back(texture);
        }
    }

    void Entity::Animation::setupIdleFrameIterator() {
        idleFrameIterator = idleFrames.begin();
    }

    void Entity::Animation::setupMovingFrameIterator() {
        movingFrameIterator = movingFrames.begin();
    }

    EntityFactory::EntityFactory() {
        entityParameters playerParams;
        playerParams.maxVelocity = 110.f;
        playerParams.acceleration = 12.f;
        playerParams.deceleration = 4.f;
        playerParams.idleFramesFilenames.push_back(
                std::filesystem::path("./res/sprite/player/skelet_idle_anim_f0.png").make_preferred().string());
        playerParams.idleFramesFilenames.push_back(
                std::filesystem::path("./res/sprite/player/skelet_idle_anim_f1.png").make_preferred().string());
        playerParams.movingFramesFilenames.push_back(
                std::filesystem::path("./res/sprite/player/skelet_run_anim_f0.png").make_preferred().string());
        playerParams.movingFramesFilenames.push_back(
                std::filesystem::path("./res/sprite/player/skelet_run_anim_f1.png").make_preferred().string());
        playerParams.movingFramesFilenames.push_back(
                std::filesystem::path("./res/sprite/player/skelet_run_anim_f2.png").make_preferred().string());
        playerParams.movingFramesFilenames.push_back(
                std::filesystem::path("./res/sprite/player/skelet_run_anim_f3.png").make_preferred().string());
        playerParams.movingFramesFilenames.push_back(
                std::filesystem::path("./res/sprite/player/skelet_run_anim_f4.png").make_preferred().string());
        playerParams.movingFramesFilenames.push_back(
                std::filesystem::path("./res/sprite/player/skelet_run_anim_f5.png").make_preferred().string());
        playerParams.textureScaleX = 4.f;
        playerParams.textureScaleY = 4.f;
        std::pair<std::string, entityParameters> player("Player", playerParams);
        params.insert(player);
    }

    Entity *EntityFactory::createEntity(const std::string &entityType, sf::Vector2f position) const {
        auto *entityPtr = new Entity();
        setupEntity(entityPtr, entityType);
        entityPtr->sprite.setPosition(position);
        entityPtr->mapPosition = position;

        return entityPtr;
    }

    void EntityFactory::setupEntity(Entity *entity, const std::string &entityType) const {
        entity->movement.setMaxVelocity(params.at(entityType).maxVelocity);
        entity->movement.setAcceleration(params.at(entityType).acceleration);
        entity->movement.setDeceleration(params.at(entityType).deceleration);
        for (const auto &it: params.at(entityType).idleFramesFilenames) {
            entity->animation.addIdleFrameFilename(it);
        }
        for (const auto &it: params.at(entityType).movingFramesFilenames) {
            entity->animation.addMovingFrameFilename(it);
        }
        entity->animation.loadFrames();
        entity->animation.setupIdleFrameIterator();
        entity->animation.setupMovingFrameIterator();

        entity->sprite.scale(params.at(entityType).textureScaleX, params.at(entityType).textureScaleY);
        entity->sprite.setTexture(entity->animation.getFirstIdleFrame());
    }
}

