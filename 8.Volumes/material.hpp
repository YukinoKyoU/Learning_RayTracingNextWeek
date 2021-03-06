#ifndef MATERIAL_H
#define MATERIAL_H

#include "rtweekend.hpp"
#include "texture.hpp"


struct hit_record;

class material{
    public:
        virtual bool scatter(
            const ray& r_in, const hit_record& rec, 
            vec3& attenuation, ray& scattered
        )const = 0;

        //不是所有材质都会发出光线，不写成纯虚函数，直接返回黑色
        virtual color emitted(double u, double v, const point3& p) const {
            return color(0,0,0);
        }

};

//光源材质
class diffuse_light : public material{
    public:
        diffuse_light(shared_ptr<texture> a) : emit(a){}
        diffuse_light(color c) : emit(make_shared<solid_color>(c)){}

        virtual bool scatter(
            const ray &r, const hit_record& rec, color& attenuation, ray& scattered
            )const override{
                return false;
            }

        virtual color emitted(double u, double v, const point3& p) const override{

            return emit->value(u, v, p);

        }

    public:               
        shared_ptr<texture> emit;
};

//漫反射
class lambertian: public material{
    public:
        //将衰减系数替换为纹理指针
        lambertian(const color& a): albedo(make_shared<solid_color>(a)){}
        lambertian(shared_ptr<texture> a) : albedo(a){}

        virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
        )const override {
            //扩散方向 = 法线方向 + 随机方向
            auto scatter_direction = rec.normal + random_unit_vector();

            //捕获退化的散射方向
            if(scatter_direction.near_zero())
                scatter_direction = rec.normal;

            //扩散之后的光线
            scattered = ray(rec.p, scatter_direction, r_in.time());
            //衰减值
            attenuation = albedo->value(rec.u, rec.v, rec.p);
            return true;
        }

    public:
        shared_ptr<texture> albedo;
};

//金属的全反射
class metal: public material{
    public:
        metal(const vec3& a, double f): albedo(a), fuzz(f < 1 ? f : 1) {}

        virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
        )const override {
            // 反射的方向
            vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
            //反射之后的光线, 在反射后的终点为球心内随机选取一个点作为最终的终点，作为模糊处理
            scattered = ray(rec.p, reflected + fuzz * random_in_unit_sphere(), r_in.time());
            //衰减值
            attenuation = albedo;
            //当反射光线与法线同向时返回
            return (dot(scattered.direction(), rec.normal) > 0);
        }

    public:
        color albedo;
        //模糊程度
        double fuzz;
};

// 一个只会发生折射和全反射的物体
class dielectric: public material{
    public:
        dielectric(double index_of_refraction): ir(index_of_refraction) {}

    virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
        )const override {
            //玻璃表面不吸收光的能量
            attenuation = color(1.0, 1.0, 1.0);
            double refraction_ratio = rec.front_face ? (1.0/ir) : ir;
            vec3 unit_direction = unit_vector(r_in.direction());

            //判断是折射还是全反射
            double cos_theta = fmin(dot(-unit_direction, rec.normal),1.0);
            double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

            bool cannot_refract = refraction_ratio * sin_theta > 1.0;
            vec3 direction;

            if(cannot_refract || reflectance(cos_theta, refraction_ratio) > random_double())
                direction = reflect(unit_direction, rec.normal);
            else
                direction = refract(unit_direction, rec.normal, refraction_ratio);

            scattered = ray(rec.p, direction, r_in.time());

            return true;
        }

    public:
        double ir;
    private:
        static double reflectance(double cosine, double ref_idx){
            //Schlick 近似， 从很狭窄的角度看玻璃，会变成镜子
            auto r0 = (1-ref_idx) / (1+ref_idx);
            r0 = r0 * r0;
            return r0 + (1-r0) * pow((1 - cosine), 5);
        }

};
//各同向性散射材料类
class isotropic : public material {
    public:
        isotropic(color c) : albedo(make_shared<solid_color>(c)) {}
        isotropic(shared_ptr<texture> a) : albedo(a) {}

        //各同向性散射均选取均匀的随机方向
        virtual bool scatter(
            const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered
        ) const override {
            scattered = ray(rec.p, random_in_unit_sphere(), r_in.time());
            attenuation = albedo->value(rec.u, rec.v, rec.p);
            return true;
        }

    public:
        shared_ptr<texture> albedo;
};

#endif