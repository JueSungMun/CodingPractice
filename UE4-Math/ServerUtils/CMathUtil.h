#pragma once
#include <Windows.h>
#include <DirectXMath.h>
#include <random>

using namespace DirectX;

static const float INVALID_ANGLE = 3.402823466e+38f;
static const float FACE_ANGLE = 90.0f;
static const float NEAR_DISTANCE = 0.1f;
static const XMFLOAT3 ZERO_VECTOR = XMFLOAT3(0, 0, 0);
static const XMFLOAT3 X_VECTOR = XMFLOAT3(1, 0, 0);
static const XMFLOAT3 Y_VECTOR = XMFLOAT3(0, 1, 0);
static const XMFLOAT3 Z_VECTOR = XMFLOAT3(0, 0, 1);

inline bool operator==(const XMFLOAT3& v1, const XMFLOAT3& v2) { return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z; }
inline bool operator!=(const XMFLOAT3& v1, const XMFLOAT3& v2) { return v1.x != v2.x || v1.y != v2.y || v1.z != v2.z; }

inline bool operator==(const XMFLOAT2& v1, const XMFLOAT2& v2) { return v1.x == v2.x && v1.y == v2.y; }
inline bool operator!=(const XMFLOAT2& v1, const XMFLOAT2& v2) { return v1.x != v2.x || v1.y != v2.y; }

inline XMFLOAT3 operator+(const XMFLOAT3& v1, const XMFLOAT3& v2) { return XMFLOAT3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z); }
inline XMFLOAT3 operator-(const XMFLOAT3& v1, const XMFLOAT3& v2) { return XMFLOAT3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z); }

inline XMFLOAT2 operator+(const XMFLOAT2& v1, const XMFLOAT2& v2) { return XMFLOAT2(v1.x + v2.x, v1.y + v2.y); }
inline XMFLOAT2 operator-(const XMFLOAT2& v1, const XMFLOAT2& v2) { return XMFLOAT2(v1.x - v2.x, v1.y - v2.y); }


inline void operator+=(XMFLOAT3& v1, const XMFLOAT3& v2) { v1.x += v2.x; v1.y += v2.y; v1.z += v2.z; }
inline void operator-=(XMFLOAT3& v1, const XMFLOAT3& v2) { v1.x -= v2.x; v1.y -= v2.y; v1.z -= v2.z; }

inline void operator+=(XMFLOAT2& v1, const XMFLOAT2& v2) { v1.x += v2.x; v1.y += v2.y; }
inline void operator-=(XMFLOAT2& v1, const XMFLOAT2& v2) { v1.x -= v2.x; v1.y -= v2.y; }

inline XMFLOAT3 operator*(const XMFLOAT3& v, float f) { return XMFLOAT3(v.x * f, v.y * f, v.z * f); }
inline XMFLOAT3 operator*(float f, const XMFLOAT3& v) { return XMFLOAT3(v.x * f, v.y * f, v.z * f); }

inline XMFLOAT2 operator*(const XMFLOAT2& v, float f) { return XMFLOAT2(v.x * f, v.y * f); }
inline XMFLOAT2 operator*(float f, const XMFLOAT2& v) { return XMFLOAT2(v.x * f, v.y * f); }

class CMathUtil
{
public:
	//Clamp : value를 min ~ max 범위안의 값으로 고정
	template <typename T>
	static T Clamp(const T& _value, const T& _min, const T& _max)
	{
		return std::max<T>(_min, std::min<T>(_value, _max));
	}

	static bool IsValid(const XMFLOAT3& v)
	{
		if (std::isnan(v.x) || std::isnan(v.y) || std::isnan(v.z) ||
			std::isinf(v.x) || std::isinf(v.y) || std::isinf(v.z))
			return false;

		return true;
	}

	static float AdjustAngle2(float x) //0 ~ 360 으로 보정
	{
		/*
			case) x가 크기가 360도 작은 경우 (ex) x = 60)
				  x / 360.0f * 360.0f  = 60 / 360 * 360 = 0.16666 * 360 = 60
				  x = 60 - 60  = 0	<-- 기존 코드 결과값이 0가 됨, 몫만 계산하기 위해 int로 캐스팅
				  x = 60 - (60/360) * 360 = 60 - 0 = 60;	<-- int 캐스팅시

			case) x가 360인 경우
				  x = 360 - 360 = 0.0f;

			case) x가 -180인 경우
				  x = -180 - 0 = -180;
					= -180 + 360 = 180;

			case) x가 540인 경우
				  x = 540 - 360 = 180
		*/
		// x = x - (x / 360.0f) * 360.0f;

		x = x - (static_cast<int>(x / 360.0f)) * 360.0f;;
		if (x < 0.0f)
			x += 360.0f;

		return x;
	}


