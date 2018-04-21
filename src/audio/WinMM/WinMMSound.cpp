#include "WinMMSound.h"

#include <Windows.h>

void WinMMSound::play()
{
	PlaySoundA(_filename.c_str(), nullptr, SND_FILENAME | SND_ASYNC);
}

void WinMMSound::stop()
{
	PlaySoundA(nullptr, nullptr, 0);
}
