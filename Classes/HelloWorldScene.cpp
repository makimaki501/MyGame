/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
//������
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

	if (closeItem == nullptr ||
		closeItem->getContentSize().width <= 0 ||
		closeItem->getContentSize().height <= 0)
	{
		problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
		float y = origin.y + closeItem->getContentSize().height / 2;
		closeItem->setPosition(Vec2(x, y));
	}

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label

	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	if (label == nullptr)
	{
		problemLoading("'fonts/Marker Felt.ttf'");
	}
	else
	{
		// position the label on the center of the screen
		label->setPosition(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().height));

		// add the label as a child to this layer
		this->addChild(label, 1);
	}

	//�����̏����� 
	//C#�Ō���Random rnd=new Random();�Ɠ���
	//srand(time(nullptr));



	//for (int i = 0; i < 10; i++)
	//{

	//	float nx, ny;
	//	nx = (float)rand()/RAND_MAX*600;
	//	ny = (float)rand()/RAND_MAX*600;


	//	sprite3[i] = Sprite::create("sample09.png");
	//	this->addChild(sprite3[i]);
	//	sprite3[i]->setPosition(Vec2(nx, ny));
	//	sprite3[i]->setTextureRect(Rect(0, 33, 32, 32));
	//	sprite3[i]->setScale(2.0f, 2.0f);

	//	float mx, my;
	//	

	//	mx = (float)rand()/RAND_MAX*600-300;
	//	my = (float)rand()/RAND_MAX*600-300;
	//	

	//	//�A�N�V����
	//	MoveBy* action1 = MoveBy::create(1.0f, Vec2(mx,my));
	//	JumpBy*action4 = JumpBy::create(1.0f, Vec2(200, 100), 300.0f, 1.0f);
	//	sprite3[i]->runAction(action1);
	//}


	//���̂ƒǉ������X�N���v�g���Ԃ����Ă��邽�߃R�����g�A�E�g
	//// add "HelloWorld" splash screen"
	//auto sprite = Sprite::create("HelloWorld.png");
	//if (sprite == nullptr)
	//{
	//    problemLoading("'HelloWorld.png'");
	//}
	//else
	//{
	//    // position the sprite on the center of the screen
	//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	//    // add the sprite as a child to this layer
	//    this->addChild(sprite, 0);
	//}

	//�e�N�X�`���t�@�C�������w�肵�āA�X�v���C�g���쐬
	Sprite* sprite = Sprite::create("image2.png");
	sprite = Sprite::create("rion.png");
	//�V�[���O���t�ɂȂ�
	this->addChild(sprite);
	sprite->setPosition(Vec2(visibleSize.width - 100, visibleSize.height - 100));
	//�摜�̃T�C�Y
	sprite->setScale(0.25f, 0.25f);

	/*
		sprite2 = Sprite::create("sample09.png");
		this->addChild(sprite2);
		sprite2->setTextureRect(Rect(0, 33, 32, 32));
		sprite2->setScale(2.0f,2.0f);*/

		//6.Action�̘A�g
		//MoveTo�̌�ɁAJumpTo��TintTo�𓯎�����������

		//JumpBy*action1 = JumpBy::create(0.5f, Vec2(100.0f, 100.0f),100,1);
		//TintTo*action2 = TintTo::create(1.5f, Color3B(0,255,255));
		//JumpTo*action3 = JumpTo::create(1.0f, Vec2(200.0f, 200.0f), 300.0f, 2);
		////�����A�N�V�����̍쐬(JumpTo��TintTo)
		//Spawn*action4 = Spawn::create(action2, action3, nullptr);
		////�A���A�N�V�����̍쐬
		//Sequence*action5 = Sequence::create(action1, action4, nullptr);
		////�J��Ԃ��A�N�V�����̍쐬
		//Repeat*action6 = Repeat::create(action5, 4);

		////�A���A�N�V�����̎��s
		////sprite->runAction(action5);
		////�J��Ԃ��A�N�V�����̎��s
		//sprite->runAction(action6);

		//6.����Ă݂悤
	MoveBy*action1_0 = MoveBy::create(2.0f, Vec2(-1075, 0));
	MoveBy*action1_1 = MoveBy::create(2.0f, Vec2(1075, 0));
	FadeIn*action1_2 = FadeIn::create(5.0f);
	FadeOut*action1_3 = FadeOut::create(5.0f);
	Spawn*action1_4 = Spawn::create(action1_0, action1_3, nullptr);
	Spawn*action1_5 = Spawn::create(action1_1, action1_2, nullptr);
	Sequence*action1_6 = Sequence::create(action1_4, action1_5, nullptr);
	Repeat*action1_7 = Repeat::create(action1_6, 5);
	MoveBy*action1_8 = MoveBy::create(2.0, Vec2(0,-525));
	MoveBy*action1_9 = MoveBy::create(2.0, Vec2(0,525));
	Sequence*action2_0 = Sequence::create(action1_0, action1_8, action1_1, action1_9, nullptr);
	RepeatForever*action2_1 = RepeatForever::create(action2_0);
	sprite->runAction(action2_1);






	//5.����Ă݂悤4
	/*MoveBy* action1 = MoveBy::create(5.0f, Vec2(-900, 0));
	FadeOut*action2 = FadeOut::create(5.0f);*/

	/*RotateBy*action1 = RotateBy::create(5.0f,360.0f);
	TintTo*action2 = TintTo::create(3.0f,Color3B(255, 255, 0));*/

	//MoveTo* action3 = MoveTo::create(1.0f, Vec2(300, 200));
	////ScaleBy*action1 = ScaleBy::create(1.0f,1.2f);
	//JumpTo*action1 = JumpTo::create(1.0f,Vec2(200,100),300.0f,1.0f);

	////�Ȑ��ړ��i�x�W�F�Ȑ��j
	//ccBezierConfig conf;
	//conf.controlPoint_1 = Vec2(500,500);
	//conf.controlPoint_2 = Vec2(500,100);
	//conf.endPosition = Vec2(200.0f,100.0f);
	//BezierTo*action1 = BezierTo::create(3.0f, conf);*/

	////EaseIn*action2 = EaseIn::create(action1,10.0f);
	////EaseBounceIn*action2 = EaseBounceIn::create(action1);
	////EaseBackInOut*action2 = EaseBackInOut::create(action1);
	////EaseSineIn*action2 = EaseSineIn::create(action1);

	//�m�[�h�ɑ΂��ăA�N�V���������s����
	//sprite->runAction(action1);
	//sprite->runAction(action2);
	//�������O�̃A�N�V���������g�������Ƃ���->clone()�����Ă�����
	//sprite2->runAction(action1->clone());


	////�摜�̍��W

	//sprite2->setPosition(Vec2(visibleSize.width / 3.0f, visibleSize.height / 3.0f));



	/*sprite2->setScale(2.0f, 2.0f);
	sprite2->getTexture()->setAliasTexParameters();*/
	//���E���]
	//sprite->setFlippedX(true);
	//�㉺���]
	//sprite->setFlippedY(true);
	//�F�����̐ݒ�
	//sprite->setColor(Color3B(0xff, 0x00, 0x00));
	//��\������
	//sprite->setVisible(false);
	//�s�����x��ݒ�
	//sprite->setOpacity(0x80);


	////���S�s����
	//sprite->setOpacity(255);

	////sprite2->setOpacity(255);

	////�摜�̍�����(0,0)
	////�摜�̉E�オ(1,0)�̍��W�n
	////��_���w�肷��
	//sprite->setAnchorPoint(Vec2(1.0f, 0.0f));


	//sprite->setRotation(45.0f);

	//                       R  G  B
	//sprite->setColor(Color3B(0, 0,255));

	//�摜�̈ꕔ��؂蔲��
	//sprite->setTextureRect(Rect(0, 33, 32,32));
	//sprite2->setTextureRect(Rect(0, 33, 32, 32));



	/*counter = 0;

	state = 0;

	state2 = 0;

	_rotate = 0.0f;

	anim_counter = 0;

	_color = 0.0f;
*/


