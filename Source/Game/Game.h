#pragma once
#include <fstream>
#include "GameWorld.h"
#include <atomic>
#include <thread>

class CGame
{
public:
	CGame();
	~CGame();
	bool Init(const std::wstring& aVersion = L"", HWND aHWND = nullptr);
private:
	void InitCallBack();
	void UpdateCallBack();
	void GamePlayThread();
	LRESULT WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	CGameWorld myGameWorld;
	std::atomic<bool> myGamePlayDone;
	std::atomic<bool> myHasSwappedBuffers;

	std::atomic<bool> myIsPlaying;
	std::thread myGameLogic;
};
