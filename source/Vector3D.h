#if !defined(_REFCLASS_) || !defined(_WRAPCLASS_) || !defined(_WRAPTYPE_)
#error _REFCLASS_, _WRAPCLASS_ and _WRAPTYPE_ must be defined for this file to process.
#endif

#include "irrMath.h"
[StructLayoutAttribute(LayoutKind::Sequential)]
public value class _REFCLASS_
{
public:

	_WRAPTYPE_ X;
	_WRAPTYPE_ Y;
	_WRAPTYPE_ Z;

	_REFCLASS_(_WRAPTYPE_ x, _WRAPTYPE_ y, _WRAPTYPE_ z)
		: X(x), Y(y), Z(z)
	{
	}

	explicit _REFCLASS_(_WRAPTYPE_ all)
		: X(all), Y(all), Z(all)
	{
	}

	// operators

	static bool equals(_REFCLASS_ v1, _REFCLASS_ v2, _WRAPTYPE_ tolerance)
	{
		return core::equals(v1.X, v2.X, tolerance) &&
			core::equals(v1.Y, v2.Y, tolerance) &&
			core::equals(v1.Z, v2.Z, tolerance);
	}

	static bool equals(_REFCLASS_ v1, _REFCLASS_ v2)
	{
		_WRAPTYPE_ tolerance = (_WRAPTYPE_)ROUNDING_ERROR_f32;
		return core::equals(v1.X, v2.X, tolerance) &&
			core::equals(v1.Y, v2.Y, tolerance) &&
			core::equals(v1.Z, v2.Z, tolerance);
	}

	static bool operator == (_REFCLASS_ v1, _REFCLASS_ v2)
	{
		return equals(v1, v2);
	}

	static bool operator != (_REFCLASS_ v1, _REFCLASS_ v2)
	{
		return !equals(v1, v2);
	}

	static bool operator > (_REFCLASS_ v1, _REFCLASS_ v2)
	{
		return (v1.X>v2.X && !core::equals(v1.X, v2.X)) ||
			(core::equals(v1.X, v2.X) && v1.Y>v2.Y && !core::equals(v1.Y, v2.Y)) ||
			(core::equals(v1.X, v2.X) && core::equals(v1.Y, v2.Y) && v1.Z>v2.Z && !core::equals(v1.Z, v2.Z));
	}

	static bool operator >= (_REFCLASS_ v1, _REFCLASS_ v2)
	{
		return (v1.X>v2.X || core::equals(v1.X, v2.X)) ||
			(core::equals(v1.X, v2.X) && (v1.Y>v2.Y || core::equals(v1.Y, v2.Y))) ||
			(core::equals(v1.X, v2.X) && core::equals(v1.Y, v2.Y) && (v1.Z>v2.Z || core::equals(v1.Z, v2.Z)));
	}

	static bool operator < (_REFCLASS_ v1, _REFCLASS_ v2)
	{
		return (v1.X<v2.X && !core::equals(v1.X, v2.X)) ||
			(core::equals(v1.X, v2.X) && v1.Y<v2.Y && !core::equals(v1.Y, v2.Y)) ||
			(core::equals(v1.X, v2.X) && core::equals(v1.Y, v2.Y) && v1.Z<v2.Z && !core::equals(v1.Z, v2.Z));
	}

	static bool operator <= (_REFCLASS_ v1, _REFCLASS_ v2)
	{
		return (v1.X<v2.X || core::equals(v1.X, v2.X)) ||
			(core::equals(v1.X, v2.X) && (v1.Y<v2.Y || core::equals(v1.Y, v2.Y))) ||
			(core::equals(v1.X, v2.X) && core::equals(v1.Y, v2.Y) && (v1.Z<v2.Z || core::equals(v1.Z, v2.Z)));
	}

	static _REFCLASS_ operator + (_REFCLASS_ v1, _REFCLASS_ v2)
	{
		return _REFCLASS_(v1.X + v2.X, v1.Y + v2.Y, v1.Z + v2.Z);
	}

	static _REFCLASS_ operator + (_REFCLASS_ v1, _WRAPTYPE_ v2)
	{
		return _REFCLASS_(v1.X + v2, v1.Y + v2, v1.Z + v2);
	}

	static _REFCLASS_ operator - (_REFCLASS_ v1)
	{
		return _REFCLASS_(-v1.X, -v1.Y, -v1.Z);
	}

	static _REFCLASS_ operator - (_REFCLASS_ v1, _REFCLASS_ v2)
	{
		return _REFCLASS_(v1.X - v2.X, v1.Y - v2.Y, v1.Z - v2.Z);
	}

	static _REFCLASS_ operator - (_REFCLASS_ v1, _WRAPTYPE_ v2)
	{
		return _REFCLASS_(v1.X - v2, v1.Y - v2, v1.Z - v2);
	}

	static _REFCLASS_ operator * (_REFCLASS_ v1, _REFCLASS_ v2)
	{
		return _REFCLASS_(v1.X * v2.X, v1.Y * v2.Y, v1.Z * v2.Z);
	}

	static _REFCLASS_ operator * (_REFCLASS_ v1, _WRAPTYPE_ v2)
	{
		return _REFCLASS_(v1.X * v2, v1.Y * v2, v1.Z * v2);
	}

	static _REFCLASS_ operator / (_REFCLASS_ v1, _REFCLASS_ v2)
	{
		return _REFCLASS_(v1.X / v2.X, v1.Y / v2.Y, v1.Z / v2.Z);
	}

	static _REFCLASS_ operator / (_REFCLASS_ v1, _WRAPTYPE_ v2)
	{
//Irrlicht has another implementation for floating point types, but I can't get it compile
//#if _WRAPTYPE_ int
		return _REFCLASS_(v1.X / v2, v1.Y / v2, v1.Z / v2);
//#else
//		_WRAPTYPE_ i = (_WRAPTYPE)1.0/v2;
//		return _REFCLASS_(v1.X * i, v1.Y * i, v1.Z * i);
//#endif
	}

	void Set(_WRAPTYPE_ nx, _WRAPTYPE_ ny, _WRAPTYPE_ nz)
	{
		X = nx;
		Y = ny;
		Z = nz;
	}

	void Set(_REFCLASS_ copy)
	{
		X = copy.X;
		Y = copy.Y;
		Z = copy.Z;
	}

	_REFCLASS_ CrossProduct(_REFCLASS_ other)
	{
		return _REFCLASS_(Y * other.Z - Z * other.Y, Z * other.X - X * other.Z, X * other.Y - Y * other.X);
	}

	bool EqualsTo(_REFCLASS_ other, _WRAPTYPE_ tolerance)
	{
		return equals(*this, other, tolerance);
	}

	array<_WRAPTYPE_>^ ToArray()
	{
		array<_WRAPTYPE_>^ a = gcnew array<_WRAPTYPE_>(4);
		a[0] = X;
		a[1] = Y;
		a[2] = Z;
		a[3] = 0;

		return a;
	}

	_REFCLASS_ Invert()
	{
		X *= -1;
		Y *= -1;
		Z *= -1;
		return *this;
	}

	void RotateXYby(double degrees, _REFCLASS_ center)
	{
		degrees *= DEGTORAD64;
		f64 cs = cos(degrees);
		f64 sn = sin(degrees);
		X -= center.X;
		Y -= center.Y;
		Set((_WRAPTYPE_)(X*cs - Y*sn), (_WRAPTYPE_)(X*sn + Y*cs), Z);
		X += center.X;
		Y += center.Y;
	}

	void RotateXYby(double degrees)
	{
		RotateXYby(degrees, _REFCLASS_());
	}

	void RotateXZby(double degrees, _REFCLASS_ center)
	{
		degrees *= DEGTORAD64;
		f64 cs = cos(degrees);
		f64 sn = sin(degrees);
		X -= center.X;
		Z -= center.Z;
		Set((_WRAPTYPE_)(X*cs - Z*sn), Y, (_WRAPTYPE_)(X*sn + Z*cs));
		X += center.X;
		Z += center.Z;
	}

	void RotateXZby(double degrees)
	{
		RotateXZby(degrees, _REFCLASS_());
	}

	void RotateYZby(double degrees, _REFCLASS_ center)
	{
		degrees *= DEGTORAD64;
		f64 cs = cos(degrees);
		f64 sn = sin(degrees);
		Z -= center.Z;
		Y -= center.Y;
		Set(X, (_WRAPTYPE_)(Y*cs - Z*sn), (_WRAPTYPE_)(Y*sn + Z*cs));
		Z += center.Z;
		Y += center.Y;
	}

	void RotateYZby(double degrees)
	{
		RotateYZby(degrees, _REFCLASS_());
	}

	_REFCLASS_ RotationToDirection(_REFCLASS_ forwards)
	{
		const f64 cr = cos( core::DEGTORAD64 * X );
		const f64 sr = sin( core::DEGTORAD64 * X );
		const f64 cp = cos( core::DEGTORAD64 * Y );
		const f64 sp = sin( core::DEGTORAD64 * Y );
		const f64 cy = cos( core::DEGTORAD64 * Z );
		const f64 sy = sin( core::DEGTORAD64 * Z );

		const f64 srsp = sr*sp;
		const f64 crsp = cr*sp;

		const f64 pseudoMatrix[] = {
			( cp*cy ), ( cp*sy ), ( -sp ),
			( srsp*cy-cr*sy ), ( srsp*sy+cr*cy ), ( sr*cp ),
			( crsp*cy+sr*sy ), ( crsp*sy-sr*cy ), ( cr*cp )};

		return _REFCLASS_(
			(_WRAPTYPE_)(forwards.X * pseudoMatrix[0] +
						 forwards.Y * pseudoMatrix[3] +
						 forwards.Z * pseudoMatrix[6]),
			(_WRAPTYPE_)(forwards.X * pseudoMatrix[1] +
						 forwards.Y * pseudoMatrix[4] +
						 forwards.Z * pseudoMatrix[7]),
			(_WRAPTYPE_)(forwards.X * pseudoMatrix[2] +
						 forwards.Y * pseudoMatrix[5] +
						 forwards.Z * pseudoMatrix[8]));
	}

	_REFCLASS_ RotationToDirection()
	{
		return RotationToDirection(_REFCLASS_(0, 0, 1));
	}

	
	_WRAPTYPE_ DotProduct(_REFCLASS_ other)
	{
		return X*other.X + Y*other.Y + Z*other.Z;
	}

	bool EqualsTo(_REFCLASS_ other)
	{
		return equals(*this, other);
	}

	_WRAPTYPE_ GetDistanceFrom(_REFCLASS_ other)
	{
		return _REFCLASS_(X - other.X, Y - other.Y, Z - other.Z).Length;
	}

	_WRAPTYPE_ GetDistanceFromSQ(_REFCLASS_ other)
	{
		return _REFCLASS_(X - other.X, Y - other.Y, Z - other.Z).LengthSQ;
	}

	_REFCLASS_ GetInterpolated(_REFCLASS_ other, double d)
	{
		const f64 inv = 1.0 - d;
		return _REFCLASS_((_WRAPTYPE_)(other.X*inv + X*d), (_WRAPTYPE_)(other.Y*inv + Y*d), (_WRAPTYPE_)(other.Z*inv + Z*d));
	}

	_REFCLASS_ GetInterpolatedQuadratic(_REFCLASS_ other1, _REFCLASS_ other2, double d)
	{
		const f64 inv = (_WRAPTYPE_) 1.0 - d;
		const f64 mul0 = inv * inv;
		const f64 mul1 = (_WRAPTYPE_) 2.0 * d * inv;
		const f64 mul2 = d * d;

		return _REFCLASS_((_WRAPTYPE_)(X * mul0 + other1.X * mul1 + other2.X * mul2),
				(_WRAPTYPE_)(Y * mul0 + other1.Y * mul1 + other2.Y * mul2),
				(_WRAPTYPE_)(Z * mul0 + other1.Z * mul1 + other2.Z * mul2));
	}

	_REFCLASS_ Interpolate(_REFCLASS_ other1, _REFCLASS_ other2, double d)
	{
		X = (_WRAPTYPE_)((f64)other2.X + ( ( other1.X - other2.X ) * d ));
		Y = (_WRAPTYPE_)((f64)other2.Y + ( ( other1.Y - other2.Y ) * d ));
		Z = (_WRAPTYPE_)((f64)other2.Z + ( ( other1.Z - other2.Z ) * d ));
		return *this;
	}

	bool IsBetweenPoints(_REFCLASS_ begin, _REFCLASS_ end)
	{
		const _WRAPTYPE_ f = (end - begin).LengthSQ;
		return GetDistanceFromSQ(begin) <= f &&
			GetDistanceFromSQ(end) <= f;
	}

	_REFCLASS_ Normalize()
	{
		f64 length = X*X + Y*Y + Z*Z;
		if (length == 0 ) // this check isn't an optimization but prevents getting NAN in the sqrt.
			return *this;
		length = core::reciprocal_squareroot(length);

		X = (_WRAPTYPE_)(X * length);
		Y = (_WRAPTYPE_)(Y * length);
		Z = (_WRAPTYPE_)(Z * length);
		return *this;
	}

	property _REFCLASS_ HorizontalAngle
	{
		_REFCLASS_ get()
		{ 
			_REFCLASS_ angle;

			// tmp avoids some precision troubles on some compilers when working with T=s32
			f64 tmp = (atan2((f64)X, (f64)Z) * RADTODEG64);
			angle.Y = (_WRAPTYPE_)tmp;

			if (angle.Y < 0)
				angle.Y += 360;
			if (angle.Y >= 360)
				angle.Y -= 360;

			const f64 z1 = core::squareroot(X*X + Z*Z);

			tmp = (atan2((f64)z1, (f64)Y) * RADTODEG64 - 90.0);
			angle.X = (_WRAPTYPE_)tmp;

			if (angle.X < 0)
				angle.X += 360;
			if (angle.X >= 360)
				angle.X -= 360;

			return angle;
		}
	}

	property _WRAPTYPE_ Length
	{
		_WRAPTYPE_ get() { return core::squareroot( X*X + Y*Y + Z*Z ); }
		void set(_WRAPTYPE_ value)
		{ 
			Normalize();
			*this *= value;
		}
	}

	property _WRAPTYPE_ LengthSQ
	{
		_WRAPTYPE_ get() { return X*X + Y*Y + Z*Z; }
	}

	property _REFCLASS_ SphericalCoordinateAngles
	{
		_REFCLASS_ get() 
		{
			_REFCLASS_ angle;
			const f64 length = X*X + Y*Y + Z*Z;

			if (length)
			{
				if (X!=0)
				{
					angle.Y = (_WRAPTYPE_)(atan2((f64)Z,(f64)X) * RADTODEG64);
				}
				else if (Z<0)
					angle.Y=180;

				angle.X = (_WRAPTYPE_)(acos(Y * core::reciprocal_squareroot(length)) * RADTODEG64);
			}
			return angle;
		}
	}
	
	/*property _WRAPTYPE_ X
	{
		_WRAPTYPE_ get() { return X; }
		void set(_WRAPTYPE_ value) { X = value; }
	}

	property _WRAPTYPE_ Y
	{
		_WRAPTYPE_ get() { return Y; }
		void set(_WRAPTYPE_ value) { Y = value; }
	}

	property _WRAPTYPE_ Z
	{
		_WRAPTYPE_ get() { return Z; }
		void set(_WRAPTYPE_ value) { Z = value; }
	}*/

	virtual String^ ToString() override
	{
		return String::Format("{0}, {1}, {2}", X, Y, Z);
	}

internal:

	_REFCLASS_(const _WRAPCLASS_& other)
	{
		X = other.X;
		Y = other.Y;
		Z = other.Z;
	}
	
	operator _WRAPCLASS_()
	{
		return _WRAPCLASS_(X, Y, Z);
	}

	_WRAPCLASS_ ToNative()
	{
		return (_WRAPCLASS_)*this;
	}
};