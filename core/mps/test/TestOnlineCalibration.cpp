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

#include <mps/OnlineCalibrationFormat.h>
#include <mps/OnlineCalibrationsReader.h>

#include <gtest/gtest.h>

using namespace projectaria::tools::mps;

#define STRING(x) #x
#define XSTRING(x) std::string(STRING(x))

static const std::string testDataFolder = XSTRING(TEST_FOLDER);

TEST(mps_online_calibration_valid_file, reader) {
  const auto onlineCalibrationValues =
      readOnlineCalibration(testDataFolder + "mps_sample/trajectory/online_calibration.jsonl");
  EXPECT_TRUE(onlineCalibrationValues.size() > 0);
}

TEST(mps_online_calibration_valid_file_v1_1_0, reader) {
  const auto onlineCalibrationValues = readOnlineCalibration(
      testDataFolder + "mps_sample/trajectory/online_calibration_v1_1_0.jsonl");
  EXPECT_TRUE(onlineCalibrationValues.size() > 0);

  const auto rgbOnlineCalibration = onlineCalibrationValues[0].getCameraCalib("camera-rgb");
  EXPECT_EQ(rgbOnlineCalibration->getImageSize()[0], 1408);
  EXPECT_EQ(rgbOnlineCalibration->getImageSize()[1], 1408);
  EXPECT_GT(rgbOnlineCalibration->getReadOutTimeSec(), 0);
  EXPECT_LT(rgbOnlineCalibration->getTimeOffsetSecDeviceCamera(), 0);
}

TEST(mps_online_calibration_invalid_file, reader) {
  const auto onlineCalibrationValues = readOnlineCalibration("");
  EXPECT_TRUE(onlineCalibrationValues.empty());
}
