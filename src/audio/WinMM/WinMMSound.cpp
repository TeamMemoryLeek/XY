#include "WinMMSound.h"

#include <assert.h>

void WinMMSound::play()
{
	MCI_PLAY_PARMS playParms = {};

	assert(mciSendCommandA(
		_mciDeviceId,
		MCI_PLAY,
		MCI_NOTIFY,
		(DWORD_PTR)&playParms) == 0);
}

void WinMMSound::stop()
{
	MCI_GENERIC_PARMS stopParms = {};

	assert(mciSendCommandA(
		_mciDeviceId,
		MCI_STOP,
		MCI_NOTIFY,
		(DWORD_PTR)&stopParms) == 0);
}
