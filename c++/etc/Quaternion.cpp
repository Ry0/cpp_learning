/// Quaternion.cpp
/// (C) Toru Nakata, toru-nakata@aist.go.jp
/// 2004 Dec 29

#include <math.h>
#include <iostream>
using namespace std;

/// Define Data type
typedef struct {
  double t;  // real-component
  double x;  // x-component
  double y;  // y-component
  double z;  // z-component
} quaternion;

//// Kakezan
quaternion Kakezan(quaternion left, quaternion right)
{
  quaternion ans;
  double d1, d2, d3, d4;

  d1 = left.t * right.t;
  d2 = -left.x * right.x;
  d3 = -left.y * right.y;
  d4 = -left.z * right.z;
  ans.t = d1 + d2 + d3 + d4;

  d1 = left.t * right.x;
  d2 = right.t * left.x;
  d3 = left.y * right.z;
  d4 = -left.z * right.y;
  ans.x = d1 + d2 + d3 + d4;

  d1 = left.t * right.y;
  d2 = right.t * left.y;
  d3 = left.z * right.x;
  d4 = -left.x * right.z;
  ans.y = d1 + d2 + d3 + d4;

  d1 = left.t * right.z;
  d2 = right.t * left.z;
  d3 = left.x * right.y;
  d4 = -left.y * right.x;
  ans.z = d1 + d2 + d3 + d4;

  return ans;
}

//// Make Rotational quaternion
quaternion MakeRotationalQuaternion(double radian, double AxisX, double AxisY, double AxisZ)
{
  quaternion ans;
  double norm;
  double ccc, sss;

  ans.t = ans.x = ans.y = ans.z = 0.0;

  norm = AxisX * AxisX + AxisY * AxisY + AxisZ * AxisZ;
  if (norm <= 0.0) return ans;

  norm = 1.0 / sqrt(norm);
  AxisX *= norm;
  AxisY *= norm;
  AxisZ *= norm;

  ccc = cos(0.5 * radian);
  sss = sin(0.5 * radian);

  ans.t = ccc;
  ans.x = sss * AxisX;
  ans.y = sss * AxisY;
  ans.z = sss * AxisZ;

  return ans;
}

//// Put XYZ into  quaternion
quaternion PutXYZToQuaternion(double PosX, double PosY, double PosZ)
{
  quaternion ans;

  ans.t = 0.0;
  ans.x = PosX;
  ans.y = PosY;
  ans.z = PosZ;

  return ans;
}

///// main
int main()
{
  double px, py, pz;
  double ax, ay, az, th;
  quaternion ppp, qqq, rrr;

  cout << "Point Position (x, y, z) " << endl;
  cout << "  x = ";
  cin >> px;
  cout << "  y = ";
  cin >> py;
  cout << "  z = ";
  cin >> pz;
  ppp = PutXYZToQuaternion(px, py, pz);

  while (1) {
    cout << "\nRotation Degree ? (Enter 0 to Quit) " << endl;
    cout << "  angle = ";
    cin >> th;
    if (th == 0.0) break;

    cout << "Rotation Axis Direction ? (x, y, z) " << endl;
    cout << "  x = ";
    cin >> ax;
    cout << "  y = ";
    cin >> ay;
    cout << "  z = ";
    cin >> az;

    th *= 3.1415926535897932384626433832795 / 180.0;  /// Degree -> radian;

    qqq = MakeRotationalQuaternion(th, ax, ay, az);
    rrr = MakeRotationalQuaternion(-th, ax, ay, az);

    ppp = Kakezan(rrr, ppp);
    ppp = Kakezan(ppp, qqq);

    cout << "\nAnser X = " << ppp.x << "\n      Y = " << ppp.y << "\n      Z = " << ppp.z << endl;
  }

  return 0;
}