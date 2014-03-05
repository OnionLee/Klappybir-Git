#include "KCUIlayer.h"

#include "KCDirector.h"

bool KCUIlayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto _widget = dynamic_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("Data/InGameUi/InGameUi_1.ExportJson"));
	addChild(_widget);

	m_pTextLable = (gui::TextBMFont *)(_widget->getChildByName("Font"));

	this->schedule(schedule_selector(KCUIlayer::UpdateScroe));


	return true;
}



void KCUIlayer::UpdateScroe(float dt)
{
	char buf[16];
	m_pTextLable->setText(itoa(DataMgr->GetScore(), buf, 10));

	auto MainLayer = (KCGameLayer*)SceneMgr->GetScene()->getChildByTag(1);
}

void KCUIlayer::LayOutLoad()
{
	GameOverPanal = dynamic_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("Data/Panal/InGameUi_2.ExportJson"));

	auto ReplayButton = dynamic_cast<Button *>(GameOverPanal->getChildByName("Replay"));
	ReplayButton->addTouchEventListener(this, toucheventselector(KCUIlayer::ReStart));
	ReplayButton->setTouchEnabled(true);
	
	auto RankButton = dynamic_cast<Button *>(GameOverPanal->getChildByName("Rank"));
	RankButton->addTouchEventListener(this, toucheventselector(KCUIlayer::Rank));
	RankButton->setTouchEnabled(true);

	auto NewImagerView = dynamic_cast<ImageView *>(GameOverPanal->getChildByName("New"));
	NewImagerView->setZOrder(5);
	NewImagerView->setVisible(false);

	if (DataMgr->GetScore() > DataMgr->GetHighScore())
	{
		DataMgr->SetHighScore(DataMgr->GetScore());
		DataMgr->SaveHighScoreFromFile("Data/HighScore.txt");
		NewImagerView->setVisible(true);
	}

	char buf[16];
	auto ScoreBMF = dynamic_cast<TextBMFont *>(GameOverPanal->getChildByName("Score"));
	ScoreBMF->setText( itoa(DataMgr->GetScore(), buf, 10));
	
	auto BestBMF = dynamic_cast<TextBMFont *>(GameOverPanal->getChildByName("Best"));
	BestBMF->setText( itoa(DataMgr->GetHighScore(), buf, 10));

	addChild(GameOverPanal);
}

void KCUIlayer::ReStart(Object* sender, TouchEventType type)
{
	if (type == TouchEventType::TOUCH_EVENT_ENDED)
	{
		removeChild(GameOverPanal);
		auto MainLayer = (KCGameLayer*)SceneMgr->GetScene()->getChildByTag(1);
		MainLayer->ReStart();
	}
}

void KCUIlayer::Rank(Object* sender, TouchEventType type)
{
	if (type == TouchEventType::TOUCH_EVENT_ENDED)
	{

	}
}


