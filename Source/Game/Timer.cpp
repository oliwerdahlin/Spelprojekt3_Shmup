#include "stdafx.h"
#include "Timer.h"

namespace Studio
{
    namespace Timer
    {
        namespace // private
        {
            CommonUtilities::Timer* myTimer;
        }

        void Construct()
        {
            myTimer = new CommonUtilities::Timer;
        }

        CommonUtilities::Timer* GetInstance()
        {
            return myTimer;
        }

        void Deconstruct()
        {
            delete myTimer;
            myTimer = nullptr;
        }
    }
}