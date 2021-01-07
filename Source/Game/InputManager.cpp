#include "stdafx.h"
#include "InputManager.h"

namespace Studio
{
    namespace InputManager
    {
        namespace // private
        {
            CommonUtilities::InputManager* myInputManager;
        }

        void Construct()
        {
            myInputManager = new CommonUtilities::InputManager;
        }

        CommonUtilities::InputManager* GetInstance()
        {
            return myInputManager;
        }

        void Deconstruct()
        {
            delete myInputManager;
            myInputManager = nullptr;
        }
    }
}