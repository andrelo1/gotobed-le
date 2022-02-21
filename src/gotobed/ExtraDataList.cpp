#include "ExtraDataList.h"
#include "Offsets.h"

namespace Gotobed
{
	bool ExtraDataList::PresenceBitfield::HasType(std::uint32_t a_type)
	{
		return a_type >> 3 < std::size(bits) && (bits[a_type >> 3] >> (a_type % 8) & 0x1) != 0;
	}

	bool ExtraDataList::HasType(std::uint32_t a_type)
	{
		return presence && presence->HasType(a_type);
	}

	BSExtraData* ExtraDataList::GetByType(std::uint32_t a_type)
	{
		if (!HasType(a_type)) {
			return nullptr;
		}

		for (auto& entry : *this) {
			if (entry.GetType() == a_type) {
				return &entry;
			}
		}

		return nullptr;
	}

	BSExtraData* ExtraDataList::Add(BSExtraData* a_data)
	{
		using func_t = decltype(&ExtraDataList::Add);
		auto addr = Offsets::ExtraDataList::Add;
		auto func = reinterpret_cast<func_t&>(addr);
		return (this->*func)(a_data);
	}

	void ExtraDataList::Remove(BSExtraData* a_data, bool a_delete)
	{
		using func_t = decltype(&ExtraDataList::Remove);
		auto addr = Offsets::ExtraDataList::Remove;
		auto func = reinterpret_cast<func_t&>(addr);
		return (this->*func)(a_data, a_delete);
	}

	std::int32_t ExtraDataList::GetCount()
	{
		auto count = static_cast<ExtraCount*>(GetByType(kExtraData_Count));
		return count ? count->count : 1;
	}
}