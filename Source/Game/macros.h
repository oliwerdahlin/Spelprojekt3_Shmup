#pragma once
#define SAFE_DELETE(aPointer) if (aPointer) delete aPointer; aPointer = nullptr