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
#include <vector>
#include "common/log.h"
#include "common/type_define.h"
#include "common/types.h"
#include "framework/lod_tensor.h"
#include "framework/scope.h"
#include "framework/tensor.h"
#include "framework/variable.h"

#ifdef PADDLE_MOBILE_FPGA_V1
#include "fpga/V1/api.h"
#endif

#ifdef PADDLE_MOBILE_FPGA_V2
#include "fpga/V2/api.h"
#endif

#ifdef PADDLE_MOBILE_CL
#include "framework/cl/cl_image.h"
#endif

namespace paddle_mobile {
namespace operators {

using framework::Attribute;
using framework::AttributeMap;
using framework::LoDTensor;
using framework::Scope;
using framework::Tensor;
using framework::Variable;
using std::string;
using std::vector;

template <typename Dtype>
struct DtypeTensorTrait {
  // This is the type we obtained in variable.
  typedef framework::LoDTensor gtype;
  // This type will be the parent class type
  // or the same type.
  typedef framework::Tensor rtype;
};

#ifdef PADDLE_MOBILE_CL
template <>
struct DtypeTensorTrait<GPU_CL> {
  // This is the type we obtained in variable.
  typedef framework::CLImage gtype;
  // This type will be the parent class type
  // or the same type.
  typedef framework::CLImage rtype;
};
#endif

class OpParam {
 protected:
  template <typename T>
  static T *InputH0From(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("H0", inputs, scope);
  }
  template <typename T>
  static T *InputAlphaFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("Alpha", inputs, scope);
  }

  template <typename T>
  static T *InputFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("Input", inputs, scope);
  }

  template <typename T>
  static T *InputXFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("X", inputs, scope);
  }
  template <typename T>
  static T *InputOutSizeFrom(const VariableNameMap &inputs,
                             const Scope &scope) {
    return GetVarValue<T>("OutSize", inputs, scope);
  }

  template <typename T>
  static T *InputWFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("W", inputs, scope);
  }

  template <typename T>
  static T *InputIdsFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("Ids", inputs, scope);
  }

  template <typename T>
  static T *InputEmissionFrom(const VariableNameMap &inputs,
                              const Scope &scope) {
    return GetVarValue<T>("Emission", inputs, scope);
  }

  template <typename T>
  static T *InputTransitionFrom(const VariableNameMap &inputs,
                                const Scope &scope) {
    return GetVarValue<T>("Transition", inputs, scope);
  }
  template <typename T>
  static T *InputLabelFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("Label", inputs, scope);
  }

  template <typename T>
  static T *InputXFrom1(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue1<T>("addX", inputs, scope);
  }

  template <typename T>
  static T *InputYFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("Y", inputs, scope);
  }

  template <typename T>
  static T *InputYFrom1(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue1<T>("Y", inputs, scope);
  }

  template <typename T>
  static T *InputZFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("Z", inputs, scope);
  }

  template <typename T>
  static T *InputBiasFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("Bias", inputs, scope);
  }
  template <typename T>
  static T *InputWeightFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("Weight", inputs, scope);
  }
  template <typename T>
  static T *InputVarianceFrom(const VariableNameMap &inputs,
                              const Scope &scope) {
    return GetVarValue<T>("Variance", inputs, scope);
  }
  template <typename T>
  static T *InputMeanFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("Mean", inputs, scope);
  }
  template <typename T>
  static T *InputScaleFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("Scale", inputs, scope);
  }
  template <typename T>
  static T *InputImageFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("Image", inputs, scope);
  }
  template <typename T>
  static T *InputPriorBoxFrom(const VariableNameMap &inputs,
                              const Scope &scope) {
    return GetVarValue<T>("PriorBox", inputs, scope);
  }
  template <typename T>
  static T *InputPriorBoxVarFrom(const VariableNameMap &inputs,
                                 const Scope &scope) {
    return GetVarValue<T>("PriorBoxVar", inputs, scope);
  }
  // LoDTensor but now use Tensor
  template <typename T>
  static T *InputTargetBoxFrom(const VariableNameMap &inputs,
                               const Scope &scope) {
    return GetVarValue<T>("TargetBox", inputs, scope);
  }

  template <typename T>
  static T *InputBBoxesFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("BBoxes", inputs, scope);
  }

  template <typename T>
  static T *InputScoresFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("Scores", inputs, scope);
  }

  template <typename T>
  static T *InputShapeFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("Shape", inputs, scope);
  }

  template <typename T>
  static vector<T *> InputMultiFrom(const VariableNameMap &inputs,
                                    const Scope &scope) {
    return GetMultiVarValue<T>("X", inputs, scope);
  }

  static vector<Variable *> InputMultiVarsFrom(const VariableNameMap &inputs,
                                               const Scope &scope) {
    return GetMultiVar("X", inputs, scope);
  }

  template <typename T>
  static T *OutputBatchGateFrom(const VariableNameMap &outputs,
                                const Scope &scope) {
    return GetVarValue<T>("BatchGate", outputs, scope);
  }

  template <typename T>
  static T *OutputViterbiPathFrom(const VariableNameMap &outputs,
                                  const Scope &scope) {
    return GetVarValue<T>("ViterbiPath", outputs, scope);
  }
  template <typename T>
  static T *OutputBatchResetHiddenPrevFrom(const VariableNameMap &outputs,
                                           const Scope &scope) {
    return GetVarValue<T>("BatchResetHiddenPrev", outputs, scope);
  }

  template <typename T>
  static T *OutputBatchHiddenFrom(const VariableNameMap &outputs,
                                  const Scope &scope) {
    return GetVarValue<T>("BatchHidden", outputs, scope);
  }

  template <typename T>
  static T *OutputHiddenFrom(const VariableNameMap &outputs,
                             const Scope &scope) {
    return GetVarValue<T>("Hidden", outputs, scope);
  }

  template <typename T>
  static T *OutputFrom(const VariableNameMap &outputs, const Scope &scope) {
    return GetVarValue<T>("Output", outputs, scope);
  }

  static Variable *OutVarFrom(const VariableNameMap &outputs,
                              const Scope &scope) {
    return GetVar("Out", outputs, scope);
  }

  template <typename T>
  static T *OutFrom(const VariableNameMap &outputs, const Scope &scope) {
    return GetVarValue<T>("Out", outputs, scope);
  }

  template <typename T>
  static vector<T *> OutMultiFrom(const VariableNameMap &outputs,
                                  const Scope &scope) {
    return GetMultiVarValue<T>("Out", outputs, scope);
  }

  template <typename T>
  static T *OutputYFrom(const VariableNameMap &outputs, const Scope &scope) {
    return GetVarValue<T>("Y", outputs, scope);
  }

  template <typename T>
  static T *OutputXShapeFrom(const VariableNameMap &outputs,
                             const Scope &scope) {
    return GetVarValue<T>("XShape", outputs, scope);
  }

  template <typename T>
  static T *OutputBoxesFrom(const VariableNameMap &outputs,
                            const Scope &scope) {
    return GetVarValue<T>("Boxes", outputs, scope);
  }

  template <typename T>
  static T *OutputBoxFrom(const VariableNameMap &outputs, const Scope &scope) {
    return GetVarValue<T>("OutputBox", outputs, scope);
  }

  template <typename T>
  static T *OutputVariancesFrom(const VariableNameMap &outputs,
                                const Scope &scope) {
    return GetVarValue<T>("Variances", outputs, scope);
  }

  template <typename T>
  static T *MidOutFrom(const VariableNameMap &outputs, const Scope &scope) {
    return GetVarValue<T>("MidOut", outputs, scope);
  }

  template <typename T>
  static T *FilterFrom(const VariableNameMap &inputs, const Scope &scope) {
    return GetVarValue<T>("Filter", inputs, scope);
  }

  template <typename T>
  static const T GetAttr(const string &key, const AttributeMap &map) {
    return ((Attribute)map.at(key)).Get<T>();
  }
  static const std::string GetStringAttr(const string &key,
                                         const AttributeMap &map) {
    return ((Attribute)map.at(key)).GetString();
  }

  static const bool HasAttr(const string &key, const AttributeMap &map) {
    return map.count(key) > 0;
  }

  template <typename T>
  static T *GetVarValue(const string &key, const VariableNameMap &var_map,
                        const Scope &scope) {
    PADDLE_MOBILE_ENFORCE(var_map.count(key) > 0,
                          "%s is not contained in var_map", key.c_str())
    auto var_vec = var_map.at(key);
    if (!var_vec.empty()) {
      auto var = scope.FindVar(var_vec[0]);
      return var->GetMutable<T>();
    } else {
      return nullptr;
    }
  }

  static Variable *GetVar(const string &key, const VariableNameMap &var_map,
                          const Scope &scope) {
    PADDLE_MOBILE_ENFORCE(var_map.count(key) > 0,
                          "%s is not contained in var_map", key.c_str())
    auto var_vec = var_map.at(key);
    if (!var_vec.empty()) {
      auto var = scope.FindVar(var_vec[0]);
      return var;
    } else {
      return nullptr;
    }
  }

  static std::string getkey(const string &key, const VariableNameMap &var_map,
                            int index) {
    auto var_vec = var_map.at(key);
    return var_vec[index];
  }

  template <typename T>
  static T *GetVarValue1(const string &key, const VariableNameMap &var_map,
                         const Scope &scope) {
    PADDLE_MOBILE_ENFORCE(var_map.count(key) > 0,
                          "%s is not contained in var_map", key.c_str())
    auto var_vec = var_map.at(key);
    if (!var_vec.empty()) {
      auto var = scope.FindVar(var_vec[1]);
      return var->GetMutable<T>();
    } else {
      return nullptr;
    }
  }

  template <typename T>
  static vector<T *> GetMultiVarValue(const string &key,
                                      const VariableNameMap &var_map,
                                      const Scope &scope) {
    auto var_vecs = var_map.at(key);
    assert(var_vecs.size() > 1);
    vector<T *> var_res;
    for (auto &var_vec : var_vecs) {
      auto var = scope.FindVar(var_vec);
      var_res.push_back(var->GetMutable<T>());
    }
    return var_res;
  }

  static vector<Variable *> GetMultiVar(const string &key,
                                        const VariableNameMap &var_map,
                                        const Scope &scope) {
    auto var_vecs = var_map.at(key);
    assert(var_vecs.size() > 1);
    vector<Variable *> var_res;
    for (auto &var_vec : var_vecs) {
      auto var = scope.FindVar(var_vec);
      var_res.push_back(var);
    }
    return var_res;
  }
};

