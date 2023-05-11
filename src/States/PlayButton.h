#ifndef GAME_PLAYBUTTON_HPP
#define GAME_PLAYBUTTON_HPP

#include "Button.h"

namespace game {
    class PlayButton : public Button {
    public:
        PlayButton(float x, float y, float width, float height, const std::string &text,
                   const std::string &font);

        ~PlayButton() override = default;

        void update() override;
    };
}

#endif //GAME_PLAYBUTTON_HPP
