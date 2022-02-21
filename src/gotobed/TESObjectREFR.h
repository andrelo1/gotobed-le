#pragma once

namespace Gotobed
{
	class TESObjectREFR : public ::TESObjectREFR
	{
	public:
		BGSLocation*	GetCurrentLocation();
		bool			SetMarkerReserved_Hook(std::uint32_t a_marker, Actor* a_actor, bool a_reserved);
		bool			SetMarkerUsed_Hook(std::uint32_t a_marker, Actor* a_actor, bool a_used);
	};

	namespace TESObjectREFRNS
	{
		void	Init();
	}
}