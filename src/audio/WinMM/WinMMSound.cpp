#include "WinMMSound.h"

#include <assert.h>

void WinMMSound::play()
{
	const std::string cmd = "play " + _alias;
	assert(mciSendStringA(cmd.c_str(), nullptr, 0, nullptr) == 0);
}

void WinMMSound::stop()
{
	const std::string cmd = "stop " + _alias;
	assert(mciSendStringA(cmd.c_str(), nullptr, 0, nullptr) == 0);
}
