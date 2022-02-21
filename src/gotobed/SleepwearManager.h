#pragma once

#include "Outfit.h"

namespace Gotobed
{
	class SleepwearManager
	{
	public:
		class EquipConditions
		{
		public:
			EquipConditions() = default;
			EquipConditions(std::int32_t a_obj);

			bool	operator()(::Actor* a_actor) const;

			std::vector<TESForm*>	locType;
		};

		static SleepwearManager&	Get();
		bool						IsSleepOutfitEnabled(::Actor* a_actor);
		bool						IsSleepOutfitEquipped(::Actor* a_actor);
		std::optional<Outfit>		GetSleepOutfit(::Actor* a_actor);
		void						EquipSleepOutfit(::Actor* a_actor);
		void						UnequipSleepOutfit(::Actor* a_actor);
		void						UpdateOutfit(::Actor* a_actor);
	};
}