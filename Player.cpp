//
// Created by Lorenzo on 19/04/2023.
//

#include "Player.h"

void Player::move(float xpos, float ypos) {
    positionVector.x += xpos;
    positionVector.y += ypos;
    sprite.setPosition(positionVector.x,positionVector.y);
}

void Player::checkPressedKeys() {
    if (this->pressedKeys.up)
        this->move(0.f,-64.f);
    else if (this->pressedKeys.down)
        this->move(0.f,64.f);
    else if (this->pressedKeys.left)
        this->move(-64.f,0.f);
    else if (this->pressedKeys.right)
        this->move(64.f,0.f);
}

void Player::setPressedKey(sf::Keyboard::Key Key) {
    switch(Key) {
        case sf::Keyboard::Unknown:
        case sf::Keyboard::A:
            pressedKeys.left = true;
            break;
        case sf::Keyboard::B:
        case sf::Keyboard::C:
        case sf::Keyboard::D:
            pressedKeys.right = true;
            break;
        case sf::Keyboard::E:
        case sf::Keyboard::F:
        case sf::Keyboard::G:
        case sf::Keyboard::H:
        case sf::Keyboard::I:
        case sf::Keyboard::J:
        case sf::Keyboard::K:
        case sf::Keyboard::L:
        case sf::Keyboard::M:
        case sf::Keyboard::N:
        case sf::Keyboard::O:
        case sf::Keyboard::P:
        case sf::Keyboard::Q:
        case sf::Keyboard::R:
        case sf::Keyboard::S:
            pressedKeys.down = true;
            break;
        case sf::Keyboard::T:
        case sf::Keyboard::U:
        case sf::Keyboard::V:
        case sf::Keyboard::W:
            pressedKeys.up = true;
            break;
        case sf::Keyboard::X:
        case sf::Keyboard::Y:
        case sf::Keyboard::Z:
        case sf::Keyboard::Num0:
        case sf::Keyboard::Num1:
        case sf::Keyboard::Num2:
        case sf::Keyboard::Num3:
        case sf::Keyboard::Num4:
        case sf::Keyboard::Num5:
        case sf::Keyboard::Num6:
        case sf::Keyboard::Num7:
        case sf::Keyboard::Num8:
        case sf::Keyboard::Num9:
        case sf::Keyboard::Escape:
        case sf::Keyboard::LControl:
        case sf::Keyboard::LShift:
        case sf::Keyboard::LAlt:
        case sf::Keyboard::LSystem:
        case sf::Keyboard::RControl:
        case sf::Keyboard::RShift:
        case sf::Keyboard::RAlt:
        case sf::Keyboard::RSystem:
        case sf::Keyboard::Menu:
        case sf::Keyboard::LBracket:
        case sf::Keyboard::RBracket:
        case sf::Keyboard::Semicolon:
        case sf::Keyboard::Comma:
        case sf::Keyboard::Period:
        case sf::Keyboard::Quote:
        case sf::Keyboard::Slash:
        case sf::Keyboard::Backslash:
        case sf::Keyboard::Tilde:
        case sf::Keyboard::Equal:
        case sf::Keyboard::Hyphen:
        case sf::Keyboard::Space:
        case sf::Keyboard::Enter:
        case sf::Keyboard::Backspace:
        case sf::Keyboard::Tab:
        case sf::Keyboard::PageUp:
        case sf::Keyboard::PageDown:
        case sf::Keyboard::End:
        case sf::Keyboard::Home:
        case sf::Keyboard::Insert:
        case sf::Keyboard::Delete:
        case sf::Keyboard::Add:
        case sf::Keyboard::Subtract:
        case sf::Keyboard::Multiply:
        case sf::Keyboard::Divide:
        case sf::Keyboard::Left:
        case sf::Keyboard::Right:
        case sf::Keyboard::Up:
        case sf::Keyboard::Down:
        case sf::Keyboard::Numpad0:
        case sf::Keyboard::Numpad1:
        case sf::Keyboard::Numpad2:
        case sf::Keyboard::Numpad3:
        case sf::Keyboard::Numpad4:
        case sf::Keyboard::Numpad5:
        case sf::Keyboard::Numpad6:
        case sf::Keyboard::Numpad7:
        case sf::Keyboard::Numpad8:
        case sf::Keyboard::Numpad9:
        case sf::Keyboard::F1:
        case sf::Keyboard::F2:
        case sf::Keyboard::F3:
        case sf::Keyboard::F4:
        case sf::Keyboard::F5:
        case sf::Keyboard::F6:
        case sf::Keyboard::F7:
        case sf::Keyboard::F8:
        case sf::Keyboard::F9:
        case sf::Keyboard::F10:
        case sf::Keyboard::F11:
        case sf::Keyboard::F12:
        case sf::Keyboard::F13:
        case sf::Keyboard::F14:
        case sf::Keyboard::F15:
        case sf::Keyboard::Pause:
        case sf::Keyboard::KeyCount:
            break;
    }
}

void Player::resetPressedKeys() {
    pressedKeys.down = false;
    pressedKeys.right = false;
    pressedKeys.left = false;
    pressedKeys.up = false;
}
