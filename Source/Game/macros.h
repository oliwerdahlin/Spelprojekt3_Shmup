#pragma once
#define SAFE_CREATE(aPointer, aClass) aPointer = new aClass
#define SAFE_DELETE(aPointer) if (aPointer) delete aPointer; aPointer = nullptr
#define SAFE_INIT(aPointer) if (aPointer != nullptr) aPointer = nullptr
