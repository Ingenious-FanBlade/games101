//
// Created by LEI XU on 4/27/19.
//
#include "Texture.hpp"
#include <math.h>

Eigen::Vector3f Texture::getColorBilinear(float u, float v)
{
    u = std::clamp(u, 0.0f, 1.0f);
    v = std::clamp(v, 0.0f, 1.0f);

    int u_img_l = std::min(static_cast<int>(std::floor(u* width)), width - 1);
    int v_img_b = std::min(static_cast<int>(std::floor((1 - v) * height)), height - 1);
    int u_img_r = std::min(static_cast<int>(std::ceil(u*width)),width-1);
    int v_img_t = std::min(static_cast<int>(std::ceil((1-v)*height)),height-1);

    float u_img = std::min(u*width,static_cast<float>(width-1));
    float v_img = std::min((1-v)*height,static_cast<float>(height-1));

    auto color_lt = image_data.at<cv::Vec3b>(v_img_t, u_img_l);
    auto color_lb = image_data.at<cv::Vec3b>(v_img_b,u_img_l);
    auto color_rt = image_data.at<cv::Vec3b>(v_img_t,u_img_r);
    auto color_rb = image_data.at<cv::Vec3b>(v_img_b,u_img_r);

    auto color_lt_ = Eigen::Vector3f(color_lt[0],color_lt[1],color_lt[2]);
    auto color_lb_ = Eigen::Vector3f(color_lb[0],color_lb[1],color_lb[2]);
    auto color_rt_ = Eigen::Vector3f(color_rt[0],color_rt[1],color_rt[2]);
    auto color_rb_ = Eigen::Vector3f(color_rb[0],color_rb[1],color_rb[2]);
    
    auto color_u_1 = color_lt_+(u_img-u_img_l)*(color_rt_-color_lt_);
    auto color_u_0 = color_lb_+(u_img-u_img_l)*(color_rb_-color_lb_);
    auto color_uv = color_u_0+(v_img-v_img_b)*(color_u_1-color_u_0);
    
    return color_uv;

}
