#pragma once
class KCDataMgr
{
public:
	KCDataMgr();
	~KCDataMgr();

	int GetScore() const { return m_nScore; }
	void SetScore(int val) { m_nScore = val; }

	int GetHighScore() const { return m_nHighScore; }
	void SetHighScore(int val) { m_nHighScore = val; }

	void LoadHighScoreFromFile(const char * filename);
	void SaveHighScoreFromFile(const char * filename);
private:
	int m_nScore;

	int m_nHighScore;
	
};