	static float AdjustAngle(float angle) //0 ~ 360 으로 보정
	{
		if (angle < 0 || angle >= 360)
		{
			while (angle > 0) angle -= 360;
			while (angle < 0) angle += 360;
		}
		return angle;
	}

	static float SQ(float f)
	{
		return f * f;
	}

	static float Length(const XMFLOAT3& v)
	{
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	}
	static float LengthSQ(const XMFLOAT3& v)
	{
		return v.x * v.x + v.y * v.y + v.z * v.z;
	}
	static float LengthSQ2D(const XMFLOAT2& v)
	{
		return v.x * v.x + v.y * v.y;
	}
	static float Length2D(const XMFLOAT3& v)
	{
		return sqrt(v.x * v.x + v.y * v.y);
	}

	static float Distance(const XMFLOAT3& v1, const XMFLOAT3& v2)
	{
		return Length(v1 - v2);
	}
	static float Distance(const POINT& v1, const POINT& v2)
	{
		XMFLOAT3 _v1(v1.x, v1.y, 0), _v2(v2.x, v2.y, 0);

		return Length(_v1 - _v2);
	}
	static float DistanceSQ(const XMFLOAT3& v1, const XMFLOAT3& v2)
	{
		return LengthSQ(v1 - v2);
	}
	static float DistanceSQ2D(const XMFLOAT2& v1, const XMFLOAT2& v2)
	{
		XMFLOAT2 v;
		v.x = v1.x - v2.x;
		v.y = v1.y - v2.y;

		return LengthSQ2D(v);
	}
	static float Distance2D(const XMFLOAT3& v1, const XMFLOAT3& v2)
	{
		return Length2D(v1 - v2);
	}

	static float Dot(const XMFLOAT3& v1, const XMFLOAT3& v2)
	{
		float val;
		XMStoreFloat(&val, XMVector3Dot(XMLoadFloat3(&v1), XMLoadFloat3(&v2)));
		return val;
	}

	static XMFLOAT3 Cross(const XMFLOAT3& v1, const XMFLOAT3& v2)
	{
		XMFLOAT3 val;
		XMStoreFloat3(&val, XMVector3Cross(XMLoadFloat3(&v1), XMLoadFloat3(&v2)));
		return val;
	}

	static XMFLOAT3 Normalize(const XMFLOAT3& v)
	{
		XMFLOAT3 val;
		XMStoreFloat3(&val, XMVector3Normalize(XMLoadFloat3(&v)));
		return val;
	}

	static XMVECTOR FindBetween_Helper(const XMFLOAT3& A, const XMFLOAT3& B)
	{
		const float NormAB = SQ(LengthSQ(A) * LengthSQ(B));
		float W = NormAB + Dot(A, B);
		XMVECTOR Result;

		if (W >= 1e-6f * NormAB)
		{
			Result = { A.y * B.z - A.z * B.y,
					A.z * B.x - A.x * B.z,
					A.x * B.y - A.y * B.x,
					W };
		}
		else
		{
			// A and B point in opposite directions
			W = 0.f;
			const float X = abs(A.x);
			const float Y = abs(A.y);
			const float Z = abs(A.z);

			// Find orthogonal basis.
			const XMFLOAT3& Basis = (X > Y && X > Z) ? Y_VECTOR : X_VECTOR * -1;

			Result = {
				A.y * Basis.z - A.z * Basis.y,
				A.z * Basis.x - A.x * Basis.z,
				A.x * Basis.y - A.y * Basis.x,
				W
			};
		}

		Result = XMVector3Normalize(Result);
		return Result;
	}

	// 추적형 미사일의 회전처리시 클라와 동기화를 위해 언리얼 함수 포팅
	// - 원본 
	//	- FMath::VInterpNormalRotationTo
	//	- https://origin-gitlab.nmfun.net/origin_all/origin-ue4/-/blob/ue5-main/Engine/Source/Runtime/Core/Private/Math/UnrealMath.cpp#L2527
	static XMFLOAT3 VInterpNormalRotationTo(const XMFLOAT3& Current, const XMFLOAT3& Target, float DeltaTime, float RotationSpeedDegrees)
	{
		// Find delta rotation between both normals.
		// Decompose into an axis and angle for rotation
		float DeltaAngle = AngleBetweenVectors(Current, Target);
		XMVECTOR DeltaAxis = FindBetween_Helper(Current, Target);

		// Find rotation step for this frame
		const float RotateionStepRadians = RotationSpeedDegrees * (XM_PI / 180) * DeltaTime;

		if (abs(DeltaAngle) > RotateionStepRadians)
		{
			XMFLOAT3 Result;
			DeltaAngle = Clamp<float>(DeltaAngle, -RotateionStepRadians, RotateionStepRadians);
			XMVECTOR DeltaQuat = XMQuaternionRotationAxis(DeltaAxis, DeltaAngle);
			XMStoreFloat3(&Result, XMVector3Rotate(XMLoadFloat3(&Current), DeltaQuat));
			return Result;
		}

		return Target;
	}

