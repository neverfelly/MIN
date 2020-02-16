#pragma once

#include "defs.h"
#include "geometry.h"

namespace min {

struct Frame {
  Vector3 s, t;
  Normal3 n;

  void ComputeCoordinateSystem(const Vector3 &a, Vector3 &b, Vector3 &c) {
    if (std::abs(a.x) > std::abs(a.y)) {
      Float inv_len = 1.0f / std::sqrt(a.x * a.x + a.z * a.z);
      c = Vector3f(-a.z * inv_len, 0.0f, a.x * inv_len);
    } else {
      Float inv_len = 1.0f / std::sqrt(a.y * a.y + a.z * a.z);
      c = Vector3f(0.0f, a.z * inv_len, -a.y * inv_len);
    }
    b = Normalize(Cross(c, a));
  }

  Frame() {}

  Frame(const Vector3f &s, const Vector3f &t, const Normal3f &n)
      : s(s), t(t), n(n) {}

  Frame(const Vector3f &n) : n(n) {
    ComputeCoordinateSystem(n, s, t);
  }

  Vector3f ToLocal(const Vector3f &v) const {
    return Vector3f(Dot(v, s), Dot(v, t), Dot(v, n));
  }

  Vector3f ToWorld(const Vector3f &v) const {
    return s * v.x + t * v.y + n * v.z;
  }

  static float CosTheta(const Vector3f &v) {
    return v.z;
  }

  static float SinTheta(const Vector3f &v) {
    float temp = SinTheta2(v);
    if (temp <= 0.0f)
      return 0.0f;
    return std::sqrt(temp);
  }

  static float TanTheta(const Vector3f &v) {
    float temp = 1 - v.z * v.z;
    if (temp <= 0.0f)
      return 0.0f;
    return std::sqrt(temp) / v.z;
  }

  static float SinTheta2(const Vector3f &v) {
    return 1.0f - v.z * v.z;
  }

  static float SinPhi(const Vector3f &v) {
    float sinTheta = Frame::SinTheta(v);
    if (sinTheta == 0.0f)
      return 1.0f;
    return Clamp(v.y / sinTheta, -1.0f, 1.0f);
  }

  static float CosPhi(const Vector3f &v) {
    float sinTheta = Frame::SinTheta(v);
    if (sinTheta == 0.0f)
      return 1.0f;
    return Clamp(v.x / sinTheta, -1.0f, 1.0f);
  }

  static float SinPhi2(const Vector3f &v) {
    return Clamp(v.y * v.y / SinTheta2(v), 0.0f, 1.0f);
  }

  static float CosPhi2(const Vector3f &v) {
    return Clamp(v.x * v.x / SinTheta2(v), 0.0f, 1.0f);
  }

  bool operator==(const Frame &frame) const {
    return frame.s == s && frame.t == t && frame.n == n;
  }

  bool operator!=(const Frame &frame) const {
    return !operator==(frame);
  }

  std::string ToString() const {
    return fmt::format(
        "Frame[\n"
        "  s = {},\n"
        "  t = {},\n"
        "  n = {}\n"
        "]",
        s.ToString(), t.ToString(), n.ToString());
  }
};

}  // namespace min::ray
