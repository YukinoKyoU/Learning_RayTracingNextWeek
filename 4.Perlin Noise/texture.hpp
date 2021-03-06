#ifndef TEXTURE_H
#define TEXTURE_H

#include "rtweekend.hpp"

#include "perlin.hpp"

//纹理类
class texture{
    public:
        virtual color value(double u, double v, const point3& p) const = 0;
};

class solid_color : public texture{
    public:
        solid_color(){}
        solid_color(color c) : color_value(c){}

        solid_color(double red, double green, double blue)
            :solid_color(color(red, green, blue)) {}

        virtual color value(double u, double v, const vec3& p) const override{
            return color_value;
        }

    private:
        color color_value;

};

//棋盘纹理类
class checker_texture : public texture {
    public:
        checker_texture() {}

        checker_texture(shared_ptr<texture> _even, shared_ptr<texture> _odd)
            : even(_even), odd(_odd) {}

        checker_texture(color c1, color c2)
            : even(make_shared<solid_color>(c1)) , odd(make_shared<solid_color>(c2)) {}

        //正余弦函数呈现周期性并关于x轴对称
        virtual color value(double u, double v, const point3& p) const override {
            auto sines = sin(10*p.x())*sin(10*p.y())*sin(10*p.z());
            if (sines < 0)
                return odd->value(u, v, p);
            else
                return even->value(u, v, p);
        }

    public:
        shared_ptr<texture> odd;
        shared_ptr<texture> even;
};

//柏林噪声纹理类
class noise_texture : public texture {
    public:
        noise_texture(){}
        //增加一个频率参数
        noise_texture(double sc) : scale(sc) {}

        virtual color value(double u, double v, const point3& p) const override{
            //让颜色与sin函数的值成比例，并使用扰动函数去调整相位，使得带状条纹有起伏
            return color(1, 1, 1) * 0.5 * (1 + sin(scale * p.z() + 10 * noise.turb(p)));
        }

    private:
        perlin noise;
        double scale;
};

#endif