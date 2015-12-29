# Motivation
Extending Python with C++ is typically a painful process.  It doesn't have to be.  Tools
such as `runcython` and `protobuf` make it easy to pass structured data from Python to C++ 
and gain massive performance improvements.   Google's `protobuf` library encourages simple and 
maintanable interfaces between Python and C++ via fast serialization and deserialization of binary
messages.  The `runcython` command line utility considerably simplifies the build process for 
`Cython`, a static compiler for Python/Cython that makes wrapping C++ libraries a breeze.  

In this example we pass an ObjectList protobuf message to a C++ function that prints its contents
and returns the number of elements in the list.  Each element in the ObjectList message is an Object 
message with two fields: `name` and `id`.

# Usage
First, you need to install the following packages:
1.  protobuf (https://developers.google.com/protocol-buffers/?hl=en)
2.  runcython (https://github.com/Russell91/runcython)

Compile protobuf definition file for use by C++ and Python: 
```
$ protoc -I=./ --python_out=./ --cpp_out=./ objlist.proto
```

Run Cython file: 
```
$ runcython++ use_objlist.pyx '' "objlist.cpp objlist.pb.cc -lprotobuf"
```
