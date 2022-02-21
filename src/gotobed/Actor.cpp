#include "Actor.h"
#include "Outfit.h"
#include "ExtraContainerChanges.h"
#include "ActorEquipManager.h"

namespace Gotobed
{
	std::int32_t Actor::GetItemCount(TESBoundObject* a_item) const
	{
		if (!a_item) {
			return 0;
		}

		if (!baseForm) {
			return 0;
		}

		auto container = &static_cast<const TESNPC*>(baseForm)->container;

		std::int32_t count = 0;

		for (std::uint32_t i = 0; i < container->numEntries; i++) {
			auto entry = container->entries[i];
			if (entry && entry->form == a_item) {
				count = entry->count;
				break;
			}
		}

		auto containerChanges = static_cast<ExtraContainerChanges*>(extraData.GetByType(kExtraData_ContainerChanges));

		if (containerChanges && containerChanges->changes && containerChanges->changes->entryList) {
			for (auto& entry : *containerChanges->changes->entryList) {
				if (entry && entry->object == a_item) {
					count += entry->countDelta;
					break;
				}
			}
		}

		return count;
	}

	bool Actor::IsEquipped(TESBoundObject* a_item) const
	{
		if (!a_item) {
			return false;
		}

		auto containerChanges = static_cast<ExtraContainerChanges*>(extraData.GetByType(kExtraData_ContainerChanges));

		if (!containerChanges || !containerChanges->changes || !containerChanges->changes->entryList) {
			return false;
		}

		for (auto& entry : *containerChanges->changes->entryList) {
			if (entry && entry->object == a_item) {
				if (entry->extraLists) {
					for (auto& extraList : *entry->extraLists) {
						if (extraList && (extraList->HasType(kExtraData_Worn) || extraList->HasType(kExtraData_WornLeft))) {
							return true;
						}
					}
				}
				break;
			}
		}

		return false;
	}

	EquipList Actor::GetEquippedItems() const
	{
		EquipList list;

		auto containerChanges = static_cast<ExtraContainerChanges*>(extraData.GetByType(kExtraData_ContainerChanges));
		auto leftHandSlot = static_cast<BGSEquipSlot*>(BGSDefaultObjectManager::GetSingleton()->objects[19]);
		auto rightHandSlot = static_cast<BGSEquipSlot*>(BGSDefaultObjectManager::GetSingleton()->objects[20]);

		if (containerChanges && containerChanges->changes && containerChanges->changes->entryList) {
			for (auto& entry : *containerChanges->changes->entryList) {
				if (entry && entry->object && entry->extraLists) {
					for (auto& extraList : *entry->extraLists) {
						if (extraList && (extraList->HasType(kExtraData_Worn) || extraList->HasType(kExtraData_WornLeft))) {
							auto count = entry->object->formType == kFormType_Ammo ? static_cast<std::uint32_t>(extraList->GetCount()) : 1;
							auto slot = entry->object->formType == kFormType_Weapon ? (extraList->HasType(kExtraData_WornLeft) ? leftHandSlot : rightHandSlot) : nullptr;
							list.entries.push_back({ entry->object, count, slot });
						}
					}
				}
			}
		}

		return list;
	}

	void Actor::EquipItems(const EquipList& a_list)
	{
		for (const auto& entry : a_list.entries) {
			if (entry.item) {
				if (entry.item->formType == kFormType_Weapon) {
					if (IsEquipped(entry.item) && GetItemCount(entry.item) == 1) {
						ActorEquipManager::GetSingleton()->UnequipObject(this, entry.item);
					}
				}

				ActorEquipManager::GetSingleton()->EquipObject(this, entry.item, nullptr, entry.count, entry.slot);
			}
		}
	}

	void Actor::UnequipItems(const EquipList& a_list)
	{
		for (const auto& entry : a_list.entries) {
			if (entry.item) {
				ActorEquipManager::GetSingleton()->UnequipObject(this, entry.item, nullptr, entry.count, entry.slot);
			}
		}
	}

	template<class Pred>
	void Actor::EquipItemsIf(const EquipList& a_list, Pred a_pred)
	{
		for (const auto& entry : a_list.entries) {
			if (entry.item && a_pred(entry)) {
				if (entry.item->formType == kFormType_Weapon) {
					if (IsEquipped(entry.item) && GetItemCount(entry.item) == 1) {
						ActorEquipManager::GetSingleton()->UnequipObject(this, entry.item);
					}
				}

				ActorEquipManager::GetSingleton()->EquipObject(this, entry.item, nullptr, entry.count, entry.slot);
			}
		}
	}

	template<class Pred>
	void Actor::UnequipItemsIf(const EquipList& a_list, Pred a_pred)
	{
		for (const auto& entry : a_list.entries) {
			if (entry.item && a_pred(entry)) {
				ActorEquipManager::GetSingleton()->UnequipObject(this, entry.item, nullptr, entry.count, entry.slot);
			}
		}
	}

	void Actor::EquipOutfit(const Outfit& a_outfit)
	{		
		auto player = *g_thePlayer;

		if (static_cast<::Actor*>(this) == player) {
			if (a_outfit.mask.lhand) {
				player->unk640 = 0;
			}
			if (a_outfit.mask.rhand) {
				player->tempPoison = nullptr;
			}
		}
		
		UnequipItemsIf(GetEquippedItems(), std::not_fn(~a_outfit.mask));
		EquipItemsIf(a_outfit.items, a_outfit.mask);
	}
}