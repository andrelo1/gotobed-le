#pragma once

#include "BSTList.h"
#include "ExtraDataList.h"

namespace Gotobed
{
	class InventoryEntryData
	{
	public:
		TESBoundObject*					object;
		BSSimpleList<ExtraDataList*>*	extraLists;
		std::int32_t					countDelta;
	};
}