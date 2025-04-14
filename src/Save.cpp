#include "Save.h"
#include <iostream>
#include <fstream>

namespace Save
{
	std::filesystem::path getSavePath()
	{
#ifdef _WIN32
		const char* appdata = std::getenv("APPDATA");
		std::filesystem::path path = std::filesystem::path(appdata) / "tetris-cpp";
#elif __linux__
		const char* home = std::getenv("HOME");
		std::filesystem::path path = std::filesystem::path(home) / ".local/share/tetris-cpp";
#elif __APPLE__
		const char* home = std::getenv("HOME");
		std::filesystem::path path = std::filesystem::path(home) / "Library/Application Support/tetris-cpp";
#endif
		std::filesystem::create_directories(path);
		return path;
	}

	void saveHighScore(int score)
	{
		std::filesystem::path file = getSavePath() / "highscore.dat";
		std::ofstream out(file, std::ios::binary);
		if (out)
			out.write(reinterpret_cast<const char*>(&score), sizeof(score));

	}

	int loadHighScore()
	{
		std::filesystem::path file = getSavePath() / "highscore.dat";
		int score = 0;
		std::ifstream in(file, std::ios::binary);
		if (in)
			in.read(reinterpret_cast<char*>(&score), sizeof(score));

		return score;
	}
}