template <typename Dtype>
class ConvParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  ConvParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
            const AttributeMap &attrs, const Scope &scope) {
    filter_ = OpParam::FilterFrom<GType>(inputs, scope);
    input_ = OpParam::InputFrom<GType>(inputs, scope);
    if (outputs.count("Output")) {
      output_ = OpParam::OutputFrom<GType>(outputs, scope);
    }
    strides_ = OpParam::GetAttr<vector<int>>("strides", attrs);
    paddings_ = OpParam::GetAttr<vector<int>>("paddings", attrs);
    dilations_ = OpParam::GetAttr<vector<int>>("dilations", attrs);
    groups = OpParam::GetAttr<int>("groups", attrs);
  }

  const RType *Input() const { return input_; }

  RType *Filter() const { return filter_; }

  RType *Output() const { return output_; }

  const vector<int> &Strides() const { return strides_; }

  const vector<int> &Paddings() const { return paddings_; }

  const vector<int> &Dilations() const { return dilations_; }

  const int &Groups() const { return groups; }

#ifdef PADDLE_MOBILE_CL
  int Offset() const { return offset_; }

  int SetOffset(int in_offset) { offset_ = in_offset; }

#endif

 private:
  RType *input_;
  RType *output_;
  RType *filter_;
  vector<int> strides_;
  vector<int> paddings_;
  vector<int> dilations_;
  int groups;

#ifdef PADDLE_MOBILE_CL
  int offset_;
#endif

#ifdef PADDLE_MOBILE_FPGA

 private:
  fpga::SplitConvArgs fpga_conv_args;

 public:
  const fpga::SplitConvArgs &FpgaArgs() const { return fpga_conv_args; }
  void SetFpgaArgs(const fpga::SplitConvArgs &args) { fpga_conv_args = args; }
#endif
};
template <typename Dtype>
Print &operator<<(Print &printer, const ConvParam<Dtype> &conv_param);

template <typename Dtype>
class ElementwiseAddParam : OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  ElementwiseAddParam(const VariableNameMap &inputs,
                      const VariableNameMap &outputs, const AttributeMap &attrs,
                      const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    input_y_ = InputYFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    axis_ = GetAttr<int>("axis", attrs);
  }

  const GType *InputX() const { return input_x_; }

  const GType *InputY() const { return input_y_; }

  GType *Out() const { return out_; }

  const int &Axis() const { return axis_; }

 private:
  GType *input_x_;
  GType *input_y_;
  GType *out_;
  int axis_;
#ifdef PADDLE_MOBILE_FPGA

 private:
  fpga::EWAddArgs fpga_EW_add_args;

 public:
  const fpga::EWAddArgs &FpgaArgs() const { return fpga_EW_add_args; }
  void SetFpgaArgs(const fpga::EWAddArgs &args) { fpga_EW_add_args = args; }
#endif
};

#ifdef ELEMENTWISEMUL_OP
template <typename Dtype>
class ElementwiseMulParam : OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  ElementwiseMulParam(const VariableNameMap &inputs,
                      const VariableNameMap &outputs, const AttributeMap &attrs,
                      const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    input_y_ = InputYFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    axis_ = GetAttr<int>("axis", attrs);
  }

  const GType *InputX() const { return input_x_; }

  const GType *InputY() const { return input_y_; }

  GType *Out() const { return out_; }

  const int &Axis() const { return axis_; }

 private:
  GType *input_x_;
  GType *input_y_;
  GType *out_;
  int axis_;
};
#endif

#ifdef FUSION_ELEMENTWISEADDRELU_OP
template <typename Dtype>
using ElementwiseAddReluParam = ElementwiseAddParam<Dtype>;
#endif

#ifdef ELEMENTWISESUB_OP
template <typename Dtype>
class ElementwiseSubParam : OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  ElementwiseSubParam(const VariableNameMap &inputs,
                      const VariableNameMap &outputs, const AttributeMap &attrs,
                      const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    input_y_ = InputYFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    axis_ = GetAttr<int>("axis", attrs);
  }

  const GType *InputX() const { return input_x_; }

  const GType *InputY() const { return input_y_; }

  GType *Out() const { return out_; }

  const int &Axis() const { return axis_; }

 private:
  GType *input_x_;
  GType *input_y_;
  GType *out_;
  int axis_;
};
#endif

#ifdef MUL_OP
template <typename Dtype>
class MulParam : OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  MulParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
           const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    input_y_ = InputYFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    x_num_col_dims_ = GetAttr<int>("x_num_col_dims", attrs);
    y_num_col_dims_ = GetAttr<int>("y_num_col_dims", attrs);
  }

  const GType *InputX() const { return input_x_; }

  const GType *InputY() const { return input_y_; }

  GType *Out() const { return out_; }

  const int &XNumColDims() const { return x_num_col_dims_; }

  const int &YNumColDims() const { return y_num_col_dims_; }

 private:
  GType *input_x_;
  GType *input_y_;
  GType *out_;
  int x_num_col_dims_;
  int y_num_col_dims_;
};
#endif

#ifdef CONCAT_OP
template <typename Dtype>
class ConcatParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  ConcatParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
              const AttributeMap &attrs, const Scope &scope) {
    inputs_ = InputMultiFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    axis_ = GetAttr<int>("axis", attrs);
  }

  vector<GType *> Inputs() const { return inputs_; }

  GType *Out() const { return out_; }

  const int &Axis() const { return axis_; }

 private:
  vector<GType *> inputs_;
  GType *out_;
  int axis_;
#ifdef PADDLE_MOBILE_FPGA

 private:
  fpga::ConcatArgs fpga_concat_args;

 public:
  const fpga::ConcatArgs &FpgaArgs() const { return fpga_concat_args; }
  void SetFpgaArgs(const fpga::ConcatArgs &args) { fpga_concat_args = args; }
#endif
};
#endif

#ifdef SUM_OP
template <typename Dtype>
class SumParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  SumParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
           const AttributeMap &attrs, const Scope &scope) {
    inputs_vars_ = InputMultiVarsFrom(inputs, scope);
    out_var_ = OutVarFrom(outputs, scope);
    inputs_ = InputMultiFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
  }

  vector<Variable *> InputsVars() const { return inputs_vars_; }

  Variable *OutVar() const { return out_var_; }

  vector<GType *> Inputs() const { return inputs_; }

  GType *Out() const { return out_; }

 private:
  vector<Variable *> inputs_vars_;
  Variable *out_var_;
  vector<GType *> inputs_;
  GType *out_;
};
#endif

#ifdef LRN_OP
template <typename Dtype>
class LrnParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  LrnParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
           const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    mid_out_ = MidOutFrom<GType>(outputs, scope);
    n_ = GetAttr<int>("n", attrs);
    alpha_ = GetAttr<float>("alpha", attrs);
    beta_ = GetAttr<float>("beta", attrs);
    k_ = GetAttr<float>("k", attrs);
    data_format_ = GetStringAttr("data_format", attrs);
  }

  const RType *InputX() const { return input_x_; }

  RType *Out() const { return out_; }

  RType *MidOut() const { return mid_out_; }

  const int &N() const { return n_; }

  const float &Alpha() const { return alpha_; }

  const float &Beta() const { return beta_; }

  const float &K() const { return k_; }

  const string &DataFormat() const { return data_format_; }

 private:
  RType *input_x_;
  RType *out_;
  RType *mid_out_;
  int n_;
  float alpha_;
  float beta_;
  float k_;
  string data_format_;
};
#endif

