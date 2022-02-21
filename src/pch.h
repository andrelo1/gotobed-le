#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <source_location>
#include <filesystem>

using namespace std::literals;

#define NOMINMAX
#include "common/IPrefix.h"
#include "skse/skse_version.h"
#include "skse/PluginAPI.h"
#include "skse/SafeWrite.h"
#include "skse/Utilities.h"
#include "skse/GameAPI.h"
#include "skse/GameTypes.h"
#include "skse/GameEvents.h"
#include "skse/GameSettings.h"
#include "skse/GameStreams.h"
#include "skse/GameResources.h"
#include "skse/GameFormComponents.h"
#include "skse/GamePathing.h"
#include "skse/GameForms.h"
#include "skse/GameObjects.h"
#include "skse/GameReferences.h"
#include "skse/GameData.h"
#include "skse/GameBSExtraData.h"
#include "skse/GameExtraData.h"
#include "skse/GameInput.h"
#include "skse/GameCamera.h"
#include "skse/GameMenus.h"
#include "skse/PapyrusVM.h"
#include "skse/PapyrusArgs.h"
#include "skse/PapyrusNativeFunctions.h"

#define DLLEXPORT __declspec(dllexport)

#include "version.h"
#include "util.h"
#include "skse/skseapi.h"
#include "skse/skselog.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

#define NOMINMAX
#define NOGDI
#include <windows.h>
#include "Detours/include/detours.h"

#define JC_DOMAIN "GTB_JCDomain"
#include "jc/jc.h"