//
//  BallTexture.h
//  MusicGameGenerator
//
//  Created by 小林 拓 on 2014/11/30.
//
//

#ifndef __MusicGameGenerator__BallTexture__
#define __MusicGameGenerator__BallTexture__

#include "cocos2d.h"
#include "TextureBase.h"

class BallTexture : public TextureBase{
public:
    BallTexture(std::string fileName) : TextureBase(fileName){
        
    }; //コンストラクタ
    void setMusicId(int musicId);
    static BallTexture* create(std::string fileName);
private:
    int mMusicId;
protected:
    std::string mFilename;
};

#endif /* defined(__MusicGameGenerator__BallTexture__) */
