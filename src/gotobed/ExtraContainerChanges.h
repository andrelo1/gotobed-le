#pragma once

#include "InventoryChanges.h"

namespace Gotobed
{
	class ExtraContainerChanges : public BSExtraData
	{
	public:
		InventoryChanges*	changes;
	};
}