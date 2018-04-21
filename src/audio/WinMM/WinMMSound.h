#pragma once
#include <string>

#include "audio/SoundItf.h"

class WinMMSound : public SoundItf
{
	friend class WinMMDevice;

public:
	void play() override;
	void stop() override;

private:
	std::string _filename;
};
