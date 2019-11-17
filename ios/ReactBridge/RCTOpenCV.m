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
                 resolver:(RCTPromiseResolveBlock)resolve
                 rejecter:(RCTPromiseRejectBlock)reject)
{
  NSString *response = [_cppApi getCanny];
  resolve(response);
}

RCT_REMAP_METHOD(getThreshold,
                get_resolver:(RCTPromiseResolveBlock)resolve
                get_rejecter:(RCTPromiseRejectBlock)reject)
{
 NSString *response = [_cppApi getThreshold];
 resolve(response);
}

RCT_REMAP_METHOD(getLines,
                 get_resolver1:(RCTPromiseResolveBlock)resolve
                 get_rejecter1:(RCTPromiseRejectBlock)reject)
{
  NSString *response = [_cppApi getLines];
  resolve(response);
}

RCT_REMAP_METHOD(getContours,
                 get_resolver2:(RCTPromiseResolveBlock)resolve
                 get_rejecter2:(RCTPromiseRejectBlock)reject)
{
  NSString *response = [_cppApi getContours];
  resolve(response);
}

RCT_REMAP_METHOD(getSegments,
                 get_resolver3:(RCTPromiseResolveBlock)resolve
                 get_rejecter3:(RCTPromiseRejectBlock)reject)
{
  NSString *response = [_cppApi getSegments];
  resolve(response);
}

RCT_REMAP_METHOD(getRoundContours,
                 get_resolver4:(RCTPromiseResolveBlock)resolve
                 get_rejecter4:(RCTPromiseRejectBlock)reject)
{
  NSString *response = [_cppApi getRoundContours];
  resolve(response);
}

@end
