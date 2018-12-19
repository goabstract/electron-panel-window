#import <CoreServices/CoreServices.h>
#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import <objc/objc-runtime.h>

#include "functions.h"

@interface PROPanel : NSPanel
@end

@implementation PROPanel
- (BOOL)needsPanelToBecomeKey {
  return YES;
}
- (BOOL)acceptsFirstResponder {
  return YES;
}
@end

NAN_METHOD(MakePanel) {
  v8::Local<v8::Object> handleBuffer = info[0].As<v8::Object>();
  v8::Isolate* isolate = info.GetIsolate();
  v8::HandleScope scope(isolate);

  char* buffer = node::Buffer::Data(handleBuffer);
  NSView* mainContentView = *reinterpret_cast<NSView**>(buffer);

  if (!mainContentView)
      return info.GetReturnValue().Set(false);

  NSWindow* window = mainContentView.window;

  // Convert the NSWindow class to NSPanel
  object_setClass(window, [PROPanel class]);

  // Ensure that the window is a "non activating panel" which means it won't activate the application
  // when it becomes key.
  window.styleMask |= NSWindowStyleMaskNonactivatingPanel;
  window.styleMask |= NSWindowStyleMaskFullSizeContentView;
  

  // Ensure that the window can display over the top of fullscreen apps
  [window setCollectionBehavior: NSWindowCollectionBehaviorTransient | NSWindowCollectionBehaviorMoveToActiveSpace | NSWindowCollectionBehaviorFullScreenAuxiliary ];
  [window setLevel:NSFloatingWindowLevel];
  [window setFloatingPanel:YES];

  // Hide the traffic light controls
  [[window standardWindowButton:NSWindowCloseButton] setHidden:YES];
  [[window standardWindowButton:NSWindowMiniaturizeButton] setHidden:YES];
  [[window standardWindowButton:NSWindowZoomButton] setHidden:YES];

  return info.GetReturnValue().Set(true);
}

NAN_METHOD(MakeKeyWindow) {
  v8::Local<v8::Object> handleBuffer = info[0].As<v8::Object>();
  v8::Isolate* isolate = info.GetIsolate();
  v8::HandleScope scope(isolate);

  char* buffer = node::Buffer::Data(handleBuffer);
  NSView* mainContentView = *reinterpret_cast<NSView**>(buffer);

  if (!mainContentView)
      return info.GetReturnValue().Set(false);

  [mainContentView.window makeKeyWindow];
  return info.GetReturnValue().Set(true);
}