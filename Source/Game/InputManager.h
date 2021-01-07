#pragma once
#include "CommonUtilities/InputManager.h"

namespace Studio
{
    namespace InputManager
    {
        /// <summary>
        /// Get the global instance of InputManager
        /// </summary>
        /// <returns></returns>
        CommonUtilities::InputManager* GetInstance();
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

