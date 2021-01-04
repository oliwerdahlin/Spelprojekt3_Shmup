#pragma once
#include "Line.hpp"
#include <vector>
namespace CommonUtilities
{
	template<class T>
	class LineVolume
	{
	public:
		LineVolume();
		LineVolume(const std::vector<Line<T>>& aLineList);
		void AddLine(const Line<T>& aLine);
		const bool IsInside(const Vector2<T>& aPosition) const;
		std::vector<Line<T>> myLines;
	};
	template<class T>
	inline LineVolume<T>::LineVolume()
	{
		myLines.clear();
	}
	template<class T>
	inline LineVolume<T>::LineVolume(const std::vector<Line<T>>& aLineList)
	{
		for (int i = 0; i < static_cast<int>(aLineList.size()); i++)
		{
			myLines.push_back(aLineList[i]);
		}
	}
	template<class T>
	inline void LineVolume<T>::AddLine(const Line<T>& aLine)
	{
		myLines.push_back(aLine);
	}
	template<class T>
	const inline bool LineVolume<T>::IsInside(const Vector2<T>& aPosition) const
	{
		for (Line<T> line : myLines)
		{
			if (!line.IsInside(aPosition))
			{
				return false;
			}
		}
		return true;
	}
	template<class T> bool operator==(LineVolume<T>& aLineVolume0, const LineVolume<T>& aLineVolume1)
	{
		assert(aLineVolume0.myLines.size() == aLineVolume1.myLines.size());
		for (int i = 0; i < static_cast<int>(aLineVolume0.myLines.size()); i++)
		{
			if (aLineVolume0.myLines[i] == aLineVolume1.myLines[i])
			{
				return true;
			}
		}

		return false;
	}

	using LineVolumei = LineVolume<int>;
	using LineVolumeui = LineVolume<unsigned int>;
	using LineVolumef = LineVolume<float>;
	using LineVolumed = LineVolume<double>;
}