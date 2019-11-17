// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from opencv.djinni

#import "HWOpencv+Private.h"
#import "HWOpencv.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#include <exception>
#include <stdexcept>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface HWOpencv ()

- (id)initWithCpp:(const std::shared_ptr<::opencv::Opencv>&)cppRef;

@end

@implementation HWOpencv {
    ::djinni::CppProxyCache::Handle<std::shared_ptr<::opencv::Opencv>> _cppRefHandle;
}

- (id)initWithCpp:(const std::shared_ptr<::opencv::Opencv>&)cppRef
{
    if (self = [super init]) {
        _cppRefHandle.assign(cppRef);
    }
    return self;
}

+ (nullable HWOpencv *)create {
    try {
        auto objcpp_result_ = ::opencv::Opencv::create();
        return ::djinni_generated::Opencv::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)getCanny {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_canny();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)getThreshold {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_threshold();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)getLines {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_lines();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)getContours {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_contours();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)getSegments {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_segments();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (nonnull NSString *)getRoundContours {
    try {
        auto objcpp_result_ = _cppRefHandle.get()->get_round_contours();
        return ::djinni::String::fromCpp(objcpp_result_);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

namespace djinni_generated {

auto Opencv::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc->_cppRefHandle.get();
}

auto Opencv::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::get_cpp_proxy<HWOpencv>(cpp);
}

}  // namespace djinni_generated

@end