//update��L���ɂ���
//this->scheduleUpdate();
	return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

void HelloWorld::update(float delta)
{
	//�����ɍX�V����������




	//Vec2 pos;


	////����]
	//_rotate += 1.0f;

	//sprite->setRotation(_rotate);*/


	////���F�����X�ɕς���
	///*_color++;
	//sprite -> setColor(Color3B(255 - (_color / 180.0f*255.0f), 0.0f, 0 +(_color / 180.0f*255.0f)));*/


	//anim_counter ++;

	//switch (anim_counter)
	//{
	//case 0:
	//	sprite2->setTextureRect(Rect(0, 33, 32, 32));
	//	break;
	//case 10:
	//	sprite2->setTextureRect(Rect(32, 33, 32, 32));
	//	break;
	//case 20:
	//	sprite2->setTextureRect(Rect(64, 33, 32, 32));
	//	break;
	//case 30:
	//	sprite2->setTextureRect(Rect(64, 33, 32, 32));
	//	anim_counter = 0;
	//	break;
	//default:
	//	break;
	//}

	//switch (state)
	//{

	//case 0:
	//	//���ړ�
	//	//�X�v���C�g�̌��ݍ��W���擾
	//    pos = sprite2->getPosition();
	//	//���W���ړ�������
	//	pos += Vec2(-5.0f, 0.0f);
	//	//�ړ���̍��W�𔽉f
	//	sprite2->setPosition(pos);

	//	
	//	if (pos.x<=150.0f)
	//	{
	//		state = 1;
	//	}
	//	break;
	//case 1:
	//	//�E�ړ�
	//	pos = sprite2->getPosition();
	//	pos += Vec2(5.0f, 0.0f);
	//	sprite2->setPosition(pos);
	//	sprite2->setFlippedX(true);
	//	if (pos.x >= 1100.0f)
	//	{
	//		state = 0;
	//		sprite2->setFlippedX(false);
	//	}
	//	
	//	break;
	//
	//}


	//���񂾂񓧖��ɂ��鏈��
	//5�b��300frm
	/*counter++;
	float opacity =255-(counter / 300.0f*255.0f);
	if (opacity < 0)
	{
		opacity = 0.0f;
	}
	float opacity2 = 0 + (counter / 300.0f*255.0f);
	if (opacity2 >= 255) {
		opacity2 = 255;
	}
	sprite->setOpacity(opacity);
	sprite2->setOpacity(opacity2);
*/



/*float alfa = sprite->getOpacity();
alfa -=0.00003;
sprite->setOpacity(alfa);*/






}
