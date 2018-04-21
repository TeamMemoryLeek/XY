#include "WinMMDevice.h"

#include <assert.h>

#include "audio/WinMM/WinMMSound.h"

SoundItf* WinMMDevice::loadSound(const std::string& filename)
{
	WinMMSound* sound	= new WinMMSound;
	sound->_filename	= filename;

	return sound;
}
