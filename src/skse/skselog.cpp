#include "skselog.h"
#include <shlobj.h>

namespace SKSE
{
	namespace log
	{
		std::filesystem::path log_directory()
		{
			std::filesystem::path path;
			PWSTR pathbuf = nullptr;

			if (SHGetKnownFolderPath(FOLDERID_Documents, 0, nullptr, &pathbuf) == S_OK) {
				path = pathbuf;
				path /= "My Games/Skyrim/SKSE";
			}

			CoTaskMemFree(pathbuf);

			return path;
		}
	}
}