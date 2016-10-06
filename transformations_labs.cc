// Copyright (C) 2016 West Virginia University.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above
//       copyright notice, this list of conditions and the following
//       disclaimer in the documentation and/or other materials provided
//       with the distribution.
//
//     * Neither the name of West Virginia University nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// Please contact the author of this library if you have any questions.
// Author: Victor Fragoso (victor.fragoso@mail.wvu.edu)

#include <Eigen/Core>
#include <Eigen/Geometry>

// This lab will be completed in class. The idea is to review all the
// transformations material we covered in class and practice coding in C++.
// The goal is to implement the functions declared below during class.
// The functions are not well defined, that is, the signatures of the function
// are not final. The second goal of the class is to choose the right signatures
// for the functions that will compute the transformations.
namespace {
// This function will apply the translation transformation to a given input
// point. Modify the signature to get the proper function.
Eigen::Vector3f Translate(const Eigen::Vector3f& point,
						  const Eigen::Vector3f& offset) {
	Eigen::Matrix4f transformation;
	transformation.setIdentity();
	transformation(0, 3) = offset.x();
	transformation(1, 3) = offset.y();
	transformation(2, 3) = offset.z();
	const Eigen::Vector4f homog_point(point.x(), point.y(), point.z(), 1.0);
	const Eigen::Vector4f result = transformation * homog_point;
	const Eigen::Vector3f transformed_point(result.x(), result.y(), result.z());
	return transformed_point;
}

// This function will apply the scaling transformation to a given input point.
Eigen::Vector3f Scale(const float scale, const Eigen::Vector3f& point) {
	Eigen::Matrix4f transformation;
	transformation.setIdentity();
	transformation *= scale;
	transformation(3, 3) = 1.0f;
	// Option 2.
	// transformation(0, 0) = scale;
	// transformation(1, 1) = scale;
	// transformation(2, 2) = scale;
	const Eigen::Vector4f homog_point(point.x(), point.y(), point.z(), 1.0);
	const Eigen::Vector4f result = transformation * homog_point;
	const Eigen::Vector3f transformed_point(result.x(), result.y(), result.z());
	return transformed_point;
}

// This function will apply a rotation transformation to a given input point.
Eigen::Vector3f RotateViaEulerAngles(const Eigen::Vector3f& point,
			     					 const float yaw,
									 const float pitch,
						  			 const float roll) {
	Eigen::Matrix4f rotation_x = Eigen::Matrix4f::Identity();
	rotation_x(1, 1) = cos(roll);
	rotation_x(1, 2) = -sin(roll);
	rotation_x(2, 1) = -rotation_x(1, 2);
	rotation_x(2, 2) = rotation_x(1, 1);
	Eigen::Matrix4f rotation_y = Eigen::Matrix4f::Identity();
	rotation_y(0, 0) = cos(pitch);
	rotation_y(0, 2) = sin(pitch);
	rotation_y(2, 0) = -rotation_y(0, 2);
	rotation_y(2, 2) = rotation_y(0, 0);
	Eigen::Matrix4f rotation_z = Eigen::Matrix4f::Identity();
	rotation_z(0, 0) = cos(yaw);
	rotation_z(0, 1) = -sin(yaw);
	rotation_z(1, 0) = -rotation_z(0, 1);
	rotation_z(1, 1) = rotation_z(0, 0);
	Eigen::Matrix4f transformation = rotation_z * rotation_y * rotation_x;
	const Eigen::Vector4f homog_point(point.x(), point.y(), point.z(), 1.0);
	const Eigen::Vector4f result = transformation * homog_point;
	const Eigen::Vector3f transformed_point(result.x(), result.y(), result.z());
	return transformed_point;
}

Eigen::Vector3f RotateAngleAxis(const Eigen::Vector3f& point,
								const Eigen::Vector3f& axis,
								const float angle) {
	Eigen::AngleAxis<float> rotation(angle, axis.normalized());
	Eigen::Matrix4f transformation = Eigen::Matrix4f::Identity();
	transformation.block(0, 0, 3, 3) = rotation.matrix();
    const Eigen::Vector4f homog_point(point.x(), point.y(), point.z(), 1.0);
	const Eigen::Vector4f result = transformation * homog_point;
	const Eigen::Vector3f transformed_point(result.x(), result.y(), result.z());
	return transformed_point;
}

// This function builds a rotation matrix that rotates, scales and translates.
void RotateScaleAndTranslate();
}  // namespace

int main(int argc, char** argv) {
  // TODO(vfragoso): Implement examples testing the translation, scale, and
  // rotation transformation implementations.
  return 0;
}
