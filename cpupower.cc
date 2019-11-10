#include <node.h>
#include <node_buffer.h>
#include <nan.h>

#include "cpupower/yespower.h"

#define THROW_ERROR_EXCEPTION(x) Nan::ThrowError(x)

using v8::Exception;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void hash(const Nan::FunctionCallbackInfo<Value>& args) {

    if(args.Length() < 1) {
        Nan::ThrowTypeError("1 argument expected");
        return;
    }

    Local<Object> target = args[0]->ToObject();

    if(!node::Buffer::HasInstance(target)) {
        Nan::ThrowTypeError("Function expects buffer as input");
        return;
    }

    char* input = node::Buffer::Data(target);
    char* output = new char[32];

    yespower_hash(input, output);

    args.GetReturnValue().Set(Nan::NewBuffer(output, 32).ToLocalChecked());
}

void Init(v8::Local<v8::Object> exports) {
    exports->Set(Nan::New("hash").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(hash)->GetFunction());
}

NODE_MODULE(cpupower, Init);
