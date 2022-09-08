#pragma once

#include "include_opencv.h"
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/cudafilters.hpp>
#include <opencv2/cudaarithm.hpp>
#include <opencv2/cudawarping.hpp>

// ReSharper disable IdentifierTypo
// ReSharper disable CppInconsistentNaming
// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile

CVAPI(ExceptionStatus) photo_createCalibrateDebevec(
    int samples, float lambda, int random, cv::Ptr<cv::CalibrateDebevec> **returnValue) 
{
    BEGIN_WRAP
    *returnValue = clone(cv::createCalibrateDebevec(samples, lambda, random != 0));
    END_WRAP
}

CVAPI(ExceptionStatus) photo_Ptr_CalibrateDebevec_delete(cv::Ptr<cv::CalibrateDebevec> *obj)
{
    BEGIN_WRAP
    delete obj;
    END_WRAP
}

CVAPI(ExceptionStatus) photo_Ptr_CalibrateDebevec_get(cv::Ptr<cv::CalibrateDebevec> *obj, cv::CalibrateDebevec **returnValue)
{
    BEGIN_WRAP
    *returnValue = obj->get();
    END_WRAP
}

CVAPI(ExceptionStatus) photo_CalibrateDebevec_getLambda(cv::CalibrateDebevec *obj, float *returnValue)
{
    BEGIN_WRAP
    *returnValue = obj->getLambda();
    END_WRAP
}
CVAPI(ExceptionStatus) photo_CalibrateDebevec_setLambda(cv::CalibrateDebevec *obj, float value)
{
    BEGIN_WRAP
    obj->setLambda(value);
    END_WRAP
}

CVAPI(ExceptionStatus) photo_CalibrateDebevec_getSamples(cv::CalibrateDebevec *obj, float *returnValue)
{
    BEGIN_WRAP
    *returnValue = obj->getLambda();
    END_WRAP
}
CVAPI(ExceptionStatus) photo_CalibrateDebevec_setSamples(cv::CalibrateDebevec *obj, float value)
{
    BEGIN_WRAP
    obj->setLambda(value);
    END_WRAP
}

CVAPI(ExceptionStatus) photo_CalibrateDebevec_getRandom(cv::CalibrateDebevec *obj, int *returnValue)
{
    BEGIN_WRAP
    *returnValue = obj->getRandom() ? 1 : 0;
    END_WRAP
}
CVAPI(ExceptionStatus) photo_CalibrateDebevec_setRandom(cv::CalibrateDebevec *obj, int value)
{
    BEGIN_WRAP
    obj->setRandom(value != 0);
    END_WRAP
}

CVAPI(ExceptionStatus) photo_createCalibrateRobertson(
    int max_iter, float threshold, cv::Ptr<cv::CalibrateRobertson> **returnValue)
{
    BEGIN_WRAP
    *returnValue = clone(cv::createCalibrateRobertson(max_iter, threshold));
    END_WRAP
}

CVAPI(ExceptionStatus) photo_Ptr_CalibrateRobertson_delete(cv::Ptr<cv::CalibrateRobertson> *obj)
{
    BEGIN_WRAP
    delete obj;
    END_WRAP
}

CVAPI(ExceptionStatus) photo_Ptr_CalibrateRobertson_get(cv::Ptr<cv::CalibrateRobertson> *obj, cv::CalibrateRobertson **returnValue)
{
    BEGIN_WRAP
    *returnValue = obj->get();
    END_WRAP
}

CVAPI(ExceptionStatus) photo_CalibrateRobertson_getMaxIter(cv::CalibrateRobertson *obj, int *returnValue)
{
    BEGIN_WRAP
    *returnValue = obj->getMaxIter();
    END_WRAP
}
CVAPI(ExceptionStatus) photo_CalibrateRobertson_setMaxIter(cv::CalibrateRobertson *obj, int value)
{
    BEGIN_WRAP
    obj->setMaxIter(value);
    END_WRAP
}

CVAPI(ExceptionStatus) photo_CalibrateRobertson_getThreshold(cv::CalibrateRobertson *obj, float *returnValue)
{
    BEGIN_WRAP
    *returnValue = obj->getThreshold();
    END_WRAP
}
CVAPI(ExceptionStatus) photo_CalibrateRobertson_setThreshold(cv::CalibrateRobertson *obj, float value)
{
    BEGIN_WRAP
    obj->setThreshold(value);
    END_WRAP
}

CVAPI(ExceptionStatus) photo_CalibrateRobertson_getRadiance(cv::CalibrateRobertson *obj, cv::Mat *returnValue)
{
    BEGIN_WRAP
    obj->getRadiance().copyTo(*returnValue);
    END_WRAP
}


