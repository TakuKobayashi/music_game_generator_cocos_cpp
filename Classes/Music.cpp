//
//  Music.cpp
//  MusicGameGenerator
//
//  Created by 小林 拓 on 2014/11/30.
//
//

#include "Music.h"

USING_NS_CC;
using namespace experimental;

Music::Music(std::string fileName) : mFilename(fileName)
{
}

Music* Music::create(std::string fileName)
{
    auto music = new Music(fileName);
    return music;
}

void Music::play(){
    mMusicId = AudioEngine::play2d(mFilename.c_str());
    mPlaying = true;
    AudioEngine::setVolume(mPlaying, mVolume);
    AudioEngine::setFinishCallback(mMusicId, CC_CALLBACK_2(Music::finishCallBack, this));
}

void Music::stop(){
    AudioEngine::stop(mMusicId);
    mPlaying = false;
}

void Music::pause(){
    AudioEngine::pause(mMusicId);
    mPlaying = false;
}

bool isPlaying(){
    return isPlaying;
}

float Music::getDuration(){
    return AudioEngine::getDuration(mMusicId);
}

float Music::getCurrentTime(){
    return AudioEngine::getCurrentTime(mMusicId);
}

void Music::setVolume(float var){
    mVolume = var;
    if (mPlaying) {
        AudioEngine::setVolume(mMusicId, var);
    }
}

void Music::finishCallBack(int musicID, std::string filePath)
{
}