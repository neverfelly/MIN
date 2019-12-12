// MIT License
//
// Copyright (c) 2018-2019, neverfelly <neverfelly@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>

namespace min::ray {

using Float = float;
constexpr Float Pi = 3.1415926535f;
constexpr Float Pi2 = Pi * 0.5f;
constexpr Float Pi4 = Pi * 0.25f;
constexpr Float InvPi = 1.0f / Pi;
constexpr Float Inv4Pi = 1.0f / (4.0f * Pi);
constexpr Float MaxFloat = std::numeric_limits<Float>::max();
constexpr Float MinFloat = std::numeric_limits<Float>::lowest();
constexpr Float MachineEpsilon = std::numeric_limits<Float>::epsilon();

constexpr Float gamma(int n) {
  return n * MachineEpsilon / (1 - n * MachineEpsilon);
}

template <class T>
inline T RadiansToDegrees(T x) {
  return x * InvPi * 180.0f;
}

template <class T>
inline T DegreesToRadians(T x) {
  return x / 180.0f * Pi;
}

}  // namespace min::ray