CVAPI(ExceptionStatus) photo_CalibrateCRF_process(
    cv::CalibrateCRF *obj, 
    cv::Mat ** srcImgs, int srcImgsLength, cv::_OutputArray *dst, float* times)
{
    BEGIN_WRAP

    // Build Mat Vector of images
    std::vector<cv::Mat> srcImgsVec(srcImgsLength);

    // Build float Vector of times
    std::vector<float> times_vec(srcImgsLength);
    
    for (int i = 0; i < srcImgsLength; i++) {
        srcImgsVec[i] = *srcImgs[i];
        times_vec[i] = times[i];
    }

    obj->process(srcImgsVec, *dst, times_vec);
    END_WRAP
}

// TODO Exception Handling

CVAPI(cv::Ptr<cv::MergeDebevec>*) photo_createMergeDebevec()
{
    return clone(cv::createMergeDebevec());
}
CVAPI(void) photo_Ptr_MergeDebevec_delete(cv::Ptr<cv::MergeDebevec>* obj)
{
    delete obj;
}
CVAPI(cv::MergeDebevec*) photo_Ptr_MergeDebevec_get(cv::Ptr<cv::MergeDebevec>* obj)
{
    return obj->get();
}

CVAPI(cv::Ptr<cv::MergeMertens>*) photo_createMergeMertens()
{
    return clone(cv::createMergeMertens());
}
CVAPI(void) photo_Ptr_MergeMertens_delete(cv::Ptr<cv::MergeMertens>* obj)
{
    delete obj;
}
CVAPI(cv::MergeMertens*) photo_Ptr_MergeMertens_get(cv::Ptr<cv::MergeMertens>* obj)
{
    return obj->get();
}

CVAPI(void) photo_MergeExposures_process(
    cv::MergeExposures* obj,
    cv::Mat** srcImgs, int srcImgsLength, cv::_OutputArray* dst, float* times, cv::_InputArray* response)
{
    // Build Mat Vector of images
    std::vector<cv::Mat> srcImgsVec(srcImgsLength);

    // Build float Vector of times
    std::vector<float> times_vec(srcImgsLength);

    for (int i = 0; i < srcImgsLength; i++) {
        srcImgsVec[i] = *srcImgs[i];
        times_vec[i] = times[i];
    }

    obj->process(srcImgsVec, *dst, times_vec, *response);
}



CVAPI(void) photo_MergeMertens_process(
    cv::MergeMertens* obj,
    cv::Mat** srcImgs, int srcImgsLength, cv::_OutputArray* dst)
{
    // Build Mat Vector of images
    std::vector<cv::Mat> srcImgsVec(srcImgsLength);

    for (int i = 0; i < srcImgsLength; i++) 
    {
        srcImgsVec[i] = *srcImgs[i];
    }

    obj->process(srcImgsVec, *dst);
}

void MergeMertens(std::vector<cv::cuda::GpuMat> images, cv::OutputArray dst, float wcon, float wsat, float wexp);
CVAPI(void) photo_MergeMertens_processg(cv::MergeMertens* obj,cv::Mat** srcImgs, int srcImgsLength, cv::_OutputArray* dst)
{
    // Build Mat Vector of images
    std::vector<cv::cuda::GpuMat> srcImgsVec(srcImgsLength);

    for (int i = 0; i < srcImgsLength; i++)
    {
        srcImgsVec[i] = cv::cuda::GpuMat(*srcImgs[i]);
    }

    // obj->process(srcImgsVec, *dst);
    MergeMertens(srcImgsVec, *dst, obj->getContrastWeight(), obj->getSaturationWeight(), obj->getExposureWeight());
}

void buildPyramid(cv::cuda::GpuMat src, std::vector<cv::cuda::GpuMat> &dst, int maxlevel)
{
    dst[0] = src;
    for (int i = 1; i <= maxlevel; i++)
        cv::cuda::pyrDown(dst[i - 1], dst[i]);
    return;
}

void pyrUp(cv::cuda::GpuMat src, cv::cuda::GpuMat &dst, cv::Size size)
{
    if (!size.empty() && (src.size().width * 2 != size.width || src.size().height * 2 != size.height))
    {
        cv::cuda::GpuMat temp;
        cv::cuda::pyrUp(src, temp);
        cv::cuda::copyMakeBorder(temp, dst, 0, size.height - temp.rows, 0, size.width - temp.cols, CV_HAL_BORDER_REPLICATE);
    }
    else
    {
        cv::cuda::pyrUp(src, dst);
    }
}

