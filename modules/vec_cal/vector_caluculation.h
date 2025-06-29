#ifndef VECTOR_UTILS_H
# define VECTOR_UTILS_H

# include <math.h>
# include <stdbool.h>
# include "../../miniRT.h"

// --- 関数プロトタイプ宣言 ---

// 生成
t_vec3  vec_new(double x, double y, double z);

// 基本演算
t_vec3  vec_add(t_vec3 v1, t_vec3 v2);
t_vec3  vec_sub(t_vec3 v1, t_vec3 v2);
t_vec3  vec_scalar_mul(t_vec3 v, double scalar); // スカラー倍（非常に便利なので追加）
t_vec3  vec_scalar_div(t_vec3 v, double scalar); // スカラー除算（便利なので追加）

// ベクトル特有の演算
double  vec_dot(t_vec3 v1, t_vec3 v2);
t_vec3  vec_cross(t_vec3 v1, t_vec3 v2);
double  vec_length(t_vec3 v);
t_vec3  vec_normalize(t_vec3 v);

#endif
