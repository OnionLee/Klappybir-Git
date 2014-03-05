#include "KCDataMgr.h"
#include <stdio.h>
#include <iostream>


KCDataMgr::KCDataMgr()
{
	m_nScore = 0;
	m_nHighScore = 0;
	LoadHighScoreFromFile("Data/HighScore.txt");
}


KCDataMgr::~KCDataMgr()
{
}

void KCDataMgr::LoadHighScoreFromFile(const char * filename)
{
	int Score;

	FILE * fp = fopen(filename, "r");
	{
		char buf[16];
		fscanf(fp, "%s", buf);
		fclose(fp);
		Score = atoi(buf);
	}

	SetHighScore(Score);
}

void KCDataMgr::SaveHighScoreFromFile(const char * filename)
{
	FILE * fp = fopen(filename, "w");
	{
		char buf[16];
		fprintf(fp, "%d", GetHighScore());
		fclose(fp);
	}
}
