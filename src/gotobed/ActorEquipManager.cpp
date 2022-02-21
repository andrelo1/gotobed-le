#include "ActorEquipManager.h"
#include "Offsets.h"

namespace Gotobed
{
	ActorEquipManager* ActorEquipManager::GetSingleton()
	{
		return *reinterpret_cast<ActorEquipManager**>(Offsets::ActorEquipManager::Singleton);
	}

	void ActorEquipManager::EquipObject(::Actor* a_actor, TESBoundObject* a_object, BaseExtraList* a_extraData, std::uint32_t a_count, const BGSEquipSlot* a_slot, bool a_queueEquip, bool a_forceEquip, bool a_playSounds, bool a_applyNow)
	{
		using func_t = decltype(&ActorEquipManager::EquipObject);
		auto addr = Offsets::ActorEquipManager::EquipObject;
		auto func = reinterpret_cast<func_t&>(addr);
		(this->*func)(a_actor, a_object, a_extraData, a_count, a_slot, a_queueEquip, a_forceEquip, a_playSounds, a_applyNow);
	}

	bool ActorEquipManager::UnequipObject(::Actor* a_actor, TESBoundObject* a_object, BaseExtraList* a_extraData, std::uint32_t a_count, const BGSEquipSlot* a_slot, bool a_queueEquip, bool a_forceEquip, bool a_playSounds, bool a_applyNow, const BGSEquipSlot* a_slotToReplace)
	{
		using func_t = decltype(&ActorEquipManager::UnequipObject);
		auto addr = Offsets::ActorEquipManager::UnequipObject;
		auto func = reinterpret_cast<func_t&>(addr);
		return (this->*func)(a_actor, a_object, a_extraData, a_count, a_slot, a_queueEquip, a_forceEquip, a_playSounds, a_applyNow, a_slotToReplace);
	}
}