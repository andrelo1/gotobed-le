#pragma once

namespace Gotobed
{
	class ActorEquipManager
	{
	public:
		static ActorEquipManager*	GetSingleton();

		void	EquipObject(::Actor* a_actor, TESBoundObject* a_object, BaseExtraList* a_extraData = nullptr, std::uint32_t a_count = 1, const BGSEquipSlot* a_slot = nullptr, bool a_queueEquip = true, bool a_forceEquip = false, bool a_playSounds = true, bool a_applyNow = false);
		bool	UnequipObject(::Actor* a_actor, TESBoundObject* a_object, BaseExtraList* a_extraData = nullptr, std::uint32_t a_count = 1, const BGSEquipSlot* a_slot = nullptr, bool a_queueEquip = true, bool a_forceEquip = false, bool a_playSounds = true, bool a_applyNow = false, const BGSEquipSlot* a_slotToReplace = nullptr);
	};
}