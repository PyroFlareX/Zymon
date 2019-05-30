#ifndef CONTEXT_H
#define CONTEXT_H

#include <SFML/Graphics.hpp>

class Context
{
    public:
        Context();

        sf::RenderWindow* getContext();
        void clear();
        void update();
        void draw();
        void initAPI();
        bool isOpen();

        ~Context();
    protected:

    private:
        sf::RenderWindow context;
};

#endif // CONTEXT_H
