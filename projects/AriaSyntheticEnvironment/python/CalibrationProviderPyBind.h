/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <AseCalibrationProvider.h>

#include <pybind11/eigen.h>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

namespace projectaria::dataset::ase {

inline void exportAriaSyntheticEnvironmentCalibProvider(py::module& m) {
  // For module documentation, see: projectaria_tools/projectaria_tools/projects/ase/__init__.py

  m.def("get_ase_rgb_calibration", &getAseRgbCalibration, py::arg("image_size") = 704);
}
} // namespace projectaria::dataset::ase
