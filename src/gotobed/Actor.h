#pragma once

namespace Gotobed
{
	struct EquipList;
	struct Outfit;

	class Actor : public ::Actor
	{
	public:
		std::int32_t	GetItemCount(TESBoundObject* a_item) const;
		bool			IsEquipped(TESBoundObject* a_item) const;
		EquipList		GetEquippedItems() const;
		void			EquipItems(const EquipList& a_list);
		void			UnequipItems(const EquipList& a_list);

		template<class Pred>
		void	EquipItemsIf(const EquipList& a_list, Pred a_pred);
		template<class Pred>
		void	UnequipItemsIf(const EquipList& a_list, Pred a_pred);

		void			EquipOutfit(const Outfit& a_outfit);
	};
}