#pragma once
#include "CommonUtilities/Timer.h"

namespace Studio
{
    namespace Timer
    {
        /// <summary>
        /// Get the global instance of InputManager
        /// </summary>
        /// <returns></returns>
        CommonUtilities::Timer* GetInstance();
        /// <summary>
        /// Should work as MySingleton()
        /// </summary>
        void Construct();
        /// <summary>
        /// Should work as ~MySingleton();
        /// </summary>
        void Deconstruct();

    }
}