#ifdef BATCHNORM_OP
template <typename Dtype>
class BatchNormParam : OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  BatchNormParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
                 const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    output_y_ = OutputYFrom<GType>(outputs, scope);
    input_bias_ = InputBiasFrom<GType>(inputs, scope);
    input_mean_ = InputMeanFrom<GType>(inputs, scope);
    input_scale_ = InputScaleFrom<GType>(inputs, scope);
    input_variance_ = InputVarianceFrom<GType>(inputs, scope);
    epsilon_ = GetAttr<float>("epsilon", attrs);
    momentum_ = GetAttr<float>("momentum", attrs);
    //    is_test_ = GetAttr<bool>("is_test", attrs);
  }

  const RType *InputX() const { return input_x_; }

  RType *OutputY() const { return output_y_; }

  const RType *InputBias() const { return input_bias_; }

  const RType *InputMean() const { return input_mean_; }

  const RType *InputScale() const { return input_scale_; }

  const RType *InputVariance() const { return input_variance_; }

  const float &Epsilon() const { return epsilon_; }

  const float &Momentum() const { return momentum_; }

  const bool &IsTest() const { return is_test_; }

  const string &DataFormat() const { return data_format_; }

  void SetNewScale(RType *new_scale) { new_scale_ = new_scale; }

  void SetNewBias(RType *new_bias) { new_bias_ = new_bias; }

  const RType *NewScale() const { return new_scale_; }

  const RType *NewBias() const { return new_bias_; }

 private:
  RType *input_x_;
  RType *output_y_;
  RType *input_bias_;
  RType *input_mean_;
  RType *input_scale_;
  RType *input_variance_;
  float epsilon_;
  float momentum_;
  bool is_test_;
  string data_format_;
  RType *new_bias_;
  RType *new_scale_;
};
#endif

#ifdef POOL_OP
template <typename Dtype>
class PoolParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  PoolParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
            const AttributeMap &attrs, const Scope &scope) {
    input_ = InputXFrom<GType>(inputs, scope);

    output_ = OutFrom<GType>(outputs, scope);
    pooling_type_ = GetStringAttr("pooling_type", attrs);
    ksize_ = GetAttr<vector<int>>("ksize", attrs);
    strides_ = GetAttr<vector<int>>("strides", attrs);
    paddings_ = GetAttr<vector<int>>("paddings", attrs);
    ceil_mode_ = GetAttr<bool>("ceil_mode", attrs);
    global_pooling_ = GetAttr<bool>("global_pooling", attrs);
  }

  const RType *Input() const { return input_; }

  RType *Output() const { return output_; }

  const string &PoolingType() const { return pooling_type_; }

  const vector<int> &Ksize() const { return ksize_; }

  const vector<int> &Strides() const { return strides_; }

  const vector<int> &Paddings() const { return paddings_; }

  bool isCeilMode() const { return ceil_mode_; }

  bool isGlobalPooling() const { return global_pooling_; }

 private:
  RType *input_;
  RType *output_;
  string pooling_type_;
  vector<int> ksize_;
  vector<int> strides_;
  vector<int> paddings_;
  bool ceil_mode_;
  bool global_pooling_ = false;
#ifdef PADDLE_MOBILE_FPGA

 private:
  fpga::PoolingArgs fpga_pool_args;

 public:
  const fpga::PoolingArgs &FpgaArgs() const { return fpga_pool_args; }
  void SetFpgaArgs(const fpga::PoolingArgs &args) { fpga_pool_args = args; }
#endif
};
#endif

#ifdef PRIORBOX_OP
template <typename Dtype>
class PriorBoxParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  PriorBoxParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
                const AttributeMap &attrs, const Scope &scope) {
    input_ = InputFrom<GType>(inputs, scope);
    input_image_ = InputImageFrom<GType>(inputs, scope);
    output_boxes_ = OutputBoxesFrom<GType>(outputs, scope);
    output_variances_ = OutputVariancesFrom<GType>(outputs, scope);
    min_sizes_ = GetAttr<vector<float>>("min_sizes", attrs);
    max_sizes_ = GetAttr<vector<float>>("max_sizes", attrs);
    aspect_ratios_ = GetAttr<vector<float>>("aspect_ratios", attrs);
    variances_ = GetAttr<vector<float>>("variances", attrs);

    if (HasAttr("min_max_aspect_ratios_order", attrs)) {
      min_max_aspect_ratios_order_ =
          GetAttr<bool>("min_max_aspect_ratios_order", attrs);
    } else {
      min_max_aspect_ratios_order_ = false;
    }
    flip_ = GetAttr<bool>("flip", attrs);
    clip_ = GetAttr<bool>("clip", attrs);
    step_w_ = GetAttr<float>("step_w", attrs);
    step_h_ = GetAttr<float>("step_h", attrs);
    offset_ = GetAttr<float>("offset", attrs);
  }
  const RType *Input() const { return input_; }

  const RType *InputImage() const { return input_image_; }

  RType *OutputBoxes() const { return output_boxes_; }

  RType *OutputVariances() const { return output_variances_; }

  const vector<float> &MinSizes() const { return min_sizes_; }

  const vector<float> &MaxSizes() const { return max_sizes_; }

  const vector<float> &AspectRatios() const { return aspect_ratios_; }

  const vector<float> &Variances() const { return variances_; }

  const bool &Flip() const { return flip_; }

  const bool &Clip() const { return clip_; }

  const float &StepW() const { return step_w_; }

  const float &StepH() const { return step_h_; }

  const float &Offset() const { return offset_; }

  const bool &MinMaxAspectRatiosOrder() const {
    return min_max_aspect_ratios_order_;
  }

 private:
  RType *input_;
  RType *input_image_;
  RType *output_boxes_;
  RType *output_variances_;
  vector<float> min_sizes_;
  vector<float> max_sizes_;
  vector<float> aspect_ratios_;
  vector<float> variances_;
  bool flip_;
  bool clip_;
  float step_w_;
  float step_h_;
  float offset_;
  bool min_max_aspect_ratios_order_;
};
#endif

#ifdef BOXCODER_OP
template <typename Dtype>
class BoxCoderParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  BoxCoderParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
                const AttributeMap &attrs, const Scope &scope) {
    input_priorbox_ = InputPriorBoxFrom<GType>(inputs, scope);
    input_priorboxvar_ = InputPriorBoxVarFrom<GType>(inputs, scope);
    input_targetbox_ = InputTargetBoxFrom<GType>(inputs, scope);
    output_box_ = OutputBoxFrom<GType>(outputs, scope);
    code_type_ = GetStringAttr("code_type", attrs);
  }
  const RType *InputPriorBox() const { return input_priorbox_; }

  const RType *InputPriorBoxVar() const { return input_priorboxvar_; }

  const RType *InputTargetBox() const { return input_targetbox_; }

  RType *OutputBox() const { return output_box_; }

  const std::string &CodeType() const { return code_type_; }

 private:
  RType *input_priorbox_;
  RType *input_priorboxvar_;
  RType *input_targetbox_;
  RType *output_box_;
  std::string code_type_;
};
#endif

#ifdef SOFTMAX_OP
template <typename Dtype>
class SoftmaxParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  SoftmaxParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
               const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
  }
  const RType *InputX() const { return input_x_; }
  RType *Out() const { return out_; }

 private:
  RType *input_x_;
  RType *out_;

#ifdef PADDLE_MOBILE_FPGA

 private:
  std::shared_ptr<RType> float_input_x_;
  fpga::BypassArgs fpga_bypass_args;

 public:
  RType *FloatInput() const {
    return float_input_x_ == nullptr ? input_x_ : float_input_x_.get();
  }
  void SetFloatInput(Tensor *input) { float_input_x_.reset(input); }
  const fpga::BypassArgs &FpgaArgs() const { return fpga_bypass_args; }
  void SetFpgaArgs(const fpga::BypassArgs &args) { fpga_bypass_args = args; }
#endif
};
#endif

#ifdef SIGMOID_OP
template <typename Dtype>
class SigmoidParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  SigmoidParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
               const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
  }
  const RType *InputX() const { return input_x_; }
  RType *Out() const { return out_; }

 private:
  RType *input_x_;
  RType *out_;
};
#endif

