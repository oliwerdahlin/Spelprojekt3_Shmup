#pragma once
#include "Vector2.hpp"
namespace CommonUtilities
{
	template<class T>
	class Line
	{
	public:
		Line();
		Line(const Line<T>& aLine);
		Line(const Vector2<T>& aPoint, const Vector2<T>& aDirection);
		void InitWith2Points(const Vector2<T>& aPoint0, const Vector2<T>& aPoint1);

		void InitWithPointAndDirection(const Vector2<T>& aPoint, const Vector2<T>& aDirection);
		void InitWithPointAndNormal(const Vector2<T>& aPoint, const Vector2<T>& aNormal);
		bool IsInside(const Vector2<T>& aPosition) const;

		Vector2<T> GetDirection() const;

		const Vector2<T>& GetNormal() const;

		union
		{
			Vector2<T> myPosition;
			Vector2<T> myPoint;
			Vector2<T> position;
			Vector2<T> point;
		};
		union
		{
			Vector2<T> myNormal;
			Vector2<T> normal;
		};
		static const Line
			XDirection,
			YDirection,
			One;
	};

	template<class T>
	inline Line<T>::Line()
	{
		myPoint = Vector2<T>::Zero;
		myNormal = Vector2<T>::Zero;
	}

	template<class T>
	inline Line<T>::Line(const Line<T>& aLine)
	{
		myPoint = aLine.myPoint;
		myNormal = aLine.myNormal;
	}

	template<class T>
	inline Line<T>::Line(const Vector2<T>& aPoint, const Vector2<T>& aPoint1)
	{
		myPoint = aPoint;
		myNormal.x = (aPoint1.y - aPoint.y) * -1;
		myNormal.y = aPoint1.x - aPoint.x;
	}

	template<class T>
	inline void Line<T>::InitWith2Points(const Vector2<T>& aPoint, const Vector2<T>& aPoint1)
	{
		myPoint = aPoint;
		myNormal.x = (aPoint1.y - aPoint.y) * -1;
		myNormal.y = aPoint1.x - aPoint.x;
	}

	template<class T>
	inline void Line<T>::InitWithPointAndDirection(const Vector2<T>& aPoint, const Vector2<T>& aDirection)
	{
		myPoint = aPoint;
		myNormal.x = aDirection.y * -1;
		myNormal.y = aDirection.x;
	}
	template<class T>
	inline void Line<T>::InitWithPointAndNormal(const Vector2<T>& aPoint, const Vector2<T>& aNormal)
	{
		myPoint = aPoint;
		myNormal = aNormal;
	}
	template<class T>
	inline bool Line<T>::IsInside(const Vector2<T>& aPosition) const
	{
		return myNormal.Dot(aPosition - myPoint) <= 0;
	}

	template<class T>
	inline Vector2<T> Line<T>::GetDirection() const
	{
		Vector2<T> tempDirection;
		tempDirection.x = myNormal.y;
		tempDirection.y = myNormal.x * -1;
		return tempDirection;
	}

	template<class T>
	inline const Vector2<T>& Line<T>::GetNormal() const
	{
		return myNormal;
	}
	template<class T> bool operator==(Line<T>& aLine0, const Line<T>& aLine1)
	{
		if (aLine0.normal == aLine1.normal && aLine0.point == aLine1.point)
		{
			return true;
		}
		return false;
	}
	using Linei = Line<int>;
	using Lineui = Line<unsigned int>;
	using Linef = Line<float>;
	using Lined = Line<double>;
	template<typename T> const Line<T> Line<T>::XDirection(Vector2<T>::UnitX, Vector2<T>::UnitX);
	template<typename T> const Line<T> Line<T>::YDirection(Vector2<T>::UnitY, Vector2<T>::UnitY);
	template<typename T> const Line<T> Line<T>::One(Vector2<T>::One, Vector2<T>::One);
}