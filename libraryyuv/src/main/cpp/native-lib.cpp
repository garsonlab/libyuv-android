//
// Created by DELL on 2018/3/26.
//

#include <jni.h>
#include <string>
#include "libyuv.h"

extern "C" {

    JNIEXPORT
    JNICALL
    void Java_org_android_opensource_libraryyuv_Libyuv_ARGBToNV21(
            JNIEnv *env, jclass *jcls,
            jbyteArray src_frame, jint src_stride_frame,
            jint width, jint height,
            jbyteArray yBuffer, jbyteArray uvBuffer) {

        uint8_t* srcFrame = (uint8_t*) env->GetByteArrayElements(src_frame, 0);

        uint8_t* dst_y=(uint8_t*) env->GetByteArrayElements(yBuffer, 0);
        uint8_t* dst_uv=(uint8_t*) env->GetByteArrayElements(uvBuffer, 0);


        libyuv::ARGBToNV21(srcFrame, src_stride_frame,
                           dst_y, width,
                           dst_uv, width, width, height);

        //remember release
        env->ReleaseByteArrayElements(src_frame, (jbyte*)srcFrame, 0);
        env->ReleaseByteArrayElements(yBuffer, (jbyte*)dst_y, 0);
        env->ReleaseByteArrayElements(uvBuffer, (jbyte*)dst_uv, 0);
    }

    JNIEXPORT void
    JNICALL
    Java_org_android_opensource_libraryyuv_Libyuv_NV21ToARGB(
            JNIEnv *env, jclass *jcls,
            jbyteArray yBuffer,jint y_stride,
            jbyteArray uvBuffer,jint uv_stride,
            jbyteArray dstARGB,jint dst_stride_argb,
            jint width, jint height) {

        uint8_t* src_y=(uint8_t*) env->GetByteArrayElements(yBuffer, 0);
        uint8_t* src_uv=(uint8_t*) env->GetByteArrayElements(uvBuffer, 0);
        uint8_t* dst_argb = (uint8_t*) env->GetByteArrayElements(dstARGB, 0);

        libyuv::NV21ToARGB(src_y, y_stride, src_uv, uv_stride, dst_argb, dst_stride_argb, width, height);

        //remember release
        env->ReleaseByteArrayElements(dstARGB, (jbyte*)dst_argb, 0);
        env->ReleaseByteArrayElements(yBuffer, (jbyte*)src_y, 0);
        env->ReleaseByteArrayElements(uvBuffer, (jbyte*)src_uv, 0);

    }

JNIEXPORT
JNICALL
void Java_org_android_opensource_libraryyuv_Libyuv_RGBAToARGB(
        JNIEnv *env, jclass *jcls,
        jbyteArray srcBuffer,jint src_stride_frame,
        jbyteArray dstBuffer, jint dst_stride_argb,
        jint width, jint height) {

    uint8_t* src_frame = (uint8_t*) env->GetByteArrayElements(srcBuffer, 0);
    uint8_t* dst_argb = (uint8_t*) env->GetByteArrayElements(dstBuffer, 0);

    libyuv::RGBAToARGB(src_frame,src_stride_frame, dst_argb,dst_stride_argb, width, height);

    //remember release
    env->ReleaseByteArrayElements(srcBuffer, (jbyte*)src_frame, 0);
    env->ReleaseByteArrayElements(dstBuffer, (jbyte*)dst_argb, 0);
}

JNIEXPORT
JNICALL
void Java_org_android_opensource_libraryyuv_Libyuv_ABGRToI420(
    JNIEnv *env, jclass *jcls,
    jbyteArray src_buffer, jint src_stride_frame,
    jbyteArray dst_yBuffer, jint dst_stride_y,
    jbyteArray dst_uBuffer, jint dst_stride_u,
    jbyteArray dst_vBuffer, jint dst_stride_v,
    jint width, jint height) {
    
    uint8_t* src_frame = (uint8_t*) env->GetByteArrayElements(src_buffer, 0);
    uint8_t* dst_y = (uint8_t*) env->GetByteArrayElements(dst_yBuffer, 0);
    uint8_t* dst_u = (uint8_t*) env->GetByteArrayElements(dst_uBuffer, 0);
    uint8_t* dst_v = (uint8_t*) env->GetByteArrayElements(dst_vBuffer, 0);
    
    libyuv::ABGRToI420(src_frame,src_stride_frame, dst_y, dst_stride_y, dst_u, dst_stride_u, dst_v, dst_stride_v, width, height);
    
    //remember release
    env->ReleaseByteArrayElements(src_buffer, (jbyte*)src_frame, 0);
    env->ReleaseByteArrayElements(dst_yBuffer, (jbyte*)dst_y, 0);
    env->ReleaseByteArrayElements(dst_uBuffer, (jbyte*)dst_u, 0);
    env->ReleaseByteArrayElements(dst_vBuffer, (jbyte*)dst_v, 0);
}

}
