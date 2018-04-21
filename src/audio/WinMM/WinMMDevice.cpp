#include "WinMMDevice.h"

#include <assert.h>

#include "audio/WinMM/WinMMSound.h"

SoundItf* WinMMDevice::loadSound(const std::string& filename)
{
	WinMMSound* sound	= new WinMMSound;

	// Open
	const std::string alias		= "Alias:" + filename;
	const std::string openCmd	= "open \"" + filename + "\" alias " + alias;
	assert(mciSendStringA(openCmd.c_str(), nullptr, 0, nullptr) == 0);

	sound->_alias = alias;
	return sound;
}