#ifdef MULTICLASSNMS_OP
template <typename Dtype>
class MultiClassNMSParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  MultiClassNMSParam(const VariableNameMap &inputs,
                     const VariableNameMap &outputs, const AttributeMap &attrs,
                     const Scope &scope) {
    input_bboxes_ = InputBBoxesFrom<GType>(inputs, scope);
    input_scores_ = InputScoresFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    background_label_ = GetAttr<int>("background_label", attrs);
    nms_top_k_ = GetAttr<int>("nms_top_k", attrs);
    keep_top_k_ = GetAttr<int>("keep_top_k", attrs);
    nms_threshold_ = GetAttr<float>("nms_threshold", attrs);
    nms_eta_ = GetAttr<float>("nms_eta", attrs);
    score_threshold_ = GetAttr<float>("score_threshold", attrs);
  }

  RType *InputBBoxes() const { return input_bboxes_; }

  RType *InputScores() const { return input_scores_; }

  RType *Out() const { return out_; }

  const int &BackGroundLabel() const { return background_label_; }

  const int &NMSTopK() const { return nms_top_k_; }

  const int &KeepTopK() const { return keep_top_k_; }

  const float &NMSThreshold() const { return nms_threshold_; }

  const float &NMSEta() const { return nms_eta_; }

  const float &ScoreThreshold() const { return score_threshold_; }

 private:
  RType *input_bboxes_;
  RType *input_scores_;
  RType *out_;
  int background_label_;
  int nms_top_k_;
  int keep_top_k_;
  float nms_threshold_;
  float nms_eta_;
  float score_threshold_;
};
#endif

#ifdef POLYGONBOXTRANSFORM_OP
template <typename Dtype>
class PolygonBoxTransformParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  PolygonBoxTransformParam(const VariableNameMap &inputs,
                           const VariableNameMap &outputs,
                           const AttributeMap &attrs, const Scope &scope) {
    input_ = InputFrom<GType>(inputs, scope);
    output_ = OutputFrom<GType>(outputs, scope);
  }
  const RType *Input() const { return input_; }
  RType *Output() const { return output_; }

 private:
  RType *input_;
  RType *output_;
};
#endif

template <typename Dtype>
class FeedParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  FeedParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
            const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<LoDTensor>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    auto var = scope.FindVar("batch_size");
    batch_size = var->GetValue<int>();
  }
  const LoDTensor *InputX() const { return input_x_; }
  GType *Out() const { return out_; }
  const int BatchSize() const { return batch_size; }

 private:
  LoDTensor *input_x_;
  GType *out_;
  int batch_size;
};

template <typename Dtype>
class FetchParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  FetchParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
             const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    out_ = OutFrom(outputs, scope);
  }

  const RType *InputX() const { return input_x_; }
  Tensor *Out() const { return out_; }

  static Tensor *OutFrom(const VariableNameMap &outputs, const Scope &scope) {
    return GetVarValue<LoDTensor>("Out", outputs, scope);
  }

 private:
  RType *input_x_;
  Tensor *out_;
};

#ifdef FILL_CONSTANT_OP
template <typename Dtype>
class FillConstantParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  FillConstantParam(const VariableNameMap &inputs,
                    const VariableNameMap &outputs, const AttributeMap &attrs,
                    const Scope &scope) {
    out_var_ = OutVarFrom(outputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    dtype_ = GetAttr<int>("dtype", attrs);
    shape_ = GetAttr<vector<int>>("shape", attrs);
    value_ = GetAttr<float>("value", attrs);
  }

  Variable *OutVar() const { return out_var_; }

  RType *Out() const { return out_; }

  const int &DataDtype() const { return dtype_; }

  const vector<int> &Shape() const { return shape_; }

  const float &Value() const { return value_; }

 private:
  Variable *out_var_;
  RType *out_;
  int dtype_;
  vector<int> shape_;
  float value_;
};
#endif

#ifdef TRANSPOSE_OP
template <typename Dtype>
class TransposeParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  TransposeParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
                 const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    axis_ = GetAttr<vector<int>>("axis", attrs);
  }

  const RType *InputX() const { return input_x_; }

  RType *Out() const { return out_; }

  const vector<int> &Axis() const { return axis_; }

 private:
  RType *input_x_;
  RType *out_;
  vector<int> axis_;
};
#endif

#ifdef TRANSPOSE2_OP
template <typename Dtype>
class Transpose2Param : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  Transpose2Param(const VariableNameMap &inputs, const VariableNameMap &outputs,
                  const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    output_xshape_ = OutputXShapeFrom<GType>(outputs, scope);
    axis_ = GetAttr<vector<int>>("axis", attrs);
  }

  const RType *InputX() const { return input_x_; }

  RType *Out() const { return out_; }

  RType *OutputXShape() const { return output_xshape_; }

  const vector<int> &Axis() const { return axis_; }

 private:
  RType *input_x_;
  RType *out_;
  RType *output_xshape_;
  vector<int> axis_;
};
#endif

#ifdef LOOKUP_OP
template <typename Dtype>
class LookupParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  LookupParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
              const AttributeMap &attrs, const Scope &scope) {
    input_w_ = InputWFrom<GType>(inputs, scope);
    input_ids_ = InputIdsFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    padding_idx_ = GetAttr<int64_t>("padding_idx", attrs);
  }

  const GType *InputW() const { return input_w_; }
  const GType *InputIds() const { return input_ids_; }
  GType *Out() const { return out_; }
  int64_t PaddingIdx() const { return padding_idx_; }

 private:
  GType *input_w_;
  GType *input_ids_;
  GType *out_;
  int64_t padding_idx_;
};
#endif

#ifdef CRF_OP
template <typename Dtype>
class CrfParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  //    {G_OP_TYPE_CRF, {{"Emission", "Transition", "Label"}, {"ViterbiPath"}}},

  CrfParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
           const AttributeMap &attrs, const Scope &scope) {
    // todo crf params
    input_emission_ = InputEmissionFrom<GType>(inputs, scope);
    input_transition_ = InputTransitionFrom<GType>(inputs, scope);
    input_label_ = InputLabelFrom<GType>(inputs, scope);
    output_viterbipath_ = OutputViterbiPathFrom<GType>(outputs, scope);
    //    padding_idx_ = GetAttr<int64_t>("padding_idx", attrs);
  }
  const GType *InputEmission() const { return input_emission_; }
  const GType *InputTransition() const { return input_transition_; }
  const GType *InputLabel() const { return input_label_; }
  GType *outputVBP() const { return output_viterbipath_; }
  //  const RType *InputIds() const { return input_ids_; }
  //  RType *Out() const { return out_; }
  //  int64_t PaddingIdx() const { return padding_idx_; }

 private:
  GType *input_emission_;
  GType *input_transition_;
  GType *input_label_;
  GType *output_viterbipath_;

  //  RType *input_ids_;
  //  RType *out_;
  //  int64_t padding_idx_;
};
#endif

#ifdef RESHAPE_OP
template <typename Dtype>
class ReshapeParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  ReshapeParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
               const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    input_shape_ = InputShapeFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    shape_ = GetAttr<vector<int>>("shape", attrs);

    if (HasAttr("inplace", attrs)) {
      inplace_ = GetAttr<bool>("inplace", attrs);
    } else {
      inplace_ = false;
      DLOG << "ReshapeParam lost inplace params. maybe fluid updated";
    }
  }

  const RType *InputX() const { return input_x_; }

  const RType *InputShape() const { return input_shape_; }

  RType *Out() const { return out_; }

  const vector<int> &Shape() const { return shape_; }

  const bool &Inplace() const { return inplace_; }

 private:
  RType *input_x_;
  RType *input_shape_;
  RType *out_;
  vector<int> shape_;
  bool inplace_;
};
#endif

#ifdef RESHAPE2_OP
template <typename Dtype>
class Reshape2Param : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  Reshape2Param(const VariableNameMap &inputs, const VariableNameMap &outputs,
                const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    input_shape_ = InputShapeFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    output_xshape_ = OutputXShapeFrom<GType>(outputs, scope);
    shape_ = GetAttr<vector<int>>("shape", attrs);
    if (HasAttr("inplace", attrs)) {
      inplace_ = GetAttr<bool>("inplace", attrs);
    } else {
      inplace_ = false;
    }
  }

  const GType *InputX() const { return input_x_; }

  const GType *InputShape() const { return input_shape_; }

  GType *Out() const { return out_; }

  GType *OutputXShape() const { return output_xshape_; }

  const vector<int> &Shape() const { return shape_; }

  const bool &Inplace() const { return inplace_; }

 private:
  GType *input_x_;
  GType *input_shape_;
  GType *out_;
  GType *output_xshape_;
  vector<int> shape_;
  bool inplace_;
};
#endif

