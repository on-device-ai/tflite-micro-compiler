TARGET_TOOLCHAIN_ROOT := 
TARGET_TOOLCHAIN_PREFIX := 

# These are microcontroller-specific rules for converting the ELF output
# of the linker into a binary image that can be loaded directly.
CXX             := '$(TARGET_TOOLCHAIN_ROOT)$(TARGET_TOOLCHAIN_PREFIX)g++'
CC              := '$(TARGET_TOOLCHAIN_ROOT)$(TARGET_TOOLCHAIN_PREFIX)gcc'
AS              := '$(TARGET_TOOLCHAIN_ROOT)$(TARGET_TOOLCHAIN_PREFIX)as'
AR              := '$(TARGET_TOOLCHAIN_ROOT)$(TARGET_TOOLCHAIN_PREFIX)ar' 
LD              := '$(TARGET_TOOLCHAIN_ROOT)$(TARGET_TOOLCHAIN_PREFIX)ld'
NM              := '$(TARGET_TOOLCHAIN_ROOT)$(TARGET_TOOLCHAIN_PREFIX)nm'
OBJDUMP         := '$(TARGET_TOOLCHAIN_ROOT)$(TARGET_TOOLCHAIN_PREFIX)objdump'
OBJCOPY         := '$(TARGET_TOOLCHAIN_ROOT)$(TARGET_TOOLCHAIN_PREFIX)objcopy'
SIZE            := '$(TARGET_TOOLCHAIN_ROOT)$(TARGET_TOOLCHAIN_PREFIX)size'

RM = rm -f
ARFLAGS := -csr

