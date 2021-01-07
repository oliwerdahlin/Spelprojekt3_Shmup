#include <chrono>
namespace CommonUtilities
{
    class Timer
    {
    public:
        Timer()
        {
            myFrameStart = std::chrono::high_resolution_clock::now();
            myBegin = std::chrono::high_resolution_clock::now();
        }
        Timer(const Timer& aTimer) = delete;
        Timer& operator=(const Timer& aTimer) = delete;
        void TUpdate();
        float TGetDeltaTime() const;
        double TGetTotalTime() const;
    private:
        float myDeltaTime = 0;
        std::chrono::time_point<std::chrono::high_resolution_clock> myFrameStart;
        std::chrono::time_point<std::chrono::high_resolution_clock> myBegin;
    };
}