#ifdef SCALE_OP
template <typename Dtype>
class ScaleParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  ScaleParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
             const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    input_bias_ = InputBiasFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    inplace_ = GetAttr<bool>("inplace", attrs);
    has_bias_ = GetAttr<bool>("has_bias", attrs);
    scales_ = GetAttr<vector<float>>("scales", attrs);
    biases_ = GetAttr<vector<float>>("biases", attrs);
  }

  const RType *InputX() const { return input_x_; }

  const RType *InputBias() const { return input_bias_; }

  RType *Out() const { return out_; }

  const bool &Inplace() const { return inplace_; }

  const bool &HasBias() const { return has_bias_; }

  const vector<float> &Scales() const { return scales_; }

  const vector<float> &Biases() const { return biases_; }

 private:
  RType *input_x_;
  RType *input_bias_;
  RType *out_;
  bool inplace_;
  bool has_bias_;
  vector<float> scales_;
  vector<float> biases_;
};
#endif

#ifdef SLICE_OP
template <typename Dtype>
class SliceParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  SliceParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
             const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    input_shape_ = InputShapeFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    axis_ = GetAttr<int>("axis", attrs);
    slice_points_ = GetAttr<vector<int>>("slice_points", attrs);
    inplace_ = GetAttr<bool>("inplace", attrs);
  }

  const RType *InputX() const { return input_x_; }

  const RType *InputShape() const { return input_shape_; }

  RType *Out() const { return out_; }

  const int &Axis() const { return axis_; }

  const vector<int> &SlicePoints() const { return slice_points_; }

  const bool &Inplace() const { return inplace_; }

 private:
  RType *input_x_;
  RType *input_shape_;
  RType *out_;
  int axis_;
  vector<int> slice_points_;
  bool inplace_;
};
#endif

#ifdef RESIZE_OP
template <typename Dtype>
class ResizeParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  ResizeParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
              const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    input_shape_ = InputShapeFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    is_pyramid_test_ = GetAttr<bool>("is_pyramid_test", attrs);
    height_ = GetAttr<int>("height", attrs);
    width_ = GetAttr<int>("width", attrs);
    out_height_scale_ = GetAttr<float>("out_height_scale", attrs);
    out_width_scale_ = GetAttr<float>("out_width_scale", attrs);
  }

  const RType *InputX() const { return input_x_; }

  const RType *InputShape() const { return input_shape_; }

  RType *Out() const { return out_; }

  const bool &IsPyramidTest() const { return is_pyramid_test_; }

  const int &Height() const { return height_; }

  const int &Width() const { return width_; }

  const float &OutHeightScale() const { return out_height_scale_; }

  const float &OutWidthScale() const { return out_width_scale_; }

 private:
  RType *input_x_;
  RType *input_shape_;
  RType *out_;
  bool is_pyramid_test_;
  int height_;
  int width_;
  float out_height_scale_;
  float out_width_scale_;
};
#endif

#ifdef RELU_OP
/*
 * @b op 层实例化好这个 param 传递给 kernel 层使用
 * */
template <typename Dtype>
class ReluParamBase : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  ReluParamBase(const VariableNameMap &inputs, const VariableNameMap &outputs,
                const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
  }

  const RType *InputX() const { return input_x_; }

  RType *Out() const { return out_; }

 private:
  RType *input_x_;
  RType *out_;
};

template <typename Dtype>
class ReluParam : public ReluParamBase<Dtype> {
 public:
  using ReluParamBase<Dtype>::ReluParamBase;
};

#ifdef PADDLE_MOBILE_CL
template <>
class ReluParam<GPU_CL> : public ReluParamBase<GPU_CL> {
 public:
  using ReluParamBase<GPU_CL>::ReluParamBase;
  framework::CLImage &getMidImage() { return midImage; }

 private:
  framework::CLImage midImage;
};
#endif

#endif

#ifdef TANH_OP
template <typename Dtype>
class TanhParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  TanhParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
            const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
  }
  const RType *InputX() const { return input_x_; }
  RType *Out() const { return out_; }

 private:
  RType *input_x_;
  RType *out_;
};
#endif

#ifdef PRELU_OP
template <typename Dtype>
class PReluParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  PReluParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
             const AttributeMap &attrs, const Scope &scope) {
    DLOG << "PReluParam inputs before";
    input_x_ = InputXFrom<GType>(inputs, scope);
    alpha_ = InputAlphaFrom<GType>(inputs, scope);
    framework::DDim dims = alpha_->dims();
    out_ = OutFrom<GType>(outputs, scope);
    mode_ = GetStringAttr("mode", attrs);
    DLOG << "PReluParam mode after" << mode_;
  }
  const RType *InputX() const { return input_x_; }
  const RType *InputAlpha() const { return alpha_; }
  RType *Out() const { return out_; }
  const std::string &Mode() const { return mode_; }

 private:
  RType *input_x_;
  RType *out_;
  RType *alpha_;
  std::string mode_;
};
#endif

template <typename Dtype>
class FusionFcParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  FusionFcParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
                const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    input_y_ = InputYFrom<GType>(inputs, scope);
    input_z_ = InputZFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    x_num_col_dims_ = GetAttr<int>("x_num_col_dims", attrs);
    y_num_col_dims_ = GetAttr<int>("y_num_col_dims", attrs);
    axis_ = GetAttr<int>("axis", attrs);
  }
  const GType *InputX() const { return input_x_; }

  const RType *InputY() const { return input_y_; }

  const RType *InputZ() const { return input_z_; }

  GType *Out() const { return out_; }

  const int &XNumColDims() const { return x_num_col_dims_; }

  const int &YNumColDims() const { return y_num_col_dims_; }

  const int &Axis() const { return axis_; }

 private:
  GType *input_x_;
  RType *input_y_;
  RType *input_z_;
  GType *out_;
  int x_num_col_dims_;
  int y_num_col_dims_;
  int axis_;
#ifdef PADDLE_MOBILE_FPGA

 private:
  fpga::SplitConvArgs fpga_conv_args;

 public:
  const fpga::SplitConvArgs &FpgaArgs() const { return fpga_conv_args; }
  void SetFpgaArgs(const fpga::SplitConvArgs &args) { fpga_conv_args = args; }
#endif
};

#ifdef FUSION_FCRELU_OP
template <typename DeviceType>
using FusionFcReluParam = FusionFcParam<DeviceType>;
#endif

template <typename Dtype>
class FusionConvAddParam : public ConvParam<Dtype> {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  FusionConvAddParam(const VariableNameMap &inputs,
                     const VariableNameMap &outputs, const AttributeMap &attrs,
                     const Scope &scope)
      : ConvParam<Dtype>(inputs, outputs, attrs, scope) {
    bias_ = OpParam::InputYFrom<GType>(inputs, scope);
    axis_ = OpParam::GetAttr<int>("axis", attrs);
    output_ = OpParam::OutFrom<GType>(outputs, scope);
  }
  RType *Bias() const { return bias_; }

  const int &Axis() const { return axis_; }

  RType *Output() const { return output_; }

 protected:
  RType *bias_;
  int axis_;
  RType *output_;
};

template <typename Dtype>
Print &operator<<(Print &printer, const FusionConvAddParam<Dtype> &conv_param);

#ifdef FUSION_CONVADDRELU_OP
template <typename DeviceType>
class FusionConvAddReluParam : public FusionConvAddParam<DeviceType> {
 public:
  FusionConvAddReluParam(const VariableNameMap &inputs,
                         const VariableNameMap &outputs,
                         const AttributeMap &attrs, const Scope &scope)
      : FusionConvAddParam<DeviceType>(inputs, outputs, attrs, scope) {}
};
#endif

#ifdef FUSION_CONVADDPRELU_OP
template <typename Dtype>
class FusionConvAddPReluParam : public ConvParam<Dtype> {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  FusionConvAddPReluParam(const VariableNameMap &inputs,
                          const VariableNameMap &outputs,
                          const AttributeMap &attrs, const Scope &scope)
      : ConvParam<Dtype>(inputs, outputs, attrs, scope) {
    alpha_ = OpParam::InputAlphaFrom<GType>(inputs, scope);
    mode_ = OpParam::GetStringAttr("mode", attrs);
    framework::DDim dims = alpha_->dims();
    bias_ = OpParam::InputYFrom<GType>(inputs, scope);
    axis_ = OpParam::GetAttr<int>("axis", attrs);
    output_ = OpParam::OutFrom<GType>(outputs, scope);
  }
  const RType *InputAlpha() const { return alpha_; }
  const std::string &Mode() const { return mode_; }
  RType *Bias() const { return bias_; }
  const int &Axis() const { return axis_; }
  RType *Output() const { return output_; }

 protected:
  RType *bias_;
  int axis_;
  RType *output_;
  RType *alpha_;
  std::string mode_;
};
#endif

