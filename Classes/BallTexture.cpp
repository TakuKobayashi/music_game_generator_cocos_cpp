//
//  BallTexture.cpp
//  MusicGameGenerator
//
//  Created by 小林 拓 on 2014/11/30.
//
//

#include "BallTexture.h"

BallTexture* BallTexture::create(std::string fileName)
{
    auto texture = new BallTexture(fileName);
    texture->init();
    texture->autorelease();
    
    return texture;
}

void BallTexture::setMusicId(int musicId){
    mMusicId = musicId;
}