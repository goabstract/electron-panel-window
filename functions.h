#ifndef NATIVE_EXTENSION_GRAB_H
#define NATIVE_EXTENSION_GRAB_H

#include <nan.h>

NAN_METHOD(MakePanel);
NAN_METHOD(MakeKeyWindow);

// Example with node ObjectWrap
// Based on https://nodejs.org/api/addons.html#addons_wrapping_c_objects but using NAN
// class MyObject : public Nan::ObjectWrap {
//   public:
//     static NAN_MODULE_INIT(Init);

//   private:
//     explicit MyObject(double value = 0);
//     ~MyObject();

//     // static NAN_METHOD(New);
//     // static NAN_METHOD(PlusOne);
//     // static Nan::Persistent<v8::Function> constructor;
//     // double value_;
// };

#endif
