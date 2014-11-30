#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "network/HttpClient.h"

using namespace cocos2d::network;

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    mBallLayer = cocos2d::Vector<BallTexture*>();
    mMusicMap = cocos2d::Map<int, Music*>();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);
    
    auto backgroundTexture = StaticTexture::create("graphpaper.png");
    backgroundTexture->setPosition(backgroundTexture->getContentSize()/2);
    this->addChild(backgroundTexture, 0);

    auto micTexture = StaticTexture::create("mic.png");
    Size size = micTexture->getContentSize();
    Vec2 point = Vec2(size.width / 2, visibleSize.height - size.height / 2);
    micTexture->setPosition(point);
    this->addChild(micTexture, 1);
    
    int musicId = stackMusic("smua_pro_finish_vocal.mp3");
    auto tapButtonTexture = TapButtonTexture::create("normal_maru.png");
    tapButtonTexture->setTag(musicId);
    tapButtonTexture->setMusicId(musicId);
    tapButtonTexture->setPosition(Vec2(point.x + size.width / 2 + tapButtonTexture->getContentSize().width / 2, point.y));
    this->addChild(tapButtonTexture, 2);
    
    auto guitarTexture = StaticTexture::create("guitar.png");
    point.y -= guitarTexture->getContentSize().height;
    guitarTexture->setPosition(point);
    this->addChild(guitarTexture, 1);
    
    musicId = stackMusic("smua_pro_finish_guitar.mp3");
    tapButtonTexture = TapButtonTexture::create("normal_maru.png");
    tapButtonTexture->setTag(musicId);
    tapButtonTexture->setMusicId(musicId);
    tapButtonTexture->setPosition(Vec2(point.x + size.width / 2 + tapButtonTexture->getContentSize().width / 2, point.y));
    this->addChild(tapButtonTexture, 2);
    
    auto bassTexture = StaticTexture::create("bass.png");
    point.y -= bassTexture->getContentSize().height;
    bassTexture->setPosition(point);
    this->addChild(bassTexture, 1);
    
    musicId = stackMusic("smua_pro_finish_synth_bass.mp3");
    tapButtonTexture = TapButtonTexture::create("normal_maru.png");
    tapButtonTexture->setTag(musicId);
    tapButtonTexture->setMusicId(musicId);
    tapButtonTexture->setPosition(Vec2(point.x + size.width / 2 + tapButtonTexture->getContentSize().width / 2, point.y));
    this->addChild(tapButtonTexture, 2);
    
    auto drumTexture = StaticTexture::create("drum.png");
    point.y -= guitarTexture->getContentSize().height;
    drumTexture->setPosition(point);
    this->addChild(drumTexture, 1);

    musicId = stackMusic("smua_pro_finish_drums.mp3");
    tapButtonTexture = TapButtonTexture::create("normal_maru.png");
    tapButtonTexture->setTag(musicId);
    tapButtonTexture->setMusicId(musicId);
    tapButtonTexture->setPosition(Vec2(point.x + size.width / 2 + tapButtonTexture->getContentSize().width / 2, point.y));
    this->addChild(tapButtonTexture, 2);

    /*
    auto fileUtils = CCFileUtils::sharedFileUtils();
    std::string path = fileUtils->fullPathForFilename("adventurers.mp3");
    
    std::string param_key = "audiofile=@";
    param_key += path;
    CCLOG("%s", param_key.c_str());
    

    HttpRequest* request = new HttpRequest();
    request->setUrl("http://devapi.gracenote.com/v1/timeline/");
    request->setRequestData(param_key.c_str(), strlen(param_key.c_str()));
    request->setRequestType(HttpRequest::Type::POST);
    request->setResponseCallback([this](HttpClient* client, HttpResponse* response) {
        if (!response) {
            return;
        }
        CCLOG("%s", CCFileUtils::sharedFileUtils()->getWritablePath().c_str());
        
        if (0 != std::strlen(response->getHttpRequest()->getTag())) {
            CCLOG("%s completed", response->getHttpRequest()->getTag());
        }
        
        long statusCode = response->getResponseCode();
        auto statusString = StringUtils::format("HTTP Status Code: %ld, tag = %s", statusCode, response->getHttpRequest()->getTag());
        CCLOG("response code: %ld", statusCode);
        
        if (!response->isSucceed()) {
            CCLOG("response failed");
            CCLOG("error buffer: %s", response->getErrorBuffer());
            return;
        }
        
        // dropbox/json11 dump data
        std::string responseString(response->getResponseData()->begin(), response->getResponseData()->end());
        CCLOG("response = %s", responseString.c_str());
    });
    
    request->setTag("GET test1");
    HttpClient::getInstance()->send(request);
    request->release();
    */
    
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->setEnabled(true);
    listener->onTouchesBegan = CC_CALLBACK_2(HelloWorld::onTouchesBegan, this);
    listener->onTouchesMoved = CC_CALLBACK_2(HelloWorld::onTouchesMoved, this);
    listener->onTouchesEnded = CC_CALLBACK_2(HelloWorld::onTouchesEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
    
    return true;
}

