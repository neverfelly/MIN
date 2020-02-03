#pragma once

#include <min-ray/common.h>

namespace min::ray {

template <typename _Scalar, int _Dimension>
struct TVector : public Eigen::Matrix<_Scalar, _Dimension, 1> {
 public:
  enum {
    Dimension = _Dimension
  };

  typedef _Scalar Scalar;
  typedef Eigen::Matrix<Scalar, Dimension, 1> Base;
  typedef TVector<Scalar, Dimension> VectorType;
  typedef TPoint<Scalar, Dimension> PointType;

  TVector(Scalar value = (Scalar)0) { Base::setConstant(value); }

  TVector(Scalar x, Scalar y) : Base(x, y) {}

  TVector(Scalar x, Scalar y, Scalar z) : Base(x, y, z) {}

  TVector(Scalar x, Scalar y, Scalar z, Scalar w) : Base(x, y, z, w) {}

  template <typename Derived>
  TVector(const Eigen::MatrixBase<Derived>& p)
      : Base(p) {}

  template <typename Derived>
  TVector& operator=(const Eigen::MatrixBase<Derived>& p) {
    this->Base::operator=(p);
    return *this;
  }

  std::string ToString() const {
    std::string result;
    for (size_t i = 0; i < Dimension; ++i) {
      result += std::to_string(this->coeff(i));
      if (i + 1 < Dimension)
        result += ", ";
    }
    return "[" + result + "]";
  }
};

template <typename _Scalar, int _Dimension>
struct TPoint : public Eigen::Matrix<_Scalar, _Dimension, 1> {
 public:
  enum {
    Dimension = _Dimension
  };

  typedef _Scalar Scalar;
  typedef Eigen::Matrix<Scalar, Dimension, 1> Base;
  typedef TVector<Scalar, Dimension> VectorType;
  typedef TPoint<Scalar, Dimension> PointType;

  TPoint(Scalar value = (Scalar)0) { Base::setConstant(value); }

  TPoint(Scalar x, Scalar y) : Base(x, y) {}

  TPoint(Scalar x, Scalar y, Scalar z) : Base(x, y, z) {}

  TPoint(Scalar x, Scalar y, Scalar z, Scalar w) : Base(x, y, z, w) {}

  template <typename Derived>
  TPoint(const Eigen::MatrixBase<Derived>& p)
      : Base(p) {}

  template <typename Derived>
  TPoint& operator=(const Eigen::MatrixBase<Derived>& p) {
    this->Base::operator=(p);
    return *this;
  }

  std::string ToString() const {
    std::string result;
    for (size_t i = 0; i < Dimension; ++i) {
      result += std::to_string(this->coeff(i));
      if (i + 1 < Dimension)
        result += ", ";
    }
    return "[" + result + "]";
  }
};

struct Normal3f : public Eigen::Matrix<float, 3, 1> {
 public:
  enum {
    Dimension = 3
  };

  typedef float Scalar;
  typedef Eigen::Matrix<Scalar, Dimension, 1> Base;
  typedef TVector<Scalar, Dimension> VectorType;
  typedef TPoint<Scalar, Dimension> PointType;

  Normal3f(Scalar value = 0.0f) { Base::setConstant(value); }

  Normal3f(Scalar x, Scalar y, Scalar z) : Base(x, y, z) {}

  template <typename Derived>
  Normal3f(const Eigen::MatrixBase<Derived>& p)
      : Base(p) {}

  template <typename Derived>
  Normal3f& operator=(const Eigen::MatrixBase<Derived>& p) {
    this->Base::operator=(p);
    return *this;
  }

  std::string ToString() const {
    return fmt::format("[{}, {}, {}]", coeff(0), coeff(1), coeff(2));
  }
};

extern void ComputeCoordinateSystem(const Vector3f& a, Vector3f& b, Vector3f& c);

}  // namespace min::ray