#ifdef FUSION_CONVADDADDPRELU_OP
template <typename Dtype>
class FusionConvAddAddPReluParam : public ConvParam<Dtype> {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  FusionConvAddAddPReluParam(const VariableNameMap &inputs,
                             const VariableNameMap &outputs,
                             const AttributeMap &attrs, const Scope &scope)
      : ConvParam<Dtype>(inputs, outputs, attrs, scope) {
    bias1_ = OpParam::InputYFrom1<GType>(inputs, scope);
    alpha_ = OpParam::InputAlphaFrom<GType>(inputs, scope);
    mode_ = OpParam::GetStringAttr("mode", attrs);
    framework::DDim dims = alpha_->dims();
    bias_ = OpParam::InputYFrom<GType>(inputs, scope);
    output_ = OpParam::OutFrom<GType>(outputs, scope);
    axis_ = OpParam::GetAttr<int>("axis", attrs);
    keyOutput_ = OpParam::getkey("addOut", inputs, 0);
    keyX1_ = OpParam::getkey("addX", inputs, 1);
    keyY1_ = OpParam::getkey("Y", inputs, 1);
    if (keyX1_ == keyOutput_) {
      bias1_ = OpParam::InputYFrom1<GType>(inputs, scope);
    } else if (keyY1_ == keyOutput_) {
      bias1_ = OpParam::InputXFrom1<GType>(inputs, scope);
    }
  }
  const RType *InputAlpha() const { return alpha_; }
  const std::string &Mode() const { return mode_; }
  const RType *Bias1() const { return bias1_; }

  RType *Bias() const { return bias_; }

  const int &Axis() const { return axis_; }
  RType *Output() const { return output_; }

 protected:
  RType *bias_;
  int axis_;
  RType *output_;
  RType *alpha_;
  std::string mode_;
  RType *bias1_;
  std::string keyOutput_;
  std::string keyX1_;
  std::string keyY1_;
};
#endif

#ifdef FUSION_CONVADDBNRELU_OP
template <typename Dtype>
class FusionConvAddBNReluParam : public ConvParam<Dtype> {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  FusionConvAddBNReluParam(const VariableNameMap &inputs,
                           const VariableNameMap &outputs,
                           const AttributeMap &attrs, const Scope &scope)
      : ConvParam<Dtype>(inputs, outputs, attrs, scope) {
    bias_ = OpParam::InputYFrom<GType>(inputs, scope);
    axis_ = OpParam::GetAttr<int>("axis", attrs);
    output_ = OpParam::OutFrom<GType>(outputs, scope);
    input_bias_ = OpParam::InputBiasFrom<GType>(inputs, scope);
    input_mean_ = OpParam::InputMeanFrom<GType>(inputs, scope);
    input_scale_ = OpParam::InputScaleFrom<GType>(inputs, scope);
    input_variance_ = OpParam::InputVarianceFrom<GType>(inputs, scope);
    epsilon_ = OpParam::GetAttr<float>("epsilon", attrs);
    momentum_ = OpParam::GetAttr<float>("momentum", attrs);
    //    is_test_ = OpParam::GetAttr<bool>("is_test", attrs);
  }
  RType *Bias() const { return bias_; }

  const int &Axis() const { return axis_; }

  RType *Output() const { return output_; }

  const RType *InputBias() const { return input_bias_; }

  const RType *InputMean() const { return input_mean_; }

  const RType *InputScale() const { return input_scale_; }

  const RType *InputVariance() const { return input_variance_; }

  const float &Epsilon() const { return epsilon_; }

  const float &Momentum() const { return momentum_; }

  const bool &IsTest() const { return is_test_; }

  void SetNewScale(RType *new_scale) { new_scale_ = new_scale; }

  void SetNewBias(RType *new_bias) { new_bias_ = new_bias; }

  const RType *NewScale() const { return new_scale_; }

  const RType *NewBias() const { return new_bias_; }

 protected:
  RType *bias_;
  int axis_;
  RType *output_;
  RType *input_bias_;
  RType *input_mean_;
  RType *input_scale_;
  RType *input_variance_;
  float epsilon_;
  float momentum_;
  bool is_test_;
  RType *new_bias_;
  RType *new_scale_;
};
#endif

#ifdef FUSION_CONVBNADDRELU_OP
template <typename Dtype>
class FusionConvBNAddReluParam : public ConvParam<Dtype> {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  FusionConvBNAddReluParam(const VariableNameMap &inputs,
                           const VariableNameMap &outputs,
                           const AttributeMap &attrs, const Scope &scope)
      : ConvParam<Dtype>(inputs, outputs, attrs, scope) {
    bias_ = OpParam::InputYFrom<GType>(inputs, scope);
    axis_ = OpParam::GetAttr<int>("axis", attrs);
    output_ = OpParam::OutFrom<GType>(outputs, scope);
    input_bias_ = OpParam::InputBiasFrom<GType>(inputs, scope);
    input_mean_ = OpParam::InputMeanFrom<GType>(inputs, scope);
    input_scale_ = OpParam::InputScaleFrom<GType>(inputs, scope);
    input_variance_ = OpParam::InputVarianceFrom<GType>(inputs, scope);
    epsilon_ = OpParam::GetAttr<float>("epsilon", attrs);
    momentum_ = OpParam::GetAttr<float>("momentum", attrs);
    keyBNY_ = OpParam::getkey("BNY", inputs, 0);
    keyX_ = OpParam::getkey("X", inputs, 0);
    keyY_ = OpParam::getkey("Y", inputs, 0);
    if (keyX_ == keyBNY_) {
      bias_ = OpParam::InputYFrom<GType>(inputs, scope);
    } else if (keyY_ == keyBNY_) {
      bias_ = OpParam::InputXFrom<GType>(inputs, scope);
    }
    //    is_test_ = OpParam::GetAttr<bool>("is_test", attrs);
  }
  RType *Bias() const { return bias_; }

  const int &Axis() const { return axis_; }

  RType *Output() const { return output_; }

  const RType *InputBias() const { return input_bias_; }

  const RType *InputMean() const { return input_mean_; }

  const RType *InputScale() const { return input_scale_; }

  const RType *InputVariance() const { return input_variance_; }

  const float &Epsilon() const { return epsilon_; }

  const float &Momentum() const { return momentum_; }

  const bool &IsTest() const { return is_test_; }

  void SetNewScale(RType *new_scale) { new_scale_ = new_scale; }

  void SetNewBias(RType *new_bias) { new_bias_ = new_bias; }

  const RType *NewScale() const { return new_scale_; }

  const RType *NewBias() const { return new_bias_; }

 protected:
  RType *bias_;
  int axis_;
  RType *output_;
  RType *input_bias_;
  RType *input_mean_;
  RType *input_scale_;
  RType *input_variance_;
  float epsilon_;
  float momentum_;
  bool is_test_;
  RType *new_bias_;
  RType *new_scale_;
  std::string keyBNY_;
  std::string keyX_;
  std::string keyY_;
};
#endif

#ifdef FUSION_CONVBN_OP
template <typename Dtype>
class FusionConvBNParam : public ConvParam<Dtype> {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  FusionConvBNParam(const VariableNameMap &inputs,
                    const VariableNameMap &outputs, const AttributeMap &attrs,
                    const Scope &scope)
      : ConvParam<Dtype>(inputs, outputs, attrs, scope) {
    output_y_ = OpParam::OutputYFrom<GType>(outputs, scope);
    input_bias_ = OpParam::InputBiasFrom<GType>(inputs, scope);
    input_mean_ = OpParam::InputMeanFrom<GType>(inputs, scope);
    input_scale_ = OpParam::InputScaleFrom<GType>(inputs, scope);
    input_variance_ = OpParam::InputVarianceFrom<GType>(inputs, scope);
    epsilon_ = OpParam::GetAttr<float>("epsilon", attrs);
    momentum_ = OpParam::GetAttr<float>("momentum", attrs);
    //    is_test_ = OpParam::GetAttr<bool>("is_test", attrs);
  }
  RType *Output() const { return output_y_; }

  const RType *InputBias() const { return input_bias_; }

  const RType *InputMean() const { return input_mean_; }

  const RType *InputScale() const { return input_scale_; }

  const RType *InputVariance() const { return input_variance_; }

  const float &Epsilon() const { return epsilon_; }

  const float &Momentum() const { return momentum_; }

  const bool &IsTest() const { return is_test_; }

  void SetNewScale(RType *new_scale) { new_scale_ = new_scale; }

  void SetNewBias(RType *new_bias) { new_bias_ = new_bias; }

  const RType *NewScale() const { return new_scale_; }

  const RType *NewBias() const { return new_bias_; }

 protected:
  RType *output_y_;
  RType *input_bias_;
  RType *input_mean_;
  RType *input_scale_;
  RType *input_variance_;
  float epsilon_;
  float momentum_;
  bool is_test_;
  RType *new_bias_;
  RType *new_scale_;
};
#endif

