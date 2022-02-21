#include "TESObjectREFR.h"
#include "Offsets.h"
#include "ExtraReservedMarkers.h"
#include "ExtraUsedMarkers.h"
#include "ExtraDataList.h"

namespace Gotobed
{
	BGSLocation* TESObjectREFR::GetCurrentLocation()
	{
		using func_t = decltype(&TESObjectREFR::GetCurrentLocation);
		auto addr = Offsets::TESObjectREFR::GetCurrentLocation;
		auto func = reinterpret_cast<func_t&>(addr);
		return (this->*func)();
	}

	bool TESObjectREFR::SetMarkerReserved_Hook(std::uint32_t a_marker, Actor* a_actor, bool a_reserved)
	{
		MarkChanged(0x80000000);

		std::uint32_t actor = a_actor ? a_actor->CreateRefHandle() : 0;
		auto& extraList = reinterpret_cast<ExtraDataList&>(extraData);

		auto reservedMarkers = static_cast<ExtraReservedMarkers*>(extraList.GetByType(ExtraDataType::kExtraData_ReservedMarkers));
		
		if (!reservedMarkers) {
			reservedMarkers = static_cast<ExtraReservedMarkers*>(BSExtraData::Create(sizeof(ExtraReservedMarkers), Offsets::ExtraReservedMarkers::vtbl));
			extraList.Add(reservedMarkers);
		}

		if (a_reserved && actor) {
			auto end = std::remove_if(reservedMarkers->entries.begin(), reservedMarkers->entries.end(), [&](auto& a_entry) { return a_entry.actor == actor && a_entry.marker != a_marker; });
			reservedMarkers->entries.resize(std::distance(reservedMarkers->entries.begin(), end));
		}

		auto marker = reservedMarkers->GetMarker(a_marker);

		if (a_reserved) {
			if (!marker) {
				marker = &reservedMarkers->entries.emplace_back();
			}

			*marker = { actor, a_marker, 5.0e+9f };
		} else {
			if (marker) {
				reservedMarkers->entries.erase(marker);
			}
		}
		return true;
	}

	bool TESObjectREFR::SetMarkerUsed_Hook(std::uint32_t a_marker, Actor* a_actor, bool a_used)
	{
		MarkChanged(0x80000000);

		std::uint32_t actor = a_actor ? a_actor->CreateRefHandle() : 0;
		auto& extraList = reinterpret_cast<ExtraDataList&>(extraData);

		auto usedMarkers = static_cast<ExtraUsedMarkers*>(extraList.GetByType(ExtraDataType::kExtraData_UsedMarkers));

		if (!usedMarkers) {
			usedMarkers = static_cast<ExtraUsedMarkers*>(BSExtraData::Create(sizeof(ExtraUsedMarkers), Offsets::ExtraUsedMarkers::vtbl));
			extraList.Add(usedMarkers);
		}

		auto reservedMarkers = static_cast<ExtraReservedMarkers*>(extraList.GetByType(ExtraDataType::kExtraData_ReservedMarkers));

		if (!reservedMarkers) {
			reservedMarkers = static_cast<ExtraReservedMarkers*>(BSExtraData::Create(sizeof(ExtraReservedMarkers), Offsets::ExtraReservedMarkers::vtbl));
			extraList.Add(reservedMarkers);
		}

		if (a_used && actor) {
			auto end = std::remove_if(usedMarkers->entries.begin(), usedMarkers->entries.end(), [&](auto& a_entry) { return a_entry.actor == actor && a_entry.marker != a_marker; });
			usedMarkers->entries.resize(std::distance(usedMarkers->entries.begin(), end));
		}

		if (!a_used) {
			auto marker = reservedMarkers->GetMarker(a_marker);
			if (marker) {
				reservedMarkers->entries.erase(marker);
			}
		}

		auto marker = usedMarkers->GetMarker(a_marker);

		if (a_used) {
			if (!marker) {
				marker = &usedMarkers->entries.emplace_back();
			}

			*marker = { actor, a_marker, 0.0f };
		} else {
			if (marker) {
				usedMarkers->entries.erase(marker);
			}
		}

		return true;
	}

	void TESObjectREFRNS::Init()
	{
		auto SetMarkerReservedAddr = Offsets::TESObjectREFR::SetMarkerReserved;
		auto SetMarkerReservedHook = &TESObjectREFR::SetMarkerReserved_Hook;
		auto SetMarkerUsedAddr = Offsets::TESObjectREFR::SetMarkerUsed;
		auto SetMarkerUsedHook = &TESObjectREFR::SetMarkerUsed_Hook;

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(reinterpret_cast<PVOID*>(&SetMarkerReservedAddr), reinterpret_cast<PVOID&>(SetMarkerReservedHook));
		DetourAttach(reinterpret_cast<PVOID*>(&SetMarkerUsedAddr), reinterpret_cast<PVOID&>(SetMarkerUsedHook));

		if (DetourTransactionCommit() != NO_ERROR) {
			spdlog::error("failed to attach detour");
		}
	}
}