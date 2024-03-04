#ifndef SCORE_MANAGER_H
#define SCORE_MANAGER_H

class ScoreManager
{
public:
    static ScoreManager &getInstance();

    String getUsername();
    void setUsername(String &newUsername);
    int getScore();
    void setScore(int newScore);

private:
    ScoreManager();
    ScoreManager(const ScoreManager &) = delete; // Disallow copy constructor
    void operator=(const ScoreManager &) = delete;
    String username;
    int score;
};

#endif
