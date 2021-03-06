#pragma once

#include <cstddef>

#include <Eigen/Dense>

namespace drake {
namespace systems {

template <typename T>
using VectorX = Eigen::Matrix<T, Eigen::Dynamic, 1 /* column */>;

/// VectorInterface is a pure abstract interface that real-valued signals
/// between Systems must satisfy. Classes that inherit from VectorInterface
/// will typically provide names for the elements of the vector, and may also
/// provide other computations for the convenience of Systems handling the
/// signal. The vector is always a column vector.
///
/// @tparam T Must be a Scalar compatible with Eigen.
template <typename T> class VectorInterface {
 public:
  virtual ~VectorInterface() {}

  // VectorInterface objects are neither copyable nor moveable.
  VectorInterface(const VectorInterface<T>& other) = delete;
  VectorInterface& operator=(const VectorInterface<T>& other) = delete;
  VectorInterface(VectorInterface<T>&& other) = delete;
  VectorInterface& operator=(VectorInterface<T>&& other) = delete;

  /// Returns the size of the vector, which must be equal to the number of rows
  /// in get_value().
  virtual ptrdiff_t size() const = 0;

  /// Sets the vector to the given value. After a.set_value(b.get_value()), a
  /// must be identical to b.
  /// May throw std::out_of_range if the new value has different dimensions
  /// than expected by the concrete class implementing VectorInterface.
  virtual void set_value(const VectorX<T>& value) = 0;

  /// Returns a column vector containing the entire value of the signal.
  virtual const Eigen::VectorBlock<const VectorX<T>> get_value() const = 0;

  /// Returns a reference that allows mutation of the values in this vector, but
  /// does not allow resizing the vector itself.
  virtual Eigen::VectorBlock<VectorX<T>> get_mutable_value() = 0;

 protected:
  VectorInterface() {}
};

}  // namespace systems
}  // namespace drake