#ifdef FUSION_CONVADDBN_OP
template <typename Dtype>
class FusionConvAddBNParam : public ConvParam<Dtype> {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  FusionConvAddBNParam(const VariableNameMap &inputs,
                       const VariableNameMap &outputs,
                       const AttributeMap &attrs, const Scope &scope)
      : ConvParam<Dtype>(inputs, outputs, attrs, scope) {
    bias_ = OpParam::InputYFrom<GType>(inputs, scope);
    axis_ = OpParam::GetAttr<int>("axis", attrs);
    output_y_ = OpParam::OutputYFrom<GType>(outputs, scope);
    input_bias_ = OpParam::InputBiasFrom<GType>(inputs, scope);
    input_mean_ = OpParam::InputMeanFrom<GType>(inputs, scope);
    input_scale_ = OpParam::InputScaleFrom<GType>(inputs, scope);
    input_variance_ = OpParam::InputVarianceFrom<GType>(inputs, scope);
    epsilon_ = OpParam::GetAttr<float>("epsilon", attrs);
    momentum_ = OpParam::GetAttr<float>("momentum", attrs);
    //    is_test_ = OpParam::GetAttr<bool>("is_test", attrs);
  }
  RType *Bias() const { return bias_; }

  const int &Axis() const { return axis_; }

  RType *Output() const { return output_y_; }

  const RType *InputBias() const { return input_bias_; }

  const RType *InputMean() const { return input_mean_; }

  const RType *InputScale() const { return input_scale_; }

  const RType *InputVariance() const { return input_variance_; }

  const float &Epsilon() const { return epsilon_; }

  const float &Momentum() const { return momentum_; }

  const bool &IsTest() const { return is_test_; }

  void SetNewScale(RType *new_scale) { new_scale_ = new_scale; }

  void SetNewBias(RType *new_bias) { new_bias_ = new_bias; }

  const RType *NewScale() const { return new_scale_; }

  const RType *NewBias() const { return new_bias_; }

 protected:
  RType *bias_;
  int axis_;
  RType *output_y_;
  RType *input_bias_;
  RType *input_mean_;
  RType *input_scale_;
  RType *input_variance_;
  float epsilon_;
  float momentum_;
  bool is_test_;
  RType *new_bias_;
  RType *new_scale_;
};
#endif

#ifdef FUSION_DWCONVBNRELU_OP
template <typename Dtype>
class FusionDWConvBNReluParam : public ConvParam<Dtype> {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  FusionDWConvBNReluParam(const VariableNameMap &inputs,
                          const VariableNameMap &outputs,
                          const AttributeMap &attrs, const Scope &scope)
      : ConvParam<Dtype>(inputs, outputs, attrs, scope) {
    output_ = OpParam::OutFrom<GType>(outputs, scope);
    input_bias_ = OpParam::InputBiasFrom<GType>(inputs, scope);
    input_mean_ = OpParam::InputMeanFrom<GType>(inputs, scope);
    input_scale_ = OpParam::InputScaleFrom<GType>(inputs, scope);
    input_variance_ = OpParam::InputVarianceFrom<GType>(inputs, scope);
    epsilon_ = OpParam::GetAttr<float>("epsilon", attrs);
    momentum_ = OpParam::GetAttr<float>("momentum", attrs);
    //    is_test_ = OpParam::GetAttr<bool>("is_test", attrs);
  }
  RType *Output() const { return output_; }

  const RType *InputBias() const { return input_bias_; }

  const RType *InputMean() const { return input_mean_; }

  const RType *InputScale() const { return input_scale_; }

  const RType *InputVariance() const { return input_variance_; }

  const float &Epsilon() const { return epsilon_; }

  const float &Momentum() const { return momentum_; }

  const bool &IsTest() const { return is_test_; }

  void SetNewScale(RType *new_scale) { new_scale_ = new_scale; }

  void SetNewBias(RType *new_bias) { new_bias_ = new_bias; }

  const RType *NewScale() const { return new_scale_; }

  const RType *NewBias() const { return new_bias_; }

 protected:
  RType *output_;
  RType *input_bias_;
  RType *input_mean_;
  RType *input_scale_;
  RType *input_variance_;
  float epsilon_;
  float momentum_;
  bool is_test_;
  RType *new_bias_;
  RType *new_scale_;
};

#endif

#ifdef FUSION_CONVBNRELU_OP
template <typename Dtype>
class FusionConvBNReluParam : public ConvParam<Dtype> {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  FusionConvBNReluParam(const VariableNameMap &inputs,
                        const VariableNameMap &outputs,
                        const AttributeMap &attrs, const Scope &scope)
      : ConvParam<Dtype>(inputs, outputs, attrs, scope) {
    output_ = OpParam::OutFrom<GType>(outputs, scope);
    input_bias_ = OpParam::InputBiasFrom<GType>(inputs, scope);
    input_mean_ = OpParam::InputMeanFrom<GType>(inputs, scope);
    input_scale_ = OpParam::InputScaleFrom<GType>(inputs, scope);
    input_variance_ = OpParam::InputVarianceFrom<GType>(inputs, scope);
    epsilon_ = OpParam::GetAttr<float>("epsilon", attrs);
    momentum_ = OpParam::GetAttr<float>("momentum", attrs);
    //    is_test_ = OpParam::GetAttr<bool>("is_test", attrs);
  }
  RType *Output() const { return output_; }

  const RType *InputBias() const { return input_bias_; }

  const RType *InputMean() const { return input_mean_; }

  const RType *InputScale() const { return input_scale_; }

  const RType *InputVariance() const { return input_variance_; }

  const float &Epsilon() const { return epsilon_; }

  const float &Momentum() const { return momentum_; }

  const bool &IsTest() const { return is_test_; }

  void SetNewScale(RType *new_scale) { new_scale_ = new_scale; }

  void SetNewBias(RType *new_bias) { new_bias_ = new_bias; }

  const RType *NewScale() const { return new_scale_; }

  const RType *NewBias() const { return new_bias_; }

 protected:
  RType *output_;
  RType *input_bias_;
  RType *input_mean_;
  RType *input_scale_;
  RType *input_variance_;
  float epsilon_;
  float momentum_;
  bool is_test_;
  RType *new_bias_;
  RType *new_scale_;
};
#endif

#ifdef IM2SEQUENCE_OP
template <typename Dtype>
class Im2SequenceParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  Im2SequenceParam(const VariableNameMap &inputs,
                   const VariableNameMap &outputs, const AttributeMap &attrs,
                   const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    kernels_ = GetAttr<vector<int>>("kernels", attrs);
    strides_ = GetAttr<vector<int>>("strides", attrs);
    paddings_ = GetAttr<vector<int>>("paddings", attrs);
  }

  const GType *Input() const { return input_x_; }

  GType *Output() const { return out_; }

  const vector<int> &Kernels() const { return kernels_; }

  const vector<int> &Strides() const { return strides_; }

  const vector<int> &Paddings() const { return paddings_; }

 private:
  GType *input_x_;
  GType *out_;
  vector<int> kernels_;
  vector<int> strides_;
  vector<int> paddings_;
};
#endif

#ifdef DROPOUT_OP
template <typename Dtype>
class DropoutParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  DropoutParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
               const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);

    dropout_prob_ = GetAttr<float>("dropout_prob", attrs);
  }

  const RType *InputX() const { return input_x_; }

  RType *Out() const { return out_; }

  float DropoutProb() const { return dropout_prob_; }

 private:
  RType *input_x_;
  RType *out_;
  float dropout_prob_;
};
#endif

template <typename Dtype>
class ConvTransposeParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  ConvTransposeParam(const VariableNameMap &inputs,
                     const VariableNameMap &outputs, const AttributeMap &attrs,
                     const Scope &scope) {
    filter_ = FilterFrom<GType>(inputs, scope);
    input_ = InputFrom<GType>(inputs, scope);
    // output_ = OutputFrom<GType>(outputs, scope);
    if (outputs.count("Output")) {
      output_ = OpParam::OutputFrom<GType>(outputs, scope);
    }
    strides_ = GetAttr<vector<int>>("strides", attrs);
    paddings_ = GetAttr<vector<int>>("paddings", attrs);
    dilations_ = GetAttr<vector<int>>("dilations", attrs);
    groups = GetAttr<int>("groups", attrs);
  }

  const RType *Input() const { return input_; }

  const RType *Filter() const { return filter_; }

  RType *Output() const { return output_; }

  const vector<int> &Strides() const { return strides_; }

  const vector<int> &Paddings() const { return paddings_; }

  const vector<int> &Dilations() const { return dilations_; }

  const int &Groups() const { return groups; }

 private:
  RType *input_;
  RType *output_;
  RType *filter_;
  vector<int> strides_;
  vector<int> paddings_;
  vector<int> dilations_;
  int groups;

