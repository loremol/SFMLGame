#ifndef GAME_ENTITY_HPP
#define GAME_ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <utility>
#include "../Init.h"
#include "../Definitions.h"

namespace game {
    class Entity {
    public:
        class Movement {
        public:
            explicit Movement(Entity &entity);

            void calcVelocity(const float &dir_x, const float &dir_y);

            void update(const float &dt);

            void setMaxVelocity(float x) { maxVelocity = x; }

            void setAcceleration(float x) { acceleration = x; }

            void setDeceleration(float x) { deceleration = x; }

            sf::Vector2f &getVelocity() { return velocity; }

        private:
            sf::Vector2f velocity;
            float maxVelocity;
            float acceleration;
            float deceleration;
            Entity &entity;

            void decelerate();
        };

        class Animation {
        public:
            explicit Animation(Entity &entity) : entity(entity) {}

            void updateSprite();

            void loadFrames();

            void addIdleFrameFilename(const std::string &filename) { idleFramesFilenames.push_back(filename); }

            void addMovingFrameFilename(const std::string &filename) { movingFramesFilenames.push_back(filename); }

            void setupIdleFrameIterator();

            sf::Texture &getFirstIdleFrame() { return *idleFrames.begin(); }

            void setupMovingFrameIterator();

        private:
            std::vector<sf::Texture> idleFrames;
            std::vector<sf::Texture> movingFrames;
            std::vector<sf::Texture>::iterator idleFrameIterator;
            std::vector<sf::Texture>::iterator movingFrameIterator;

            std::vector<std::string> idleFramesFilenames;
            std::vector<std::string> movingFramesFilenames;

            sf::Clock clock;
            Entity &entity;

            [[nodiscard]] bool checkIfMoving() const;

        };

        Entity();

        virtual ~Entity() = default;

        virtual void flipSpriteLeft();

        virtual void flipSpriteRight();

        virtual void update(const float &dt);

        virtual void render();

        sf::Vector2f mapPosition;

        sf::Sprite sprite;

        bool isMoving = false;

        unsigned int entityID = 0;

        Movement movement;

        Animation animation;
    protected:
        bool direction_r = true;
        bool direction_l = false;
    };

    class EntityFactory {
    public:
        explicit EntityFactory();

        [[nodiscard]] Entity *createEntity(const std::string &entityType, sf::Vector2f position) const;

        void setupEntity(Entity *entity, const std::string &entityType) const;

    private:
        struct entityParameters {
            float maxVelocity;
            float acceleration;
            float deceleration;
            std::vector<std::string> idleFramesFilenames;
            std::vector<std::string> movingFramesFilenames;
            float textureScaleX;
            float textureScaleY;
        };
        std::map<std::string, entityParameters> params{};
    };

}

#endif //GAME_ENTITY_HPP
