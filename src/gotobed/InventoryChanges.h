#pragma once

#include "BSTList.h"
#include "InventoryEntryData.h"

namespace Gotobed
{
	class InventoryChanges
	{
	public:
		BSSimpleList<InventoryEntryData*>*	entryList;
		::TESObjectREFR*					owner;
		float								totalWieght;
		float								armorWeight;
	};
}