	// 추적형 미사일의 회전처리시 클라와 동기화를 위해 언리얼 함수 포팅
	// - 원본 
	//	- FMath::VInterpNormalRotationTo
	//	- https://origin-gitlab.nmfun.net/origin_all/origin-ue4/-/blob/ue5-main/Engine/Source/Runtime/Core/Private/Math/UnrealMath.cpp#L2527
	static XMFLOAT3 VInterpNormalRotationTo2(const XMFLOAT3& Current, const XMFLOAT3& Target, float DeltaTime, float RotationSpeedDegrees)
	{
		// Find delta rotation between both normals.
		// Decompose into an axis and angle for rotation
		XMVECTOR DeltaAxis;
		float DeltaAngle;
		XMVECTOR DeltaQuat = XMVector3AngleBetweenVectors(XMLoadFloat3(&Current), XMLoadFloat3(&Target));
		XMQuaternionToAxisAngle(&DeltaAxis, &DeltaAngle, DeltaQuat);

		// Find rotation step for this frame
		const float RotateionStepRadians = RotationSpeedDegrees * (XM_PI / 180) * DeltaTime;

		if (abs(DeltaAngle) > RotateionStepRadians)
		{
			XMFLOAT3 Result;
			DeltaAngle = Clamp<float>(DeltaAngle, -RotateionStepRadians, RotateionStepRadians);
			DeltaQuat = XMQuaternionRotationAxis(DeltaAxis, DeltaAngle);
			XMStoreFloat3(&Result, XMVector3Rotate(XMLoadFloat3(&Current), DeltaQuat));
			return Result;
		}

		return Target;
	}

	static XMFLOAT3 VInterpNormalRotationTo3(const XMFLOAT3& Current, const XMFLOAT3& Target, float DeltaTime, float RotationSpeedDegrees)
	{
		// Find delta rotation between both normals.
		// Decompose into an axis and angle for rotation
		XMFLOAT3 DeltaAxis;
		float DeltaAngle;
		XMVECTOR DeltaQuat = XMVector3AngleBetweenVectors(XMLoadFloat3(&Current), XMLoadFloat3(&Target));
		XMStoreFloat(&DeltaAngle, DeltaQuat);
		XMStoreFloat3(&DeltaAxis, XMVector3Normalize(DeltaQuat));

		// Find rotation step for this frame
		const float RotateionStepRadians = RotationSpeedDegrees * (XM_PI / 180) * DeltaTime;

		if (abs(DeltaAngle) > RotateionStepRadians)
		{
			XMFLOAT3 Result;
			DeltaAngle = Clamp<float>(DeltaAngle, -RotateionStepRadians, RotateionStepRadians);
			DeltaQuat = XMQuaternionRotationAxis(XMLoadFloat3(&DeltaAxis), DeltaAngle);
			XMStoreFloat3(&Result, XMVector3Rotate(XMLoadFloat3(&Current), DeltaQuat));
			return Result;
		}

		return Target;
	}

	static float AngleBetweenVectors(const XMFLOAT3& v1, const XMFLOAT3& v2)
	{
		float val;
		XMStoreFloat(&val, XMVector3AngleBetweenVectors(XMLoadFloat3(&v1), XMLoadFloat3(&v2)));
		float _res = XMConvertToDegrees(val);
		return _res;
	}

	static XMFLOAT3 RotateZ(const XMFLOAT3& v, float angle)
	{
		XMFLOAT3 val;
		XMVECTOR quaternion = XMQuaternionRotationAxis(XMLoadFloat3(&Z_VECTOR), XMConvertToRadians(angle));
		XMStoreFloat3(&val, XMVector3Rotate(XMLoadFloat3(&v), quaternion));
		return val;
	}

	static XMFLOAT3 RotateX(const XMFLOAT3& v, float angle)
	{
		XMFLOAT3 val;
		XMVECTOR quaternion = XMQuaternionRotationAxis(XMLoadFloat3(&X_VECTOR), XMConvertToRadians(angle));
		XMStoreFloat3(&val, XMVector3Rotate(XMLoadFloat3(&v), quaternion));
		return val;
	}

	static XMFLOAT3 RotateY(const XMFLOAT3& v, float angle)
	{
		XMFLOAT3 val;
		XMVECTOR quaternion = XMQuaternionRotationAxis(XMLoadFloat3(&Y_VECTOR), XMConvertToRadians(angle));
		XMStoreFloat3(&val, XMVector3Rotate(XMLoadFloat3(&v), quaternion));
		return val;
	}
}