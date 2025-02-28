#include "sound-data.hpp"

std::vector<SoundData *> SoundData::sounds;

SoundData::SoundData(const QString &name_, const QString &path_, bool loop_)
	: name(name_), path(path_), loop(loop_)
{
	sounds.emplace_back(this);
}

SoundData::~SoundData()
{
	obs_hotkey_unregister(hotkey);
	sounds.erase(std::remove(sounds.begin(), sounds.end(), this),
		     sounds.end());
}

QString SoundData::GetName(const SoundData &sound)
{
	return sound.name;
}

QString SoundData::GetPath(const SoundData &sound)
{
	return sound.path;
}

obs_hotkey_id SoundData::GetHotkey(const SoundData &sound)
{
	return sound.hotkey;
}

void SoundData::SetName(SoundData &sound, const QString &newName)
{
	sound.name = newName;
}

void SoundData::SetPath(SoundData &sound, const QString &newPath)
{
	sound.path = newPath;
}

void SoundData::SetHotkey(SoundData &sound, const obs_hotkey_id &hotkey)
{
	sound.hotkey = hotkey;
}

SoundData *SoundData::FindSoundByName(const QString &name)
{
	for (auto &sound : sounds) {
		if (sound->name == name)
			return sound;
	}

	return nullptr;
}

void SoundData::SetLoopingEnabled(SoundData &sound, bool loop)
{
	sound.loop = loop;
}

bool SoundData::LoopingEnabled(const SoundData &sound)
{
	return sound.loop;
}

std::vector<SoundData *> SoundData::GetSounds()
{
	return sounds;
}
