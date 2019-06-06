#ifndef APPLICATION_H
#define APPLICATION_H

#include <vector>
#include <memory>
#include <iostream>

#include "Context.h"
#include "Renderers/Renderer.h"
#include "Camera.h"
#include "States/Basestate.h"


class Application
{
public:
    Application();

    void RunLoop();

    //State Stuff

	void pushState(std::unique_ptr<Basestate> state)
	{
		m_states.emplace_back(std::move(state));
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
