#ifndef __j1AUDIO_H__
#define __j1AUDIO_H__

#include "j1Module.h"

#define DEFAULT_MUSIC_FADE_TIME 2.0f

struct _Mix_Music;
struct Mix_Chunk;

class j1Audio : public j1Module
{
public:

	j1Audio();

	// Destructor
	virtual ~j1Audio();

	// Called before render is available
	bool Awake(pugi::xml_node&);

	// Called before quitting
	bool CleanUp();

	// Play a music file
	bool PlayMusic(const char* path, float fade_time = DEFAULT_MUSIC_FADE_TIME);

	// Load a WAV in memory
	unsigned int LoadFx(const char* path);

	// Play a previously loaded WAV
	bool PlayFx(unsigned int fx, int repeat = 0);

	void RaiseVolumeMusic();
	void RaiseVolumeFx();
	void DecreaseVolumeMusic();
	void DecreaseVolumeFx();

private:

	_Mix_Music*			music;
	p2List<Mix_Chunk*>	fx;
	int music_volume = 0;
	int fx_volume = 0;
};

#endif // __j1AUDIO_H__