#ifdef PADDLE_MOBILE_FPGA

 private:
  fpga::DeconvArgs fpga_conv_args;

 public:
  const fpga::DeconvArgs &FpgaArgs() const { return fpga_conv_args; }
  void SetFpgaArgs(const fpga::DeconvArgs &args) { fpga_conv_args = args; }
#endif
};

#ifdef FUSION_DECONVADD_OP
template <typename Dtype>
class FusionDeconvAddParam : public ConvTransposeParam<Dtype> {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  FusionDeconvAddParam(const VariableNameMap &inputs,
                       const VariableNameMap &outputs,
                       const AttributeMap &attrs, const Scope &scope)
      : ConvTransposeParam<Dtype>(inputs, outputs, attrs, scope) {
    bias_ = OpParam::InputYFrom<GType>(inputs, scope);
    axis_ = OpParam::GetAttr<int>("axis", attrs);
    output_ = OpParam::OutFrom<GType>(outputs, scope);
  }
  RType *Bias() const { return bias_; }

  const int &Axis() const { return axis_; }

  RType *Output() const { return output_; }

 protected:
  RType *bias_;
  int axis_;
  RType *output_;
};
#endif

#ifdef FUSION_DECONVADDRELU_OP
template <typename Dtype>
using FusionDeconvAddReluParam = FusionDeconvAddParam<Dtype>;
#endif

#ifdef FUSION_DECONVRELU_OP
template <typename Dtype>
using FusionDeconvReluParam = ConvTransposeParam<Dtype>;
#endif

#ifdef GRU_OP
template <typename Dtype>
class GruParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;

 public:
  /**
   *
   * @param inputs
   * @param outputs
   * @param attrs
   * @param scope
   * */
  GruParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
           const AttributeMap &attrs, const Scope &scope) {
    input_input_ = InputFrom<GType>(inputs, scope);
    input_h0_ = InputH0From<GType>(inputs, scope);
    input_bias_ = InputBiasFrom<GType>(inputs, scope);
    input_weight_ = InputWeightFrom<GType>(inputs, scope);

    output_batch_gate_ = OutputBatchGateFrom<GType>(outputs, scope);
    output_batch_reset_hidden_prev_ =
        OutputBatchResetHiddenPrevFrom<GType>(outputs, scope);
    output_batch_hidden_ = OutputBatchHiddenFrom<GType>(outputs, scope);
    output_hidden_ = OutputHiddenFrom<GType>(outputs, scope);
    activation_ = GetStringAttr("activation", attrs);
    gate_activation_ = GetStringAttr("gate_activation", attrs);
    is_reverse_ = GetAttr<bool>("is_reverse", attrs);
  }
  const GType *InputInput() const { return input_input_; }
  const GType *InputWeight() const { return input_weight_; }
  const GType *InputH0() const { return input_h0_; }
  const GType *InputBias() const { return input_bias_; }
  const std::string &Activation() const { return activation_; }
  const std::string &GateActivation() const { return gate_activation_; }
  const bool &IsReverse() const { return is_reverse_; }

  GType *OutBatchGate() const { return output_batch_gate_; }
  GType *OutBatchResetHiddenPrev() const {
    return output_batch_reset_hidden_prev_;
  }
  GType *OutBatchHidden() const { return output_batch_hidden_; }
  GType *OutHidden() const { return output_hidden_; }

 private:
  GType *input_input_;
  GType *input_h0_;
  GType *input_bias_;
  GType *input_weight_;

  GType *output_batch_gate_;
  GType *output_batch_reset_hidden_prev_;
  GType *output_batch_hidden_;
  GType *output_hidden_;
  std::string activation_;
  std::string gate_activation_;
  bool is_reverse_;
};
#endif

#ifdef FLATTEN_OP
template <typename Dtype>
class FlattenParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  FlattenParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
               const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    axis = GetAttr<int>("axis", attrs);
  }
  const RType *InputX() const { return input_x_; }
  RType *Out() const { return out_; }
  const int &Axis() const { return axis; }

 private:
  RType *input_x_;
  RType *out_;
  int axis;
};
#endif

#ifdef SPLIT_OP
template <typename Dtype>
class SplitParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  SplitParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
             const AttributeMap &attrs, const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    outs_ = OutMultiFrom<GType>(outputs, scope);
    axis = GetAttr<int>("axis", attrs);
    num = GetAttr<int>("num", attrs);
    sections = GetAttr<std::vector<int>>("sections", attrs);

    //    for (int i = 0; i < outs_.size(); ++i) {
    //      out_ts_.push_back(*scope.FindVar(outs_[i])->GetMutable());
    //    }
  }
  const RType *InputX() const { return input_x_; }
  std::vector<GType *> Outs() const { return outs_; }
  int Axis() const { return axis; }
  int Num() const { return num; }
  std::vector<int> Sections() const { return sections; }
  //  std::vector<GType> OutTs() const { return out_ts_; }

 private:
  RType *input_x_;
  std::vector<GType *> outs_;
  int axis;
  int num;
  std::vector<int> sections;
  //  std::vector<GType> out_ts_;
#ifdef PADDLE_MOBILE_FPGA

 private:
  fpga::SplitArgs fpga_split_args;

 public:
  const fpga::SplitArgs &FpgaArgs() const { return fpga_split_args; }
  void SetFpgaArgs(const fpga::SplitArgs &args) { fpga_split_args = args; }
#endif
};
#endif

#ifdef BILINEAR_INTERP_OP
template <typename Dtype>
class BilinearInterpParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  BilinearInterpParam(const VariableNameMap &inputs,
                      const VariableNameMap &outputs, const AttributeMap &attrs,
                      const Scope &scope) {
    input_x_ = InputXFrom<GType>(inputs, scope);
    input_outsize_ = InputOutSizeFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    out_h_ = GetAttr<int>("out_h", attrs);
    out_w_ = GetAttr<int>("out_w", attrs);
  }
  const RType *InputX() const { return input_x_; }
  const RType *InputOutPutSize() const { return input_outsize_; }
  RType *Out() const { return out_; }
  int OutH() const { return out_h_; }
  int OutW() const { return out_w_; }

 private:
  RType *input_x_;
  RType *input_outsize_;
  RType *out_;
  int out_h_;
  int out_w_;
};
#endif

#ifdef SHAPE_OP
template <typename Dtype>
class ShapeParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  ShapeParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
             const AttributeMap &attrs, const Scope &scope) {
    input_ = InputFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
  }
  const RType *Input() const { return input_; }
  RType *Out() const { return out_; }

 private:
  RType *input_;
  RType *out_;
};
#endif

#ifdef QUANT_OP
template <typename Dtype>
class QuantizeParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  QuantizeParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
                const AttributeMap &attrs, const Scope &scope) {
    input_ = InputXFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    // online
    // scale = max(abs(x))
    online_scale_ = GetVarValue<GType>("OutScale", outputs, scope);
    // offline
    if (HasAttr("static_scale", attrs)) {
      is_static_ = true;
      static_scale_ = GetAttr<float>("static_scale", attrs);
    }
    // x = round(scale * x)
    if (HasAttr("round_type", attrs)) {
      round_type_ = GetAttr<RoundType>("round_type", attrs);
    }
  }

 public:
  // op input
  RType *input_;
  // op output
  RType *out_;
  //
  RType *online_scale_;
  // if static scale or not
  bool is_static_ = false;
  // quantize scale
  float static_scale_ = 1.0f;
  // round method type
  // nearest_zero and nearest_even is valid currently
  RoundType round_type_ = ROUND_NEAREST_AWAY_ZERO;
};
#endif

#ifdef DEQUANT_OP
template <typename Dtype>
class DequantizeParam : public OpParam {
  typedef typename DtypeTensorTrait<Dtype>::gtype GType;
  typedef typename DtypeTensorTrait<Dtype>::rtype RType;

 public:
  DequantizeParam(const VariableNameMap &inputs, const VariableNameMap &outputs,
                  const AttributeMap &attrs, const Scope &scope) {
    input_ = InputXFrom<GType>(inputs, scope);
    out_ = OutFrom<GType>(outputs, scope);
    activation_scale_ = GetVarValue<GType>("Scale", inputs, scope);
    // dequantization is performed as x = x / static_scale / online_scale
    if (HasAttr("weight_scale", attrs)) {
      weight_scale_ = GetAttr<float>("weight_scale", attrs);
    } else {
      weight_scale_ = GetAttr<float>("max_range", attrs);
    }
  }

 public:
  // op input
  RType *input_;
  // op output
  RType *out_;
  RType *activation_scale_;
  float weight_scale_;
};
#endif

}  // namespace operators
}  // namespace paddle_mobile