void MergeMertens(std::vector<cv::cuda::GpuMat> images, cv::OutputArray dst, float wcon, float wsat, float wexp)
{
    int channels = images[0].channels();
    CV_Assert(channels == 1 || channels == 3);
    cv::Size size = images[0].size();
    int CV_32FCC = CV_MAKETYPE(CV_32F, channels);

    std::vector<cv::cuda::GpuMat> weights(images.size());
    cv::cuda::GpuMat weight_sum = cv::cuda::GpuMat(size, CV_32F,cv::Scalar(0));

    cv::Ptr<cv::cuda::Filter> lapFilter = cv::cuda::createLaplacianFilter(CV_32F, CV_32F);

    for (size_t i = 0; i < images.size(); i++) 
    {
        cv::cuda::GpuMat img, gray, contrast, saturation, wellexp;
        std::vector<cv::cuda::GpuMat> splitted(channels);

        images[i].convertTo(img, CV_32F, 1.0f / 255.0f);
        if (channels == 3) 
        {
            cv::cuda::cvtColor(img, gray, cv::COLOR_RGB2GRAY);
        }
        else 
        {
            img.copyTo(gray);
        }
        cv::cuda::split(img, splitted);
        lapFilter->apply(gray, contrast);
        // cv::Laplacian(gray, contrast, CV_32F);
        cv::cuda::abs(contrast,contrast);

        cv::cuda::GpuMat mean = cv::cuda::GpuMat(size, CV_32F,cv::Scalar(0));
        for (int c = 0; c < channels; c++) 
        {
            cv::cuda::add(mean,splitted[c],mean);
        }
        cv::cuda::divide(mean,channels,mean);

        saturation = cv::cuda::GpuMat(size, CV_32F,cv::Scalar(0));
        cv::cuda::GpuMat deviation = cv::cuda::GpuMat(size, CV_32F);
        for (int c = 0; c < channels; c++) 
        {
            cv::cuda::subtract(splitted[c],mean,deviation);
            // cv::cuda::pow(deviation, 2.0f, deviation);
            cv::cuda::multiply(deviation, deviation, deviation);
            cv::cuda::add(saturation,deviation,saturation);
        }
        cv::cuda::sqrt(saturation, saturation);

        wellexp = cv::cuda::GpuMat(size, CV_32F,cv::Scalar(1));
        cv::cuda::GpuMat expo = cv::cuda::GpuMat(size, CV_32F);
        float a = -1.0f / 0.08f;
        for (int c = 0; c < channels; c++) 
        {
            cv::cuda::subtract(splitted[c],0.5f,expo);
            /*cv::cuda::pow(expo, 2.0, expo);
            cv::cuda::divide(expo, -0.08, expo);*/
            cv::cuda::multiply(expo, expo, expo);
            cv::cuda::multiply(expo,a,expo);
            cv::cuda::exp(expo, expo);
            cv::cuda::multiply(wellexp,expo,wellexp);
        }

        cv::cuda::pow(contrast, wcon, contrast);
        cv::cuda::pow(saturation, wsat, saturation);
        cv::cuda::pow(wellexp, wexp, wellexp);

        weights[i] = contrast;
        if (channels == 3) 
        {
            cv::cuda::multiply(weights[i],saturation, weights[i]);
        }
        cv::cuda::multiply(weights[i], wellexp, weights[i]);
        cv::cuda::add(weights[i],1e-12f, weights[i]);
        cv::cuda::add(weight_sum,weights[i], weight_sum);
    }
    int maxlevel = static_cast<int>(logf(static_cast<float>(cv::min(size.width, size.height))) / logf(2.0f));
    std::vector<cv::cuda::GpuMat> res_pyr(maxlevel + 1);

    for (size_t i = 0; i < images.size(); i++)
    {
        cv::cuda::divide(weights[i],weight_sum, weights[i]);
        cv::cuda::GpuMat img;
        images[i].convertTo(img, CV_32F, 1.0f / 255.0f);

        std::vector<cv::cuda::GpuMat> img_pyr(maxlevel+1), weight_pyr(maxlevel+1);
        buildPyramid(img, img_pyr, maxlevel);
        buildPyramid(weights[i], weight_pyr, maxlevel);

        for (int lvl = 0; lvl < maxlevel; lvl++)
        {
            cv::cuda::GpuMat up;
            pyrUp(img_pyr[lvl + 1], up, img_pyr[lvl].size());
            cv::cuda::subtract(img_pyr[lvl],up, img_pyr[lvl]);
        }
        for (int lvl = 0; lvl <= maxlevel; lvl++) 
        {
            std::vector<cv::cuda::GpuMat> splitted(channels);
            cv::cuda::split(img_pyr[lvl], splitted);
            for (int c = 0; c < channels; c++) 
            {
                cv::cuda::multiply(splitted[c],weight_pyr[lvl], splitted[c]);
            }
            cv::cuda::merge(splitted, img_pyr[lvl]);
            if (res_pyr[lvl].empty()) 
            {
                res_pyr[lvl] = img_pyr[lvl];
            }
            else 
            {
                cv::cuda::add(res_pyr[lvl],img_pyr[lvl], res_pyr[lvl]);
            }
        }
    }
    for (int lvl = maxlevel; lvl > 0; lvl--) 
    {
        cv::cuda::GpuMat up;
        pyrUp(res_pyr[lvl], up, res_pyr[lvl - 1].size());
        cv::cuda::add(res_pyr[lvl - 1],up, res_pyr[lvl - 1]);
    }
    cv::cuda::GpuMat last;
    res_pyr[0].convertTo(last, CV_8UC3, 255);
    dst.create(size, CV_8UC3);
    last.download(dst);
}

