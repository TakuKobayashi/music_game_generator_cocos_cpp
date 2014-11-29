//
//  Music.h
//  MusicGameGenerator
//
//  Created by 小林 拓 on 2014/11/30.
//
//

#ifndef __MusicGameGenerator__Music__
#define __MusicGameGenerator__Music__

#include "cocos2d.h"
#include "audio/include/AudioEngine.h"

class Music{
public:
    Music(std::string fileName); //コンストラクタ
    static Music* create(std::string fileName);
    void play();
    void stop();
    void pause();
    float getDuration();
    float getCurrentTime();
    void setVolume(float var);
    bool isPlaying();
private:
    std::string mFilename;
    int mMusicId = -1;
    bool mPlaying = false;
    float mVolume = 1.0;
    void finishCallBack(int audioID, std::string filePath);
};

#endif /* defined(__MusicGameGenerator__Music__) */
