#pragma once
#include <fstream>
#include "GameWorld.h"
#include <atomic>
#include <thread>


class CGame
{
public:
	//CGame();
	CGame() : myGameWorld(&myInputManager, &myTimer) {}
	~CGame();
	bool Init(const std::wstring& aVersion = L"", HWND aHWND = nullptr);
private:
	void InitCallBack();
	void UpdateCallBack();
	void GamePlayThread();
	LRESULT WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	CGameWorld myGameWorld;
	CommonUtilities::InputManager myInputManager;
	CommonUtilities::Timer myTimer;

	std::atomic<bool> myGamePlayDone;
	std::atomic<bool> myHasSwappedBuffers;

	std::atomic<bool> myIsPlaying;
	std::thread myGameLogic;
};
