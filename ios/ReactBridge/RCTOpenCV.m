#import "RCTOpenCV.h"
#import "HWOpencv.h"
@implementation RCTOpenCV{
  HWOpencv *_cppApi;
}
- (RCTOpenCV *)init
{
  self = [super init];
  _cppApi = [HWOpencv create];
  return self;
}
+ (BOOL)requiresMainQueueSetup
{
  return NO;
}
RCT_EXPORT_MODULE();
RCT_REMAP_METHOD(getCanny,
                 path:(NSString *)path
                 resolver:(RCTPromiseResolveBlock)resolve
                 rejecter:(RCTPromiseRejectBlock)reject)
{
  NSString *response = [_cppApi getCanny:path];
  resolve(response);
}

RCT_REMAP_METHOD(getThreshold,
                path1:(NSString *)path
                get_resolver:(RCTPromiseResolveBlock)resolve
                get_rejecter:(RCTPromiseRejectBlock)reject)
{
  NSString *response = [_cppApi getThreshold:path];
  resolve(response);
}

RCT_REMAP_METHOD(getLines,
                 path1:(NSString *)path
                 get_resolver1:(RCTPromiseResolveBlock)resolve
                 get_rejecter1:(RCTPromiseRejectBlock)reject)
{
  NSString *response = [_cppApi getLines:path];
  resolve(response);
}

RCT_REMAP_METHOD(getContours,
                 path1:(NSString *)path
                 get_resolver2:(RCTPromiseResolveBlock)resolve
                 get_rejecter2:(RCTPromiseRejectBlock)reject)
{
  NSString *response = [_cppApi getContours:path];
  resolve(response);
}

RCT_REMAP_METHOD(getSegments,
                 path1:(NSString *)path
                 get_resolver3:(RCTPromiseResolveBlock)resolve
                 get_rejecter3:(RCTPromiseRejectBlock)reject)
{
  NSString *response = [_cppApi getSegments:path];
  resolve(response);
}

RCT_REMAP_METHOD(getRoundContours,
                 path1:(NSString *)path
                 get_resolver4:(RCTPromiseResolveBlock)resolve
                 get_rejecter4:(RCTPromiseRejectBlock)reject)
{
  NSString *response = [_cppApi getRoundContours:path];
  resolve(response);
}

@end
