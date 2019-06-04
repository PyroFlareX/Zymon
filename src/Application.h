#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include <memory>
#include <iostream>

#include "States/Basestate.h"
#include "Context.h"
#include "Renderers/Renderer.h"
#include "Camera.h"

class Basestate;

class Application
{
public:
    Application();

    void RunLoop();

    //State Stuff
    template<typename S, typename... Args>
    void pushState(Args&&... args)
    {
        m_states.push_back(std::make_unique<S>(std::forward<Args>(args)...));
    }

    void popState();
    void handleEvents();
protected:

private:
    Basestate& currentState();
    Context m_context;
    std::vector<std::unique_ptr<Basestate>> m_states;
	Renderer m_renderer;
};

#endif // APPLICATION_H
