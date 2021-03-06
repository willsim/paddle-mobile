/* Copyright (c) 2018 PaddlePaddle Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. */

#pragma once

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace paddle_mobile {
enum class Precision : int { FP32 = 0, FP16 = 1 };

typedef int16_t half;

template <Precision p>
struct PrecisionTrait {
  typedef void ptype;
};

template <>
struct PrecisionTrait<Precision::FP32> {
  typedef float ptype;
};
template <>
struct PrecisionTrait<Precision::FP16> {
  typedef half ptype;
};

//! device type
enum DeviceTypeEnum {
  kINVALID = -1,
  kCPU = 0,
  kFPGA = 1,
  kGPU_MALI = 2,
  kGPU_CL = 3
};

template <DeviceTypeEnum T>
struct DeviceType {};

typedef DeviceType<kCPU> CPU;
typedef DeviceType<kFPGA> FPGA;
typedef DeviceType<kGPU_MALI> GPU_MALI;
typedef DeviceType<kGPU_CL> GPU_CL;

//! data type
enum DataType {
  PM_INVALID = -1,
  PM_HALF = 0,
  PM_FLOAT = 1,
  PM_DOUBLE = 2,
  PM_INT8 = 3,
  PM_INT16 = 4,
  PM_INT32 = 5,
  PM_INT64 = 6,
  PM_UINT8 = 7,
  PM_UINT16 = 8,
  PM_UINT32 = 9,
  PM_STRING = 10,
  PM_BOOL = 11,
  PM_SHAPE = 12,
  PM_TENSOR = 13
};
//!
enum PMStatus {
  PMSuccess = 0xFF,        /*!< No errors */
  PMNotInitialized = 0x01, /*!< Data not initialized. */
  PMInvalidValue = 0x02,   /*!< Incorrect variable value. */
  PMMemAllocFailed = 0x03, /*!< Memory allocation error. */
  PMUnKownError = 0x04,    /*!< Unknown error. */
  PMOutOfAuthority = 0x05, /*!< Try to modified data not your own*/
  PMOutOfMem = 0x06,       /*!< OOM error*/
  PMUnImplError = 0x07,    /*!< Unimplement error. */
  PMWrongDevice = 0x08     /*!< un-correct device. */
};

enum RoundType {
  ROUND_UNK = 0,
  ROUND_NEAREST_AWAY_ZERO = 1,
  ROUND_NEAREST_TOWARDS_ZERO = 2,
  ROUND_NEAREST_TO_EVEN = 3
};

extern const char *G_OP_TYPE_CONV;
extern const char *G_OP_TYPE_BATCHNORM;
extern const char *G_OP_TYPE_BOX_CODER;
extern const char *G_OP_TYPE_CONCAT;
extern const char *G_OP_TYPE_ELEMENTWISE_ADD;
extern const char *G_OP_TYPE_FUSION_CONV_ADD_RELU;
extern const char *G_OP_TYPE_FUSION_CONV_ADD_PRELU;
extern const char *G_OP_TYPE_FUSION_CONV_ADD_ADD_PRELU;
extern const char *G_OP_TYPE_FC;
extern const char *G_OP_TYPE_FUSION_CONV_ADD;
extern const char *G_OP_TYPE_FUSION_CONV_ADD_BN_RELU;
extern const char *G_OP_TYPE_FUSION_CONV_BN_ADD_RELU;
extern const char *G_OP_TYPE_FUSION_DWCONV_BN_RELU;
extern const char *G_OP_TYPE_FUSION_CONV_BN_RELU;

extern const char *G_OP_TYPE_LRN;
extern const char *G_OP_TYPE_MUL;
extern const char *G_OP_TYPE_MULTICLASS_NMS;
extern const char *G_OP_TYPE_POOL2D;
extern const char *G_OP_TYPE_PRIOR_BOX;
extern const char *G_OP_TYPE_RELU;
extern const char *G_OP_TYPE_RESHAPE;
extern const char *G_OP_TYPE_SIGMOID;
extern const char *G_OP_TYPE_SOFTMAX;
extern const char *G_OP_TYPE_TRANSPOSE;
extern const char *G_OP_TYPE_SPLIT;
extern const char *G_OP_TYPE_FEED;
extern const char *G_OP_TYPE_FETCH;
extern const char *G_OP_TYPE_DEPTHWISE_CONV;
extern const char *G_OP_TYPE_IM2SEQUENCE;
extern const char *G_OP_TYPE_DROPOUT;

extern const char *G_OP_TYPE_FUSION_CONV_ADD_BN;
extern const char *G_OP_TYPE_FUSION_POOL_BN;
extern const char *G_OP_TYPE_FUSION_ELEMENTWISE_ADD_RELU;
extern const char *G_OP_TYPE_FUSION_FC_RELU;
extern const char *G_OP_TYPE_REGION;
extern const char *G_OP_TYPE_FUSION_CONV_BN;
extern const char *G_OP_TYPE_CONV_TRANSPOSE;
extern const char *G_OP_TYPE_PRELU;
extern const char *G_OP_TYPE_SUM;
extern const char *G_OP_TYPE_ELEMENTWISE_MUL;

extern const char *G_OP_TYPE_QUANTIZE;
extern const char *G_OP_TYPE_DEQUANTIZE;

extern const char *G_OP_TYPE_TANH;
extern const char *G_OP_TYPE_FUSION_DECONV_RELU;

extern const char *G_OP_TYPE_FUSION_DECONV_ADD;
extern const char *G_OP_TYPE_FUSION_DECONV_ADD_RELU;

extern std::unordered_map<
    std::string, std::pair<std::vector<std::string>, std::vector<std::string>>>
    op_input_output_key;

}  // namespace paddle_mobile
