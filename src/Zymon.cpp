#include "Zymon.h"

#include "Util/Random.h"
#include "nlohmann/json.hpp"

Zymon::Zymon()
{
	Random random;

	Type[0] = Types::FIRE;
	Type[1] = Types::FIGHTING;
	dexID = 4;

	IV = IVs {	random.intInRange(0,31), random.intInRange(0,31), 
				random.intInRange(0,31), random.intInRange(0,31), 
				random.intInRange(0,31), random.intInRange(0,31) };
	
	EV = { 0 };

	/*nlohmann::json j;

	j.parse*/
}

Zymon::~Zymon()
{
	
}