void HelloWorld::onTouchesBegan(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *unused_event){
    std::vector<cocos2d::Touch*>::const_iterator iterator = touches.begin();
    while (iterator != touches.end()) {
        Touch* touch = (Touch*)(*iterator);
        auto location = touch->getLocation();
        
        std::vector<int> ids = mMusicMap.keys();
        for(int i = 0;i < ids.size();++i){
            auto button = this->getChildByTag(ids[i]);
            cocos2d::Vec2 position = button->getPosition();
            if(location.x < (position.x + size.width) &&
            (position.x + size.width) < location.x &&
            location.y < (position.y + size.height) &&
               (position.y + size.height) < location.y){
                Music music = *mMusicMap.at(ids[i]);
            }
        }
        iterator++;
    }
    return;
}

void HelloWorld::onTouchesMoved(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *unused_event){
    
}

void HelloWorld::onTouchesEnded(const std::vector<cocos2d::Touch *> &touches, cocos2d::Event *unused_event){
    std::vector<cocos2d::Touch*>::const_iterator iterator = touches.begin();
    while (iterator != touches.end()) {
        Touch* touch = (Touch*)(*iterator);
        auto location = touch->getLocation();
        
        iterator++;
    }
    return;
}

void HelloWorld::update(float dt){

}

int HelloWorld::stackMusic(std::string fileName){
    auto music = Music::create(fileName);
    music->play();
    mMusicMap.insert(music->getMusicId(), music);
    return music->getMusicId();
}

