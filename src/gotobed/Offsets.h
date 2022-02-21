#pragma once

namespace Gotobed::Offsets
{
	namespace
	{
		constexpr std::uintptr_t ShowMessageBox{ 0x0087AC60 };
		constexpr std::uintptr_t ShowSleepWaitMenu{ 0x00887B20 };
		constexpr std::uintptr_t unk_1B3FCA8{ 0x01B3FCA8 };
	}

	namespace Actor
	{
		constexpr std::uintptr_t FinishLoadGame{ 0x006D81C0 };
	}

	namespace ActorEquipManager
	{
		constexpr std::uintptr_t EquipObject{ 0x006EF3E0 };
		constexpr std::uintptr_t Singleton{ 0x012E5FAC };
		constexpr std::uintptr_t UnequipObject{ 0x006EE560 };
	}

	namespace AIProcess
	{
		constexpr std::uintptr_t SitSleepStateUpdate{ 0x0072A680 };
		constexpr std::uintptr_t sub_702120{ 0x00702120 };
	}

	namespace ExtraDataList
	{
		constexpr std::uintptr_t Add{ 0x0040A790 };
		constexpr std::uintptr_t Remove{ 0x0040BB00 };
	}

	namespace ExtraReservedMarkers
	{
		constexpr std::uintptr_t vtbl{ 0x010898D8 };
	}

	namespace ExtraUsedMarkers
	{
		constexpr std::uintptr_t vtbl{ 0x010898C8 };
	}

	namespace MenuOpenHandler
	{
		constexpr std::uintptr_t ProcessButton{ 0x00879250 };
	}

	namespace PlayerCharacter
	{
		constexpr std::uintptr_t CanSleepWaitHere{ 0x00739A90 };
		constexpr std::uintptr_t Update{ 0x0074EF80 };
	}

	namespace TESFurniture
	{
		constexpr std::uintptr_t Activate{ 0x0049A220 };
	}

	namespace TESObjectREFR
	{
		constexpr std::uintptr_t GetCurrentLocation{ 0x004D83C0 };
		constexpr std::uintptr_t SetMarkerReserved{ 0x004EB270 };
		constexpr std::uintptr_t SetMarkerUsed{ 0x004EB1B0 };
	}
}