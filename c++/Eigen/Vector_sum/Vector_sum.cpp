#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

int main() {
  using namespace Eigen;

  // あらかじめ用意されている値
  // 単位ベクトル(1, 0, 0)
  Vector3f v;
  v = Vector3f::Identity();

  // (0, 0, 0)
  v = Vector3f::Zero();

  // (1, 1, 1)
  v = Vector3f::Ones();

  // (1, 0, 0)
  v = Vector3f::UnitX();

  // (0, 1, 0)
  v = Vector3f::UnitY();

  // (0, 0, 1)
  v = Vector3f::UnitZ();

  // ランダムな値
  // FIXME:std::rand()を使っている
  v = Vector3f::Random();

  // 定数
  v = Vector3f::Constant(0.5f);


  // 各要素への読み書き
  float x, y, z;
  x = v.x();
  y = v.y();
  z = v.z();

  v.x() = x;
  v.y() = y;
  v.z() = z;

  // こういう書き方もできる
  v(0) = x;
  v(1) = y;
  v(2) = z;

  // []の場合は添え字の正当性をチェックしない
  x = v[0];
  y = v[1];
  z = v[2];

  // こういう代入も可能
  v << 0.5f, 1.2f, -2.0f;

  // コピー
  Vector3f v1;
  v1 = v;

  // 加算・減算
  Vector3f v2;
  v2 = v + v1;
  v2 = v - v1;

  // 乗算・除算(ベクトル同士の乗算、除算は無い)
  v1 = v * 2.0f;
  v1 = v / 2.0f;

  // 内積・外積
  float dot = v.dot(v1);
  Vector3f cross = v.cross(v1);

  // ベクトルの長さ
  float norm = v.norm();

  // 正規化(長さ1)したベクトルを生成
  Vector3f n = v.normalized();

  // ベクトルを正規化する
  v.normalize();
}