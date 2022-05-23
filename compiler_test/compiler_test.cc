#include <iostream>
#include "tensorflow/lite/c/common.h"
#include "tensorflow/lite/kernels/internal/tensor_ctypes.h"
#include "hello_compiled.h"

void test_compiled(void) {
	hello_init();
	tflite::GetTensorData<float>(hello_input(0))[0]= 1.57f;
	hello_invoke();
	float out = tflite::GetTensorData<float>(hello_output(0))[0];
	std::cerr << "compiled result " << out << std::endl;
}

int main(int argc, char** argv) {
	test_compiled();
	return 0;
}