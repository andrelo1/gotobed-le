#include "SleepwearManager.h"
#include "Offsets.h"
#include "TESObjectREFR.h"
#include "Actor.h"

namespace Gotobed
{
	SleepwearManager::EquipConditions::EquipConditions(std::int32_t a_obj)
	{
		if (a_obj) {
			auto domain = jc::domain::get();
			auto locTypeObj = jc::JMap::getObj(domain, a_obj, "locType");

			if (locTypeObj) {
				auto count = jc::JArray::count(domain, locTypeObj);

				for (int i = 0; i < count; ++i) {
					auto f = jc::JArray::getForm(domain, locTypeObj, i);
					if (f) {
						locType.push_back(f);
					}
				}
			}
		}
	}

	bool SleepwearManager::EquipConditions::operator()(::Actor* a_actor) const
	{
		if (!a_actor) {
			return false;
		}

		if (locType.empty()) {
			return true;
		}

		auto location = static_cast<TESObjectREFR*>(static_cast<::TESObjectREFR*>(a_actor))->GetCurrentLocation();

		if (location) {
			for (auto& type : locType) {
				if (type->formType == kFormType_Keyword) {
					if (location->keyword.HasKeyword(static_cast<BGSKeyword*>(type))) {
						return true;
					}
				}
			}
		}

		return false;
	}
	
	SleepwearManager& SleepwearManager::Get()
	{
		static SleepwearManager manager;
		return manager;
	}

	bool SleepwearManager::IsSleepOutfitEnabled(::Actor* a_actor)
	{
		return a_actor && true;
	}

	bool SleepwearManager::IsSleepOutfitEquipped(::Actor* a_actor)
	{
		return a_actor && jc::JFormDB::solveObj(jc::domain::get(), a_actor, ".formdb.outfit");
	}

	std::optional<Outfit> SleepwearManager::GetSleepOutfit(::Actor* a_actor)
	{
		if (!a_actor) {
			return std::nullopt;
		}

		auto outfit = jc::JFormDB::solveObj(jc::domain::get(), a_actor, ".formdb.preferences.sleepwear.outfit");

		if (outfit) {
			return outfit;
		}

		auto actorBase = static_cast<TESNPC*>(a_actor->baseForm);

		if (actorBase && actorBase->sleepOutfit) {
			return *actorBase->sleepOutfit;
		}

		return std::nullopt;
	}

	void SleepwearManager::EquipSleepOutfit(::Actor* a_actor)
	{
		if (!a_actor || IsSleepOutfitEquipped(a_actor)) {
			return;
		}

		auto actor = static_cast<Actor*>(a_actor);

		auto sleepOutfit = GetSleepOutfit(a_actor);

		if (!sleepOutfit) {
			return;
		}

		auto domain = jc::domain::get();
		Outfit outfit{ actor->GetEquippedItems() };

		jc::JFormDB::solveObjSetter(domain, actor, ".formdb.outfit", outfit, true);

		actor->EquipOutfit(*sleepOutfit);
	}

	void SleepwearManager::UnequipSleepOutfit(::Actor* a_actor)
	{
		if (!a_actor || !IsSleepOutfitEquipped(a_actor)) {
			return;
		}

		auto actor = static_cast<Actor*>(a_actor);

		auto domain = jc::domain::get();
		auto outfit = jc::JFormDB::solveObj(domain, actor, ".formdb.outfit");

		if (!outfit) {
			return;
		}

		actor->EquipOutfit(outfit);

		jc::JFormDB::solveObjSetter(domain, actor, ".formdb.outfit", 0);
	}

	void SleepwearManager::UpdateOutfit(::Actor* a_actor)
	{
		if (!a_actor) {
			return;
		}

		if (IsSleepOutfitEnabled(a_actor) && (a_actor->actorState.flags04 >> 0xE & 0xF) >= 5 && (a_actor->actorState.flags04 >> 0xE & 0xF) <= 8) {
			EquipConditions conditions{ jc::JFormDB::solveObj(jc::domain::get(), a_actor, ".formdb.preferences.sleepwear.conditions") };

			if (conditions(a_actor)) {
				EquipSleepOutfit(a_actor);
			}
		} else {
			UnequipSleepOutfit(a_actor);
		}
	}
}