Json* getBeatJson(){
    Json* json = Json_create("[4.9010004997,5.2650003433,5.6250004768,6.0050005913,6.3890004158,6.7890005112,7.1730003357,7.5410003662,7.9050006866,8.2729997635,8.640999794,9.0170001984,9.392999649,9.7650003433,10.152999878,10.536999702,10.916999817,11.293000221,11.677000046,12.048999786,12.428999901,12.793000221,13.157000542,13.532999992,13.913000107,14.293000221,14.669000626,15.037000656,15.385000229,15.773000717,16.153001785,16.529001236,16.905000687,17.285001755,17.665000916,18.041002274,18.413002014,18.789001465,19.169000626,19.529001236,19.897001266,20.285001755,20.661001205,21.045001984,21.429000854,21.797000885,22.181001663,22.553001404,22.929000854,23.297000885,23.681001663,24.045001984,24.409002304,24.793001175,25.177001953,25.549001694,25.925001144,26.301002502,26.681001663,27.045001984,27.429002762,27.801002502,28.181001663,28.553001404,28.929002762,29.297002792,29.681001663,30.045001984,30.425001144,30.793001175,31.177001953,31.545001984,31.905002594,32.277000427,32.665000916,33.037002563,33.421001434,33.793003082,34.177001953,34.545001984,34.925003052,35.293003082,35.669002533,36.041004181,36.421001434,36.793003082,37.165000916,37.541004181,37.925003052,38.293003082,38.665000916,39.041004181,39.429000854,39.801002502,40.181003571,40.553001404,40.933002472,41.297000885,41.665000916,42.049003601,42.425003052,42.793003082,43.165000916,43.537002563,43.913002014,44.293003082,44.677001953,45.037002563,45.381004333,45.757003784,46.125003815,46.509002686,46.881004333,47.257003784,47.649002075,48.037002563,48.409004211,48.793003082,49.177001953,49.545001984,49.921001434,50.293003082,50.681003571,51.041004181,51.405002594,51.789001465,52.157001495,52.533004761,52.901004791,53.273002625,53.649002075,54.021003723,54.405002594,54.789001465,55.153003693,55.529003143,55.905002594,56.293003082,56.67300415,57.041004181,57.393001556,57.769004822,58.149002075,58.525001526,58.901004791,59.285003662,59.637004852,60.013004303,60.401004791,60.793003082,61.177001953,61.541004181,61.917003632,62.293003082,62.681003571,63.049003601,63.417003632,63.785003662,64.14100647,64.521003723,64.901000977,65.289001465,65.653007507,66.025001526,66.381004333,66.781005859,67.161003113,67.537002563,67.905006409,68.293006897,68.685005188,69.045005798,69.421005249,69.793006897,70.169006348,70.541000366,70.913002014,71.273002625,71.65700531,72.041000366,72.429000854,72.793006897,73.169006348,73.545005798,73.921005249,74.293006897,74.67300415,75.045005798,75.429000854,75.7970047,76.165000916,76.545005798,76.929000854,77.289001465,77.65700531,78.041007996,78.413002014,78.789001465,79.15700531,79.51700592,79.897003174,80.261001587,80.633003235,81.033004761,81.405006409,81.773002625,82.153007507,82.525001526,82.901000977,83.285003662,83.653007507,84.021003723,84.377006531,84.745002747,85.125007629,85.51700592,85.901000977,86.285003662,86.65700531,87.041007996,87.409004211,87.789001465,88.15700531,88.525001526,88.905006409,89.285003662,89.661003113,90.041007996,90.413002014,90.789001465,91.15700531,91.533004761,91.905006409,92.293006897,92.67300415,93.045005798,93.409004211,93.773002625,94.149002075,94.521003723,94.901008606,95.285003662,95.653007507,96.021003723,96.389007568,96.765007019,97.129005432,97.529006958,97.901008606,98.281005859,98.64100647,99.037002563,99.401008606,99.745002747,100.11700439,100.50100708,100.88900757,101.28100586,101.65700531,102.0450058,102.42500305,102.8010025,103.17300415,103.55300903,103.93700409,104.31700897,104.69300842,105.06900787,105.43700409,105.82100677,106.20100403,106.56500244,106.93300629,107.31300354,107.68100739,108.041008,108.42500305,108.80500793,109.16900635,109.53700256,109.91700745,110.3010025,110.68100739,111.0450058,111.42900848,111.80900574,112.18500519,112.55700684,112.93300629,113.30900574,113.68500519,114.06100464,114.41700745,114.78900909,115.15300751,115.52500916,115.90900421,116.2930069,116.68100739,117.0450058,117.41300964,117.7930069,118.17700958,118.541008,118.90500641,119.28900909,119.65700531,120.03700256,120.40900421,120.7930069,121.17300415,121.541008,121.92100525,122.2930069,122.68100739,123.0450058,123.41300964,123.7930069,124.18100739,124.541008,124.90500641,125.28900909,125.65700531,126.0450058,126.42500305,126.7930069,127.16100311,127.53701019,127.91700745,128.29299927,128.68099976,129.04501343,129.41300964,129.79299927,130.17700195,130.54100037,130.90501404,131.28900146,131.65701294,132.04100037,132.40901184,132.79301453,133.17700195,133.54100037,133.91700745,134.29301453,134.68099976,135.04501343,135.41300964,135.79301453,136.18099976,136.54501343,136.90501404,137.29301453,137.65701294]");
    return json;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
