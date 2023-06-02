#ifndef GAME_EXITBUTTON_HPP
#define GAME_EXITBUTTON_HPP

#include "Button.h"

namespace game {
    class ExitButton : public Button {
    public:
        ExitButton(float x, float y, float width, float height, const std::string &text,
                   const std::string &font);

        bool isPressed() override;

        void update() override;

    };
}


#endif //GAME_EXITBUTTON_HPP
