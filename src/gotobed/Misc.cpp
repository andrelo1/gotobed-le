#include "Misc.h"
#include "Offsets.h"

namespace Gotobed::Misc
{
	void Init()
	{
		// don't show sleep menu
		SafeWrite16(Offsets::TESFurniture::Activate + 0x0131, 0x14EB);
		// don't show "serve time" message
		SafeWrite8(Offsets::TESFurniture::Activate + 0x00E4, 0xEB);
		// get up using movement keys
		SafeWrite8(Offsets::PlayerCharacter::Update + 0x01D9, 0x02);
		// don't allow sleeping in reserved bed
		SafeWrite8(Offsets::PlayerCharacter::CanSleepWaitHere + 0x018F, 0x00);
		// don't stop animations when sleeping
		SafeWrite8(Offsets::AIProcess::SitSleepStateUpdate + 0x01AB, 0xEB);
		SafeWrite8(Offsets::AIProcess::sub_702120 + 0x00D1, 0xEB);
		SafeWrite8(Offsets::Actor::FinishLoadGame + 0x017B, 0xEB);
	}
}