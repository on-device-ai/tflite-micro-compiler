# tflite-micro-compiler  
I reorganized the code of the [TensorFlow Lite for Microcontrollers](https://www.tensorflow.org/lite/microcontrollers) and the [tflite\_micro\_compiler](https://github.com/cpetig/tflite_micro_compiler) project for study.  

### Generate library  
Follow the instructions in "[Generate projects for other platforms](https://www.tensorflow.org/lite/microcontrollers/library)" to generate the library. The steps are as follows:  
`git clone -b r2.3 https://github.com/tensorflow/tensorflow.git`  
`cd tensorflow/`  
`make -f tensorflow/lite/micro/tools/make/Makefile generate_projects`  
The final result is in the tflite-micro directory of this project.  
  
### Build hello\_world example (original)  
Build and execute the hello\_world example steps are as follows:  
`cd tflite-micro-compiler/hello_world_original/`  
`make`  
`./hello_world`  
`cd -`  
  
### Build tflite\_micro\_compiler  
Build the "compiler"  steps are as follows:  
`cd tflite-micro-compiler/compiler/`  
`make`  
`cd -`  
After the build is complete, compile the tflite model file to C++ code with the following command:
`cd tflite-micro-compiler/models/`  
`../compiler/compiler model.tflite hello_compiled.cpp hello_`  
`cd -`  
After that, please change the file extension of C++ program from cpp to cc.  
  
### Build hello\_world example (compile)
Build and execute the hello\_world example steps are as follows:  
`cd tflite-micro-compiler/hello_world_compile/`  
`make`  
`./hello_world`  
`cd -`  

