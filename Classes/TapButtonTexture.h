//
//  TapButtonTexture.h
//  MusicGameGenerator
//
//  Created by 小林 拓 on 2014/11/30.
//
//

#ifndef __MusicGameGenerator__TapButtonTexture__
#define __MusicGameGenerator__TapButtonTexture__

#include "cocos2d.h"
#include "TextureBase.h"

class TapButtonTexture : public TextureBase{
public:
    TapButtonTexture(std::string fileName) : TextureBase(fileName){
        
    }; //コンストラクタ
    void setMusicId(int musicId);
    bool isTaped(cocos2d::Vec2 tapPosion);
    bool isTarget(int musicId);
    static TapButtonTexture* create(std::string fileName);
private:
    int mMusicId;
protected:
    std::string mFilename;
};

#endif /* defined(__MusicGameGenerator__TapButtonTexture__) */
