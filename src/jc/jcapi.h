#pragma once

#include "JContainers/JContainers/src/jc_interface.h"

namespace jc
{
	namespace api
	{
		void						init();
		const reflection_interface*	getReflectionInterface();
		const domain_interface*		getDomainInterface();
	}
}