#pragma once

#include "BSTArray.h"

namespace Gotobed
{
	class ExtraUsedMarkers : public BSExtraData
	{
	public:
		struct Entry
		{
			std::uint32_t	actor;	// 0
			std::uint32_t	marker;	// 4
			float			time;	// 8
		};

		static_assert(sizeof(Entry) == 0xC);

		//~ExtraUsedMarkers() override;	// 00

		//std::uint32_t	GetType() const override;	// 01

		Entry*			GetMarker(std::uint32_t a_marker);

		BSTArray<Entry>	entries;	// 8
	};

	static_assert(sizeof(ExtraUsedMarkers) == 0x14);
}