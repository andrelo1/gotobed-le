#pragma once

namespace SKSE
{
	void	Init(const SKSEInterface* a_intfc);

	PluginHandle	GetPluginHandle();
	std::uint32_t	GetReleaseIndex();

	const SKSEScaleformInterface*		GetScaleformInterface();
	const SKSEPapyrusInterface*			GetPapyrusInterface();
	const SKSESerializationInterface*	GetSerializationInterface();
	const SKSETaskInterface*			GetTaskInterface();
	const SKSEMessagingInterface*		GetMessagingInterface();
}