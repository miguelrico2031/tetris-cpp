#pragma once
#include <filesystem>

namespace Save
{
    std::filesystem::path getSavePath();

    void saveHighScore(int score);

    int loadHighScore();
}