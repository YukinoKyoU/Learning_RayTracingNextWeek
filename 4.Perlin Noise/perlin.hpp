#ifndef PERLIN_H
#define PERLIN_H

#include "rtweekend.hpp"

class perlin {
    public:
        perlin(){
            //用随机向量代替随机浮点数
            ranvec= new vec3[point_count];
            for(int i = 0; i < point_count; ++i){
                ranvec[i] = unit_vector(vec3::random(-1, 1));
            }

            perm_x = perlin_generate_perm();
            perm_y = perlin_generate_perm();
            perm_z = perlin_generate_perm();
        }

        ~perlin(){
            delete [] ranvec;
            delete [] perm_x;    
            delete [] perm_y;
            delete [] perm_z;

        }
        //用位与和位异或运算符完成随机
        double noise(const point3& p) const{

            //取出x，y，z小数部分
            auto u = p.x() - floor(p.x());
            auto v = p.y() - floor(p.y());
            auto w = p.z() - floor(p.z());

            auto i = static_cast<int>(floor(p.x()));
            auto j = static_cast<int>(floor(p.y()));
            auto k = static_cast<int>(floor(p.z()));
            vec3 c[2][2][2];

            for(int di = 0; di < 2; di++){
                for(int dj = 0; dj < 2; dj++){
                    for(int dk = 0; dk < 2; dk++){
                        c[di][dj][dk] = ranvec[
                            perm_x[(i + di) & 255]^
                            perm_y[(j + dj) & 255]^
                            perm_z[(k + dk) & 255]
                        ];
                    }
                }
            }

            return perlin_interp(c, u, v, w);
        }
    
    private:
        static const int point_count = 256;
        vec3 *ranvec;
        int* perm_x;
        int* perm_y;
        int* perm_z;

        //生成分量的随机数列，初始序列为1-255
        static int* perlin_generate_perm(){
            auto p = new int[point_count];

            for(int i =0; i < perlin::point_count; ++i)
                p[i] = i;
            
            //序列随机化
            permute(p, point_count);

            return p;
        }
        //遍历整个分量的随机数列，当前位置和一个随机生成的位置进行交换
        static void permute(int* p, int n){
            for(int i = n-1; i > 0; i--){
                int target = random_int(0, i);
                int tmp = p[i];
                p[i] = p[target];
                p[target] = tmp;
            }
        }
        //三线性插值
        static double perlin_interp(vec3 c[2][2][2], double u, double v, double w){
            auto uu = u * u * (3 - 2 * u);
            auto vv = v * v * (3 - 2 * v);
            auto ww = w * w * (3 - 2 * w);
            auto accum = 0.0;

            for(int i = 0; i < 2; i++){
                for(int j = 0; j < 2; j++){
                    for(int k = 0; k < 2; k++){
                        //各分量权重
                        vec3 weight_v(u - i, v - j, w - k);
                        accum += (i * uu + (1 - i) * (1 - uu))
                               * (j * vv + (1 - j) * (1 - vv))
                               * (k * ww + (1 - k) * (1 - ww))
                               * dot(c[i][j][k], weight_v); 
                    }
                }
            }
            return accum;
        }
};



#endif