SRCS := \
../tflite-micro/tensorflow/lite/micro/simple_memory_allocator.cc ../tflite-micro/tensorflow/lite/micro/memory_helpers.cc ../tflite-micro/tensorflow/lite/micro/test_helpers.cc ../tflite-micro/tensorflow/lite/micro/recording_micro_allocator.cc ../tflite-micro/tensorflow/lite/micro/micro_error_reporter.cc ../tflite-micro/tensorflow/lite/micro/micro_time.cc ../tflite-micro/tensorflow/lite/micro/recording_simple_memory_allocator.cc ../tflite-micro/tensorflow/lite/micro/micro_string.cc ../tflite-micro/tensorflow/lite/micro/micro_profiler.cc ../tflite-micro/tensorflow/lite/micro/micro_utils.cc ../tflite-micro/tensorflow/lite/micro/debug_log.cc ../tflite-micro/tensorflow/lite/micro/micro_optional_debug_tools.cc ../tflite-micro/tensorflow/lite/micro/all_ops_resolver.cc ../tflite-micro/tensorflow/lite/micro/micro_interpreter.cc ../tflite-micro/tensorflow/lite/micro/micro_allocator.cc ../tflite-micro/tensorflow/lite/micro/benchmarks/keyword_scrambled_model_data.cc ../tflite-micro/tensorflow/lite/micro/kernels/logistic.cc ../tflite-micro/tensorflow/lite/micro/kernels/circular_buffer.cc ../tflite-micro/tensorflow/lite/micro/kernels/conv.cc ../tflite-micro/tensorflow/lite/micro/kernels/prelu.cc ../tflite-micro/tensorflow/lite/micro/kernels/softmax.cc ../tflite-micro/tensorflow/lite/micro/kernels/dequantize.cc ../tflite-micro/tensorflow/lite/micro/kernels/pad.cc ../tflite-micro/tensorflow/lite/micro/kernels/ethosu.cc ../tflite-micro/tensorflow/lite/micro/kernels/l2norm.cc ../tflite-micro/tensorflow/lite/micro/kernels/resize_nearest_neighbor.cc ../tflite-micro/tensorflow/lite/micro/kernels/tanh.cc ../tflite-micro/tensorflow/lite/micro/kernels/activations.cc ../tflite-micro/tensorflow/lite/micro/kernels/ceil.cc ../tflite-micro/tensorflow/lite/micro/kernels/arg_min_max.cc ../tflite-micro/tensorflow/lite/micro/kernels/fully_connected.cc ../tflite-micro/tensorflow/lite/micro/kernels/add.cc ../tflite-micro/tensorflow/lite/micro/kernels/split.cc ../tflite-micro/tensorflow/lite/micro/kernels/round.cc ../tflite-micro/tensorflow/lite/micro/kernels/pack.cc ../tflite-micro/tensorflow/lite/micro/kernels/floor.cc ../tflite-micro/tensorflow/lite/micro/kernels/unpack.cc ../tflite-micro/tensorflow/lite/micro/kernels/svdf.cc ../tflite-micro/tensorflow/lite/micro/kernels/sub.cc ../tflite-micro/tensorflow/lite/micro/kernels/pooling.cc ../tflite-micro/tensorflow/lite/micro/kernels/concatenation.cc ../tflite-micro/tensorflow/lite/micro/kernels/neg.cc ../tflite-micro/tensorflow/lite/micro/kernels/quantize.cc ../tflite-micro/tensorflow/lite/micro/kernels/mul.cc ../tflite-micro/tensorflow/lite/micro/kernels/maximum_minimum.cc ../tflite-micro/tensorflow/lite/micro/kernels/reshape.cc ../tflite-micro/tensorflow/lite/micro/kernels/reduce.cc ../tflite-micro/tensorflow/lite/micro/kernels/strided_slice.cc ../tflite-micro/tensorflow/lite/micro/kernels/logical.cc ../tflite-micro/tensorflow/lite/micro/kernels/elementwise.cc ../tflite-micro/tensorflow/lite/micro/kernels/comparisons.cc ../tflite-micro/tensorflow/lite/micro/kernels/depthwise_conv.cc ../tflite-micro/tensorflow/lite/micro/memory_planner/linear_memory_planner.cc ../tflite-micro/tensorflow/lite/micro/memory_planner/greedy_memory_planner.cc ../tflite-micro/tensorflow/lite/micro/testing/test_conv_model.cc ../tflite-micro/tensorflow/lite/c/common.c ../tflite-micro/tensorflow/lite/core/api/error_reporter.cc ../tflite-micro/tensorflow/lite/core/api/flatbuffer_conversions.cc ../tflite-micro/tensorflow/lite/core/api/op_resolver.cc ../tflite-micro/tensorflow/lite/core/api/tensor_utils.cc ../tflite-micro/tensorflow/lite/kernels/internal/quantization_util.cc ../tflite-micro/tensorflow/lite/kernels/kernel_util.cc ../tflite-micro/tensorflow/lite/micro/testing/test_utils.cc
SRCS += \
main.cc main_functions.cc model.cc output_handler.cc constants.cc 

OBJS := \
$(patsubst %.cc,%.o,$(patsubst %.c,%.o,$(SRCS)))

CXXFLAGS += -std=c++11 -DTF_LITE_STATIC_MEMORY -DNDEBUG -O3 -DTF_LITE_DISABLE_X86_NEON -I../tflite-micro -I../tflite-micro/third_party/gemmlowp -I../tflite-micro/third_party/flatbuffers/include -I../tflite-micro/third_party/ruy -I../tflite-micro/third_party/kissfft
CCFLAGS +=  -std=c11   -DTF_LITE_STATIC_MEMORY -DNDEBUG -O3 -DTF_LITE_DISABLE_X86_NEON -I../tflite-micro -I../tflite-micro/third_party/gemmlowp -I../tflite-micro/third_party/flatbuffers/include -I../tflite-micro/third_party/ruy -I../tflite-micro/third_party/kissfft

LDFLAGS +=  -lm

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.c
	$(CC) $(CCFLAGS) $(INCLUDES) -c $< -o $@

hello_world : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

all: hello_world

clean:
	-$(RM) $(OBJS)
	-$(RM) hello_world