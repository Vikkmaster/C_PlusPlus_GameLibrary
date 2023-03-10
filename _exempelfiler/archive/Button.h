#ifndef BUTTON_H
#define BUTTON_H
#include <SDL2/SDL.h>

#include <string>

#include "Component.h"

namespace cwing {

    class Button: public Component {
    public:
        static Button* getInstance(int x, int y, int w, int h, std::string txt);
        void mouseDown(const SDL_Event&);
        void mouseUp(const SDL_Event&);
        void draw() const;
        virtual void perform(Button* source) {};
        void tick() {};
        ~Button();

    protected:
        Button(int x, int y, int w, int h, std::string txt);

    private:
        std::string text;
        SDL_Texture* texture;
        SDL_Texture* upIcon, * downIcon;
        bool isDown = false;
    };
} // namespace cwing
#endif