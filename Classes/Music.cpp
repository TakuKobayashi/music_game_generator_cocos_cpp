//
//  Music.cpp
//  MusicGameGenerator
//
//  Created by 小林 拓 on 2014/11/30.
//
//

#include "Music.h"

USING_NS_CC;

Music::Music(std::string fileName) : mFilename(fileName)
{
}

Music* Music::create(std::string fileName)
{
    auto music = new Music(fileName);
    music->init();
    //music->autorelease();
    
    return music;
}

bool Music::init()
{
    return true;
}