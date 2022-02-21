#include "jc/jcinit.h"
#include "gotobed/gotobedinit.h"

extern "C" DLLEXPORT bool SKSEPlugin_Query(const SKSEInterface* a_skse, PluginInfo* a_info)
{
	auto path = SKSE::log::log_directory();
	path /= Version::PROJECT;
	path += ".log";
	spdlog::set_default_logger(spdlog::basic_logger_mt("default", path.string(), true));
	spdlog::set_level(spdlog::level::trace);
	spdlog::flush_on(spdlog::level::trace);

	a_info->infoVersion = PluginInfo::kInfoVersion;
	a_info->name = Version::PROJECT;
	a_info->version = Version::MAJOR << 24 | Version::MINOR << 16 | Version::PATCH << 4;

	if (a_skse->runtimeVersion != RUNTIME_VERSION_1_9_32_0) {
		spdlog::critical("unsupported runtime version %08X", a_skse->runtimeVersion);
		return false;
	}

	return true;
}

extern "C" DLLEXPORT bool SKSEPlugin_Load(const SKSEInterface* a_skse)
{
	spdlog::info("loaded");

	SKSE::Init(a_skse);
#ifndef NOJC
	jc::init();
#endif
	Gotobed::Init();

	return true;
}