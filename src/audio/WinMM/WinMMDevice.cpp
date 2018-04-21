#include "WinMMDevice.h"

#include <assert.h>

#include "audio/WinMM/WinMMSound.h"

SoundItf* WinMMDevice::loadSound(const std::string& filename)
{
	WinMMSound* sound	= new WinMMSound;

	MCI_OPEN_PARMSA openParms	= {};
	openParms.lpstrDeviceType	= "waveaudio";
	openParms.lpstrElementName	= filename.c_str();

	assert(mciSendCommandA(
		0,
		MCI_OPEN,
		MCI_OPEN_TYPE | MCI_OPEN_ELEMENT,
		(DWORD_PTR)&openParms) == 0);

	sound->_mciDeviceId = openParms.wDeviceID;
	return sound;
}
