#ifndef INTERSECT_SPHERE_H
# define INTERSECT_SPHERE_H

# include <math.h>
# include <stdbool.h>

// --- 構造体の定義 ---
// プロジェクト全体で共有される型定義

// 3次元ベクトル
typedef struct s_vec3 {
    double x, y, z;
} t_vec3;

// レイ（光線）
typedef struct s_ray {
    t_vec3 origin;    // 始点
    t_vec3 direction; // 方向 (正規化されていること)
} t_ray;

// 球
typedef struct s_sphere {
    t_vec3   center;
    double   diameter;
    // t_color color; // 将来的に追加
} t_sphere;


// --- 関数プロトタイプ宣言 ---
// 実装ファイル (.c) で定義される関数の宣言

double  intersect_sphere(t_ray ray, t_sphere sphere);

// --- ヘルパー関数のプロトタイプ宣言 ---
// (テストや実装で使うかもしれないヘルパー関数)
t_vec3  vec_new(double x, double y, double z);


#endif
