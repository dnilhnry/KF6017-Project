#include "Components.h"

void SoundComponent::setSound(const char* s)
{
	switch (entityType)
	{
	case Character:
		sound = pAM->getCharacterSound(s);
		break;
	case Background:
		sound = pAM->getBackgroundSound(s);
		break;
	case World:
		sound = pAM->getWorldSound(s);
		break;
	default:
		break;
	}
	playing = false;
	looping = false;
}

void SoundComponent::setSound(const char* s, bool l)
{
	switch (entityType)
	{
	case Character:
		sound = pAM->getCharacterSound(s);
		break;
	case Background:
		sound = pAM->getBackgroundSound(s);
		break;
	case World:
		sound = pAM->getWorldSound(s);
		break;
	default:
		break;
	}
	playing = false;
	looping = l;
}

void SoundComponent::play()
{
	if (playing == false)
	{
		if (sound != -1 && sound != NULL)
		{
			pSE->Play(sound, looping);
			playing = true;
		}
	}
}